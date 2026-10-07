#include "Precompiled.hh"

#include "Graphics/GL/GLRenderer.hh"
#include "Utils/Macros/GLMacros.hh"

namespace Rupture::Graphics
{
	GLRenderer::GLRenderer(glm::vec2 viewportSize)
		:m_FixedQuadBuffer(Graphics::GL::GL_ARRAY_BUFFER),
		m_InstancedQuadBuffer(Graphics::GL::GL_ARRAY_BUFFER),
		m_ElementBufferObject(Graphics::GL::GL_ELEMENT_ARRAY_BUFFER),
		m_ViewportSize(viewportSize),
		m_ViewMatrix(1.0f),
		m_ProjectionMatrix(glm::ortho(0.0f, m_ViewportSize.x, m_ViewportSize.y, 0.0f))
	{
		m_InstancesData.reserve(GLRenderer::MAX_QUADS);

		// Load shaders
		m_ShaderProgram.CompileShader(Graphics::GL::GL_VERTEX_SHADER, "assets/default_vert.glsl");
		m_ShaderProgram.CompileShader(Graphics::GL::GL_FRAGMENT_SHADER, "assets/default_frag.glsl");
		m_ShaderProgram.LinkProgram();
		m_ShaderProgram.UseProgram();

		m_ShaderProgram.SetUniformMatrix4("m_Projection", 1, Graphics::GL::GL_FALSE, glm::value_ptr(m_ProjectionMatrix));
		m_ShaderProgram.SetUniformMatrix4("m_View", 1, Graphics::GL::GL_FALSE, glm::value_ptr(m_ViewMatrix));

		GenericQuad quad[]
		{
			{ { 0.5f, 0.5f, 0.0f }, { 1.0f, 1.0f } },
			{ { -0.5f, 0.5f, 0.0f }, { 0.0f, 1.0f } },
			{ {-0.5f, -0.5f, 0.0f }, { 0.0f, 0.0f } },
			{ {0.5f, -0.5f, 0.0f }, { 1.0f, 0.0f } },
		};

		// Bind the buffers
		m_QuadVao.Bind();
		m_QuadVao.SetGenericVertexData<GenericQuad>("v_GenericQuad");
		m_QuadVao.SetInstancedVertexData<InstancedQuad>("v_InstancedQuad");

		m_ElementBufferObject.Bind();
		GenIndices();
		m_ElementBufferObject.AllocateData(GLRenderer::MAX_INDICES * sizeof(Graphics::GL::GLuint), m_Indices.data());

		// White texture will sit at index 0
		m_WhiteTexture.Bind(Graphics::GL::GL_TEXTURE0);
		const int avaliableTextureSlots = 0;
		m_ShaderProgram.SetUniform1iv("u_Textures", 1, &avaliableTextureSlots);

		// Enables the next 7 attributes
		m_QuadVao.EnableAtttributes(7);

		m_FixedQuadBuffer.Bind();
		m_FixedQuadBuffer.AllocateData(sizeof(quad), &quad);
		// Fixed data
		/// Position
		RP_GL(Graphics::GL::glVertexAttribPointer(
			0, 3, Graphics::GL::GL_FLOAT, Graphics::GL::GL_FALSE, 
			sizeof(GenericQuad), reinterpret_cast<const void*>(offsetof(GenericQuad, Position))));

		// UV Coordinates
		RP_GL(Graphics::GL::glVertexAttribPointer(
			1, 2, Graphics::GL::GL_FLOAT, Graphics::GL::GL_FALSE, 
			sizeof(Vertex), reinterpret_cast<const void*>(offsetof(Vertex, UV))));
		
		m_InstancedQuadBuffer.Bind();
		m_InstancedQuadBuffer.AllocateData(GLRenderer::MAX_QUADS * sizeof(InstancedQuad));
		// Per instance data
		// Color
		RP_GL(Graphics::GL::glVertexAttribPointer(
			2, 4, Graphics::GL::GL_FLOAT, Graphics::GL::GL_FALSE, 
			sizeof(InstanceData), reinterpret_cast<const void*>(offsetof(InstanceData, Color))));

		// Texture ID
		RP_GL(Graphics::GL::glVertexAttribIPointer(
			3, 1, Graphics::GL::GL_INT, 
			sizeof(InstanceData), reinterpret_cast<const void*>(offsetof(InstanceData, TextureId))));

		// Model Matrix
		RP_GL(Graphics::GL::glVertexAttribPointer(
			4, 4, Graphics::GL::GL_FLOAT, Graphics::GL::GL_FALSE,
			sizeof(InstanceData), reinterpret_cast<const void*>(offsetof(InstanceData, ModelMatrix))));

		RP_GL(Graphics::GL::glVertexAttribPointer(
			5, 4, Graphics::GL::GL_FLOAT, Graphics::GL::GL_FALSE,
			sizeof(InstanceData), reinterpret_cast<const void*>(offsetof(InstanceData, ModelMatrix) + sizeof(glm::vec4))));

		RP_GL(Graphics::GL::glVertexAttribPointer(
			6, 4, Graphics::GL::GL_FLOAT, Graphics::GL::GL_FALSE,
			sizeof(InstanceData), reinterpret_cast<const void*>(offsetof(InstanceData, ModelMatrix) + sizeof(glm::vec4) * 2)));

		RP_GL(Graphics::GL::glVertexAttribPointer(
			7, 4, Graphics::GL::GL_FLOAT, Graphics::GL::GL_FALSE,
			sizeof(InstanceData), reinterpret_cast<const void*>(offsetof(InstanceData, ModelMatrix) + sizeof(glm::vec4) * 3)));

		RP_GL(Graphics::GL::glVertexAttribDivisor(2, 1));
		RP_GL(Graphics::GL::glVertexAttribDivisor(3, 1));
		RP_GL(Graphics::GL::glVertexAttribDivisor(4, 1));
		RP_GL(Graphics::GL::glVertexAttribDivisor(5, 1));
		RP_GL(Graphics::GL::glVertexAttribDivisor(6, 1));
		RP_GL(Graphics::GL::glVertexAttribDivisor(7, 1));

		m_QuadVao.Unbind();
	}

