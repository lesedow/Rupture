#include <chrono>

#include "Utils/Logging/Logger.hh"

namespace Rupture::Utils::Logging
{
	Logger& Logger::GetInstance() {
		static Logger instance;
		return instance;
	}

	void Logger::Log(
		std::string_view message, 
		std::string_view module, 
		std::string_view lvl,
		LogColor color,
		std::ostream& stream) const
	{
		SetConsoleColor(color);
		std::string timeStamp = GetTimestamp();
		stream << std::format("{}{}{}{}: {}\n", timeStamp, NAME, module, lvl, message);
		SetConsoleColor(LogColor::DEFAULT_COLOR);
	}

	void Logger::LogInfo(std::string_view message, std::string_view module) const
	{
		Log(message, module, INFO_LVL, LogColor::DEFAULT_COLOR, std::cout);
	}

	void Logger::LogWarn(std::string_view message, std::string_view module) const
	{
		Log(message, module, WARN_LVL, LogColor::WARN_COLOR, std::cout);
	}

	void Logger::LogFatal(std::string_view message, std::string_view module) const
	{
		Log(message, module, FATAL_LVL, LogColor::FATAL_COLOR, std::cerr);
	}

	void Logger::SetConsoleColor(LogColor color) const
	{
		#ifdef _WIN32
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(handle, std::to_underlying(color));
		#endif 
	}

	std::string Logger::GetTimestamp() const
	{
		const auto now = std::chrono::system_clock::now();
		const auto seconds = std::chrono::time_point_cast<std::chrono::seconds>(now);

		std::chrono::zoned_time localTime{ std::chrono::current_zone(), seconds };

		return std::format("[{:%H:%M:%S}]", localTime);
	}
}