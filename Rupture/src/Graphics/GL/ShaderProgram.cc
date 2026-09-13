#include "Graphics/GL/ShaderProgram.hh"

#include "Utils/Logging/Logger.hh"
#include "Utils/GL/GLError.hh"

#include "Utils/Macros/GLMacros.hh"
#include "Utils/Macros/LoggerMacros.hh"

#include <fstream>
#include <sstream>

namespace Rupture::Graphics::GL
{
	ShaderProgram::ShaderProgram()
		:shaderIds_{}, uniformsCache_{}
	{
		RUPTURE_GL_CALL(id_ = glCreateProgram());
	}

	std::string ShaderProgram::LoadShaderFromPath(const std::filesystem::path& path)
	{
		std::ifstream ifStream{};
		std::ostringstream shaderSrc{};
		ifStream.exceptions(std::ifstream::failbit | std::ifstream::badbit);

		try {
			ifStream.open(path);
			shaderSrc << ifStream.rdbuf();
		}
		catch (const std::ifstream::failure& err)
		{
			RUPTURE_LOG_FATAL(std::format("Failed to read file {}: {}", path.string(), err.what()));
		}
		
		return shaderSrc.str();
	}

	void ShaderProgram::CompileShader(GLenum type, const std::filesystem::path& path)
	{
		GLuint id{};
		RUPTURE_GL_CALL(id = glCreateShader(type));
		
		std::string src = LoadShaderFromPath(path);
		const char* shaderSrc = src.c_str();

		RUPTURE_GL_CALL(glShaderSource(id, 1, &shaderSrc, nullptr));
		RUPTURE_GL_CALL(glCompileShader(id));

		GLint result{};
		RUPTURE_GL_CALL(glGetShaderiv(id, GL_COMPILE_STATUS, &result));

		if (result == GL_FALSE) {
			GLint length{};

			RUPTURE_GL_CALL(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));

			std::string message{};
			message.resize(length);

			RUPTURE_GL_CALL(glGetShaderInfoLog(id, length, nullptr, message.data()));

			RUPTURE_LOG_FATAL(std::format("Failed to compile shader: {}", message));
		};

