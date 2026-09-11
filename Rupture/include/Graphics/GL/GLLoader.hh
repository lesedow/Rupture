#pragma once 

#include <windows.h>
#include <any>

#include "Graphics/GL/GLTypes.hh"
#include "Utils/Logger.hh"

#ifndef GLLOAD
#define GLLOAD(procName) Rupture::Graphics::GL::LoadGLFunction(procName, #procName);
#endif

namespace Rupture::Graphics::GL
{
	template<class Func>
	void LoadGLFunction(Func& glFunc, const char* name)
	{
		PROC address = reinterpret_cast<PROC>(wglGetProcAddress(name));
		if (address == reinterpret_cast<PROC>(0x1) || 
			address == reinterpret_cast<PROC>(0x2) || 
			address == reinterpret_cast<PROC>(0x3) || 
			address == reinterpret_cast<PROC>(-1) || 
			address == reinterpret_cast<PROC>(0x0))
		{
			HMODULE glDLL = GetModuleHandleA("opengl32.dll");
			if (!glDLL)
				glDLL = LoadLibraryA("opengl32.dll");
				if (glDLL != nullptr)
					address = reinterpret_cast<PROC>(GetProcAddress(glDLL, name));
						
		}
			glFunc = reinterpret_cast<Func>(address);
			if (!address)
				std::cout << std::format("[{}][GL] Failed to load {}\n", PROJECT_NAME, name);
	}

	void LoadGL10()
	{
		GLLOAD(glCullFace);
		GLLOAD(glFrontFace);
		GLLOAD(glHint);
		GLLOAD(glLineWidth);
		GLLOAD(glPointSize);
		GLLOAD(glPolygonMode);
		GLLOAD(glScissor);
		GLLOAD(glTexParameterf);
		GLLOAD(glTexParameterfv);
		GLLOAD(glTexParameteri);
		GLLOAD(glTexParameteriv);
		GLLOAD(glTexImage1D);
		GLLOAD(glTexImage2D);
		GLLOAD(glDrawBuffer);
		GLLOAD(glClear);
		GLLOAD(glClearColor);
		GLLOAD(glClearStencil);
		GLLOAD(glClearDepth);
		GLLOAD(glStencilMask);
		GLLOAD(glColorMask);
		GLLOAD(glDepthMask);
		GLLOAD(glDisable);
		GLLOAD(glEnable);
		GLLOAD(glFinish);
		GLLOAD(glFlush);
		GLLOAD(glBlendFunc);
		GLLOAD(glLogicOp);
		GLLOAD(glStencilFunc);
		GLLOAD(glStencilOp);
		GLLOAD(glDepthFunc);
		GLLOAD(glPixelStoref);
		GLLOAD(glPixelStorei);
		GLLOAD(glReadBuffer);
		GLLOAD(glReadPixels);
		GLLOAD(glGetBooleanv);
		GLLOAD(glGetDoublev);
		GLLOAD(glGetError);
		GLLOAD(glGetFloatv);
		GLLOAD(glGetIntegerv);
		GLLOAD(glGetString);
		GLLOAD(glGetTexImage);
		GLLOAD(glGetTexParameterfv);
		GLLOAD(glGetTexParameteriv);
		GLLOAD(glGetTexLevelParameterfv);
		GLLOAD(glGetTexLevelParameteriv);
		GLLOAD(glIsEnabled);
		GLLOAD(glDepthRange);
		GLLOAD(glViewport);
	}

	void LoadGL11()
	{
		GLLOAD(glDrawArrays);
		GLLOAD(glDrawElements);
		GLLOAD(glGetPointerv);
		GLLOAD(glPolygonOffset);
		GLLOAD(glCopyTexImage1D);
		GLLOAD(glCopyTexImage2D);
		GLLOAD(glCopyTexSubImage1D);
		GLLOAD(glCopyTexSubImage2D);
		GLLOAD(glTexSubImage1D);
		GLLOAD(glTexSubImage2D);
		GLLOAD(glBindTexture);
		GLLOAD(glDeleteTextures);
		GLLOAD(glGenTextures);
		GLLOAD(glIsTexture);
	}

