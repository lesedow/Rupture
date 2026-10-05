#pragma once

#include "Precompiled.hh"

#include "GLTypes.hh"
#include "Texture2D.hh"
#include "GLBuffer.hh"
#include "VertexArrayObject.hh"
#include "ShaderProgram.hh"
#include "RenderData.hh"

namespace Rupture::Graphics
{
	class GLRenderer
	{
	private:
		static constexpr GL::GLint MAX_QUADS			= 2500;
		static constexpr GL::GLint INDICES_PER_QUAD		= 6;
		static constexpr GL::GLint MAX_INDICES			= MAX_QUADS * INDICES_PER_QUAD;
		static constexpr GL::GLint MAX_ACTIVE_TEXTURES	= 32;
	private:
		std::vector<InstancedQuad> m_InstancesData;
		std::vector<GL::GLuint> m_Indices;
		GL::VertexArrayObject m_QuadVao;
		GL::GLBuffer m_FixedQuadBuffer;
		GL::GLBuffer m_InstancedQuadBuffer;
		GL::GLBuffer m_ElementBufferObject;
		GL::ShaderProgram m_ShaderProgram;
		
		glm::vec2 m_ViewportSize;
		glm::mat4 m_ProjectionMatrix;
		glm::mat4 m_ViewMatrix;

		GL::Texture2D m_WhiteTexture;
	private:
		void GenIndices();
	public:
		explicit GLRenderer(glm::vec2 viewportSize);
		~GLRenderer();
	public:
		void StartBatch();
		void EndBatch();
		void BatchQuad(glm::vec2 position, glm::vec2 size, glm::vec4 color);
		void BatchTexture(const GL::Texture2D& texture, glm::vec2 position, glm::vec2 size, glm::vec4 tint);
	};
}