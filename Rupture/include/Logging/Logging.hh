#pragma once

#include "Precompiled.hh"

#include "LoggingConstants.hh"
#include "Platform/Console.hh"

namespace Rupture::Logging
{

	enum class LogCategory
	{
		WIN,
		X11,
		WAYLAND,
		COCOA,
		ANDROID,
		GL,
		VK,
		METAL,
	};

	enum class LogLevel
	{
		TRACE,
		DEBUG,
		WARN,
		INFO,
		ERROR
	};

	template<LogCategory Category> 
	class Logger
	{
	private:
		Category m_Category;
		std::shared_ptr<Platform::Console> m_ConsoleRef;
	public:
		explicit Logger(Category category, std::shared_ptr<Platform::Console> outConsole) 
			:m_Category(category) {};
		
		template<class Args...>
		void Trace(std::format_string<Args...> fmt, Args&&... args)
		{

		}
	};

	using GLLogger	= Logger<LogCategory::GL>;
	using WINLogger = Logger<LogCategory::WIN>;
	
	void Log(std::string_view message, std::string_view category, std::string_view color, std::string_view lvl);
	std::string GetTimestamp();
	
	template <class... Args>
	inline void LogTrace(std::format_string<Args...> fmt, Args&&... args)
	{
		auto msg = std::format(fmt, std::forward<Args>(args)...);
	}
	void LogDebug();
	void LogInfo();
	void LogWarn();
	void LogError();
}