	void LoadGL12()
	{
		GLLOAD(glDrawRangeElements);
		GLLOAD(glTexImage3D);
		GLLOAD(glTexSubImage3D);
		GLLOAD(glCopyTexSubImage3D);
	}

	void LoadGL13()
	{
		GLLOAD(glActiveTexture);
		GLLOAD(glSampleCoverage);
		GLLOAD(glCompressedTexImage3D);
		GLLOAD(glCompressedTexImage2D);
		GLLOAD(glCompressedTexImage1D);
		GLLOAD(glCompressedTexSubImage3D);
		GLLOAD(glCompressedTexSubImage2D);
		GLLOAD(glCompressedTexSubImage1D);
		GLLOAD(glGetCompressedTexImage);
	}

	void LoadGL14()
	{
		GLLOAD(glBlendFuncSeparate);
		GLLOAD(glMultiDrawArrays);
		GLLOAD(glMultiDrawElements);
		GLLOAD(glPointParameterf);
		GLLOAD(glPointParameterfv);
		GLLOAD(glPointParameteri);
		GLLOAD(glPointParameteriv);
		GLLOAD(glBlendColor);
		GLLOAD(glBlendEquation);
	}

	void LoadGL15()
	{
		GLLOAD(glGenQueries);
		GLLOAD(glDeleteQueries);
		GLLOAD(glIsQuery);
		GLLOAD(glBeginQuery);
		GLLOAD(glEndQuery);
		GLLOAD(glGetQueryiv);
		GLLOAD(glGetQueryObjectiv);
		GLLOAD(glGetQueryObjectuiv);
		GLLOAD(glBindBuffer);
		GLLOAD(glDeleteBuffers);
		GLLOAD(glGenBuffers);
		GLLOAD(glIsBuffer);
		GLLOAD(glBufferData);
		GLLOAD(glBufferSubData);
		GLLOAD(glGetBufferSubData);
		GLLOAD(glMapBuffer);
		GLLOAD(glUnmapBuffer);
		GLLOAD(glGetBufferParameteriv);
		GLLOAD(glGetBufferPointerv);
	}

