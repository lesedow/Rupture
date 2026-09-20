#pragma once

#include "Utils/Logging/Logger.hh"

#ifndef RP_ASSERT
#define RP_ASSERT(condition, message)\
	do {\
		if (!(condition)){\
			std::cout << std::format(\
				"[ASSERT]: {}\n {}\n[File]: {}\n[Line]: {}\n",\
				#condition, message, __FILE__, __LINE__);\
			__debugbreak();\
		}\
	} while (0)
#endif

#ifndef RP_LOG_INFO
#define RP_LOG_INFO(message) \
		Rupture::Utils::Logging::Logger::GetInstance() \
			.LogInfo(message, Rupture::Utils::Logging::Logger::GL_MODULE);
#endif
#ifndef RP_LOG_WARN
#define RP_LOG_WARN(message) \
		Rupture::Utils::Logging::Logger::GetInstance() \
			.LogWarn(message, Rupture::Utils::Logging::Logger::GL_MODULE);
#endif
#ifndef RP_LOG_ERROR
#define RP_LOG_ERROR(message) \
		Rupture::Utils::Logging::Logger::GetInstance() \
			.LogError(message, Rupture::Utils::Logging::Logger::GL_MODULE);
#endif