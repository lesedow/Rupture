#pragma once

#include "Precompiled.hh"
#include "GLTypes.hh"

namespace Rupture::Graphics::GL
{
	class Texture2D
	{
	private:
		glm::vec2 Size_;
		GLuint ID_;
	public:
		Texture2D();
		Texture2D(const std::string& path);
		~Texture2D();
		void Bind(GLenum slot);
		glm::vec2 GetSize() const;
	};
}