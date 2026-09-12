#pragma once

#ifdef RUPTURE_DEBUG
#ifndef RUPTUREASSERT 
#define RUPTUREASSERT(condition, message)\
	do {\
		if (!(condition)){\
			std::cout << std::format(\
				"[ASSERT]: {}\n {}\n[File]: {}\n[Line]: {}\n",\
				#condition, message, __FILE__, __LINE__);\
			__debugbreak();\
		}\
	} while (0)
#endif

#ifndef RUPTURE_LOG_INFO
#define RUPTURE_LOG_INFO(message) \
		Rupture::Utils::Logging::Logger::GetInstance() \
			.LogInfo(message, Rupture::Utils::Logging::Logger::GL_MODULE);
#endif
#ifndef RUPTURE_LOG_WARN
#define RUPTURE_LOG_WARN(message) \
		Rupture::Utils::Logging::Logger::GetInstance() \
			.LogWarn(message, Rupture::Utils::Logging::Logger::GL_MODULE);
#endif
#ifndef RUPTURE_LOG_FATAL
#define RUPTURE_LOG_FATAL(message) \
		Rupture::Utils::Logging::Logger::GetInstance() \
			.LogFatal(message, Rupture::Utils::Logging::Logger::GL_MODULE);
#endif
#endif