#pragma once

#if defined(_WIN32)
#ifndef RUPTURE_WIN32_CHECK
#define RUPTURE_WIN32_CHECK(failCondition) \
	do{\
		DWORD errorID = GetLastError();\
		if ((failCondition) && errorID != ERROR_SUCCESS){\
			std::string formattedError = Utils::Platform::GetFormattedErrorMessage(errorID);\
			RUPTURE_LOG_FATAL(formattedError);\
			__debugbreak();\
		}\
	}while(0)
#endif
#endif