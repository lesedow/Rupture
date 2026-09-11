#pragma once

#include "GLTypes.hh"

#include <glm/glm.hpp>
#include <string>

namespace Rupture::Graphics::GL
{
	class Texture2D
	{
	private:
		glm::vec2 size;
		GLuint id;
	public:
		Texture2D(const std::string& path);
		void Bind(GLenum slot);
	};
}