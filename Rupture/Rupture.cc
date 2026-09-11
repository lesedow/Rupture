#ifndef UNICODE
#define UNICODE
#endif // !UNICODE

#include <windows.h>
#include <print>
#include <iostream>

#include "Graphics/GL/GLLoader.hh"
#include "Graphics/GL/Texture2D.hh"
#include "Utils/Logger.hh"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#pragma warning(push)
#pragma warning(disable: 28251)

namespace gl = Rupture::Graphics::GL;

constexpr int attribList[]{
	gl::WGL_DRAW_TO_WINDOW_ARB, gl::GL_TRUE,
	gl::WGL_SUPPORT_OPENGL_ARB, gl::GL_TRUE,
	gl::WGL_DOUBLE_BUFFER_ARB, gl::GL_TRUE,
	gl::WGL_PIXEL_TYPE_ARB,  gl::WGL_TYPE_RGBA_ARB,
	gl::WGL_COLOR_BITS_ARB, 32,
	gl::WGL_DEPTH_BITS_ARB, 24,
	gl::WGL_STENCIL_BITS_ARB, 8,
	0
};

constexpr int ctxAttribList[]
{
	gl::WGL_CONTEXT_MAJOR_VERSION_ARB, 3,
	gl::WGL_CONTEXT_MINOR_VERSION_ARB, 3,
	gl::WGL_CONTEXT_PROFILE_MASK_ARB,
	gl::WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
	0 
};

struct Vertex
{
	glm::vec3 position;
	glm::vec4 color;
	glm::vec2 texCoords;
	float texId;
};

constexpr int SCREEN_W = 1280;
constexpr int SCREEN_H = 720;

