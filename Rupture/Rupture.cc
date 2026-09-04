#ifndef UNICODE
#define UNICODE
#endif // !UNICODE

#include <windows.h>
#include <GL/GL.h>
#include <print>
#include <iostream>

#pragma comment(lib, "opengl32.lib")
#pragma warning(push)
#pragma warning(disable: 28251)

constexpr int WGL_DRAW_TO_WINDOW_ARB						= 0x2001;
constexpr int WGL_SUPPORT_OPENGL_ARB						= 0x2010;
constexpr int WGL_DOUBLE_BUFFER_ARB							= 0x2011;
constexpr int WGL_PIXEL_TYPE_ARB							= 0x2013;
constexpr int WGL_TYPE_RGBA_ARB								= 0x202B;
constexpr int WGL_COLOR_BITS_ARB							= 0x2014;
constexpr int WGL_DEPTH_BITS_ARB							= 0x2022;
constexpr int WGL_STENCIL_BITS_ARB							= 0x2023;

constexpr int WGL_CONTEXT_MAJOR_VERSION_ARB					= 0x2091;
constexpr int WGL_CONTEXT_MINOR_VERSION_ARB					= 0x2092;
constexpr int WGL_CONTEXT_LAYER_PLANE_ARB					= 0x2093;
constexpr int WGL_CONTEXT_FLAGS_ARB							= 0x2094;

constexpr int WGL_CONTEXT_PROFILE_MASK_ARB					= 0x9126;
constexpr int WGL_CONTEXT_CORE_PROFILE_BIT_ARB				= 0x00000001;
constexpr int WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB		= 0x00000002;

// GL DEFINES
constexpr GLenum GL_ARRAY_BUFFER							= 0x8892;
constexpr GLenum GL_STATIC_DRAW								= 0x88E4;
constexpr GLenum GL_FRAGMENT_SHADER							= 0x8B30;
constexpr GLenum GL_VERTEX_SHADER							= 0x8B31;
constexpr GLenum GL_COMPILE_STATUS							= 0x8B81;
constexpr GLenum GL_INFO_LOG_LENGTH							= 0x8B84;
constexpr GLenum GL_LINK_STATUS								= 0x8B82;

constexpr int attribList[]{
	WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
	WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
	WGL_DOUBLE_BUFFER_ARB, GL_TRUE,
	WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB,
	WGL_COLOR_BITS_ARB, 32,
	WGL_DEPTH_BITS_ARB, 24,
	WGL_STENCIL_BITS_ARB, 8,
	0
};

constexpr int ctxAttribList[]
{
	WGL_CONTEXT_MAJOR_VERSION_ARB, 3,
	WGL_CONTEXT_MINOR_VERSION_ARB, 3,
	WGL_CONTEXT_PROFILE_MASK_ARB,
	WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
	0
};


// WGL EXTENSIONS
inline PFNGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB = nullptr;
inline PFNGLCREATECONTEXTATTRIBSARB wglCreateContextAttribsARB = nullptr;

// GL FUNCTIONS
inline PFNGLGENBUFFERSPROC glGenBuffers = nullptr;
inline PFNGLBINDBUFFERPROC glBindBuffer = nullptr;		
inline PFNGLBUFFERDATAPROC glBufferData = nullptr;
inline PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer = nullptr;
inline PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray = nullptr;
inline PFNGLCREATEPROGRAMPROC glCreateProgram = nullptr;
inline PFNGLSHADERSOURCEPROC glShaderSource = nullptr;
inline PFNGLCREATESHADERPROC glCreateShader = nullptr;
inline PFNGLCOMPILESHADERPROC glCompileShader = nullptr;
inline PFNGLDELETESHADERPROC glDeleteShader = nullptr;
inline PFNGLLINKPROGRAMPROC glLinkProgram = nullptr;
inline PFNGLATTACHSHADERPROC glAttachShader = nullptr;
inline PFNGLVALIDATEPROGRAMPROC glValidateProgram = nullptr;
inline PFNGLGETSHADERIVPROC glGetShaderiv = nullptr;
inline PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog = nullptr;
inline PFNGLUSEPROGRAMPROC glUseProgram = nullptr;
inline PFNGLGETPROGRAMIVPROC glGetProgramiv = nullptr;
inline PFNGLGENVERTEXARRAYSPROC glGenVertexArrays = nullptr;
inline PFNGLBINDVERTEXARRAYPROC glBindVertexArray = nullptr;

LRESULT CALLBACK WindowProc(HWND windowHandle, UINT message, WPARAM wParam, LPARAM lParam);
bool HandleWindowCreation(HWND windowHandle);
GLint CreateShader(const std::string& fragment, const std::string& vertex);
GLuint CompileShader(GLenum type, const std::string& source);

