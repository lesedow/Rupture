#pragma once

#include "Precompiled.hh"
#include "Graphics/GL/GLTypes.hh"

namespace Rupture::Utils::GL
{ 
	inline void ClearGLErrors()
	{
		while (Graphics::GL::glGetError() != Graphics::GL::GL_NO_ERROR);
	}

	inline std::string GetGLErrors()
	{
		std::string errors{};
		while (Graphics::GL::GLenum error = Graphics::GL::glGetError())
		{
			switch (error)
			{
			case Graphics::GL::GL_INVALID_ENUM: errors.append("INVALID ENUM\n"); break;
			case Graphics::GL::GL_INVALID_VALUE: errors.append("INVALID VALUE\n"); break;
			case Graphics::GL::GL_INVALID_OPERATION: errors.append("INVALID OPERATION\n"); break;
			case Graphics::GL::GL_INVALID_FRAMEBUFFER_OPERATION: errors.append("INVALID FRAMEBUFFER OPERATION\n"); break;
			case Graphics::GL::GL_OUT_OF_MEMORY: errors.append("OUT OF MEMORY\n"); break;
			}
		}

		return errors;
	}
}