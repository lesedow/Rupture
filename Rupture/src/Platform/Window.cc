#include "Precompiled.hh"

#include "Platform/Window.hh"
#include "Graphics/GL/GLtypes.hh"
#include "Utils/Logging/Logging.hh"
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
			RP_WINAPI(!lPtr);

			self->Window_ = windowHandle;
		}
		else {
			SetLastError(ERROR_SUCCESS);
			LONG_PTR lPtr = GetWindowLongPtr(windowHandle, GWLP_USERDATA);
			RP_WINAPI(!lPtr);

			self = reinterpret_cast<Window*>(lPtr);
		}

		if (self)
		{
			return self->HandleMessages(uMsg, wParam, lParam);
		}

		return DefWindowProc(windowHandle, uMsg, wParam, lParam);
	}

	Window::~Window() {}

	Window::Window(glm::ivec2 dimensions, std::wstring_view name)
		:Dimensions_(dimensions), Name_(name)
	{
		const std::wstring CLASS_NAME = L"Rupture";

		HINSTANCE instance{ GetModuleHandle(nullptr) };
		RP_WINAPI(instance == nullptr);

		WNDCLASS windowClass{};
		windowClass.lpfnWndProc = Window::WinProc;
		windowClass.hInstance = instance;
		windowClass.lpszClassName = CLASS_NAME.c_str();
		windowClass.style = CS_VREDRAW | CS_HREDRAW | CS_OWNDC;

		ATOM registeredClass{ RegisterClass(&windowClass) };
		RP_WINAPI(registeredClass == 0);

		Window_ = CreateWindowEx(
			WS_EX_OVERLAPPEDWINDOW,
			CLASS_NAME.c_str(),
			Name_.c_str(),
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT, Dimensions_.x, Dimensions_.y,
			nullptr, nullptr, instance, this
		);

		RP_WINAPI(!Window_);

		ShowWindow(Window_, SW_SHOWDEFAULT);
	}
	
	glm::ivec2 Window::GetDimensions() const
	{
		return Dimensions_;
	}
	
	void Window::SwapFramebuffers() const
	{
		BOOL swapped = SwapBuffers(DeviceContext_);
		RP_WINAPI(!swapped);
	}

	void Window::OnWindowResize(UINT width, UINT height)
	{
		Dimensions_.x = width;
		Dimensions_.y = height;
	}

	void Window::CreateGLContext()
	{
		DeviceContext_ = GetDC(Window_);
		
		UINT numberOfFormats{};
		int pixelFormat{};

		// This is irrelevant
		PIXELFORMATDESCRIPTOR pixelFormatDescriptor{};

		BOOL pixelFormatChosen{ Rupture::Graphics::GL::wglChoosePixelFormatARB(
			DeviceContext_, Rupture::Graphics::GL::RGBA_32_24_8,
			nullptr, 1, &pixelFormat,
			&numberOfFormats
			) };
		RP_WINAPI(!pixelFormatChosen);
			
		BOOL pixelFormatSet{ SetPixelFormat(DeviceContext_, pixelFormat, &pixelFormatDescriptor) };
		RP_WINAPI(!pixelFormatSet);

		GLContext_ = Rupture::Graphics::GL::wglCreateContextAttribsARB(
			DeviceContext_,
			nullptr,
			Rupture::Graphics::GL::CORE_3_3
		);
		RP_WINAPI(!GLContext_);

		BOOL setContext = wglMakeCurrent(DeviceContext_, GLContext_);
		RP_WINAPI(!setContext);
	}

	LRESULT Window::HandleMessages(UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{ 
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		case WM_SIZE:
			{
				UINT width = LOWORD(lParam);
				UINT height = HIWORD(lParam);
				OnWindowResize(width, height);
			}
			return 0;
		default:
			return DefWindowProc(Window_, uMsg, wParam, lParam);
		}
	}

	HDC Window::GetDeviceContext() const
	{
		return DeviceContext_;
	}

	HGLRC Window::GetGLContext() const
	{
		return GLContext_;
	}
}