#include "Precompiled.hh"
#include "Graphics/GL/Texture2D.hh"

#include "Utils/Macros/LoggerMacros.hh"
#include "Utils/Macros/GLMacros.hh"

#include "Utils/Logging/Logger.hh"
#include "Utils/GL/GLError.hh"

namespace Rupture::Graphics::GL
{
	Texture2D::Texture2D(const std::string& path)
	{
		int width, height, channels;
		unsigned char* imageData = stbi_load(path.c_str(), &width, &height, &channels, 0);

		if (!imageData) RP_LOG_ERROR(std::format("Failed to load image: {}", path));

		size_ = glm::vec2(width, height);
		GLenum pixelFormat = channels == 4 ? GL_RGBA : GL_RGB;

		RP_GL(glGenTextures(1, &id_));
		RP_GL(glBindTexture(GL_TEXTURE_2D, id_));

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

	glm::vec2 Texture2D::GetSize() const
	{
		return size_;
	}

	void Texture2D::Bind(GLenum slot)
	{
		RP_GL(glActiveTexture(slot));
		RP_GL(glBindTexture(GL_TEXTURE_2D, id_));
	}
}