#include "Graphics/GL/GLBuffer.hh"
#include "Utils/Macros/GLMacros.hh"

namespace Rupture::Graphics::GL
{
	GLBuffer::GLBuffer(GLenum type)
		:Type_(type)
	{
		RP_GL(glGenBuffers(1, &ID_));
	}

	GLBuffer::~GLBuffer()
	{
		RP_GL(glDeleteBuffers(1, &ID_));
	}

	void GLBuffer::AllocateData(GLsizeiptr size, const GLvoid* data, GLenum usage)
	{
		RP_GL(glBufferData(Type_, size, data, usage));
	}

	void GLBuffer::Bind() const
	{
		RP_GL(glBindBuffer(Type_, ID_));
	}

	void GLBuffer::Unbind() const
	{
		RP_GL(glBindBuffer(Type_, 0));
	}
}