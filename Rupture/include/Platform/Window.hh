#pragma once

#if defined(_WIN32)

#ifndef UNICODE
#define UNICODE
#endif

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#ifndef NOMINMAX
#define NOMINMAX
#endif

#include <windows.h>

#endif

#include <glm/glm.hpp>
#include <string_view>
#include <string>

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