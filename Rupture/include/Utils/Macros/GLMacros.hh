#pragma once

#ifndef GLLOAD
#define GLLOAD(procName) Rupture::Graphics::GL::LoadGLFunction(procName, #procName);
#endif

#ifndef RUPTURE_GL_CALL
#define RUPTURE_GL_CALL(statement) \
	do {\
		Rupture::Utils::GL::ClearGLErrors();\
		(statement); \
		std::string errors = Rupture::Utils::GL::GetGLErrors();\
		if (!errors.empty()) {\
			RUPTURE_LOG_FATAL(std::format(\
				"\n[STATEMENT]: {}\n[FILE]: {}\n[LINE]: {}\n[ERROR]: {}\n",\
				#statement, __FILE__, __LINE__, errors\
				))\
			__debugbreak();\
		}\
	} while(0)
#endif