	void LoadGL20()
	{
		GLLOAD(glBlendEquationSeparate);
		GLLOAD(glDrawBuffers);
		GLLOAD(glStencilOpSeparate);
		GLLOAD(glStencilFuncSeparate);
		GLLOAD(glStencilMaskSeparate);
		GLLOAD(glAttachShader);
		GLLOAD(glBindAttribLocation);
		GLLOAD(glCompileShader);
		GLLOAD(glCreateProgram);
		GLLOAD(glCreateShader);
		GLLOAD(glDeleteProgram);
		GLLOAD(glDeleteShader);
		GLLOAD(glDetachShader);
		GLLOAD(glDisableVertexAttribArray);
		GLLOAD(glEnableVertexAttribArray);
		GLLOAD(glGetActiveAttrib);
		GLLOAD(glGetActiveUniform);
		GLLOAD(glGetAttachedShaders);
		GLLOAD(glGetAttribLocation);
		GLLOAD(glGetProgramiv);
		GLLOAD(glGetProgramInfoLog);
		GLLOAD(glGetShaderiv);
		GLLOAD(glGetShaderInfoLog);
		GLLOAD(glGetShaderSource);
		GLLOAD(glGetUniformLocation);
		GLLOAD(glGetUniformfv);
		GLLOAD(glGetUniformiv);
		GLLOAD(glGetVertexAttribdv);
		GLLOAD(glGetVertexAttribfv);
		GLLOAD(glGetVertexAttribiv);
		GLLOAD(glGetVertexAttribPointerv);
		GLLOAD(glIsProgram);
		GLLOAD(glIsShader);
		GLLOAD(glLinkProgram);
		GLLOAD(glShaderSource);
		GLLOAD(glUseProgram);
		GLLOAD(glUniform1f);
		GLLOAD(glUniform2f);
		GLLOAD(glUniform3f);
		GLLOAD(glUniform4f);
		GLLOAD(glUniform1i);
		GLLOAD(glUniform2i);
		GLLOAD(glUniform3i);
		GLLOAD(glUniform4i);
		GLLOAD(glUniform1fv);
		GLLOAD(glUniform2fv);
		GLLOAD(glUniform3fv);
		GLLOAD(glUniform4fv);
		GLLOAD(glUniform1iv);
		GLLOAD(glUniform2iv);
		GLLOAD(glUniform3iv);
		GLLOAD(glUniform4iv);
		GLLOAD(glUniformMatrix2fv);
		GLLOAD(glUniformMatrix3fv);
		GLLOAD(glUniformMatrix4fv);
		GLLOAD(glValidateProgram);
		GLLOAD(glVertexAttrib1d);
		GLLOAD(glVertexAttrib1dv);
		GLLOAD(glVertexAttrib1f);
		GLLOAD(glVertexAttrib1fv);
		GLLOAD(glVertexAttrib1s);
		GLLOAD(glVertexAttrib1sv);
		GLLOAD(glVertexAttrib2d);
		GLLOAD(glVertexAttrib2dv);
		GLLOAD(glVertexAttrib2f);
		GLLOAD(glVertexAttrib2fv);
		GLLOAD(glVertexAttrib2s);
		GLLOAD(glVertexAttrib2sv);
		GLLOAD(glVertexAttrib3d);
		GLLOAD(glVertexAttrib3dv);
		GLLOAD(glVertexAttrib3f);
		GLLOAD(glVertexAttrib3fv);
		GLLOAD(glVertexAttrib3s);
		GLLOAD(glVertexAttrib3sv);
		GLLOAD(glVertexAttrib4Nbv);
		GLLOAD(glVertexAttrib4Niv);
		GLLOAD(glVertexAttrib4Nsv);
		GLLOAD(glVertexAttrib4Nub);
		GLLOAD(glVertexAttrib4Nubv);
		GLLOAD(glVertexAttrib4Nuiv);
		GLLOAD(glVertexAttrib4Nusv);
		GLLOAD(glVertexAttrib4bv);
		GLLOAD(glVertexAttrib4d);
		GLLOAD(glVertexAttrib4dv);
		GLLOAD(glVertexAttrib4f);
		GLLOAD(glVertexAttrib4fv);
		GLLOAD(glVertexAttrib4iv);
		GLLOAD(glVertexAttrib4s);
		GLLOAD(glVertexAttrib4sv);
		GLLOAD(glVertexAttrib4ubv);
		GLLOAD(glVertexAttrib4uiv);
		GLLOAD(glVertexAttrib4usv);
		GLLOAD(glVertexAttribPointer);
	}

	void LoadGL21()
	{
		GLLOAD(glUniformMatrix2x3fv);
		GLLOAD(glUniformMatrix3x2fv);
		GLLOAD(glUniformMatrix2x4fv);
		GLLOAD(glUniformMatrix4x2fv);
		GLLOAD(glUniformMatrix3x4fv);
		GLLOAD(glUniformMatrix4x3fv);
	}

