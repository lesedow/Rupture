#include "Precompiled.hh"
#include "Graphics/GL/VertexArrayObject.hh"
#include "Utils/Macros/GLMacros.hh"

namespace Rupture::Graphics::GL
{
	VertexArrayObject::VertexArrayObject()
	{
		RP_GL(glGenVertexArrays(1, &m_ID));
	}

	VertexArrayObject::~VertexArrayObject()
	{
		RP_GL(glDeleteVertexArrays(1, &m_ID));
	}

	void VertexArrayObject::Bind() const
	{
		RP_GL(glBindVertexArray(m_ID));
	}

	void VertexArrayObject::Unbind() const
	{
		RP_GL(glBindVertexArray(0));
	}

	void VertexArrayObject::EnableAtttributes(GLuint count) const
	{
		for (auto i = 0; i <= count; i++)
		{
			RP_GL(glEnableVertexAttribArray(i));
		}
	}

	void VertexArrayObject::EnableAtttributes(GLuint from, GLuint to) const
	{
		for (auto i = from; i <= to; i++)
		{
			RP_GL(glEnableVertexAttribArray(i));
		}
	}
}