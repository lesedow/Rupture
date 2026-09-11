#include "Graphics/GL/ShaderProgram.hh"
#include "Utils/Logger.hh"

namespace Rupture::Graphics::GL
{
	ShaderProgram::ShaderProgram()
		:shaderIds_{}, uniformsCache_{}
	{
		RUPTURE_GL_CALL(id_ = glCreateProgram());
	}

	void ShaderProgram::CompileShader(GLenum type, std::string_view source)
	{
		GLuint id{};
		RUPTURE_GL_CALL(id = glCreateShader(type));
		shaderIds_.emplace_back(id);
	
		const GLchar* src = source.data();
		const GLint length = source.size();

		RUPTURE_GL_CALL(glShaderSource(id, 1, &src, &length));
		RUPTURE_GL_CALL(glCompileShader(id));

		GLint result{};
		RUPTURE_GL_CALL(glGetShaderiv(id, GL_COMPILE_STATUS, &result));

		if (result == GL_FALSE) {
			GLint length{};

			RUPTURE_GL_CALL(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));

			std::string message{};
			message.resize(length);

			RUPTURE_GL_CALL(glGetShaderInfoLog(id, length, nullptr, message.data()));

			RUPTURE_LOG_ERROR(message);
		};
	}

	void ShaderProgram::LinkProgram()
	{
	}
	void ShaderProgram::UseProgram()
	{

	}
}