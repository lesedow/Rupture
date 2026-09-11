#pragma once

#include <iostream>
#include <string>
#include <windows.h>
#include <chrono>

namespace Rupture::Utils::Logging
{
	enum class LogLevel
	{
		INFO, WARN, FATAL
	};

	enum class LogColor
	{
		INFO_COLOR = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
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
	private:
		Logger() {}
	public:
		Logger(const Logger&) = delete;
		Logger& operator=(const Logger&) = delete;
		
		static Logger& GetInstance();
		void SetConsoleColor(LogColor color) const;
		void Log(std::string_view message, LogLevel level) const;
		std::string_view GetTimestamp() const;
	};


	//inline void ClearGLErrors()
	//{
	//	namespace gl = Rupture::Graphics::GL;
	//	while (gl::glGetError() != gl::GL_NO_ERROR);
	//}

	//inline std::string GetGLErrors()
	//{
	//	namespace gl = Rupture::Graphics::GL;
	//	std::string errors{};
	//	while (GLenum error = gl::glGetError())
	//	{
	//		switch (error)
	//		{
	//		case gl::GL_INVALID_ENUM: errors.append("INVALID ENUM\n"); break;
	//		case gl::GL_INVALID_VALUE: errors.append("INVALID VALUE\n"); break;
	//		case gl::GL_INVALID_OPERATION: errors.append("INVALID OPERATIO\n"); break;
	//		case gl::GL_INVALID_FRAMEBUFFER_OPERATION: errors.append("INVALID FRAMEBUFFER OPERATION\n"); break;
	//		case gl::GL_OUT_OF_MEMORY: errors.append("OUT OF MEMORY\n"); break;
	//		}
	//	}

	//	return errors;
	//}
}