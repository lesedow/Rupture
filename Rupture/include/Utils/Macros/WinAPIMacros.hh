#pragma once

#include "Precompiled.hh"

#if defined(_WIN32)
#ifndef RP_WINAPI
#define RP_WINAPI(failCondition) \
	do{\
		DWORD errorID = GetLastError();\
		if ((failCondition) && errorID != ERROR_SUCCESS){\
			std::string formattedError = Utils::Platform::GetFormattedErrorMessage(errorID);\
			RP_LOG_ERROR(formattedError);\
			__debugbreak();\
		}\
	}while(0)
#endif
#endif