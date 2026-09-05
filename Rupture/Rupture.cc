#ifndef UNICODE
#define UNICODE
#endif // !UNICODE

#include <windows.h>
#include <GL/GL.h>
#include <print>
#include <iostream>

#include "Graphics/GL/GLLoader.hh"

#pragma comment(lib, "opengl32.lib")
#pragma warning(push)
#pragma warning(disable: 28251)

constexpr int attribList[]{
	RUPTUREGL WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
	RUPTUREGL WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
	RUPTUREGL WGL_DOUBLE_BUFFER_ARB, GL_TRUE,
	RUPTUREGL WGL_PIXEL_TYPE_ARB,  RUPTUREGL WGL_TYPE_RGBA_ARB,
	RUPTUREGL WGL_COLOR_BITS_ARB, 32,
	RUPTUREGL WGL_DEPTH_BITS_ARB, 24,
	RUPTUREGL WGL_STENCIL_BITS_ARB, 8,
	0
};

constexpr int ctxAttribList[]
{
	RUPTUREGL WGL_CONTEXT_MAJOR_VERSION_ARB, 3,
	RUPTUREGL WGL_CONTEXT_MINOR_VERSION_ARB, 3,
	RUPTUREGL WGL_CONTEXT_PROFILE_MASK_ARB,
	RUPTUREGL WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
	0 
};

LRESULT CALLBACK WindowProc(HWND windowHandle, UINT message, WPARAM wParam, LPARAM lParam);
bool HandleWindowCreation(HWND windowHandle);
GLint CreateShader(const std::string& fragment, const std::string& vertex);
GLuint CompileShader(GLenum type, const std::string& source);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE prevInstance, PWSTR lpCmdLine, int cmdShow)
{
	// So apparently windows only has support for legacy GL 
	// The first thing to do is pull the wglCreateContextARB method to create a MODERN GL context
	// I need to do that with a dummy window first and then recreate the window with the new stuff
#ifdef _DEBUG

	AllocConsole();

	FILE* file;

	freopen_s(&file, "CONOUT$", "w", stdout);
	freopen_s(&file, "CONOUT$", "w", stderr);
	freopen_s(&file, "CONIN$", "r", stdin);

#endif

	if (!RUPTUREGL LoadGLMethods())
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
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		nullptr, nullptr, hInstance, nullptr
	);

	if (!window) return 0;

	HDC deviceContext = GetDC(window);

	UINT numberOfFormats{};
	int pixelFormat{};

	// This is irrelevant
	PIXELFORMATDESCRIPTOR pixelFormatDescriptor{};

	BOOL pixelFormatChosen = RUPTUREGL wglChoosePixelFormatARB(deviceContext, attribList, nullptr, 1, &pixelFormat, &numberOfFormats);
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

	
	HGLRC glContext = RUPTUREGL wglCreateContextAttribsARB(deviceContext, nullptr, ctxAttribList);
	if (!glContext)
	{
		std::cout << "Failed to create GL Context: " << GetLastError() << "\n";
		return 0;
	}

	wglMakeCurrent(deviceContext, glContext);

	ShowWindow(window, cmdShow);

	std::cout << "[Rupture][GL] Running GL VER " << glGetString(GL_VERSION) << "\n";

	MSG message{};
	bool running = true;

	///////

	float vertices[]
	{
		-.5f, -.5f,
		.0f, .5f,
		.5f, -.5f
	};
	GLuint vao{};
	RUPTUREGL glGenVertexArrays(1, &vao);
	RUPTUREGL glBindVertexArray(vao);

	GLuint vbo{};
	RUPTUREGL glGenBuffers(1, &vbo);
	RUPTUREGL glBindBuffer(RUPTUREGL GL_ARRAY_BUFFER, vbo);
	RUPTUREGL glBufferData(RUPTUREGL GL_ARRAY_BUFFER, 6 * sizeof(float), vertices, RUPTUREGL GL_STATIC_DRAW);

	RUPTUREGL glEnableVertexAttribArray(0);
	RUPTUREGL glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	std::string vertexShader =
		"#version 330 core\n"
		"\n"
		"layout (location = 0) in vec2 aPos;\n"
		"out vec4 vColor;\n"
		"void main()\n"
		"{\n"
		"	gl_Position = vec4(aPos, 0.0, 1.0);\n"
		"	vColor = vec4(1.0);\n"
		"}\n";

	std::string fragmentShader =
		"#version 330 core \n"
		"out vec4 FragColor;\n"
		"in vec4 vColor;\n"
		"void main()\n"
		"{\n"
		"	FragColor = vColor;\n"
		"}\n";

	GLint program = CreateShader(fragmentShader, vertexShader);
	RUPTUREGL glUseProgram(program);

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

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glDrawArrays(GL_TRIANGLES, 0, 3);
		GLenum error = glGetError();
		if (error != GL_NO_ERROR)
		{
			std::cout << "GL ERROR: 0x" << std::hex << error << "\n";
		}

		SwapBuffers(deviceContext);
	}

	return 0;
}

GLuint CompileShader(GLenum type, const std::string& source)
{
	GLuint id = RUPTUREGL glCreateShader(type);
	const char* src = source.c_str();
	RUPTUREGL glShaderSource(id, 1, &src, nullptr);
	RUPTUREGL glCompileShader(id);

	// TODO: Error handling
	GLint result{};
	RUPTUREGL glGetShaderiv(id, RUPTUREGL GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE) {
		GLint length{};

		RUPTUREGL glGetShaderiv(id, RUPTUREGL GL_INFO_LOG_LENGTH, &length);

		std::string message{};
		message.resize(length);

		RUPTUREGL glGetShaderInfoLog(id, length, nullptr, message.data());

		std::cout << "Failed to compile shader: " << message << "\n";
	};

	return id;
}

GLint CreateShader(const std::string& fragment, const std::string& vertex)
{
	GLuint program = RUPTUREGL glCreateProgram();
	GLuint vertexShader{ CompileShader(RUPTUREGL GL_VERTEX_SHADER, vertex)};
	GLuint fragmentShader{ CompileShader(RUPTUREGL GL_FRAGMENT_SHADER, fragment)};

	RUPTUREGL glAttachShader(program, vertexShader);
	RUPTUREGL glAttachShader(program, fragmentShader);

	RUPTUREGL glLinkProgram(program);

	GLint status{};
	RUPTUREGL glGetProgramiv(program, RUPTUREGL GL_LINK_STATUS, &status);

	if (status == GL_FALSE)
	{
		GLint length{};

		RUPTUREGL glGetProgramiv(program, RUPTUREGL GL_INFO_LOG_LENGTH, &length);

		std::string message{};
		message.resize(length);

		RUPTUREGL glGetShaderInfoLog(program, length, nullptr, message.data());

		std::cout << "Failed to link program: " << message << "\n";
	}

	RUPTUREGL glValidateProgram(program);

	RUPTUREGL glDeleteShader(vertexShader);
	RUPTUREGL glDeleteShader(fragmentShader);

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
