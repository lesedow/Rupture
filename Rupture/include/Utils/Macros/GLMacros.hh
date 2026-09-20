#pragma once

#ifndef GLLOAD
#define GLLOAD(procName) Rupture::Graphics::GL::LoadGLFunction(procName, #procName);
#endif

#include <string>
#include <format>

#include "Utils/GL/GLError.hh"
#include "Utils/Macros/LoggerMacros.hh"

#ifndef RP_GL
#define RP_GL(statement) \
	do {\
		Rupture::Utils::GL::ClearGLErrors();\
		(statement); \
		std::string errors = Rupture::Utils::GL::GetGLErrors();\
		if (!errors.empty()) {\
			RP_LOG_ERROR(std::format(\
				"\n[STATEMENT]: {}\n[FILE]: {}\n[LINE]: {}\n[ERROR]: {}\n",\
				#statement, __FILE__, __LINE__, errors\
				))\
			__debugbreak();\
		}\
	} while(0)
#endif