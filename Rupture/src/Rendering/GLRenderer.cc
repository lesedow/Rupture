#include "Rendering/GLRenderer.hh"
#include "Utils/Macros/GLMacros.hh"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Rupture::Rendering
{
	GLRenderer::GLRenderer()
		:Vertices_(),
		Indices_(),
		VertexArrayObject_(),
		VertexBufferObject_(Graphics::GL::GL_ARRAY_BUFFER),
		ElementBufferObject_(Graphics::GL::GL_ELEMENT_ARRAY_BUFFER),
		ShaderProgram_(),
		QuadCount_()
	{
		// Bind the buffers
		VertexArrayObject_.Bind();
		VertexBufferObject_.Bind();
		ElementBufferObject_.Bind();

		// Load shaders
		ShaderProgram_.CompileShader(Graphics::GL::GL_VERTEX_SHADER, "assets/default_vert.glsl");
		ShaderProgram_.CompileShader(Graphics::GL::GL_VERTEX_SHADER, "assets/default_frag.glsl");
		ShaderProgram_.LinkProgram();

		// Allocate enough memory for BATCH_CAPCITY
		VertexBufferObject_.AllocateData(GLRenderer::BATCH_CAPACITY * sizeof(Vertex));
		GenIndices();
		ElementBufferObject_.AllocateData(GLRenderer::MAX_INDICES * sizeof(std::uint32_t), Indices_.data());

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
		// Generate enough indices for the entire capacity
		for (auto index = 0; index < GLRenderer::MAX_INDICES; index++)
		{
			auto row = (index / 3) % 2;
			auto column = index % 3;

			if (row)
			{
				if (column < 2)
					Indices_.push_back(index - 1);
				else
					Indices_.push_back(index - 5);

				continue;
			}

			Indices_.push_back(index);
		}
	}

	void GLRenderer::StartBatch()
	{
	}

	void GLRenderer::EndBatch()
	{
		VertexArrayObject_.Bind();
		ShaderProgram_.UseProgram();

		Graphics::GL::glDrawElements(
			Graphics::GL::GL_TRIANGLES, 
			QuadCount_ * INDICES_PER_QUAD, 
			Graphics::GL::GL_UNSIGNED_INT, nullptr
		);
	}

	void GLRenderer::DrawQuad(glm::vec2 position, glm::vec2 size, glm::vec4 color)
	{
		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 model = glm::mat4(1.0f);

		glm::mat4 projection = glm::ortho(0.0f, 1280.0f, 0.0f, 720.0f, -1.0f, 1.0f);

		model = glm::translate(model, glm::vec3(position.x, position.y, 0.0f));
		model = glm::scale(model, glm::vec3(size.x, size.y, 1.0f));

		ShaderProgram_.SetUniformMatrix4("View", 1, Graphics::GL::GL_FALSE, glm::value_ptr(view));
		ShaderProgram_.SetUniformMatrix4("Projection", 1, Graphics::GL::GL_FALSE, glm::value_ptr(projection));
		ShaderProgram_.SetUniformMatrix4("Model", 1, Graphics::GL::GL_FALSE, glm::value_ptr(model));
		ShaderProgram_.SetUniform1i("OutTexture", 0);

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