#pragma once

#include "Precompiled.hh"

namespace Rupture::Logging
{
	inline constexpr uint32_t RP_TRACE	= (1u << 0);
	inline constexpr uint32_t RP_DEBUG	= (1u << 1);
	inline constexpr uint32_t RP_INFO	= (1u << 2);
	inline constexpr uint32_t RP_WARN	= (1u << 3);
	inline constexpr uint32_t RP_ERROR	= (1u << 4);
	inline constexpr uint32_t RP_ALL	= RP_TRACE | RP_DEBUG | RP_INFO | RP_WARN | RP_ERROR;
	inline constexpr uint32_t RP_LEVEL	= RP_ALL;

	inline constexpr std::wstring_view TRACE_COLOR	= L"\x1b[96m";
	inline constexpr std::wstring_view DEBUG_COLOR	= L"\x1b[32m";
	inline constexpr std::wstring_view WARN_COLOR	= L"\x1b[33m";
	inline constexpr std::wstring_view INFO_COLOR	= L"\x1b[37m";
	inline constexpr std::wstring_view ERROR_COLOR	= L"\x1b[31m";
	inline constexpr std::wstring_view ASSERT_COLOR = L"\x1b[35m";

	inline constexpr std::wstring_view CAT_GL		= L"[GL]";
	inline constexpr std::wstring_view CAT_VK		= L"[VK]";
	inline constexpr std::wstring_view CAT_DX		= L"[DX]";
	inline constexpr std::wstring_view CAT_METAL	= L"[METAL]";
	inline constexpr std::wstring_view CAT_WINAPI	= L"[WINAPI]";
	inline constexpr std::wstring_view CAT_X11		= L"[X11]";
	inline constexpr std::wstring_view CAT_WAYLAND	= L"[WAYLAND]";
	inline constexpr std::wstring_view CAT_COCOA	= L"[COCOA]";
	inline constexpr std::wstring_view TRACE_LVL	= L"[TRACE]";
	inline constexpr std::wstring_view DEBUG_LVL	= L"[DEBUG]";
	inline constexpr std::wstring_view INFO_LVL		= L"[INFO]";
	inline constexpr std::wstring_view WARN_LVL		= L"[WARN]";
	inline constexpr std::wstring_view ERROR_LVL	= L"[ERROR]";
	inline constexpr std::wstring_view ASSERTION	= L"[ASSERT]";
}