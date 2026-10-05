#include "Precompiled.hh"
#include "Graphics/GL/GLBuffer.hh"
#include "Utils/Macros/GLMacros.hh"

namespace Rupture::Graphics::GL
{
	GLBuffer::GLBuffer(GLenum type)
		:m_Type(type)
	{
		RP_GL(glGenBuffers(1, &m_ID));
	}

	GLBuffer::~GLBuffer()
	{
		RP_GL(glDeleteBuffers(1, &m_ID));
	}

	void GLBuffer::AllocateData(GLsizeiptr size, const GLvoid* data, GLenum usage)
	{
		RP_GL(glBufferData(m_Type, size, data, usage));
	}

	void GLBuffer::Bind() const
	{
		RP_GL(glBindBuffer(m_Type, m_ID));
	}

	void GLBuffer::Unbind() const
	{
		RP_GL(glBindBuffer(m_Type, 0));
	}
}