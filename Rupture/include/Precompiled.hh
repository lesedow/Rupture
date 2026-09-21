#pragma once

#if defined(_WIN32)
#ifndef UNICODE
#define UNICODE
#endif
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMIMAX
#define NOMINMAX
#endif
#pragma comment(lib, "opengl32.lib")
#include <windows.h>	
#ifndef APIENTRYP
#define APIENTRYP APIENTRY *
#endif
#endif

#include <stb_image.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <print>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <string>
#include <string_view>
#include <filesystem>
#include <concepts>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iostream>