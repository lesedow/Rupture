#ifndef UNICODE
#define UNICODE
#endif // !UNICODE

#include <windows.h>
#include <print>
#include <iostream>

#include "Graphics/GL/GLLoader.hh"
#include "Graphics/GL/Texture2D.hh"
#include "Graphics/GL/ShaderProgram.hh"

#include "Utils/Macros/LoggerMacros.hh"
#include "Utils/Macros/GLMacros.hh"
#include "Utils/GL/GLError.hh"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#pragma warning(push)
#pragma warning(disable: 28251)

namespace gl = Rupture::Graphics::GL;

constexpr int attribList[]{
	gl::WGL_DRAW_TO_WINDOW_ARB, gl::GL_TRUE,
	gl::WGL_SUPPORT_OPENGL_ARB, gl::GL_TRUE,
	gl::WGL_DOUBLE_BUFFER_ARB, gl::GL_TRUE,
	gl::WGL_PIXEL_TYPE_ARB,  gl::WGL_TYPE_RGBA_ARB,
	gl::WGL_COLOR_BITS_ARB, 32,
	gl::WGL_DEPTH_BITS_ARB, 24,
	gl::WGL_STENCIL_BITS_ARB, 8,
	0
};

constexpr int ctxAttribList[]
{
	gl::WGL_CONTEXT_MAJOR_VERSION_ARB, 3,
	gl::WGL_CONTEXT_MINOR_VERSION_ARB, 3,
	gl::WGL_CONTEXT_PROFILE_MASK_ARB,
	gl::WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
	0 
};

struct Vertex
{
	glm::vec3 position;
	glm::vec4 color;
	glm::vec2 texCoords;
	int texId;
};

struct Region
{
	float x, y;
	float width, height;
};

struct Animation
{
	int fps{};
	int currentFrameIndex{};
	std::vector<Region> regions{};
	void UpdateFrame();
};

struct AnimatedSprite
{
	Rupture::Graphics::GL::Texture2D texture;
	std::unordered_map<std::string, Animation> animations;
	
	explicit AnimatedSprite(Rupture::Graphics::GL::Texture2D texture) :texture(texture), animations{} {}

	// Assuming each animation frame is placed horizontally
	// And each animation is basically one row
	static std::vector<Animation> AutoCreateAnimations(glm::vec2 textureSize, glm::vec2 frameSize, int fps)
	{
		std::vector<Animation> animations;
		int totalFrames = textureSize.x / frameSize.x;
		int totalAnimations = textureSize.y / frameSize.y;
		
		for (int animation = 0; animation < totalAnimations; animation++)
		{
			Animation anim;
			anim.fps = fps;

			for (int frame = 0; frame < totalFrames; frame++)
			{
				Region frameRegion
				{
					.x = (frame * frameSize.x) / textureSize.x,
					.y = 1.0f - (animation * frameSize.y) / textureSize.y,
					.width =  frameRegion.x + frameSize.x / textureSize.x,
					.height = frameRegion.y - frameSize.y / textureSize.y,
				};

				anim.regions.push_back(frameRegion);
			}

			animations.push_back(anim);
		}

		return animations;
	}
};

constexpr int SCREEN_W = 1280;
constexpr int SCREEN_H = 720;

