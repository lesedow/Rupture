#ifndef UNICODE
#define UNICODE
#endif // !UNICODE

#include <windows.h>
#include <print>
#include <iostream>

#include "Graphics/GL/GLLoader.hh"
#include "Logger.hh"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

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

LRESULT CALLBACK WindowProc(HWND windowHandle, UINT message, WPARAM wParam, LPARAM lParam);
bool HandleWindowCreation(HWND windowHandle);
gl::GLint CreateShader(const std::string& fragment, const std::string& vertex);
gl::GLuint CompileShader(gl::GLenum type, const std::string& source);

gl::GLuint CreateTexture(const char* path, gl::GLenum pixelFormat)
{
	int width, height, channels;
	unsigned char* imageData = stbi_load(path, &width, &height, &channels, 0);

	gl::GLuint texture{};
	gl::glGenTextures(1, &texture);
	gl::glBindTexture(gl::GL_TEXTURE_2D, texture);

	gl::glTexParameteri(gl::GL_TEXTURE_2D, gl::GL_TEXTURE_WRAP_S, gl::GL_REPEAT);
	gl::glTexParameteri(gl::GL_TEXTURE_2D, gl::GL_TEXTURE_WRAP_T, gl::GL_REPEAT);
	gl::glTexParameteri(gl::GL_TEXTURE_2D, gl::GL_TEXTURE_MIN_FILTER, gl::GL_LINEAR_MIPMAP_LINEAR);
	gl::glTexParameteri(gl::GL_TEXTURE_2D, gl::GL_TEXTURE_MAG_FILTER, gl::GL_LINEAR);

	RUPTUREASSERT(imageData != nullptr, "Failed to load image!");

	gl::glTexImage2D(gl::GL_TEXTURE_2D, 0, gl::GL_RGB, width, height, 0, pixelFormat, gl::GL_UNSIGNED_BYTE, imageData);
	gl::glGenerateMipmap(gl::GL_TEXTURE_2D);

	stbi_image_free(imageData);
	
	return texture;
}

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
		CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
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

	MSG message{};
	bool running = true;

	///////

	stbi_set_flip_vertically_on_load(true);

	#pragma region TEXTURES
	
	gl::GLuint boxTexture{ CreateTexture("assets/container.jpg", gl::GL_RGB) };
	gl::GLuint faceTexture{ CreateTexture("assets/awesomeface.png", gl::GL_RGBA) };

	gl::glActiveTexture(gl::GL_TEXTURE0);
	gl::glBindTexture(gl::GL_TEXTURE_2D, boxTexture);

	gl::glActiveTexture(gl::GL_TEXTURE1);
	gl::glBindTexture(gl::GL_TEXTURE_2D, faceTexture);

	#pragma endregion TEXTURES

	float vertices[]
	{
		0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
		-0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f
	};

	uint32_t indices[]
	{
		0, 1, 2,
		2, 3, 0
	};

	GLuint vao{};
	gl::glGenVertexArrays(1, &vao);
	gl::glBindVertexArray(vao);

	GLuint vbo{};
	gl::glGenBuffers(1, &vbo);

	GLuint ebo{};
	gl::glGenBuffers(1, &ebo);
	gl::glBindBuffer(gl::GL_ELEMENT_ARRAY_BUFFER, ebo);
	gl::glBufferData(gl::GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, gl::GL_STATIC_DRAW);

	gl::glBindBuffer(gl::GL_ARRAY_BUFFER, vbo);
	gl::glBufferData(gl::GL_ARRAY_BUFFER, sizeof(vertices), vertices, gl::GL_STATIC_DRAW);

	gl::glEnableVertexAttribArray(0);
	gl::glEnableVertexAttribArray(1);
	gl::glEnableVertexAttribArray(2);

	gl::glVertexAttribPointer(0, 3, gl::GL_FLOAT, gl::GL_FALSE, sizeof(float) * 8, 0);
	gl::glVertexAttribPointer(1, 3, gl::GL_FLOAT, gl::GL_FALSE, sizeof(float) * 8, (void*)(sizeof(float)*3));
	gl::glVertexAttribPointer(2, 2, gl::GL_FLOAT, gl::GL_FALSE, sizeof(float) * 8, (void*)(sizeof(float)*6));

	std::string vertexShader =
		"#version 330 core\n"
		"\n"
		"layout (location = 0) in vec3 aPos;\n"
		"layout (location = 1) in vec3 aColor;\n"
		"layout (location = 2) in vec2 aTexCoord;\n"
		"out vec4 vColor;\n"
		"out vec2 TexCoord;\n"
		"void main()\n"
		"{\n"
		"	gl_Position = vec4(aPos, 1.0);\n"
		"	vColor = vec4(aColor, 1.0);\n"
		"	TexCoord = aTexCoord;\n"
		"}\n";

	std::string fragmentShader =
		"#version 330 core \n"
		"out vec4 FragColor;\n"
		"in vec4 vColor;\n"
		"in vec2 TexCoord;\n"
		"uniform sampler2D boxTexture;\n"
		"uniform sampler2D faceTexture;\n"
		"void main()\n"
		"{\n"
		"	FragColor = mix(texture(boxTexture, TexCoord), texture(faceTexture, TexCoord), 0.5);\n"
		"}\n";

	gl::GLint program = CreateShader(fragmentShader, vertexShader);
	gl::glUseProgram(program);

	gl::glUniform1i(gl::glGetUniformLocation(program, "boxTexture"), 0);
	gl::glUniform1i(gl::glGetUniformLocation(program, "faceTexture"), 1);

	//////
	
	while (running)
	{
		while (PeekMessage(&message, nullptr, 0, 0, PM_REMOVE))
		{
			if (message.message == WM_QUIT)
				running = false;

			TranslateMessage(&message);
			DispatchMessage(&message);
		}

		gl::glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		gl::glClear(gl::GL_COLOR_BUFFER_BIT);

		gl::glDrawElements(gl::GL_TRIANGLES, 6, gl::GL_UNSIGNED_INT, nullptr);

		gl::GLenum error = gl::glGetError();
		if (error != gl::GL_NO_ERROR)
		{
			std::cout << "GL ERROR: 0x" << std::hex << error << "\n";
		}

		SwapBuffers(deviceContext);
	}

	return 0;
}

