#pragma once

#include "Precompiled.hh"

namespace Rupture::Platform
{
	class Window
	{
	protected:
		HWND Window_;
	private:
		HDC DeviceContext_;
		HGLRC GLContext_;
		
		glm::ivec2 Dimensions_;
		std::wstring Name_;
	public:
		static LRESULT WinProc(HWND windowHandle, UINT uMsg, WPARAM wParam, LPARAM lParam);

		Window(glm::ivec2 dimensions, std::wstring_view name);
		~Window();
		
		void CreateGLContext();
		glm::ivec2 GetDimensions() const;
		HDC GetDeviceContext() const;
		HGLRC GetGLContext() const;
		void SwapFramebuffers() const;
		void OnWindowResize(UINT width, UINT height);
	protected:
		LRESULT HandleMessages(UINT uMsg, WPARAM wParam, LPARAM lParam);
	};
}