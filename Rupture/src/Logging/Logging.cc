#include "Logging/Logging.hh"

namespace Rupture::Logging
{
	void Log(std::string_view message, std::string_view category, std::string_view color, std::string_view lvl)
	{
		std::string timeStamp = GetTimestamp();

		// This assumes VST is enabled
		std::cout << color;

		std::cout << std::format("{}{}{}: {}\n", timeStamp, category, lvl, message);
	}

	std::string GetTimestamp()
	{
		const auto now = std::chrono::system_clock::now();
		const auto seconds = std::chrono::time_point_cast<std::chrono::seconds>(now);

		std::chrono::zoned_time localTime{ std::chrono::current_zone(), seconds };

		return std::format("[{:%H:%M:%S}]", localTime);
	}

	DEF_LOG(Trace, TRACE);
	DEF_LOG(Debug, DEBUG);
	DEF_LOG(Info, INFO);
	DEF_LOG(Warn, WARN);
	DEF_LOG(Error, ERROR);
}