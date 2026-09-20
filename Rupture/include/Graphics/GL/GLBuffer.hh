#pragma once

#include "Graphics/GL/GLTypes.hh"

namespace Rupture::Graphics::GL
{
	class GLBuffer
	{
	private:
		GLuint ID_;
		GLenum Type_;
	public:
		GLBuffer(GLenum type);
		~GLBuffer();
		void AllocateData(GLsizeiptr size, const GLvoid* data = nullptr, GLenum usage = GL_DYNAMIC_DRAW);
		void Bind() const;
		void Unbind() const;
	};
}	