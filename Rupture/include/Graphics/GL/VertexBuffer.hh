#pragma once

#include "GLTypes.hh"

namespace Rupture::Graphics::GL
{
	class VertexBuffer
	{
	private:
		GLuint bufferId_;
		GLenum type_;
	public:
		VertexBuffer(GLenum type);
		void SetData(GLsizeiptr size, const GLVoid* data, GLenum usage)
	};
}	