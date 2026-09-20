#pragma once

#include "GLTypes.hh"

#include <vector>
#include <unordered_map>
#include <string>
#include <filesystem>
#include <concepts>

namespace Rupture::Graphics::GL
{
	template<typename _GT>
	concept GLtype = (
		std::same_as<_GT, GLuint> ||
		std::same_as<_GT, GLint> ||
		std::same_as<_GT, GLfloat>
		);

	class ShaderProgram
	{
	private:
		GLuint id_;
		std::vector<GLuint> shaderIds_;
		std::unordered_map<std::string, GLuint> uniformsCache_;
	private:
		std::string LoadShaderFromPath(const std::filesystem::path& path);
	public:
		ShaderProgram();
		~ShaderProgram();

		void CompileShader(GLenum type, const std::filesystem::path& path);
		void LinkProgram();
		void UseProgram();

		void SetUniformMatrix2(const char* name, GLsizei count, GLboolean transpose, const GLfloat* value);
		void SetUniformMatrix3(const char* name, GLsizei count, GLboolean transpose, const GLfloat* value);
		void SetUniformMatrix4(const char* name, GLsizei count, GLboolean transpose, const GLfloat* value);

		void SetUniform1f(const char* name, GLfloat v0);
		void SetUniform2f(const char* name, GLfloat v0, GLfloat v1);
		void SetUniform3f(const char* name, GLfloat v0, GLfloat v1, GLfloat v2);
		void SetUniform4f(const char* name, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);

		void SetUniform1i(const char* name, GLint v0);
		void SetUniform2i(const char* name, GLint v0, GLint v1);
		void SetUniform3i(const char* name, GLint v0, GLint v1, GLint v2);
		void SetUniform4i(const char* name, GLint v0, GLint v1, GLint v2, GLint v3);

		void SetUniform1ui(const char* name, GLuint v0);
		void SetUniform2ui(const char* name, GLuint v0, GLuint v1);
		void SetUniform3ui(const char* name, GLuint v0, GLuint v1, GLuint v2);
		void SetUniform4ui(const char* name, GLuint v0, GLuint v1, GLuint v2, GLuint v3);

		void SetUniform1fv(const char* name, GLsizei count, const GLfloat* value);
		void SetUniform2fv(const char* name, GLsizei count, const GLfloat* value);
		void SetUniform3fv(const char* name, GLsizei count, const GLfloat* value);
		void SetUniform4fv(const char* name, GLsizei count, const GLfloat* value);

		void SetUniform1iv(const char* name, GLsizei count, const GLint* value);
		void SetUniform2iv(const char* name, GLsizei count, const GLint* value);
		void SetUniform3iv(const char* name, GLsizei count, const GLint* value);
		void SetUniform4iv(const char* name, GLsizei count, const GLint* value);

		void SetUniform1uiv(const char* name, GLsizei count, const GLuint* value);
		void SetUniform2uiv(const char* name, GLsizei count, const GLuint* value);
		void SetUniform3uiv(const char* name, GLsizei count, const GLuint* value);
		void SetUniform4uiv(const char* name, GLsizei count, const GLuint* value);

	private:
		GLint GetCachedUniformLocation(const char* name);
	};
}	