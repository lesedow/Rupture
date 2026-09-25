#include "Precompiled.hh"
#include "Rendering/GLRenderer.hh"
#include "Utils/Macros/GLMacros.hh"

namespace Rupture::Rendering
{
	GLRenderer::GLRenderer(glm::vec2 viewportSize)
		:FixedVertexData_(Graphics::GL::GL_ARRAY_BUFFER),
		PerInstanceData_(Graphics::GL::GL_ARRAY_BUFFER),
		ElementBufferObject_(Graphics::GL::GL_ELEMENT_ARRAY_BUFFER),
		ViewportSize_(viewportSize),
		ViewMatrix_(1.0f),
		ProjectionMatrix_(glm::ortho(0.0f, ViewportSize_.x, ViewportSize_.y, 0.0f))
	{
		InstancesData_.reserve(GLRenderer::MAX_QUADS);

		// Load shaders
		ShaderProgram_.CompileShader(Graphics::GL::GL_VERTEX_SHADER, "assets/default_vert.glsl");
		ShaderProgram_.CompileShader(Graphics::GL::GL_FRAGMENT_SHADER, "assets/default_frag.glsl");
		ShaderProgram_.LinkProgram();
		ShaderProgram_.UseProgram();

		ShaderProgram_.SetUniformMatrix4("m_Projection", 1, Graphics::GL::GL_FALSE, glm::value_ptr(ProjectionMatrix_));
		ShaderProgram_.SetUniformMatrix4("m_View", 1, Graphics::GL::GL_FALSE, glm::value_ptr(ViewMatrix_));
	
		//ShaderProgram_.SetUniform("OutTexture", 0);
		
		Vertex quad[]
		{
			{ { 0.5f, 0.5f, 0.0f }, { 1.0f, 1.0f } },
			{ { -0.5f, 0.5f, 0.0f }, { 0.0f, 1.0f } },
			{ {-0.5f, -0.5f, 0.0f }, { 0.0f, 0.0f } },
			{ {0.5f, -0.5f, 0.0f }, { 1.0f, 0.0f } },
		};


		// Bind the buffers
		VertexArrayObject_.Bind();

		ElementBufferObject_.Bind();
		ElementBufferObject_.AllocateData(GLRenderer::MAX_INDICES * sizeof(Graphics::GL::GLuint), Indices_.data());
		GenIndices();

		// White texture will sit at index 0
		WhiteTexture_.Bind(Graphics::GL::GL_TEXTURE0);
		const int avaliableTextureSlots = 0;
		ShaderProgram_.SetUniform1iv("u_Textures", 1, &avaliableTextureSlots);

		// Enable attributes for the vertex
		RP_GL(Graphics::GL::glEnableVertexAttribArray(0));
		RP_GL(Graphics::GL::glEnableVertexAttribArray(1));

		// Enable attributes for the instance
		RP_GL(Graphics::GL::glEnableVertexAttribArray(2));
		RP_GL(Graphics::GL::glEnableVertexAttribArray(3));
		RP_GL(Graphics::GL::glEnableVertexAttribArray(4));
		RP_GL(Graphics::GL::glEnableVertexAttribArray(5));
		RP_GL(Graphics::GL::glEnableVertexAttribArray(6));
		RP_GL(Graphics::GL::glEnableVertexAttribArray(7));

		FixedVertexData_.Bind();
		FixedVertexData_.AllocateData(sizeof(Vertex), &quad);
		// Fixed data
		/// Position
		RP_GL(Graphics::GL::glVertexAttribPointer(
			0, 3, Graphics::GL::GL_FLOAT, Graphics::GL::GL_FALSE, 
			sizeof(Vertex), reinterpret_cast<const void*>(offsetof(Vertex, Position))));

		// UV Coordinates
		RP_GL(Graphics::GL::glVertexAttribPointer(
			1, 2, Graphics::GL::GL_FLOAT, Graphics::GL::GL_FALSE, 
			sizeof(Vertex), reinterpret_cast<const void*>(offsetof(Vertex, UV))));
		
		PerInstanceData_.Bind();
		PerInstanceData_.AllocateData(GLRenderer::BATCH_CAPACITY * sizeof(InstanceData));
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
			4, 1, Graphics::GL::GL_FLOAT_MAT4, Graphics::GL::GL_FALSE,
			sizeof(InstanceData), reinterpret_cast<const void*>(offsetof(InstanceData, ModelMatrix))));

		VertexArrayObject_.Unbind();
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

			Indices_.push_back(offset + vertices[vertex]);
		}
	}

	void GLRenderer::StartBatch()
	{
		InstancesData_.clear();
	}

	void GLRenderer::EndBatch()
	{
		 VertexArrayObject_.Bind();

		RP_GL(Graphics::GL::glBufferSubData(
			Graphics::GL::GL_ARRAY_BUFFER, 0, 
			GLRenderer::BATCH_CAPACITY, InstancesData_.data()
		));

		RP_GL(Graphics::GL::glDrawElements(
			Graphics::GL::GL_TRIANGLES, 
			QuadCount_ * INDICES_PER_QUAD, 
			Graphics::GL::GL_UNSIGNED_INT, nullptr
		));

		QuadCount_ = 0;
	}

	void GLRenderer::DrawQuad(glm::vec2 position, glm::vec2 size, glm::vec4 color)
	{		
		if (QuadCount_ >= GLRenderer::MAX_QUADS)
		{
			EndBatch();
			StartBatch();
		}
		
		glm::mat4 model = glm::scale(glm::mat4(1.0f), glm::vec3(position, 1.0f));
		model = glm::translate(model, glm::vec3(size, 0.0f));

		InstancesData_.emplace_back(color, 0, model);

		QuadCount_++;
	}

	void GLRenderer::DrawCircle(glm::vec2 position, Graphics::GL::GLfloat radius, glm::vec4 color)
	{

	}

	void GLRenderer::DrawTexture(
		const Graphics::GL::Texture2D& texture, 
		glm::vec2 position, 
		glm::vec2 size, 
		glm::vec4 tint)
	{
		QuadCount_++;
	}
}