#pragma once

#include "Precompiled.hh"
#include "GLTypes.hh"

namespace Rupture::Graphics::GL
{
	class Texture2D
	{
	private:
		glm::vec2 m_Size;
		GLuint m_ID;
	public:
		Texture2D();
		Texture2D(const std::string& path);
		~Texture2D();
		void Bind(GLenum slot) const;
		glm::vec2 GetSize() const;
	};
}