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

	inline constexpr std::string_view TRACE_COLOR	= "\x1b[96m";
	inline constexpr std::string_view DEBUG_COLOR	= "\x1b[32m";
	inline constexpr std::string_view WARN_COLOR	= "\x1b[33m";
	inline constexpr std::string_view INFO_COLOR	= "\x1b[37m";
	inline constexpr std::string_view ERROR_COLOR	= "\x1b[31m";
	inline constexpr std::string_view ASSERT_COLOR	= "\x1b[35m";

	inline constexpr std::string_view CAT_GL		= "[GL]";
	inline constexpr std::string_view CAT_VK		= "[VK]";
	inline constexpr std::string_view CAT_DX		= "[DX]";
	inline constexpr std::string_view CAT_METAL		= "[METAL]";
	inline constexpr std::string_view CAT_WINAPI	= "[WINAPI]";
	inline constexpr std::string_view CAT_X11		= "[X11]";
	inline constexpr std::string_view CAT_WAYLAND	= "[WAYLAND]";
	inline constexpr std::string_view CAT_COCOA		= "[COCOA]";
	inline constexpr std::string_view TRACE_LVL		= "[TRACE]";
	inline constexpr std::string_view DEBUG_LVL		= "[DEBUG]";
	inline constexpr std::string_view INFO_LVL		= "[INFO]";
	inline constexpr std::string_view WARN_LVL		= "[WARN]";
	inline constexpr std::string_view ERROR_LVL		= "[ERROR]";
	inline constexpr std::string_view ASSERTION		= "[ASSERT]";
}