#pragma once

#include "Precompiled.hh"

namespace Rupture::Platform
{
	class Window
	{
	protected:
		HWND window_;
	private:
		HDC context_;
		HGLRC glContext_;
		
		glm::ivec2 dimensions_;
		std::wstring name_;
	public:
		static LRESULT WinProc(HWND windowHandle, UINT uMsg, WPARAM wParam, LPARAM lParam);

		Window(glm::ivec2 dimensions, std::wstring_view name);
		
		void CreateGLContext();
		HDC GetDeviceContext() const;
		HGLRC GetGLContext() const;
	protected:
		LRESULT HandleMessages(UINT uMsg, WPARAM wParam, LPARAM lParam);
	};
}