#include "Platform/Window.hh"

#include "Graphics/GL/GLLoader.hh"
#include "Graphics/GL/GLTypes.hh"
#include "Graphics/GL/Texture2D.hh"
#include "Graphics/GL/ShaderProgram.hh"
#include "Rendering/GLRenderer.hh"

#include "Utils/Macros/LoggerMacros.hh"
#include "Utils/Macros/GLMacros.hh"
#include "Utils/GL/GLError.hh"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <print>
#include <iostream>

#pragma warning(push)
#pragma warning(disable: 28251)

namespace Rupture
{
	//struct Vertex
	//{
	//	glm::vec3 position;
	//	glm::vec4 color;
	//	glm::vec2 texCoords;
	//	int texId;
	//};

	//struct Region
	//{
	//	float x, y;
	//	float width, height;
	//};

	//struct Animation
	//{
	//	int fps{};
	//	int currentFrameIndex{};
	//	std::vector<Region> regions{};
	//	void UpdateFrame();
	//};

	//struct AnimatedSprite
	//{
	//	Rupture::Graphics::GL::Texture2D texture;
	//	std::unordered_map<std::string, Animation> animations;

	//	explicit AnimatedSprite(Rupture::Graphics::GL::Texture2D texture) :texture(texture), animations{} {}

	//	// Assuming each animation frame is placed horizontally
	//	// And each animation is basically one row
	//	static std::vector<Animation> AutoCreateAnimations(glm::vec2 textureSize, glm::vec2 frameSize, int fps)
	//	{
	//		std::vector<Animation> animations;
	//		int totalFrames = textureSize.x / frameSize.x;
	//		int totalAnimations = textureSize.y / frameSize.y;

	//		for (int animation = 0; animation < totalAnimations; animation++)
	//		{
	//			Animation anim;
	//			anim.fps = fps;

	//			for (int frame = 0; frame < totalFrames; frame++)
	//			{
	//				Region frameRegion
	//				{
	//					.x = (frame * frameSize.x) / textureSize.x,
	//					.y = 1.0f - (animation * frameSize.y) / textureSize.y,
	//					.width = frameRegion.x + frameSize.x / textureSize.x,
	//					.height = frameRegion.y - frameSize.y / textureSize.y,
	//				};

	//				anim.regions.push_back(frameRegion);
	//			}

	//			animations.push_back(anim);
	//		}

	//		return animations;
	//	}
	//};

	constexpr int SCREEN_W = 1280;
	constexpr int SCREEN_H = 720;

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

		if (Graphics::GL::LoadGLMethods())
		{
			std::cout << "ERROR\n";
		}

		Platform::Window ruptureWindow(glm::vec2(SCREEN_W, SCREEN_H), L"Rupture");
		ruptureWindow.CreateGLContext();

		Rendering::GLRenderer Renderer_{};

		//std::string glVersion(reinterpret_cast<const char*>(Graphics::GL::glGetString(Graphics::GL::GL_VERSION)));
		//std::string glVendor(reinterpret_cast<const char*>(Graphics::GL::glGetString(Graphics::GL::GL_VENDOR)));
		//std::string glRenderer(reinterpret_cast<const char*>(Graphics::GL::glGetString(Graphics::GL::GL_RENDERER)));
		//std::string glGlsl(reinterpret_cast<const char*>(Graphics::GL::glGetString(Graphics::GL::GL_SHADING_LANGUAGE_VERSION)));

		//RP_LOG_INFO(std::format("Running GL Version: {}", Graphics::GL::glGetString(Graphics::GL::GL_VERSION)));
		//RP_LOG_INFO(std::format("Vendor: {}", Graphics::GL::glGetString(Graphics::GL::GL_VENDOR)));
		//RP_LOG_INFO(std::format("Renderer: {}", Graphics::GL::glGetString(Graphics::GL::GL_RENDERER)));
		//RP_LOG_INFO(std::format("GLSL Version: {}", Graphics::GL::glGetString(Graphics::GL::GL_SHADING_LANGUAGE_VERSION)));

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

			//RUPTURE_GL_CALL(gl::glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
			//RUPTURE_GL_CALL(gl::glClear(gl::GL_COLOR_BUFFER_BIT | gl::GL_DEPTH_BUFFER_BIT));

			//RUPTURE_GL_CALL(gl::glDrawElements(gl::GL_TRIANGLES, 6, gl::GL_UNSIGNED_INT, nullptr));

			SwapBuffers(ruptureWindow.GetDeviceContext());
		}

		return 0;
	}

#pragma warning(pop)

}