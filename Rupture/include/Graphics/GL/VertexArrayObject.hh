#pragma once

#include "Graphics/GL/GLTypes.hh"

namespace Rupture::Graphics::GL
{
	class VertexArrayObject
	{
	private:
		GLuint ID_;
	public:
		VertexArrayObject();
		~VertexArrayObject();
	public:
		void Bind() const;
		void Unbind() const;
	};
}