	void LoadGL30()
	{
		GLLOAD(glColorMaski);
		GLLOAD(glGetBooleani_v);
		GLLOAD(glGetIntegeri_v);
		GLLOAD(glEnablei);
		GLLOAD(glDisablei);
		GLLOAD(glIsEnabledi);
		GLLOAD(glBeginTransformFeedback);
		GLLOAD(glEndTransformFeedback);
		GLLOAD(glBindBufferRange);
		GLLOAD(glBindBufferBase);
		GLLOAD(glTransformFeedbackVaryings);
		GLLOAD(glGetTransformFeedbackVarying);
		GLLOAD(glClampColor);
		GLLOAD(glBeginConditionalRender);
		GLLOAD(glEndConditionalRender);
		GLLOAD(glVertexAttribIPointer);
		GLLOAD(glGetVertexAttribIiv);
		GLLOAD(glGetVertexAttribIuiv);
		GLLOAD(glVertexAttribI1i);
		GLLOAD(glVertexAttribI2i);
		GLLOAD(glVertexAttribI3i);
		GLLOAD(glVertexAttribI4i);
		GLLOAD(glVertexAttribI1ui);
		GLLOAD(glVertexAttribI2ui);
		GLLOAD(glVertexAttribI3ui);
		GLLOAD(glVertexAttribI4ui);
		GLLOAD(glVertexAttribI1iv);
		GLLOAD(glVertexAttribI2iv);
		GLLOAD(glVertexAttribI3iv);
		GLLOAD(glVertexAttribI4iv);
		GLLOAD(glVertexAttribI1uiv);
		GLLOAD(glVertexAttribI2uiv);
		GLLOAD(glVertexAttribI3uiv);
		GLLOAD(glVertexAttribI4uiv);
		GLLOAD(glVertexAttribI4bv);
		GLLOAD(glVertexAttribI4sv);
		GLLOAD(glVertexAttribI4ubv);
		GLLOAD(glVertexAttribI4usv);
		GLLOAD(glGetUniformuiv);
		GLLOAD(glBindFragDataLocation);
		GLLOAD(glGetFragDataLocation);
		GLLOAD(glUniform1ui);
		GLLOAD(glUniform2ui);
		GLLOAD(glUniform3ui);
		GLLOAD(glUniform4ui);
		GLLOAD(glUniform1uiv);
		GLLOAD(glUniform2uiv);
		GLLOAD(glUniform3uiv);
		GLLOAD(glUniform4uiv);
		GLLOAD(glTexParameterIiv);
		GLLOAD(glTexParameterIuiv);
		GLLOAD(glGetTexParameterIiv);
		GLLOAD(glGetTexParameterIuiv);
		GLLOAD(glClearBufferiv);
		GLLOAD(glClearBufferuiv);
		GLLOAD(glClearBufferfv);
		GLLOAD(glClearBufferfi);
		GLLOAD(glGetStringi);
		GLLOAD(glIsRenderbuffer);
		GLLOAD(glBindRenderbuffer);
		GLLOAD(glDeleteRenderbuffers);
		GLLOAD(glGenRenderbuffers);
		GLLOAD(glRenderbufferStorage);
		GLLOAD(glGetRenderbufferParameteriv);
		GLLOAD(glIsFramebuffer);
		GLLOAD(glBindFramebuffer);
		GLLOAD(glDeleteFramebuffers);
		GLLOAD(glGenFramebuffers);
		GLLOAD(glCheckFramebufferStatus);
		GLLOAD(glFramebufferTexture1D);
		GLLOAD(glFramebufferTexture2D);
		GLLOAD(glFramebufferTexture3D);
		GLLOAD(glFramebufferRenderbuffer);
		GLLOAD(glGetFramebufferAttachmentParameteriv);
		GLLOAD(glGenerateMipmap);
		GLLOAD(glBlitFramebuffer);
		GLLOAD(glRenderbufferStorageMultisample);
		GLLOAD(glFramebufferTextureLayer);
		GLLOAD(glMapBufferRange);
		GLLOAD(glFlushMappedBufferRange);
		GLLOAD(glBindVertexArray);
		GLLOAD(glDeleteVertexArrays);
		GLLOAD(glGenVertexArrays);
		GLLOAD(glIsVertexArray);
	}

	void LoadGL31()
	{
		GLLOAD(glDrawArraysInstanced);
		GLLOAD(glDrawElementsInstanced);
		GLLOAD(glTexBuffer);
		GLLOAD(glPrimitiveRestartIndex);
		GLLOAD(glCopyBufferSubData);
		GLLOAD(glGetUniformIndices);
		GLLOAD(glGetActiveUniformsiv);
		GLLOAD(glGetActiveUniformName);
		GLLOAD(glGetUniformBlockIndex);
		GLLOAD(glGetActiveUniformBlockiv);
		GLLOAD(glGetActiveUniformBlockName);
		GLLOAD(glUniformBlockBinding);
	}

	void LoadGL32()
	{
		GLLOAD(glDrawElementsBaseVertex);
		GLLOAD(glDrawRangeElementsBaseVertex);
		GLLOAD(glDrawElementsInstancedBaseVertex);
		GLLOAD(glMultiDrawElementsBaseVertex);
		GLLOAD(glProvokingVertex);
		GLLOAD(glFenceSync);
		GLLOAD(glIsSync);
		GLLOAD(glDeleteSync);
		GLLOAD(glClientWaitSync);
		GLLOAD(glWaitSync);
		GLLOAD(glGetInteger64v);
		GLLOAD(glGetSynciv);
		GLLOAD(glGetInteger64i_v);
		GLLOAD(glGetBufferParameteri64v);
		GLLOAD(glFramebufferTexture);
		GLLOAD(glTexImage2DMultisample);
		GLLOAD(glTexImage3DMultisample);
		GLLOAD(glGetMultisamplefv);
		GLLOAD(glSampleMaski);
	}

