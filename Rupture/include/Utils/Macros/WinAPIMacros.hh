#pragma once

#include "Precompiled.hh"

#include "Utils/Logging/Logging.hh"
#include "Utils/Platform/WinAPI.hh"

#ifdef _WIN32
#define RP_WINAPI(failCondition) \
	do{\
		DWORD errorID = GetLastError();\
		if ((failCondition) && errorID != ERROR_SUCCESS){\
			std::wstring formattedError = Rupture::Utils::Platform::GetFormattedErrorMessage(errorID);\
			Rupture::Logging::LogError(formattedError, Rupture::Logging::CAT_WINAPI);\
			__debugbreak();\
		}\
	}while(0)
#define RP_CLWINAPI(failCondition)\
	do{\
		DWORD errorID = GetLastError();\
		if ((failCondition) && errorID != ERROR_SUCCESS){\
			std::wstring formattedError = Rupture::Utils::Platform::GetFormattedErrorMessage(errorID);\
			OutputDebugString(formattedError.c_str());\
		}\
	}while(0)
#endif