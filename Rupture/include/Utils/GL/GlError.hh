#pragma once

#include <string>

namespace Rupture::Utils::GL
{
	inline void ClearGLErrors()
	{
		namespace gl = Rupture::Graphics::GL;
		while (gl::glGetError() != gl::GL_NO_ERROR);
	}

	inline std::string GetGLErrors()
	{
		namespace gl = Rupture::Graphics::GL;
		std::string errors{};
		while (GLenum error = gl::glGetError())
		{
			switch (error)
			{
			case gl::GL_INVALID_ENUM: errors.append("INVALID ENUM\n"); break;
			case gl::GL_INVALID_VALUE: errors.append("INVALID VALUE\n"); break;
			case gl::GL_INVALID_OPERATION: errors.append("INVALID OPERATION\n"); break;
			case gl::GL_INVALID_FRAMEBUFFER_OPERATION: errors.append("INVALID FRAMEBUFFER OPERATION\n"); break;
			case gl::GL_OUT_OF_MEMORY: errors.append("OUT OF MEMORY\n"); break;
			}
		}

		return errors;
	}
}