	void LoadGL33()
	{
		GLLOAD(glBindFragDataLocationIndexed);
		GLLOAD(glGetFragDataIndex);
		GLLOAD(glGenSamplers);
		GLLOAD(glDeleteSamplers);
		GLLOAD(glIsSampler);
		GLLOAD(glBindSampler);
		GLLOAD(glSamplerParameteri);
		GLLOAD(glSamplerParameteriv);
		GLLOAD(glSamplerParameterf);
		GLLOAD(glSamplerParameterfv);
		GLLOAD(glSamplerParameterIiv);
		GLLOAD(glSamplerParameterIuiv);
		GLLOAD(glGetSamplerParameteriv);
		GLLOAD(glGetSamplerParameterIiv);
		GLLOAD(glGetSamplerParameterfv);
		GLLOAD(glGetSamplerParameterIuiv);
		GLLOAD(glQueryCounter);
		GLLOAD(glGetQueryObjecti64v);
		GLLOAD(glGetQueryObjectui64v);
		GLLOAD(glVertexAttribDivisor);
		GLLOAD(glVertexAttribP1ui);
		GLLOAD(glVertexAttribP1uiv);
		GLLOAD(glVertexAttribP2ui);
		GLLOAD(glVertexAttribP2uiv);
		GLLOAD(glVertexAttribP3ui);
		GLLOAD(glVertexAttribP3uiv);
		GLLOAD(glVertexAttribP4ui);
		GLLOAD(glVertexAttribP4uiv);
	}	

	bool LoadGLMethods()
	{
		// Create a window as usual

		const std::wstring DUMMY_CLASS = L"DummyCls";

		WNDCLASS dummy{};
		dummy.lpfnWndProc = DefWindowProc;
		dummy.lpszClassName = DUMMY_CLASS.c_str();
		dummy.hInstance = GetModuleHandle(nullptr);
		dummy.style = CS_OWNDC;

		if (!RegisterClass(&dummy))
		{
			std::cout << "Failed to register class dummy: " << GetLastError() << "\n";
			return false;
		};

		HWND window = CreateWindowEx(
			0,
			DUMMY_CLASS.c_str(),
			L"Dummy",
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
			nullptr, nullptr, GetModuleHandle(nullptr), nullptr
		);

		if (!window)
		{
			std::cout << "Failed to create dummy window!: " << GetLastError() << "\n";
			return false;
		}

		// Define a temp pixelformat for this gl context
		PIXELFORMATDESCRIPTOR pixelFormatDescriptor
		{
			sizeof(PIXELFORMATDESCRIPTOR),
			1,
			PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
			PFD_TYPE_RGBA,
			32,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0,
			24, 8, 0,
			PFD_MAIN_PLANE,
			0, 0, 0, 0
		};

		// Let windows choose a pixel format
		HDC deviceContext = GetDC(window);
		int pixelFormat = ChoosePixelFormat(deviceContext, &pixelFormatDescriptor);

		if (!pixelFormat)
		{
			std::cout << "Failed to find a pixel format for this descriptor: " << GetLastError() << "\n";
			return false;
		}

		// Set the pixel format
		BOOL pixelFormatChosen = SetPixelFormat(deviceContext, pixelFormat, &pixelFormatDescriptor);
		if (!pixelFormatChosen)
		{
			std::cout << "Failed to set the specified pixel format!: " << GetLastError() << "\n";
			return false;
		}

		// Create the GL context
		HGLRC glContext = wglCreateContext(deviceContext);
		wglMakeCurrent(deviceContext, glContext);

		GLLOAD(wglCreateContextAttribsARB);
		GLLOAD(wglChoosePixelFormatARB);

		LoadGL10();
		LoadGL11();
		LoadGL12();
		LoadGL13();
		LoadGL14();
		LoadGL15();
		LoadGL20();
		LoadGL21();
		LoadGL30();
		LoadGL31();
		LoadGL32();
		LoadGL33();

		wglMakeCurrent(deviceContext, NULL);
		wglDeleteContext(glContext);
		DestroyWindow(window);

		return true;
	}
	
}