LRESULT CALLBACK WindowProc(HWND windowHandle, UINT message, WPARAM wParam, LPARAM lParam);
bool HandleWindowCreation(HWND windowHandle);
gl::GLint CreateShader(const std::string& fragment, const std::string& vertex);
gl::GLuint CompileShader(gl::GLenum type, const std::string& source);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE prevInstance, PWSTR lpCmdLine, int cmdShow)
{
	// So apparently windows only has support for legacy GL 
	// The first thing to do is pull the wglCreateContextARB method to create a MODERN GL context
	// I need to do that with a dummy window first and then recreate the window with the new stuff
#ifdef RUPTURE_DEBUG

	AllocConsole();

	FILE* file;

	freopen_s(&file, "CONOUT$", "w", stdout);
	freopen_s(&file, "CONOUT$", "w", stderr);
	freopen_s(&file, "CONIN$", "r", stdin);

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
#endif

	if (!gl::LoadGLMethods())
	{
		std::cout << "ERROR\n";
	}

	const std::wstring CLASS_NAME = L"OpenGLClass";

	WNDCLASS windowClass{};

	windowClass.lpfnWndProc = WindowProc;
	windowClass.hInstance = hInstance;
	windowClass.lpszClassName = CLASS_NAME.c_str();
	windowClass.style = CS_VREDRAW | CS_HREDRAW | CS_OWNDC;

	RegisterClass(&windowClass);

	HWND window = CreateWindowEx(
		0,
		CLASS_NAME.c_str(),
		L"OpenGL",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, SCREEN_W, SCREEN_H,
		nullptr, nullptr, hInstance, nullptr
	);

	if (!window) return 0;

	HDC deviceContext = GetDC(window);

	UINT numberOfFormats{};
	int pixelFormat{};

	// This is irrelevant
	PIXELFORMATDESCRIPTOR pixelFormatDescriptor{};

	BOOL pixelFormatChosen = gl::wglChoosePixelFormatARB(deviceContext, attribList, nullptr, 1, &pixelFormat, &numberOfFormats);
	if (!pixelFormatChosen)
	{
		std::cout << "Failed to choose pixel format ARB: " << GetLastError() << "\n";
		return 0;
	}

	BOOL pixelFormatSet = SetPixelFormat(deviceContext, pixelFormat, &pixelFormatDescriptor);
	if (!pixelFormatChosen)
	{
		std::cout << "Failed to set pixel format ARB: " << GetLastError() << "\n";
		return 0;
	}


	HGLRC glContext = gl::wglCreateContextAttribsARB(deviceContext, nullptr, ctxAttribList);
	if (!glContext)
	{
		std::cout << "Failed to create GL Context: " << GetLastError() << "\n";
		return 0;
	}

	wglMakeCurrent(deviceContext, glContext);

	ShowWindow(window, cmdShow);

	std::cout << "[Rupture][GL] Running GL VER " << gl::glGetString(gl::GL_VERSION) << "\n";
	std::cout << "[Rupture][GL] Vendor: " << gl::glGetString(gl::GL_VENDOR) << "\n";
	std::cout << "[Rupture][GL] Renderer: " << gl::glGetString(gl::GL_RENDERER) << "\n";
	std::cout << "[Rupture][GL] GLSL VER: " << gl::glGetString(gl::GL_SHADING_LANGUAGE_VERSION) << "\n";

	MSG message{};
	bool running = true;

	///////

	//stbi_set_flip_vertically_on_load(true);

	#pragma region TEXTURES
	
	gl::Texture2D redTexture{ "assets/red_normal.png" };
	redTexture.Bind(gl::GL_TEXTURE0);

	#pragma endregion TEXTURES

	float vertices[] = {
		0.5f, 0.5f, 0.0f, 0.25f, 1.0f,
		-0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, 0.0f, 0.0f, 0.75f,
		0.5f, -0.5f, 0.0f, 0.25f, 0.75f
	};

	uint32_t indices[]
	{
		0, 1, 2,
		2, 3, 0
	};

	GLuint vao{};
	RUPTURE_GL_CALL(gl::glGenVertexArrays(1, &vao));
	RUPTURE_GL_CALL(gl::glBindVertexArray(vao));

	GLuint vbo{};
	RUPTURE_GL_CALL(gl::glGenBuffers(1, &vbo));

	GLuint ebo{};
	RUPTURE_GL_CALL(gl::glGenBuffers(1, &ebo));
	RUPTURE_GL_CALL(gl::glBindBuffer(gl::GL_ELEMENT_ARRAY_BUFFER, ebo));
	RUPTURE_GL_CALL(gl::glBufferData(gl::GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, gl::GL_STATIC_DRAW));

	RUPTURE_GL_CALL(gl::glBindBuffer(gl::GL_ARRAY_BUFFER, vbo));
	RUPTURE_GL_CALL(gl::glBufferData(gl::GL_ARRAY_BUFFER, sizeof(vertices), vertices, gl::GL_STATIC_DRAW));

	RUPTURE_GL_CALL(gl::glEnableVertexAttribArray(0));
	RUPTURE_GL_CALL(gl::glEnableVertexAttribArray(1));

	RUPTURE_GL_CALL(gl::glVertexAttribPointer(0, 3, gl::GL_FLOAT, gl::GL_FALSE, sizeof(float) * 5, 0));
	RUPTURE_GL_CALL(gl::glVertexAttribPointer(1, 2, gl::GL_FLOAT, gl::GL_FALSE, sizeof(float) * 5, (void*)(sizeof(float)*3)));

	std::string vertexShader =
		"#version 330 core\n"
		"\n"
		"layout (location = 0) in vec3 aPos;\n"
		"layout (location = 1) in vec2 aTexCoord;\n"
		"uniform mat4 view;\n"
		"uniform mat4 projection;\n"
		"uniform mat4 model;\n"
		"out vec2 TexCoord;\n"
		"void main()\n"
		"{\n"
		"	gl_Position = projection * view * model * vec4(aPos, 1.0);\n"
		"	TexCoord = aTexCoord;\n"
		"}\n";

	std::string fragmentShader =
		"#version 330 core \n"
		"out vec4 FragColor;\n"
		"in vec2 TexCoord;\n"
		"uniform sampler2D oTex;\n"
		"void main()\n"
		"{\n"
		"	FragColor = texture(oTex, TexCoord);\n"
		"}\n";

	RUPTURE_GL_CALL(gl::glEnable(gl::GL_DEPTH_TEST));

	gl::GLint program = CreateShader(fragmentShader, vertexShader);
	RUPTURE_GL_CALL(gl::glUseProgram(program));

	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 model = glm::mat4(1.0f);
	
	model = glm::translate(model, glm::vec3(1280.0f/2, 720.0f/2, 0.0f));
	model = glm::scale(model, glm::vec3(64.0f, 128.0f, 1.0f));

	glm::mat4 projection = glm::ortho(0.0f, 1280.0f, 720.0f, 0.0f, -1.0f, 1.0f);

	RUPTURE_GL_CALL(gl::glUniformMatrix4fv(gl::glGetUniformLocation(program, "view"), 1, gl::GL_FALSE, glm::value_ptr(view)));
	RUPTURE_GL_CALL(gl::glUniformMatrix4fv(gl::glGetUniformLocation(program, "projection"), 1, gl::GL_FALSE, glm::value_ptr(projection)));
	RUPTURE_GL_CALL(gl::glUniformMatrix4fv(gl::glGetUniformLocation(program, "model"), 1, gl::GL_FALSE, glm::value_ptr(model)));

	RUPTURE_GL_CALL(gl::glUniform1i(gl::glGetUniformLocation(program, "oTex"), 0));

	while (running)
	{
		while (PeekMessage(&message, nullptr, 0, 0, PM_REMOVE))
		{
			if (message.message == WM_QUIT)
				running = false;

			TranslateMessage(&message);
			DispatchMessage(&message);
		}

		RUPTURE_GL_CALL(gl::glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
		RUPTURE_GL_CALL(gl::glClear(gl::GL_COLOR_BUFFER_BIT | gl::GL_DEPTH_BUFFER_BIT));

		RUPTURE_GL_CALL(gl::glDrawElements(gl::GL_TRIANGLES, 6, gl::GL_UNSIGNED_INT, nullptr));

		SwapBuffers(deviceContext);
	}

	return 0;
}

gl::GLuint CompileShader(GLenum type, const std::string& source)
{
	gl::GLuint id{};
	RUPTURE_GL_CALL(id = gl::glCreateShader(type));
	const char* src = source.c_str();

	RUPTURE_GL_CALL(gl::glShaderSource(id, 1, &src, nullptr));
	RUPTURE_GL_CALL(gl::glCompileShader(id));

	gl::GLint result{};
	RUPTURE_GL_CALL(gl::glGetShaderiv(id, gl::GL_COMPILE_STATUS, &result));

	if (result == gl::GL_FALSE) {
		gl::GLint length{};

		RUPTURE_GL_CALL(gl::glGetShaderiv(id, gl::GL_INFO_LOG_LENGTH, &length));

		std::string message{};
		message.resize(length);

		RUPTURE_GL_CALL(gl::glGetShaderInfoLog(id, length, nullptr, message.data()));

		std::cout << "Failed to compile shader: " << message << "\n";
	};

	return id;
}

gl::GLint CreateShader(const std::string& fragment, const std::string& vertex)
{
	gl::GLuint program{};
	RUPTURE_GL_CALL(program = gl::glCreateProgram());

	gl::GLuint vertexShader{ CompileShader(gl::GL_VERTEX_SHADER, vertex) };
	gl::GLuint fragmentShader{ CompileShader(gl::GL_FRAGMENT_SHADER, fragment)};

	RUPTURE_GL_CALL(gl::glAttachShader(program, vertexShader));
	RUPTURE_GL_CALL(gl::glAttachShader(program, fragmentShader));

	RUPTURE_GL_CALL(gl::glLinkProgram(program));

	gl::GLint status{};
	RUPTURE_GL_CALL(gl::glGetProgramiv(program, gl::GL_LINK_STATUS, &status));

	if (status == gl::GL_FALSE)
	{
		gl::GLint length{};

		RUPTURE_GL_CALL(gl::glGetProgramiv(program, gl::GL_INFO_LOG_LENGTH, &length));

		std::string message{};
		message.resize(length);
		
		RUPTURE_GL_CALL(gl::glGetShaderInfoLog(program, length, nullptr, message.data()));

		std::cout << "Failed to link program: " << message << "\n";
	}

	RUPTURE_GL_CALL(gl::glValidateProgram(program));
	RUPTURE_GL_CALL(gl::glDeleteShader(vertexShader));
	RUPTURE_GL_CALL(gl::glDeleteShader(fragmentShader));

	return program;
}


LRESULT CALLBACK WindowProc(HWND windowHandle, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CLOSE:
		DestroyWindow(windowHandle);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(windowHandle, message, wParam, lParam);
	}
}

#pragma warning(pop)