		shaderIds_.emplace_back(id);
	}

	void ShaderProgram::LinkProgram()
	{
		for (const auto& shaderId : shaderIds_)
		{
			RUPTURE_GL_CALL(glAttachShader(id_, shaderId));
		}

		glLinkProgram(id_);
		GLint result{};
		RUPTURE_GL_CALL(glGetProgramiv(id_, GL_LINK_STATUS, &result));

		if (result == GL_FALSE) {
			GLint length{};

			RUPTURE_GL_CALL(glGetProgramiv(id_, GL_INFO_LOG_LENGTH, &length));

			std::string message{};
			message.resize(length);

			RUPTURE_GL_CALL(glGetProgramInfoLog(id_, length, nullptr, message.data()));

			RUPTURE_LOG_FATAL(std::format("Failed to link shader program: {}", message));
		};

		for (const auto& shaderId : shaderIds_)
		{
			RUPTURE_GL_CALL(glDetachShader(id_, shaderId));
			RUPTURE_GL_CALL(glDeleteShader(shaderId));
		}

		shaderIds_.clear();
	}

	void ShaderProgram::UseProgram()
	{
		RUPTURE_GL_CALL(glUseProgram(id_));
	}

	void ShaderProgram::SetUniform1f(const char* name, GLfloat v0)
	{
		GLint location = GetCachedUniformLocation(name);
		RUPTURE_GL_CALL(glUniform1f(location, v0));
	}

	void ShaderProgram::SetUniform2f(const char* name, GLfloat v0, GLfloat v1)
	{
		GLint location = GetCachedUniformLocation(name);
		RUPTURE_GL_CALL(glUniform2f(location, v0, v0));
	}

	void ShaderProgram::SetUniform3f(const char* name, GLfloat v0, GLfloat v1, GLfloat v2)
	{
		GLint location = GetCachedUniformLocation(name);
		RUPTURE_GL_CALL(glUniform3f(location, v0, v1, v2));
	}

	void ShaderProgram::SetUniform4f(const char* name, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)
	{
		GLint location = GetCachedUniformLocation(name);
		RUPTURE_GL_CALL(glUniform4f(location, v0, v1, v2, v3));
	}

	void ShaderProgram::SetUniform1i(const char* name, GLint v0)
	{
		GLint location = GetCachedUniformLocation(name);
		RUPTURE_GL_CALL(glUniform1i(location, v0));
	}

	void ShaderProgram::SetUniform2i(const char* name, GLint v0, GLint v1)
	{
		GLint location = GetCachedUniformLocation(name);
		RUPTURE_GL_CALL(glUniform2i(location, v0, v1));
	}

	void ShaderProgram::SetUniform3i(const char* name, GLint v0, GLint v1, GLint v2)
	{
		GLint location = GetCachedUniformLocation(name);
		RUPTURE_GL_CALL(glUniform3i(location, v0, v1, v2));
	}

	void ShaderProgram::SetUniform4i(const char* name, GLint v0, GLint v1, GLint v2, GLint v3)
	{
		GLint location = GetCachedUniformLocation(name);
		RUPTURE_GL_CALL(glUniform4i(location, v0, v1, v2, v3));
	}

	void ShaderProgram::SetUniform1ui(const char* name, GLuint v0)
	{
		GLint location = GetCachedUniformLocation(name);
		RUPTURE_GL_CALL(glUniform1ui(location, v0));
	}

	void ShaderProgram::SetUniform2ui(const char* name, GLuint v0, GLuint v1)
	{
		GLint location = GetCachedUniformLocation(name);
		RUPTURE_GL_CALL(glUniform2ui(location, v0, v1));
	}

	void ShaderProgram::SetUniform3ui(const char* name, GLuint v0, GLuint v1, GLuint v2)
	{
		GLint location = GetCachedUniformLocation(name);
		RUPTURE_GL_CALL(glUniform3ui(location, v0, v1, v2) );
	}

	void ShaderProgram::SetUniform4ui(const char* name, GLuint v0, GLuint v1, GLuint v2, GLuint v3)
	{
		GLint location = GetCachedUniformLocation(name);
		RUPTURE_GL_CALL(glUniform4ui(location, v0, v1, v2, v3));
	}

	void ShaderProgram::SetUniform1fv(const char* name, GLsizei count, const GLfloat* value)
	{
		GLint location = GetCachedUniformLocation(name);
		RUPTURE_GL_CALL(glUniform1fv(location, count, value));
	}

	void ShaderProgram::SetUniform2fv(const char* name, GLsizei count, const GLfloat* value)
	{
		GLint location = GetCachedUniformLocation(name);
		RUPTURE_GL_CALL(glUniform2fv(location, count, value));
	}

	void ShaderProgram::SetUniform3fv(const char* name, GLsizei count, const GLfloat* value)
	{
		GLint location = GetCachedUniformLocation(name);
		RUPTURE_GL_CALL(glUniform3fv(location, count, value));
	}

	void ShaderProgram::SetUniform4fv(const char* name, GLsizei count, const GLfloat* value)
	{
		GLint location = GetCachedUniformLocation(name);
		RUPTURE_GL_CALL(glUniform4fv(location, count, value));
	}

	void ShaderProgram::SetUniform1iv(const char* name, GLsizei count, const GLint* value)
	{
		GLint location = GetCachedUniformLocation(name);
		RUPTURE_GL_CALL(glUniform1iv(location, count, value));
	}

	void ShaderProgram::SetUniform2iv(const char* name, GLsizei count, const GLint* value)
	{
		GLint location = GetCachedUniformLocation(name);
		RUPTURE_GL_CALL(glUniform2iv(location, count, value));
	}

	void ShaderProgram::SetUniform3iv(const char* name, GLsizei count, const GLint* value)
	{
		GLint location = GetCachedUniformLocation(name);
		RUPTURE_GL_CALL(glUniform3iv(location, count, value));
	}

	void ShaderProgram::SetUniform4iv(const char* name, GLsizei count, const GLint* value)
	{
		GLint location = GetCachedUniformLocation(name);
		RUPTURE_GL_CALL(glUniform4iv(location, count, value));
	}

	void ShaderProgram::SetUniform1uiv(const char* name, GLsizei count, const GLuint* value)
	{
		GLint location = GetCachedUniformLocation(name);
		RUPTURE_GL_CALL(glUniform1uiv(location, count, value));
	}

	void ShaderProgram::SetUniform2uiv(const char* name, GLsizei count, const GLuint* value)
	{
		GLint location = GetCachedUniformLocation(name);
		RUPTURE_GL_CALL(glUniform2uiv(location, count, value));

	}
	void ShaderProgram::SetUniform3uiv(const char* name, GLsizei count, const GLuint* value)
	{
		GLint location = GetCachedUniformLocation(name);
		RUPTURE_GL_CALL(glUniform3uiv(location, count, value));
	}

	void ShaderProgram::SetUniform4uiv(const char* name, GLsizei count, const GLuint* value)
	{
		GLint location = GetCachedUniformLocation(name);
		RUPTURE_GL_CALL(glUniform4uiv(location, count, value));
	}

	void ShaderProgram::SetUniformMatrix2(const char* name, GLsizei count, GLboolean transpose, const GLfloat* value)
	{
		GLint location = GetCachedUniformLocation(name);
		RUPTURE_GL_CALL(glUniformMatrix2fv(location, count, transpose, value));
	}

	void ShaderProgram::SetUniformMatrix3(const char* name, GLsizei count, GLboolean transpose, const GLfloat* value)
	{
		GLint location = GetCachedUniformLocation(name);
		RUPTURE_GL_CALL(glUniformMatrix3fv(location, count, transpose, value));
	}

	void ShaderProgram::SetUniformMatrix4(const char* name, GLsizei count, GLboolean transpose, const GLfloat* value)
	{
		GLint location = GetCachedUniformLocation(name);
		RUPTURE_GL_CALL(glUniformMatrix4fv(location, count, transpose, value));
	}

	GLint ShaderProgram::GetCachedUniformLocation(const char* name)
	{
		auto iterator = uniformsCache_.find(name);
		if (iterator != uniformsCache_.end()) {
			return iterator->second;
		}

		GLint location;
		RUPTURE_GL_CALL(location = glGetUniformLocation(id_, name));

		if (location == -1)
			RUPTURE_LOG_FATAL(std::format("Uniform {} is not avaliable in shader program {}!\n", name, id_));
		
		uniformsCache_.emplace(name, location);

		return location;
	}

}