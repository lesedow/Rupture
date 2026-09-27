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
		std::wstring_view message, 
		std::wstring_view category, 
		std::wstring_view color, 
		std::wstring_view lvl) const;
	std::wstring GetTimestamp() const;
	public:
		Logger(const Logger&) = delete;
		Logger& operator=(const Logger&) = delete;
		static Logger& GetInstance();
	};
}