#include "Precompiled.hh"
#include "Rendering/GLRenderer.hh"
#include "Utils/Macros/GLMacros.hh"

namespace Rupture::Rendering
{
	GLRenderer::GLRenderer(glm::vec2 viewportSize)
		:ModelMatrices_(),
		Indices_(),
		VertexArrayObject_(),
		VertexBufferObject_(Graphics::GL::GL_ARRAY_BUFFER),
		ElementBufferObject_(Graphics::GL::GL_ELEMENT_ARRAY_BUFFER),
		ShaderProgram_(),
		QuadCount_(),
		ViewportSize_(viewportSize),
		ViewMatrix_(1.0f),
		WhiteTexture_()
	{
		ProjectionMatrix_ = glm::ortho(0.0f, ViewportSize_.x, ViewportSize_.y, 0.0f);
		
		ModelMatrices_.reserve(GLRenderer::MAX_QUADS);
		
		// Bind the buffers
		VertexArrayObject_.Bind();
		VertexBufferObject_.Bind();
		ElementBufferObject_.Bind();

		WhiteTexture_.Bind(Graphics::GL::GL_TEXTURE0);

		// Load shaders
		ShaderProgram_.CompileShader(Graphics::GL::GL_VERTEX_SHADER, "assets/default_vert.glsl");
		ShaderProgram_.CompileShader(Graphics::GL::GL_FRAGMENT_SHADER, "assets/default_frag.glsl");
		ShaderProgram_.LinkProgram();
		ShaderProgram_.UseProgram();

		ShaderProgram_.SetUniformMatrix4("Projection", 1, Graphics::GL::GL_FALSE, glm::value_ptr(ProjectionMatrix_));
		ShaderProgram_.SetUniformMatrix4("View", 1, Graphics::GL::GL_FALSE, glm::value_ptr(ViewMatrix_));
		ShaderProgram_.SetUniform1i("OutTexture", 0);

		// Allocate enough memory for BATCH_CAPCITY
		VertexBufferObject_.AllocateData(GLRenderer::BATCH_CAPACITY * sizeof(Vertex));
		GenIndices();
		ElementBufferObject_.AllocateData(GLRenderer::MAX_INDICES * sizeof(Graphics::GL::GLuint), Indices_.data());

		// Enable attributes for the vertex
		RP_GL(Graphics::GL::glEnableVertexAttribArray(0));
		RP_GL(Graphics::GL::glEnableVertexAttribArray(1));
		RP_GL(Graphics::GL::glEnableVertexAttribArray(2));
		RP_GL(Graphics::GL::glEnableVertexAttribArray(3));

		/// Position
		RP_GL(Graphics::GL::glVertexAttribPointer(
			0, 3, Graphics::GL::GL_FLOAT, Graphics::GL::GL_FALSE, 
			sizeof(Vertex), reinterpret_cast<const void*>(offsetof(Vertex, Position))));

		// Color
		RP_GL(Graphics::GL::glVertexAttribPointer(
			1, 4, Graphics::GL::GL_FLOAT, Graphics::GL::GL_FALSE, 
			sizeof(Vertex), reinterpret_cast<const void*>(offsetof(Vertex, Color))));

		// UV Coordinates
		RP_GL(Graphics::GL::glVertexAttribPointer(
			2, 2, Graphics::GL::GL_FLOAT, Graphics::GL::GL_FALSE, 
			sizeof(Vertex), reinterpret_cast<const void*>(offsetof(Vertex, TextureCoords))));

		// Texture ID
		RP_GL(Graphics::GL::glVertexAttribIPointer(
			3, 1, Graphics::GL::GL_INT, 
			sizeof(Vertex), reinterpret_cast<const void*>(offsetof(Vertex, TextureId))));

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
		Vertices_.clear();
	}

	void GLRenderer::EndBatch()
	{
		 VertexArrayObject_.Bind();

		RP_GL(Graphics::GL::glBufferSubData(
			Graphics::GL::GL_ARRAY_BUFFER, 0, 
			GLRenderer::BATCH_CAPACITY, Vertices_.data()
		));

		RP_GL(Graphics::GL::glDrawElements(
			Graphics::GL::GL_TRIANGLES, 
			QuadCount_ * INDICES_PER_QUAD, 
			Graphics::GL::GL_UNSIGNED_INT, nullptr
		));

		QuadCount_ = 0;
	}

	glm::vec3 GetTransformedVector(glm::vec3 base, glm::vec2 size, glm::vec2 position)
	{
		return base * glm::vec3(size, 1.0f) + glm::vec3(position, 0.0f);
	}

	void GLRenderer::DrawQuad(glm::vec2 position, glm::vec2 size, glm::vec4 color)
	{		
		if (QuadCount_ >= GLRenderer::MAX_QUADS)
		{
			EndBatch();
			StartBatch();
		}
		
		Vertex v1 
		{
			.Position = GetTransformedVector(glm::vec3{ 0.5f, 0.5f, 0.0f }, size, position),
			.Color = color,
			.TextureCoords = glm::vec2{ 1.0f, 1.0f },
			.TextureId = 0
		};

		Vertex v2 
		{
			.Position = GetTransformedVector(glm::vec3{ -0.5f, 0.5f, 0.0f }, size, position),
			.Color = color,
			.TextureCoords = glm::vec2{ 0.0f, 1.0f },
			.TextureId = 0
		};

		Vertex v3 
		{
			.Position = GetTransformedVector(glm::vec3{ -0.5f, -0.5f, 0.0f }, size, position),
			.Color = color,
			.TextureCoords = glm::vec2{ 0.0f, 0.0f },
			.TextureId = 0
		};

		Vertex v4
		{
			.Position = GetTransformedVector(glm::vec3{ 0.5f, -0.5f, 0.0f }, size, position),
			.Color = color,
			.TextureCoords = glm::vec2{ 1.0f, 0.0f },
			.TextureId = 0
		};

		Vertices_.push_back(v1);
		Vertices_.push_back(v2);
		Vertices_.push_back(v3);
		Vertices_.push_back(v4);

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