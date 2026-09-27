#pragma once

#include "Precompiled.hh"

namespace Rupture::Logging
{
	class Logger
	{
	private:
		Logger() {}
	public:
	void Log(
		std::string_view message, 
		std::string_view category, 
		std::string_view color, 
		std::string_view lvl) const;
	std::string GetTimestamp() const;
	public:
		Logger(const Logger&) = delete;
		Logger& operator=(const Logger&) = delete;
		static Logger& GetInstance();
	};
}