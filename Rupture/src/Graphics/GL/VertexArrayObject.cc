#include "Precompiled.hh"
#include "Graphics/GL/VertexArrayObject.hh"
#include "Utils/Macros/GLMacros.hh"

namespace Rupture::Graphics::GL
{
	VertexArrayObject::VertexArrayObject()
	{
		RP_GL(glGenVertexArrays(1, &ID_));
	}

	VertexArrayObject::~VertexArrayObject()
	{
		RP_GL(glDeleteVertexArrays(1, &ID_));
	}

	void VertexArrayObject::Bind() const
	{
		RP_GL(glBindVertexArray(ID_));
	}

	void VertexArrayObject::Unbind() const
	{
		RP_GL(glBindVertexArray(0));
	}
}