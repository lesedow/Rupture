#pragma once

#include "Precompiled.hh"
#include "Logging/LoggingConstants.hh"
#include "Logging/Logger.hh"

#define REGISTER_LOG(name, type) \
	inline void Log##name(\
		std::wstring_view message,\
		std::wstring_view category) \
	{ \
		if constexpr (RP_LEVEL & (RP_##type)) {  \
			Logger::GetInstance().Log(message, category, type##_COLOR, type##_LVL); \
		} \
	}

namespace Rupture::Logging
{
	REGISTER_LOG(Trace,	TRACE);
	REGISTER_LOG(Debug,	DEBUG);
	REGISTER_LOG(Info,	INFO);
	REGISTER_LOG(WARN,	WARN);
	REGISTER_LOG(Error,	ERROR);
}