#include "Precompiled.hh"
#include "Graphics/GL/Texture2D.hh"

#include "Utils/Macros/LoggerMacros.hh"
#include "Utils/Macros/GLMacros.hh"

#include "Utils/Logging/Logger.hh"
#include "Utils/GL/GLError.hh"

namespace Rupture::Graphics::GL
{

	// Generates a white texture by default
	Texture2D::Texture2D()
		:Size_(glm::vec2(1.0f, 1.0f))
	{
		GLuint white{ 0xFFFFFF };

		RP_GL(glGenTextures(1, &ID_));
		RP_GL(glBindTexture(GL_TEXTURE_2D, ID_));

		RP_GL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));
		RP_GL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));
		RP_GL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST));
		RP_GL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));

		RP_GL(glTexImage2D(
			GL_TEXTURE_2D, 0, GL_RGBA, 0x1, 
			0x1, 0, GL_RGBA, GL_UNSIGNED_BYTE, &white
		));

		RP_GL(glGenerateMipmap(GL_TEXTURE_2D));
	}

	Texture2D::~Texture2D()
	{
		RP_GL(glDeleteTextures(1, &ID_));
	}

	Texture2D::Texture2D(const std::string& path)
	{
		int width, height, channels;
		unsigned char* imageData = stbi_load(path.c_str(), &width, &height, &channels, 0);

		if (!imageData) RP_LOG_ERROR(std::format("Failed to load image: {}", path));

		Size_ = glm::vec2(width, height);
		GLenum pixelFormat = channels == 4 ? GL_RGBA : GL_RGB;

		RP_GL(glGenTextures(1, &ID_));
		RP_GL(glBindTexture(GL_TEXTURE_2D, ID_));

		RP_GL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));
		RP_GL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));
		RP_GL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST));
		RP_GL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));

		RP_GL(glTexImage2D(
			GL_TEXTURE_2D, 0, pixelFormat, width, 
			height, 0, pixelFormat, GL_UNSIGNED_BYTE, imageData
		));

		RP_GL(glGenerateMipmap(GL_TEXTURE_2D));

		stbi_image_free(imageData);
	}

	glm::vec2 Texture2D::GetSize() const { return Size_; }

	void Texture2D::Bind(GLenum slot)
	{
		RP_GL(glActiveTexture(slot));
		RP_GL(glBindTexture(GL_TEXTURE_2D, ID_));
	}
}