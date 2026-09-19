#pragma once

#include <iostream>
#include <string_view>
#include <windows.h>

namespace Rupture::Utils::Logging
{
	enum class LogColor
	{
		DEFAULT_COLOR = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
		FATAL_COLOR = FOREGROUND_INTENSITY | FOREGROUND_RED,
		WARN_COLOR = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN
	};

	class Logger
	{
	public:
		static constexpr std::string_view NAME			= "[RUPTURE]";
		static constexpr std::string_view GL_MODULE		= "[GL]";
		static constexpr std::string_view FATAL_LVL		= "[ERROR]";
		static constexpr std::string_view INFO_LVL		= "[INFO]";
		static constexpr std::string_view WARN_LVL		= "[WARN]";
		static constexpr std::string_view ASSERTION		= "[ASSERT]";
	private:
		Logger() {}
		void Log(
			std::string_view message, 
			std::string_view module, 
			std::string_view lvl,
			LogColor color,
			std::ostream& stream) const;
	public:
		Logger(const Logger&) = delete;
		Logger& operator=(const Logger&) = delete;
		
		static Logger& GetInstance();
		void SetConsoleColor(LogColor color) const;
		void LogInfo(std::string_view message, std::string_view module) const;
		void LogWarn(std::string_view message, std::string_view module) const;
		void LogFatal(std::string_view message, std::string_view module) const;
		void Assert(bool condition, std::string_view message, std::string_view module) const;
		std::string GetTimestamp() const;
	};
}