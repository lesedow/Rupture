#pragma once 

#include <windows.h>
#include <string>
#include <format>

namespace Rupture::Utils::Platform
{
	std::string GetFormattedErrorMessage(DWORD errorID)
	{
		char* buffer{ nullptr };

		DWORD length = FormatMessage(
			FORMAT_MESSAGE_ALLOCATE_BUFFER |
			FORMAT_MESSAGE_FROM_SYSTEM |
			FORMAT_MESSAGE_IGNORE_INSERTS,
			nullptr,
			errorID,
			0,
			// This is some next level bullshittery
			reinterpret_cast<LPWSTR>(buffer),
			0,
			nullptr
		);

		if (length == 0)
		{
			DWORD currentErrorId = GetLastError();
			return std::format("Failed to format last error: ID - {}", currentErrorId);
		}

		std::string message(buffer, length);
		LocalFree(buffer);

		return message;
	}
}