	GLRenderer::~GLRenderer() {}

	void GLRenderer::GenIndices()
	{
		constexpr std::array<int, 6> vertices{ 0, 1, 2, 2, 3, 0 };

		// Generate enough indices for the entire capacity
		for (auto index = 0; index < GLRenderer::MAX_INDICES; index++)
		{ 
			int quad = index / 6;
			int vertex = index % 6;
			int offset = quad * 4;

			m_Indices.push_back(offset + vertices[vertex]);
		}
	}

	void GLRenderer::StartBatch()
	{
		m_InstancesData.clear();
	}

	void GLRenderer::EndBatch()
	{
		 m_QuadVao.Bind();

		RP_GL(Graphics::GL::glBufferSubData(
			Graphics::GL::GL_ARRAY_BUFFER, 0, 
			sizeof(InstanceData) * GLRenderer::MAX_QUADS, 
			InstancesData_.data()
		));

		RP_GL(Graphics::GL::glDrawElementsInstanced(
			Graphics::GL::GL_TRIANGLES, 
			QuadCount_ * INDICES_PER_QUAD, 
			Graphics::GL::GL_UNSIGNED_INT,
			nullptr,
			QuadCount_
		));

		QuadCount_ = 0;
	}

	void GLRenderer::BatchQuad(glm::vec2 position, glm::vec2 size, glm::vec4 color)
	{		
		if (QuadCount_ >= GLRenderer::MAX_QUADS)
		{
			EndBatch();
			StartBatch();
		}
		
		glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(position, 0.0f));
		model = glm::scale(model, glm::vec3(size, 1.0f));

		InstancesData_.emplace_back(color, 0, model);

		QuadCount_++;
	}

	void GLRenderer::BatchTexture(
		const Graphics::GL::Texture2D& texture, 
		glm::vec2 position, 
		glm::vec2 size, 
		glm::vec4 tint)
	{
		QuadCount_++;
	}
}