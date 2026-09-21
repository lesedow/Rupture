#include "Precompiled.hh"
#include "Platform/Window.hh"
#include "Graphics/GL/GLtypes.hh"
#include "Utils/Logging/Logger.hh"
#include "Utils/Macros/LoggerMacros.hh"
#include "Utils/Macros/WinAPIMacros.hh"
#include "Utils/Platform/WinAPI.hh"

namespace Rupture::Platform
{
	LRESULT Window::WinProc(HWND windowHandle, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		Window* self{ nullptr };

		if (uMsg == WM_NCCREATE)
		{
			CREATESTRUCT* pCreate = reinterpret_cast<CREATESTRUCT*>(lParam);
			self = reinterpret_cast<Window*>(pCreate->lpCreateParams);

			// Needed because SetWindowLongPtr can return 0 even if it succeeds
			SetLastError(ERROR_SUCCESS); 

			LONG_PTR lPtr = SetWindowLongPtr(windowHandle, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(self));
			RP_WIN64(!lPtr);

			self->window_ = windowHandle;
		}
		else {
			SetLastError(ERROR_SUCCESS);
			LONG_PTR lPtr = GetWindowLongPtr(windowHandle, GWLP_USERDATA);
			RP_WIN64(!lPtr);

			self = reinterpret_cast<Window*>(lPtr);
		}

		if (self)
		{
			return self->HandleMessages(uMsg, wParam, lParam);
		}

		return DefWindowProc(windowHandle, uMsg, wParam, lParam);
	}

	Window::Window(glm::ivec2 dimensions, std::wstring_view name)
		:dimensions_(dimensions), name_(name)
	{
		const std::wstring CLASS_NAME = L"Rupture";

		HINSTANCE instance{ GetModuleHandle(nullptr) };
		RP_WIN64(instance == nullptr);

		WNDCLASS windowClass{};
		windowClass.lpfnWndProc = Window::WinProc;
		windowClass.hInstance = instance;
		windowClass.lpszClassName = CLASS_NAME.c_str();
		windowClass.style = CS_VREDRAW | CS_HREDRAW | CS_OWNDC;

		ATOM registeredClass{ RegisterClass(&windowClass) };
		RP_WIN64(registeredClass == 0);

		window_ = CreateWindowEx(
			WS_EX_OVERLAPPEDWINDOW,
			CLASS_NAME.c_str(),
			name_.c_str(),
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT, dimensions_.x, dimensions_.y,
			nullptr, nullptr, instance, this
		);

		RP_WIN64(!window_);

		ShowWindow(window_, SW_SHOWDEFAULT);
	}

	void Window::CreateGLContext()
	{
		context_ = GetDC(window_);

		UINT numberOfFormats{};
		int pixelFormat{};

		// This is irrelevant
		PIXELFORMATDESCRIPTOR pixelFormatDescriptor{};

		BOOL pixelFormatChosen{ Rupture::Graphics::GL::wglChoosePixelFormatARB(
			context_, Rupture::Graphics::GL::RGBA_32_24_8,
			nullptr, 1, &pixelFormat,
			&numberOfFormats
			) };
		RP_WIN64(!pixelFormatChosen);
			
		BOOL pixelFormatSet{ SetPixelFormat(context_, pixelFormat, &pixelFormatDescriptor) };
		RP_WIN64(!pixelFormatSet);

		glContext_ = Rupture::Graphics::GL::wglCreateContextAttribsARB(
			context_,
			nullptr,
			Rupture::Graphics::GL::CORE_3_3
		);
		RP_WIN64(!glContext_);

		BOOL setContext = wglMakeCurrent(context_, glContext_);
		RP_WIN64(!setContext);
	}

	LRESULT Window::HandleMessages(UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		default:
			return DefWindowProc(window_, uMsg, wParam, lParam);
		}
	}

	HDC Window::GetDeviceContext() const
	{
		return context_;
	}

	HGLRC Window::GetGLContext() const
	{
		return glContext_;
	}
}