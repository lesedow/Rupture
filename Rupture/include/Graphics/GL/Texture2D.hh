#pragma once

#include "GLTypes.hh"

#include <glm/glm.hpp>
#include <string>

namespace Rupture::Graphics::GL
{
	class Texture2D
	{
	private:
		glm::vec2 size_;
		GLuint id_;
	public:
		Texture2D(const std::string& path);
		void Bind(GLenum slot);
		glm::vec2 GetSize() const;
	};
}