#include "Graphics/GL/Texture2D.hh"
#include "Utils/Logger.hh"
#include "stb_image.h"

namespace Rupture::Graphics::GL
{
	Texture2D::Texture2D(const std::string& path)
	{
		int width, height, channels;
		unsigned char* imageData = stbi_load(path.c_str(), &width, &height, &channels, 0);
		size = glm::vec2(width, height);

		GLenum pixelFormat = channels == 4 ? GL_RGBA : GL_RGB;

		RUPTURE_GL_CALL(glGenTextures(1, &id));
		RUPTURE_GL_CALL(glBindTexture(GL_TEXTURE_2D, id));

		RUPTURE_GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));
		RUPTURE_GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));
		RUPTURE_GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST));
		RUPTURE_GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));

		RUPTUREASSERT(imageData != nullptr, "Failed to load image!");

		RUPTURE_GL_CALL(glTexImage2D(
			GL_TEXTURE_2D, 0, pixelFormat, width, 
			height, 0, pixelFormat, GL_UNSIGNED_BYTE, imageData
		));

		RUPTURE_GL_CALL(glGenerateMipmap(GL_TEXTURE_2D));

		stbi_image_free(imageData);
	}

	void Texture2D::Bind(GLenum slot)
	{
		RUPTURE_GL_CALL(glActiveTexture(slot));
		RUPTURE_GL_CALL(glBindTexture(GL_TEXTURE_2D, id));
	}
}