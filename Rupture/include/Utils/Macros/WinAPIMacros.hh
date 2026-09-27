#pragma once

#include "Precompiled.hh"

#include "Utils/Logging/Logging.hh"
#include "Utils/Platform/WinAPI.hh"

#if defined(_WIN32)
#ifndef RP_WINAPI
#define RP_WINAPI(failCondition) \
	do{\
		DWORD errorID = GetLastError();\
		if ((failCondition) && errorID != ERROR_SUCCESS){\
			std::string formattedError = Rupture::Utils::Platform::GetFormattedErrorMessage(errorID);\
			Rupture::Logging::LogError(formattedError, Rupture::Logging::CAT_WINAPI);\
			__debugbreak();\
		}\
	}while(0)
#endif
#endif