#include "Utils/Logger.hh"

namespace Rupture::Utils::Logging
{
	Logger& Logger::GetInstance() {
		static Logger instance;
		return instance;
	}

	void Logger::SetConsoleColor(LogColor color) const
	{
		#ifdef _WIN32
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(handle, std::to_underlying(color));
		#endif 
	}

	std::string_view Logger::GetTimestamp() const
	{
		auto now = std::chrono::system_clock::now();
		std::chrono::zoned_time localTime{ std::chrono::current_zone(), now };

		return std::format("{%H:%M:%S}", localTime);
	}
}