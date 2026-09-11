#pragma once

#include "Logger.hh"

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
			.Log(message, Rupture::Utils::Logging::LogLevel::INFO);
#endif
#ifndef RUPTURE_LOG_WARN
#define RUPTURE_LOG_WARN(message) \
		Rupture::Utils::Logging::Logger::GetInstance() \
			.Log(message, Rupture::Utils::Logging::LogLevel::WARN);
#endif
#ifndef RUPTURE_LOG_FATAL
#define RUPTURE_LOG_FATAL(message) \
		Rupture::Utils::Logging::Logger::GetInstance() \
			.Log(message, Rupture::Utils::Logging::LogLevel::FATAL);
#endif
#endif

#ifndef RUPTURE_GL_CALL
#define RUPTURE_GL_CALL(statement) \
	do {\
		Rupture::Utils::Logging::ClearGLErrors();\
		(statement); \
		std::string errors = Rupture::Utils::Logging::GetGLErrors();\
		if (!errors.empty()) {\
			std::cout << std::format(\
				"[RUPTURE][GLERROR]:\n[STATEMENT]: {}\n[FILE]: {}\n[LINE]: {}\n[ERRORS]: {}\n",\
				#statement, __FILE__, __LINE__, errors\
			);\
			__debugbreak();\
		}\
	} while(0)
#endif