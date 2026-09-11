#pragma once

#include "GLTypes.hh"

#include <vector>
#include <unordered_map>
#include <type_traits>
#include <string>
#include <string_view>

namespace Rupture::Graphics::GL
{
	class ShaderProgram
	{
	private:
		GLuint id_;
		std::vector<GLuint> shaderIds_;
		std::unordered_map<std::string, GLuint> uniformsCache_;
	public:
		ShaderProgram();
		void CompileShader(GLenum type, std::string_view source);
		void LinkProgram();
		void UseProgram();
		
		void SetUniform(std::string_view name, GLfloat v0);
		void SetUniform(std::string_view name, GLfloat v0, GLfloat v1);
		void SetUniform(std::string_view name, GLfloat v0, GLfloat v1, GLfloat v2);
		void SetUniform(std::string_view name, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);

		void SetUniform(std::string_view name, GLint v0);
		void SetUniform(std::string_view name, GLint v0, GLint v1);
		void SetUniform(std::string_view name, GLint v0, GLint v1, GLint v2);
		void SetUniform(std::string_view name, GLint v0, GLint v1, GLint v2, GLint v3);

		void SetUniform(std::string_view name, GLuint v0);
		void SetUniform(std::string_view name, GLuint v0, GLuint v1);
		void SetUniform(std::string_view name, GLuint v0, GLuint v1, GLuint v2);
		void SetUniform(std::string_view name, GLuint v0, GLuint v1, GLuint v2, GLuint v3);

		void SetUniformv(std::string_view name, GLsizei count, const GLfloat* value);
		void SetUniformv(std::string_view name, GLsizei count, const GLint* value);
		void SetUniformv(std::string_view name, GLsizei count, const GLuint* value);

		void SetUniformMatrix2(std::string_view name, GLsizei count, GLboolean transpose, const GLfloat* value);
		void SetUniformMatrix3(std::string_view name, GLsizei count, GLboolean transpose, const GLfloat* value);
		void SetUniformMatrix4(std::string_view name, GLsizei count, GLboolean transpose, const GLfloat* value);

	private:
		GLint GetCachedUniformLocation(std::string_view key);
	};
}	