bool InitWGLExtensions()
{

	// Create a window as usual
	
	const std::wstring DUMMY_CLASS = L"DummyCls";

	WNDCLASS dummy{};
	dummy.lpfnWndProc = DefWindowProc;
	dummy.lpszClassName = DUMMY_CLASS.c_str();
	dummy.hInstance = GetModuleHandle(nullptr);
	dummy.style = CS_OWNDC;

	if (!RegisterClass(&dummy))
	{
		std::cout << "Failed to register class dummy: " << GetLastError() << "\n";
		return false;
	};

	HWND window = CreateWindowEx(
		0,
		DUMMY_CLASS.c_str(),
		L"Dummy",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		nullptr, nullptr, GetModuleHandle(nullptr), nullptr
	);

	if (!window)
	{
		std::cout << "Failed to create dummy window!: " << GetLastError() << "\n";
		return false;
	}

	// Define a temp pixelformat for this gl context
	PIXELFORMATDESCRIPTOR pixelFormatDescriptor
	{
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
		PFD_TYPE_RGBA,
		32,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		24, 8, 0,
		PFD_MAIN_PLANE,
		0, 0, 0, 0
	};

	// Let windows choose a pixel format
	HDC deviceContext = GetDC(window);
	int pixelFormat = ChoosePixelFormat(deviceContext, &pixelFormatDescriptor);

	if (!pixelFormat)
	{
		std::cout << "Failed to find a pixel format for this descriptor: " << GetLastError() << "\n";
		return false;
	}

	// Set the pixel format
	BOOL pixelFormatChosen = SetPixelFormat(deviceContext, pixelFormat, &pixelFormatDescriptor);
	if (!pixelFormatChosen)
	{
		std::cout << "Failed to set the specified pixel format!: " << GetLastError() << "\n";
		return false;
	}

	// Create the GL context
	HGLRC glContext = wglCreateContext(deviceContext);
	wglMakeCurrent(deviceContext, glContext);
	
	// And finally load the gl methods

	wglChoosePixelFormatARB = reinterpret_cast<PFNGLCHOOSEPIXELFORMATARBPROC>(wglGetProcAddress("wglChoosePixelFormatARB"));
	if (wglChoosePixelFormatARB)
		std::cout << "[Rupture][GL] Loaded wglChoosePixelFormatARB\n";

	wglCreateContextAttribsARB = reinterpret_cast<PFNGLCREATECONTEXTATTRIBSARB>(wglGetProcAddress("wglCreateContextAttribsARB"));
	if (wglCreateContextAttribsARB)
		std::cout << "[Rupture][GL] Loaded wglCreateContextAttribsARB\n";
	
	glGenBuffers = reinterpret_cast<PFNGLGENBUFFERSPROC>(wglGetProcAddress("glGenBuffers"));
	if (glGenBuffers)
		std::cout << "[Rupture][GL] Loaded glGenBuffers\n";

	glBindBuffer = reinterpret_cast<PFNGLBINDBUFFERPROC>(wglGetProcAddress("glBindBuffer"));
	if (glBindBuffer)
		std::cout << "[Rupture][GL] Loaded glBindBuffer\n";

	glBufferData = reinterpret_cast<PFNGLBUFFERDATAPROC>(wglGetProcAddress("glBufferData"));
	if (glBufferData)
		std::cout << "[Rupture][GL] Loaded glBufferData\n";

	glVertexAttribPointer = reinterpret_cast<PFNGLVERTEXATTRIBPOINTERPROC>(wglGetProcAddress("glVertexAttribPointer"));
	if (glVertexAttribPointer)
		std::cout << "[Rupture][GL] Loaded glVertexAttribPointer\n";

	glEnableVertexAttribArray = reinterpret_cast<PFNGLENABLEVERTEXATTRIBARRAYPROC>(wglGetProcAddress("glEnableVertexAttribArray"));
	if (glEnableVertexAttribArray)
		std::cout << "[Rupture][GL] Loaded glEnableVertexAttribArray\n";

	glCreateProgram = reinterpret_cast<PFNGLCREATEPROGRAMPROC>(wglGetProcAddress("glCreateProgram"));
	if (glCreateProgram)
		std::cout << "[Rupture][GL] Loaded glCreateProgram\n";

	glCompileShader = reinterpret_cast<PFNGLCOMPILESHADERPROC>(wglGetProcAddress("glCompileShader"));
	if (glCompileShader)
		std::cout << "[Rupture][GL] Loaded glCompileShader\n";

	glCreateShader = reinterpret_cast<PFNGLCREATESHADERPROC>(wglGetProcAddress("glCreateShader"));
	if (glCreateShader)
		std::cout << "[Rupture][GL] Loaded glCreateShader\n";

	glShaderSource = reinterpret_cast<PFNGLSHADERSOURCEPROC>(wglGetProcAddress("glShaderSource"));
	if (glShaderSource)
		std::cout << "[Rupture][GL] Loaded glShaderSource\n";

	glDeleteShader = reinterpret_cast<PFNGLDELETESHADERPROC>(wglGetProcAddress("glDeleteShader"));
	if (glDeleteShader)
		std::cout << "[Rupture][GL] Loaded glDeleteShader\n";

	glLinkProgram = reinterpret_cast<PFNGLLINKPROGRAMPROC>(wglGetProcAddress("glLinkProgram"));
	if (glLinkProgram)
		std::cout << "[Rupture][GL] Loaded glLinkProgram\n";

	glAttachShader = reinterpret_cast<PFNGLATTACHSHADERPROC>(wglGetProcAddress("glAttachShader"));
	if (glAttachShader)
		std::cout << "[Rupture][GL] Loaded glAttachShader\n";

	glValidateProgram = reinterpret_cast<PFNGLVALIDATEPROGRAMPROC>(wglGetProcAddress("glValidateProgram"));
	if (glValidateProgram)
		std::cout << "[Rupture][GL] Loaded glValidateProgram\n";

	glGetShaderiv = reinterpret_cast<PFNGLGETSHADERIVPROC>(wglGetProcAddress("glGetShaderiv"));
	if (glGetShaderiv)
		std::cout << "[Rupture][GL] Loaded glGetShaderiv\n";

	glGetShaderInfoLog = reinterpret_cast<PFNGLGETSHADERINFOLOGPROC>(wglGetProcAddress("glGetShaderInfoLog"));
	if (glGetShaderiv)
		std::cout << "[Rupture][GL] Loaded glGetShaderInfoLog\n";

	glUseProgram = reinterpret_cast<PFNGLUSEPROGRAMPROC>(wglGetProcAddress("glUseProgram"));
	if (glGetShaderiv)
		std::cout << "[Rupture][GL] Loaded glUseProgram\n";

	glGetProgramiv = reinterpret_cast<PFNGLGETPROGRAMIVPROC>(wglGetProcAddress("glGetProgramiv"));
	if (glGetProgramiv)
		std::cout << "[Rupture][GL] Loaded glGetProgramiv\n";
	
	glGenVertexArrays = reinterpret_cast<PFNGLGENVERTEXARRAYSPROC>(wglGetProcAddress("glGenVertexArrays"));
	if (glGenVertexArrays)
		std::cout << "[Rupture][GL] Loaded glGenVertexArrays\n";

	glBindVertexArray = reinterpret_cast<PFNGLBINDVERTEXARRAYPROC>(wglGetProcAddress("glBindVertexArray"));
	if (glBindVertexArray)
		std::cout << "[Rupture][GL] Loaded glBindVertexArray\n";
	
	wglMakeCurrent(deviceContext, NULL);
	wglDeleteContext(glContext);
	DestroyWindow(window);

	return true;
}

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

	if (!InitWGLExtensions())
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

	BOOL pixelFormatChosen = wglChoosePixelFormatARB(deviceContext, attribList, nullptr, 1, &pixelFormat, &numberOfFormats);
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

	
	HGLRC glContext = wglCreateContextAttribsARB(deviceContext, nullptr, ctxAttribList);
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
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	GLuint vbo{};
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);	
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

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
	glUseProgram(program);

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
	GLuint id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	// TODO: Error handling
	GLint result{};
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE) {
		GLint length{};

		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);

		std::string message{};
		message.resize(length);

		glGetShaderInfoLog(id, length, nullptr, message.data());

		std::cout << "Failed to compile shader: " << message << "\n";
	};

	return id;
}

GLint CreateShader(const std::string& fragment, const std::string& vertex)
{
	GLuint program = glCreateProgram();
	GLuint vertexShader{ CompileShader(GL_VERTEX_SHADER, vertex)};
	GLuint fragmentShader{ CompileShader(GL_FRAGMENT_SHADER, fragment)};

	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);

	glLinkProgram(program);

	GLint status{};
	glGetProgramiv(program, GL_LINK_STATUS, &status);

	if (status == GL_FALSE)
	{
		GLint length{};

		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);

		std::string message{};
		message.resize(length);

		glGetShaderInfoLog(program, length, nullptr, message.data());

		std::cout << "Failed to link program: " << message << "\n";
	}

	glValidateProgram(program);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

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
