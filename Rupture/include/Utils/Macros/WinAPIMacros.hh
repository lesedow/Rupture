#pragma once

#include "Precompiled.hh"

#if defined(_WIN64)
#ifndef RP_WIN64
#define RP_WIN64(failCondition) \
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