gl::GLuint CompileShader(GLenum type, const std::string& source)
{
	gl::GLuint id = gl::glCreateShader(type);
	const char* src = source.c_str();
	gl::glShaderSource(id, 1, &src, nullptr);
	gl::glCompileShader(id);

	// TODO: Error handling
	gl::GLint result{};
	gl::glGetShaderiv(id, gl::GL_COMPILE_STATUS, &result);
	if (result == gl::GL_FALSE) {
		gl::GLint length{};

		gl::glGetShaderiv(id, gl::GL_INFO_LOG_LENGTH, &length);

		std::string message{};
		message.resize(length);

		gl::glGetShaderInfoLog(id, length, nullptr, message.data());

		std::cout << "Failed to compile shader: " << message << "\n";
	};

	return id;
}

gl::GLint CreateShader(const std::string& fragment, const std::string& vertex)
{
	gl::GLuint program = gl::glCreateProgram();
	gl::GLuint vertexShader{ CompileShader(gl::GL_VERTEX_SHADER, vertex) };
	gl::GLuint fragmentShader{ CompileShader(gl::GL_FRAGMENT_SHADER, fragment)};

	gl::glAttachShader(program, vertexShader);
	gl::glAttachShader(program, fragmentShader);
	gl::glGetError();

	gl::glLinkProgram(program);

	gl::GLint status{};
	gl::glGetProgramiv(program, gl::GL_LINK_STATUS, &status);

	if (status == gl::GL_FALSE)
	{
		gl::GLint length{};

		gl::glGetProgramiv(program, gl::GL_INFO_LOG_LENGTH, &length);

		std::string message{};
		message.resize(length);

		gl::glGetShaderInfoLog(program, length, nullptr, message.data());

		std::cout << "Failed to link program: " << message << "\n";
	}

	gl::glValidateProgram(program);

	gl::glDeleteShader(vertexShader);
	gl::glDeleteShader(fragmentShader);

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
