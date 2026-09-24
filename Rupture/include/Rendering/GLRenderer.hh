#pragma once

#include "Precompiled.hh"

#include "Graphics/GL/GLTypes.hh"
#include "Graphics/GL/Texture2D.hh"
#include "Graphics/GL/GLBuffer.hh"
#include "Graphics/GL/VertexArrayObject.hh"
#include "Graphics/GL/ShaderProgram.hh"

namespace Rupture::Rendering
{
	struct Vertex
	{
		glm::vec3 Position;
		glm::vec4 Color;
		glm::vec2 TextureCoords;
		std::uint32_t TextureId;
	};

	class GLRenderer
	{
	private:
		static constexpr Graphics::GL::GLsizeiptr BATCH_CAPACITY	= 0x2710LL;
		static constexpr Graphics::GL::GLint MAX_QUADS				= BATCH_CAPACITY / 4;
		static constexpr Graphics::GL::GLint INDICES_PER_QUAD		= 6;
		static constexpr Graphics::GL::GLint MAX_INDICES			= MAX_QUADS * INDICES_PER_QUAD;
		static constexpr Graphics::GL::GLint MAX_ACTIVE_TEXTURES	= 32;
	private:
		std::vector<glm::mat3> ModelMatrices_;
		std::vector<std::uint32_t> Indices_;
		Graphics::GL::VertexArrayObject VertexArrayObject_;
		Graphics::GL::GLBuffer FixedVertexData_;
		Graphics::GL::GLBuffer PerInstanceData_;
		Graphics::GL::GLBuffer ElementBufferObject_;
		Graphics::GL::ShaderProgram ShaderProgram_;
		Graphics::GL::GLuint QuadCount_;
		glm::vec2 ViewportSize_;
		glm::mat4 ProjectionMatrix_;
		glm::mat4 ViewMatrix_;

		Graphics::GL::Texture2D WhiteTexture_;
	private:
		void GenIndices();
	public:
		explicit GLRenderer(glm::vec2 viewportSize);
		~GLRenderer();
	public:
		void StartBatch();
		void EndBatch();
		void DrawQuad(glm::vec2 position, glm::vec2 size, glm::vec4 color);
		void DrawCircle(glm::vec2 position, Graphics::GL::GLfloat radius, glm::vec4 color);
		void DrawTexture(const Graphics::GL::Texture2D& texture, glm::vec2 position, glm::vec2 size, glm::vec4 tint);
	};
}