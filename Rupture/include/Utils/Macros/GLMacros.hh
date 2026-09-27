#pragma once

#include "Precompiled.hh"

#include "Utils/GL/GLError.hh"
#include "Utils/Logging/Logging.hh"

#ifndef GLLOAD
#define GLLOAD(procName) Rupture::Graphics::GL::LoadGLFunction(procName, #procName);
#endif

#ifndef RP_GL
#define RP_GL(statement) \
do {\
	Rupture::Utils::GL::ClearGLErrors();\
	(statement); \
	std::string errors = Rupture::Utils::GL::GetGLErrors();\
	if (!errors.empty()) {\
		Rupture::Logging::LogError(std::format(\
			L"\n[STATEMENT]: {}\n[FILE]: {}\n[LINE]: {}\n[ERROR]: {}\n",\
			#statement, __FILE__, __LINE__, errors\
			), Rupture::Logging::CAT_GL);\
		__debugbreak();\
	}\
} while(0)
#endif