#include "Precompiled.hh"

#include "Graphics/GL/ShaderProgram.hh"
#include "Utils/GL/GLError.hh"
#include "Utils/Macros/GLMacros.hh"

#include "Utils/Logging/Logging.hh"

namespace Rupture::Graphics::GL
{
	ShaderProgram::ShaderProgram()
		:m_ShaderIDs{}, m_UniformsCache{}
	{
		RP_GL(m_ID = glCreateProgram());
	}

	ShaderProgram::~ShaderProgram()
	{
		RP_GL(glDeleteProgram(m_ID));
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
			Logging::LogError(std::format("Failed to read file {}: {}", path.string(), err.what()), Logging::CAT_GL);
		}
		
		return shaderSrc.str();
	}

	void ShaderProgram::CompileShader(GLenum type, const std::filesystem::path& path)
	{
		GLuint id{};
		RP_GL(id = glCreateShader(type));
		
		std::string src = LoadShaderFromPath(path);
		const char* shaderSrc = src.c_str();

		RP_GL(glShaderSource(id, 1, &shaderSrc, nullptr));
		RP_GL(glCompileShader(id));

		GLint result{};
		RP_GL(glGetShaderiv(id, GL_COMPILE_STATUS, &result));

		if (result == GL_FALSE) {
			GLint length{};

			RP_GL(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));

			std::string message{};
			message.resize(length);

			RP_GL(glGetShaderInfoLog(id, length, nullptr, message.data()));

			Logging::LogError(std::format("Failed to compile shader: {}", message), Logging::CAT_GL);
		};

		m_ShaderIDs.emplace_back(id);
	}

	void ShaderProgram::LinkProgram()
	{
		for (const auto& shaderId : m_ShaderIDs)
		{
			RP_GL(glAttachShader(m_ID, shaderId));
		}

		glLinkProgram(m_ID);
		GLint result{};
		RP_GL(glGetProgramiv(m_ID, GL_LINK_STATUS, &result));

		if (result == GL_FALSE) {
			GLint length{};

			RP_GL(glGetProgramiv(m_ID, GL_INFO_LOG_LENGTH, &length));

			std::string message{};
			message.resize(length);

			RP_GL(glGetProgramInfoLog(m_ID, length, nullptr, message.data()));

			Logging::LogError(std::format("Failed to link shader program: {}", message), Logging::CAT_GL);
		};

		for (const auto& shaderId : m_ShaderIDs)
		{
			RP_GL(glDetachShader(m_ID, shaderId));
			RP_GL(glDeleteShader(shaderId));
		}

		m_ShaderIDs.clear();
	}

	void ShaderProgram::UseProgram() const
	{
		RP_GL(glUseProgram(m_ID));
	}

	void ShaderProgram::SetUniform1f(const char* name, GLfloat v0)
	{
		GLint location = GetCachedUniformLocation(name);
		RP_GL(glUniform1f(location, v0));
	}

	void ShaderProgram::SetUniform2f(const char* name, GLfloat v0, GLfloat v1)
	{
		GLint location = GetCachedUniformLocation(name);
		RP_GL(glUniform2f(location, v0, v0));
	}

	void ShaderProgram::SetUniform3f(const char* name, GLfloat v0, GLfloat v1, GLfloat v2)
	{
		GLint location = GetCachedUniformLocation(name);
		RP_GL(glUniform3f(location, v0, v1, v2));
	}

	void ShaderProgram::SetUniform4f(const char* name, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)
	{
		GLint location = GetCachedUniformLocation(name);
		RP_GL(glUniform4f(location, v0, v1, v2, v3));
	}

	void ShaderProgram::SetUniform1i(const char* name, GLint v0)
	{
		GLint location = GetCachedUniformLocation(name);
		RP_GL(glUniform1i(location, v0));
	}

	void ShaderProgram::SetUniform2i(const char* name, GLint v0, GLint v1)
	{
		GLint location = GetCachedUniformLocation(name);
		RP_GL(glUniform2i(location, v0, v1));
	}

	void ShaderProgram::SetUniform3i(const char* name, GLint v0, GLint v1, GLint v2)
	{
		GLint location = GetCachedUniformLocation(name);
		RP_GL(glUniform3i(location, v0, v1, v2));
	}

	void ShaderProgram::SetUniform4i(const char* name, GLint v0, GLint v1, GLint v2, GLint v3)
	{
		GLint location = GetCachedUniformLocation(name);
		RP_GL(glUniform4i(location, v0, v1, v2, v3));
	}

	void ShaderProgram::SetUniform1ui(const char* name, GLuint v0)
	{
		GLint location = GetCachedUniformLocation(name);
		RP_GL(glUniform1ui(location, v0));
	}

	void ShaderProgram::SetUniform2ui(const char* name, GLuint v0, GLuint v1)
	{
		GLint location = GetCachedUniformLocation(name);
		RP_GL(glUniform2ui(location, v0, v1));
	}

	void ShaderProgram::SetUniform3ui(const char* name, GLuint v0, GLuint v1, GLuint v2)
	{
		GLint location = GetCachedUniformLocation(name);
		RP_GL(glUniform3ui(location, v0, v1, v2) );
	}

	void ShaderProgram::SetUniform4ui(const char* name, GLuint v0, GLuint v1, GLuint v2, GLuint v3)
	{
		GLint location = GetCachedUniformLocation(name);
		RP_GL(glUniform4ui(location, v0, v1, v2, v3));
	}

	void ShaderProgram::SetUniform1fv(const char* name, GLsizei count, const GLfloat* value)
	{
		GLint location = GetCachedUniformLocation(name);
		RP_GL(glUniform1fv(location, count, value));
	}

	void ShaderProgram::SetUniform2fv(const char* name, GLsizei count, const GLfloat* value)
	{
		GLint location = GetCachedUniformLocation(name);
		RP_GL(glUniform2fv(location, count, value));
	}

	void ShaderProgram::SetUniform3fv(const char* name, GLsizei count, const GLfloat* value)
	{
		GLint location = GetCachedUniformLocation(name);
		RP_GL(glUniform3fv(location, count, value));
	}

	void ShaderProgram::SetUniform4fv(const char* name, GLsizei count, const GLfloat* value)
	{
		GLint location = GetCachedUniformLocation(name);
		RP_GL(glUniform4fv(location, count, value));
	}

	void ShaderProgram::SetUniform1iv(const char* name, GLsizei count, const GLint* value)
	{
		GLint location = GetCachedUniformLocation(name);
		RP_GL(glUniform1iv(location, count, value));
	}

	void ShaderProgram::SetUniform2iv(const char* name, GLsizei count, const GLint* value)
	{
		GLint location = GetCachedUniformLocation(name);
		RP_GL(glUniform2iv(location, count, value));
	}

	void ShaderProgram::SetUniform3iv(const char* name, GLsizei count, const GLint* value)
	{
		GLint location = GetCachedUniformLocation(name);
		RP_GL(glUniform3iv(location, count, value));
	}

	void ShaderProgram::SetUniform4iv(const char* name, GLsizei count, const GLint* value)
	{
		GLint location = GetCachedUniformLocation(name);
		RP_GL(glUniform4iv(location, count, value));
	}

	void ShaderProgram::SetUniform1uiv(const char* name, GLsizei count, const GLuint* value)
	{
		GLint location = GetCachedUniformLocation(name);
		RP_GL(glUniform1uiv(location, count, value));
	}

	void ShaderProgram::SetUniform2uiv(const char* name, GLsizei count, const GLuint* value)
	{
		GLint location = GetCachedUniformLocation(name);
		RP_GL(glUniform2uiv(location, count, value));

	}
	void ShaderProgram::SetUniform3uiv(const char* name, GLsizei count, const GLuint* value)
	{
		GLint location = GetCachedUniformLocation(name);
		RP_GL(glUniform3uiv(location, count, value));
	}

	void ShaderProgram::SetUniform4uiv(const char* name, GLsizei count, const GLuint* value)
	{
		GLint location = GetCachedUniformLocation(name);
		RP_GL(glUniform4uiv(location, count, value));
	}

	void ShaderProgram::SetUniformMatrix2(const char* name, GLsizei count, GLboolean transpose, const GLfloat* value)
	{
		GLint location = GetCachedUniformLocation(name);
		RP_GL(glUniformMatrix2fv(location, count, transpose, value));
	}

	void ShaderProgram::SetUniformMatrix3(const char* name, GLsizei count, GLboolean transpose, const GLfloat* value)
	{
		GLint location = GetCachedUniformLocation(name);
		RP_GL(glUniformMatrix3fv(location, count, transpose, value));
	}

	void ShaderProgram::SetUniformMatrix4(const char* name, GLsizei count, GLboolean transpose, const GLfloat* value)
	{
		GLint location = GetCachedUniformLocation(name);
		RP_GL(glUniformMatrix4fv(location, count, transpose, value));
	}

	GLint ShaderProgram::GetCachedUniformLocation(const char* name)
	{
		auto iterator = m_UniformsCache.find(name);
		if (iterator != m_UniformsCache.end()) {
			return iterator->second;
		}

		GLint location;
		RP_GL(location = glGetUniformLocation(m_ID, name));

		if (location == -1)
			Logging::LogError(std::format(
				"Uniform {} is not avaliable in shader program {}!\n", name, m_ID), 
					Logging::CAT_GL
				);
		
		m_UniformsCache.emplace(name, location);

		return location;
	}

}