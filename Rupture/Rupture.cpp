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

// GL PROFILE ATTRIBUTES
constexpr int WGL_CONTEXT_PROFILE_MASK_ARB					= 0x9126;
constexpr int WGL_CONTEXT_CORE_PROFILE_BIT_ARB				= 0x00000001;
constexpr int WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB		= 0x00000002;

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

// GL FUNCTIONS
using PFNGLGENBUFFERSPROC				= void (WINAPI*)(GLsizei n, GLuint* buffers);

// WGL EXTENSIONS
using PFNGLCHOOSEPIXELFORMATARBPROC		= BOOL (WINAPI*)(HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);
using PFNGLCREATECONTEXTATTRIBSARB		= HGLRC (WINAPI*)(HDC hdc, HGLRC hShareContext, const int* attribList);

// WGL EXTENSIONS
inline PFNGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB		= nullptr;
inline PFNGLCREATECONTEXTATTRIBSARB wglCreateContextAttribsARB		= nullptr;

// GL FUNCTIONS
inline PFNGLGENBUFFERSPROC glGenBuffers								= nullptr;

LRESULT CALLBACK WindowProc(HWND windowHandle, UINT message, WPARAM wParam, LPARAM lParam);
bool HandleWindowCreation(HWND windowHandle);

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
	wglCreateContextAttribsARB = reinterpret_cast<PFNGLCREATECONTEXTATTRIBSARB>(wglGetProcAddress("wglCreateContextAttribsARB"));

	glGenBuffers = reinterpret_cast<PFNGLGENBUFFERSPROC>(wglGetProcAddress("glGenBuffers"));
	
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
	AllocConsole();

	FILE* file;

	freopen_s(&file, "CONOUT$", "w", stdout);
	freopen_s(&file, "CONOUT$", "w", stderr);
	freopen_s(&file, "CONIN$", "r", stdin);

	std::cout << "Hello from the console!\n";

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

	std::cout << glGetString(GL_VERSION) << "\n";

	MSG message{};
	bool running = true;

	unsigned int vbo;
	glGenBuffers(1, &vbo);

	while (running)
	{
		while (PeekMessage(&message, window, 0, 0, PM_REMOVE))
		{
			if (message.message == WM_QUIT) running = false;

			TranslateMessage(&message);
			DispatchMessage(&message);
		}

		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);

		SwapBuffers(deviceContext);
	}
	return 0;
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
