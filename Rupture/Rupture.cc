#include "Precompiled.hh"

#include "Platform/Window.hh"
#include "Graphics/GL/GLLoader.hh"
#include "Rendering/GLRenderer.hh"

#include "Utils/Macros/LoggerMacros.hh"
#include "Utils/Logging/Logger.hh"
//#include "Utils/Macros/GLMacros.hh"
//#include "Utils/GL/GLError.hh"

#pragma warning(push)
#pragma warning(disable: 28251)

constexpr int SCREEN_W = 1280;
constexpr int SCREEN_H = 720;

namespace RGL = Rupture::Graphics::GL;

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

	if (!Rupture::Graphics::GL::LoadGLMethods())
	{
		RP_LOG_ERROR("Failed to load GL functions");
	}

	Rupture::Platform::Window ruptureWindow(glm::vec2(SCREEN_W, SCREEN_H), L"Rupture");
	ruptureWindow.CreateGLContext();

	Rupture::Rendering::GLRenderer Renderer_{};

	std::string glVersion(reinterpret_cast<const char*>(RGL::glGetString(RGL::GL_VERSION)));
	std::string glVendor(reinterpret_cast<const char*>(RGL::glGetString(RGL::GL_VENDOR)));
	std::string glRenderer(reinterpret_cast<const char*>(RGL::glGetString(RGL::GL_RENDERER)));
	std::string glGlsl(reinterpret_cast<const char*>(RGL::glGetString(RGL::GL_SHADING_LANGUAGE_VERSION)));

	RP_LOG_INFO(std::format("Running GL Version: {}", glVersion));
	RP_LOG_INFO(std::format("Vendor: {}", glVendor));
	RP_LOG_INFO(std::format("Renderer: {}", glRenderer));
	RP_LOG_INFO(std::format("GLSL Version: {}", glGlsl));

	MSG message{};
	bool running = true;

	stbi_set_flip_vertically_on_load(true);

	while (running)
	{
		while (PeekMessage(&message, nullptr, 0, 0, PM_REMOVE))
		{
			if (message.message == WM_QUIT)
				running = false;

			TranslateMessage(&message);
			DispatchMessage(&message);
		}

		RP_GL(RGL::glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
		RP_GL(RGL::glClear(RGL::GL_COLOR_BUFFER_BIT | RGL::GL_DEPTH_BUFFER_BIT));

		//RUPTURE_GL_CALL(gl::glDrawElements(gl::GL_TRIANGLES, 6, gl::GL_UNSIGNED_INT, nullptr));

		SwapBuffers(ruptureWindow.GetDeviceContext());
	}

	return 0;
}

#pragma warning(pop)