LRESULT CALLBACK WindowProc(HWND windowHandle, UINT message, WPARAM wParam, LPARAM lParam);
bool HandleWindowCreation(HWND windowHandle);

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

	if (!gl::LoadGLMethods())
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
		CW_USEDEFAULT, CW_USEDEFAULT, SCREEN_W, SCREEN_H,
		nullptr, nullptr, hInstance, nullptr
	);

	if (!window) return 0;

	HDC deviceContext = GetDC(window);

	UINT numberOfFormats{};
	int pixelFormat{};

	// This is irrelevant
	PIXELFORMATDESCRIPTOR pixelFormatDescriptor{};

	BOOL pixelFormatChosen = gl::wglChoosePixelFormatARB(deviceContext, attribList, nullptr, 1, &pixelFormat, &numberOfFormats);
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


	HGLRC glContext = gl::wglCreateContextAttribsARB(deviceContext, nullptr, ctxAttribList);
	if (!glContext)
	{
		std::cout << "Failed to create GL Context: " << GetLastError() << "\n";
		return 0;
	}

	wglMakeCurrent(deviceContext, glContext);

	ShowWindow(window, cmdShow);
	
	// SPRITE BATCH
	// - Place sprite data in a vertex buffer
	// ...


	std::string glVersion(reinterpret_cast<const char*>(gl::glGetString(gl::GL_VERSION)));
	std::string glVendor(reinterpret_cast<const char*>(gl::glGetString(gl::GL_VENDOR)));
	std::string glRenderer(reinterpret_cast<const char*>(gl::glGetString(gl::GL_RENDERER)));
	std::string glGlsl(reinterpret_cast<const char*>(gl::glGetString(gl::GL_SHADING_LANGUAGE_VERSION)));

	RUPTURE_LOG_INFO(std::format("Running GL Version: {}", glVersion));
	RUPTURE_LOG_INFO(std::format("Vendor: {}", glVendor));
	RUPTURE_LOG_INFO(std::format("Renderer: {}", glRenderer));
	RUPTURE_LOG_INFO(std::format("GLSL Version: {}", glGlsl));

	MSG message{};
	bool running = true;

	stbi_set_flip_vertically_on_load(true);

	#pragma region TEXTURES
	
	gl::Texture2D redTexture{ "assets/red_normal.png" };
	redTexture.Bind(gl::GL_TEXTURE0);

	std::vector<Animation> animations = AnimatedSprite::AutoCreateAnimations(
		redTexture.GetSize(), glm::vec2(16, 32), 8
	);

	Animation& walkUp = animations[0];
	Region& frame = walkUp.regions[3];

	RUPTURE_LOG_INFO(std::format("x: {}, y: {}, w: {}, h: {}\n", frame.x, frame.y, frame.width, frame.height));


	#pragma endregion TEXTURES

	Vertex vertices[] = {	
		{glm::vec3(0.5f, 0.5f, 0.0f), glm::vec4(1.0f), glm::vec2(frame.width, frame.y), 0},
		{glm::vec3(-0.5f, 0.5f, 0.0f), glm::vec4(1.0f), glm::vec2(frame.x, frame.y), 0},
		{glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec4(1.0f), glm::vec2(frame.x, frame.height), 0},
		{glm::vec3(0.5f, -0.5f, 0.0f), glm::vec4(1.0f), glm::vec2(frame.width, frame.height), 0},
	};

	uint32_t indices[]
	{
		0, 1, 2,
		2, 3, 0
	};

	GLuint vao{};
	RUPTURE_GL_CALL(gl::glGenVertexArrays(1, &vao));
	RUPTURE_GL_CALL(gl::glBindVertexArray(vao));

	GLuint vbo{};
	RUPTURE_GL_CALL(gl::glGenBuffers(1, &vbo));

	GLuint ebo{};
	RUPTURE_GL_CALL(gl::glGenBuffers(1, &ebo));
	RUPTURE_GL_CALL(gl::glBindBuffer(gl::GL_ELEMENT_ARRAY_BUFFER, ebo));
	RUPTURE_GL_CALL(gl::glBufferData(gl::GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, gl::GL_STATIC_DRAW));

	RUPTURE_GL_CALL(gl::glBindBuffer(gl::GL_ARRAY_BUFFER, vbo));
	RUPTURE_GL_CALL(gl::glBufferData(gl::GL_ARRAY_BUFFER, sizeof(vertices), vertices, gl::GL_STATIC_DRAW));

	RUPTURE_GL_CALL(gl::glEnableVertexAttribArray(0));
	RUPTURE_GL_CALL(gl::glEnableVertexAttribArray(1));
	RUPTURE_GL_CALL(gl::glEnableVertexAttribArray(2));
	RUPTURE_GL_CALL(gl::glEnableVertexAttribArray(3));

	RUPTURE_GL_CALL(gl::glVertexAttribPointer(0, 3, gl::GL_FLOAT, gl::GL_FALSE, sizeof(Vertex), reinterpret_cast<const void*>(offsetof(Vertex, position))));
	RUPTURE_GL_CALL(gl::glVertexAttribPointer(1, 4, gl::GL_FLOAT, gl::GL_FALSE, sizeof(Vertex), reinterpret_cast<const void*>(offsetof(Vertex, color))));
	RUPTURE_GL_CALL(gl::glVertexAttribPointer(2, 2, gl::GL_FLOAT, gl::GL_FALSE, sizeof(Vertex), reinterpret_cast<const void*>(offsetof(Vertex, texCoords))));
	RUPTURE_GL_CALL(gl::glVertexAttribIPointer(3, 1, gl::GL_INT, sizeof(Vertex), reinterpret_cast<const void*>(offsetof(Vertex, texId))));

	RUPTURE_GL_CALL(gl::glEnable(gl::GL_DEPTH_TEST));

	Rupture::Graphics::GL::ShaderProgram shaderProgram{};
	shaderProgram.CompileShader(gl::GL_VERTEX_SHADER, "assets/default_vert.glsl");
	shaderProgram.CompileShader(gl::GL_FRAGMENT_SHADER, "assets/default_frag.glsl");
	shaderProgram.LinkProgram();
	shaderProgram.UseProgram();

	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 model = glm::mat4(1.0f);
	
	model = glm::translate(model, glm::vec3(1280.0f/2, 720.0f/2, 0.0f));
	model = glm::scale(model, glm::vec3(64.0f, 128.0f, 1.0f));

	glm::mat4 projection = glm::ortho(0.0f, 1280.0f, 0.0f, 720.0f, -1.0f, 1.0f);

	shaderProgram.SetUniformMatrix4("view", 1, gl::GL_FALSE, glm::value_ptr(view));
	shaderProgram.SetUniformMatrix4("projection", 1, gl::GL_FALSE, glm::value_ptr(projection));
	shaderProgram.SetUniformMatrix4("model", 1, gl::GL_FALSE, glm::value_ptr(model));
	shaderProgram.SetUniform1i("oTex", 0);

	while (running)
	{
		while (PeekMessage(&message, nullptr, 0, 0, PM_REMOVE))
		{
			if (message.message == WM_QUIT)
				running = false;

			TranslateMessage(&message);
			DispatchMessage(&message);
		}

		RUPTURE_GL_CALL(gl::glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
		RUPTURE_GL_CALL(gl::glClear(gl::GL_COLOR_BUFFER_BIT | gl::GL_DEPTH_BUFFER_BIT));

		RUPTURE_GL_CALL(gl::glDrawElements(gl::GL_TRIANGLES, 6, gl::GL_UNSIGNED_INT, nullptr));

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
