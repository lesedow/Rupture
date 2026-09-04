#pragma once

#include <windows.h>
#include <gl/GL.h>

#pragma comment(lib, "opengl32.lib")

namespace Rupture::Graphics::GL
{
	/* Why did I start to write this manually you might ask? I DONT fucking know
	   IT WAS SUCH A PAIN PLEASE STOP ME FROM DOING THIS EVER AGAIN!!!!!!
	*/

	using GLintptr = ptrdiff_t;
	using GLsizeiptr = ptrdiff_t;
	using GLint64 = long long;
	using GLuint64 = unsigned long long;
		
	// GL 3.3

	// TEXTURES
	using PFNGLATTACHTEXTUREPROC = void (APIENTRY*)(GLenum texture);
	using PFNGLBINDTEXTUREPROC = void (APIENTRY*)(GLenum target, GLuint texture);

	using PFNGLCOMPRESSEDTEXIMAGE1DPROC = void (APIENTRY*)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLVoid *data);
	using PFNGLCOMPRESSEDTEXIMAGE2DPROC = void (APIENTRY*)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLVoid *data);
	using PFNGLCOMPRESSEDTEXIMAGE3DPROC = void (APIENTRY*)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLVoid *data);

	using PFNGLCOMPRESSEDTEXTSUBIMAGE1DPROC = void (APIENTRY*)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data);
	using PFNGLCOMPRESSEDTEXTSUBIMAGE2DPROC = void (APIENTRY*)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data);
	using PFNGLCOMPRESSEDTEXTSUBIMAGE3DPROC = void (APIENTRY*)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data);

	using PFNGLCOPYTEXIMAGE1DPROC = void (APIENTRY*)(GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLint border);
	using PFNGLCOPYTEXIMAGE2DPROC = void (APIENTRY*)(GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
	
	using PFNGLCOPYTEXSUBIMAGE1DPROC = void (APIENTRY*)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
	using PFNGLCOPYTEXSUBIMAGE2DPROC = void (APIENTRY*)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
	using PFNGLCOPYTEXSUBIMAGE2DPROC = void (APIENTRY*)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);

	using PFNGLGENTEXTURESPROC = void (APIENTRY*)(GLsizei n, const GLuint *textures);
	using PFNGLDELETETEXTURESPROC = void (APIENTRY*)(GLsizei n, const GLuint *textures);

	using PFNGLGETCOMPRESSEDTEXIMAGEPROC = void (APIENTRY*)(GLenum target, GLint lod, GLvoid *img);
	using PFNGLGETTEXIMAGEPROC = void (APIENTRY*)(GLenum target, GLint level, GLenum format, GLenum type, GLvoid *img);
	using PFNGLGETTEXLEVELPARAMETERFVPROC = void (APIENTRY*)(GLenum target, GLint level, GLenum pname, GLfloat *params);
	using PFNGLGETTEXLEVELPARAMETERIVPROC = void (APIENTRY*)(GLenum target, GLint level, GLenum pname, GLint *params);

	using PFNGLISTEXTUREPROC = GLboolean (APIENTRY*)(GLuint texture);
	using PFNGLTEXBUFFER = void (APIENTRY*)(GLenum target, GLenum internalFormat, GLuint buffer);

	using PFNGLTEXIMAGE1DPROC = void (APIENTRY*)(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid* data);
	using PFNGLTEXIMAGE2DPROC = void (APIENTRY*)(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid* data);
	using PFNGLTEXIMAGE2DMULTISAMPLEPROC = void (APIENTRY*)(GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
	
	using PFNGLTEXIMAGE3DPROC = void (APIENTRY*)(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid* data);
	using PFNGLTEXIMAGE3DMULTISAMPLEPROC = void (APIENTRY*)(GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
	
	using PFNGLTEXPARAMETERFPROC = void (APIENTRY*)(GLenum target, GLenum pname, GLfloat param);
	using PFNGLTEXPARAMETERIPROC = void (APIENTRY*)(GLenum target, GLenum pname, GLint param);

	using PFNGLTEXSUBIMAGE1DPROC = void (APIENTRY*)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *data);
	using PFNGLTEXSUBIMAGE2DPROC = void (APIENTRY*)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *data);
	using PFNGLTEXSUBIMAGE3DPROC = void (APIENTRY*)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *data);

	// RENDERING
	using PFNGLCOLORPOINTEREXTPROC = void (APIENTRY*)(GLbitfield mask);	
	
	// FRAME BUFFERS
	using PFNGLBINDFRAMEBUFFERPROC = void (APIENTRY*)(GLenum target, GLuint framebuffer);
	using PFNGLBINDRENDERBUFFERPROC = void (APIENTRY*)(GLenum target, GLuint renderbuffer);
	using PFNGLBLITFRAMEBUFFERPROC = void (APIENTRY*)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
	using PFNGLCHECKFRAMEBUFFERSTATUSPROC = void (APIENTRY*)(GLenum target);
	using PFNGLDELETEFRAMEBUFFERSPROC = void (APIENTRY*)(GLsizei n, GLuint *framebuffers);
	using PFNGLDELETERENDERBUFFERSPROC = void (APIENTRY*)(GLsizei n, GLuint *renderbuffers);
	using PFNGLDRAWBUFFERSPROC = void (APIENTRY*)(GLsizei n, const GLenum *bufs);
	using PFNGLFRAMEBUFFERRENDERBUFFERPROC = void (APIENTRY*)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
	using PFNGLFRAMEBUFFERTEXTUREPROC = void (APIENTRY*)(GLenum target, GLenum attachment, GLuint texture, GLint level);
	using PFNGLFRAMEBUFFERTEXTURE1DPROC = void (APIENTRY*)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
	using PFNGLFRAMEBUFFERTEXTURE2DPROC = void (APIENTRY*)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
	using PFNGLFRAMEBUFFERTEXTURE3DPROC = void (APIENTRY*)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint layer);
	using PFNFGLFRAMEBUFFERTEXTURELAYERPROC = void (APIENTRY*)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
	using PFNGLGENFRAMEBUFFERSPROC = void (APIENTRY*)(GLsizei n, GLuint *ids);
	using PFNGLGENRENDERBUFFERSPROC = void (APIENTRY*)(GLsizei n, GLuint *renderbuffers);
	using PFNGLGENERATEMIPMAPPROC = void (APIENTRY*)(GLenum target);
	using PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC = void (APIENTRY*)(GLenum target, GLenum attachment, GLenum pname, GLint *params);
	using PFNGLGETRENDERBUFFERPARAMETERIVPROC = void (APIENTRY*)(GLenum target, GLenum pname, GLint *params);
	using PFNGLISFRAMEBUFFERPROC = GLboolean (APIENTRY*)(GLuint framebuffer);
	using PFNGLISRENDERBUFFERPROC = GLboolean (APIENTRY*)(GLuint renderbuffer);
	using PFNGLRENDERBUFFERSTORAGEPROC = void (APIENTRY*)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
	using PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC = void (APIENTRY*)(GLenum target, GLenum samples, GLenum internalformat, GLsizei width, GLsizei height);
	using PFNGLSAMPLEMASKIPROC = void (APIENTRY*)(GLuint maskNumber, GLbitfield mask);

	// SHADERS
	using PFNGLCREATEPROGRAMPROC = GLuint(APIENTRY*)(void);
	using PFNGLSHADERSOURCEPROC = void (APIENTRY*)(GLuint shader, GLsizei count, const char** string, const GLint* length);
	using PFNGLCREATESHADERPROC = GLuint(APIENTRY*)(GLenum shaderType);
	using PFNGLCOMPILESHADERPROC = void (APIENTRY*)(GLuint shader);
	using PFNGLDELETESHADERPROC = void (APIENTRY*)(GLuint shader);
	using PFNGLLINKPROGRAMPROC = void (APIENTRY*)(GLuint program);
	using PFNGLATTACHSHADERPROC = void (APIENTRY*)(GLuint program, GLuint shader);
	using PFNGLVALIDATEPROGRAMPROC = void (APIENTRY*)(GLuint program);
	using PFNGLGETSHADERIVPROC = void (APIENTRY*)(GLuint shader, GLenum pname, GLint* params);
	using PFNGLGETSHADERINFOLOGPROC = void (APIENTRY*)(GLuint shader, GLsizei maxLength, GLsizei* length, char* infoLog);
	using PFNGLUSEPROGRAMPROC = void (APIENTRY*)(GLuint program);
	using PFNGLGETPROGRAMIVPROC = void (APIENTRY*)(GLuint program, GLenum pname, GLint* params);
	using PFNGLBINDATTRIBLOCATIONPROC = void (APIENTRY*)(GLuint program, GLuint index, const char* name);
	using PFNGLBINDFRAGDATALOCATIONINDEXEDPROC = void (APIENTRY*)(GLuint program, GLuint colorNumber, GLuint index, const char *name);
	using PFNGLDELETEPROGRAMPROC = void (APIENTRY*)(GLuint program);
	using PFNGLDETACHSHADERPROC = void (APIENTRY*)(GLuint program, GLuint shader);
	using PFNGLGETACTIVEATTRIBPROC = void (APIENTRY*)(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, char* name);
	using PFNGLGETACTIVEUNIFORMPROC = void (APIENTRY*)(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, char* name);
	using PFNGLGETACTIVEUNIFORMBLOCKIVPROC = void (APIENTRY*)(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint* params);
	using PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC = void (APIENTRY*)(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei* length, char* uniformBlockName);
	using PFNGLGETACTIVEUNIFORMNAMEPROC = void (APIENTRY*)(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei* length, char* uniformName);
	using PFNGLGETACTIVEUNIFORMSIVPROC = void (APIENTRY*)(GLuint program, GLsizei uniformCount, const GLuint* uniformIndices);
	using PFNGLGETATTACHEDSHADERSPROC = void (APIENTRY*)(GLuint program, GLsizei maxCount, GLsizei* count, GLuint* shaders);
	using PFNGLGETATTRIBLOCATIONPROC = void (APIENTRY*)(GLuint program, const char* name);
	using PFNGLGETFRAGDATAINDEXPROC = void (APIENTRY*)(GLuint program, const char* name);
	using PFNGLGETFRAGDATALOCATIONPROC = void (APIENTRY*)(GLuint program, const char* name);
	using PFNGLGETPROGRAMPROC = void (APIENTRY*)(GLuint program, GLenum pname, GLint* params);
	using PFNGLGETSHADERSOURCEPROC = void (APIENTRY*)(GLuint shader, GLsizei bufSize, GLsizei* length, char* source);
	using PFNGLGETUNIFORMFVPROC = void (APIENTRY*)(GLuint program, GLint location, GLfloat* params);
	using PFNGLGETUNIFORMIVPROC = void (APIENTRY*)(GLuint program, GLint location, GLint* params);
	using PFNGLGETUNIFORMUIVPROC = void (APIENTRY*)(GLuint program, GLint location, GLuint* params);
	using PFNGLGETUNIFORMBLOCKINDEXPROC = void (APIENTRY*)(GLuint program, const char* uniformBlockName);
	using PFNGLGETUNIFORMINDICESPROC = void (APIENTRY*)(GLuint program, GLsizei uniformCount, const char** uniformNames, GLuint *uniformIndices);
	using PFNGLGETUNIFORMLOCATIONPROC = void (APIENTRY*)(GLuint program, const char* name);
	using PFNGLISPROGRAMPROC = GLboolean (APIENTRY*)(GLuint program);
	using PFNGLISSHADERPROC = GLboolean (APIENTRY*)(GLuint shader);
	using PFNGLUNIFORMBLOCKBINDINGPROC = void (APIENTRY*)(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);

	using PFNGLUNIFORM1FPROC = void (APIENTRY*)(GLint location, GLfloat v0);
	using PFNGLUNIFORM2FPROC = void (APIENTRY*)(GLint location, GLfloat v0, GLfloat v1);
	using PFNGLUNIFORM3FPROC = void (APIENTRY*)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
	using PFNGLUNIFORM4FPROC = void (APIENTRY*)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);

	using PFNGLUNIFORM1IPROC = void (APIENTRY*)(GLint location, GLint v0);
	using PFNGLUNIFORM2IPROC = void (APIENTRY*)(GLint location, GLint v0, GLint v1);
	using PFNGLUNIFORM3IPROC = void (APIENTRY*)(GLint location, GLint v0, GLint v1, GLint v2);
	using PFNGLUNIFORM4IPROC = void (APIENTRY*)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);

	using PFNGLUNIFORM1UIPROC = void (APIENTRY*)(GLint location, GLuint v0);
	using PFNGLUNIFORM2UIPROC = void (APIENTRY*)(GLint location, GLuint v0, GLuint v1);
	using PFNGLUNIFORM3UIPROC = void (APIENTRY*)(GLint location, GLuint v0, GLuint v1, GLuint v2);
	using PFNGLUNIFORM4UIPROC = void (APIENTRY*)(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);

	using PFNGLUNIFORM1FVPROC = void (APIENTRY*)(GLint location, GLsizei count, const GLfloat* value);
	using PFNGLUNIFORM2FVPROC = void (APIENTRY*)(GLint location, GLsizei count, const GLfloat* value);
	using PFNGLUNIFORM3FVPROC = void (APIENTRY*)(GLint location, GLsizei count, const GLfloat* value);
	using PFNGLUNIFORM4FVPROC = void (APIENTRY*)(GLint location, GLsizei count, const GLfloat* value);

	using PFNGLUNIFORM1IVPROC = void (APIENTRY*)(GLint location, GLsizei count, const GLint* value);
	using PFNGLUNIFORM2IVPROC = void (APIENTRY*)(GLint location, GLsizei count, const GLint* value);
	using PFNGLUNIFORM3IVPROC = void (APIENTRY*)(GLint location, GLsizei count, const GLint* value);
	using PFNGLUNIFORM4IVPROC = void (APIENTRY*)(GLint location, GLsizei count, const GLint* value);

	using PFNGLUNIFORM1UIVPROC = void (APIENTRY*)(GLint location, GLsizei count, const GLuint* value);
	using PFNGLUNIFORM2UIVPROC = void (APIENTRY*)(GLint location, GLsizei count, const GLuint* value);
	using PFNGLUNIFORM3UIVPROC = void (APIENTRY*)(GLint location, GLsizei count, const GLuint* value);
	using PFNGLUNIFORM4UIVPROC = void (APIENTRY*)(GLint location, GLsizei count, const GLuint* value);

	using PFNGLUNIFORMMATRIX2FVPROC = void (APIENTRY*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	using PFNGLUNIFORMMATRIX3FVPROC = void (APIENTRY*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	using PFNGLUNIFORMMATRIX4FVPROC = void (APIENTRY*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	using PFNGLUNIFORMMATRIX2X3FVPROC = void (APIENTRY*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	using PFNGLUNIFORMMATRIX2X3FVPROC = void (APIENTRY*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	using PFNGLUNIFORMMATRIX3X2FVPROC = void (APIENTRY*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	using PFNGLUNIFORMMATRIX2X4FVPROC = void (APIENTRY*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	using PFNGLUNIFORMMATRIX4X2FVPROC = void (APIENTRY*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	using PFNGLUNIFORMMATRIX3X4FVPROC = void (APIENTRY*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	using PFNGLUNIFORMMATRIX4X3FVPROC = void (APIENTRY*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);

	// BUFFER OBJECTS
	using PFNGLGENBUFFERSPROC = void (APIENTRY*)(GLsizei n, GLuint* buffers);
	using PFNGLBINDBUFFERPROC = void (APIENTRY*)(GLenum target, GLuint buffer);
	using PFNGLBINDBUFFERBASEPROC = void (APIENTRY*)(GLenum target, GLuint index, GLuint buffer);
	using PFNGLBINDBUFFERRANGEPROC = void (APIENTRY*)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
	
	using PFNGLBUFFERSUBDATAPROC = void (APIENTRY*)(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid* data);
	using PFNGLCOPYBUFFERSUBDATAPROC = void (APIENTRY*)(GLenum target, GLenum writetarget, GLintptr readoffset, GLintptr writeoffset, GLsizeiptr size);
	using PFNGLDELETEBUFFERSPROC = void (APIENTRY*)(GLsizei n, const GLuint* buffers);
	using PFNGLBUFFERDATAPROC = void (APIENTRY*)(GLenum target, GLsizeiptr size, const GLvoid* data, GLenum usage);
	
	using PFNGLVERTEXATTRIBPOINTERPROC = void (APIENTRY*)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer);
	using PFNGLENABLEVERTEXATTRIBARRAYPROC = void (APIENTRY*)(GLuint index);
	using PFNGLDISABLEVERTEXATTRIBARRAYPROC = void (APIENTRY*)(GLuint index);
	using PFNGLDRAWARRAYSINSTANCEDPROC = void(APIENTRY*)(GLenum mode, GLint first, GLsizei count, GLsizei primcount);
	using PFNGLDRAWELEMENTSPROC = void(APIENTRY*)(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices);
	using PFNGLDRAWELEMENTSBASEVERTEXPROC = void(APIENTRY*)(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLint basevertex);
	using PFNGLDRAWELEMENTSINSTANCEDPROC = void(APIENTRY*)(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLsizei primcount);
	using PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC = void(APIENTRY*)(GLenum mode, GLsizei count, GLenum type, GLvoid* indices, GLsizei primcount, GLint basevertex);
	using PFNGLDRAWRANGEELEMENTSPROC = void(APIENTRY*)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid* indices);
	using PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC = void(APIENTRY*)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid* indices, GLint basevertex);
	using PFNGLFLUSHMAPPEDBUFFERRANGEPROC = void(APIENTRY*)(GLenum target, GLintptr offset, GLsizeiptr length);
	using PFNGLGENBUFFERPARAMETERIVPROC = void(APIENTRY*)(GLenum target, GLenum value, GLint* data);
	using PFNGLGENBUFFERPARAMETERI64VPROC = void(APIENTRY*)(GLenum target, GLenum value, GLint64 * data);
	using PFNGLGETBUFFERPOINTERVPROC = void(APIENTRY*)(GLenum target, GLenum pname, GLvoid** params);
	using PFNGLGETBUFFERSUBDATAPROC = void(APIENTRY*)(GLenum target, GLintptr offset, GLsizei ptrsize, GLvoid* data);

	using PFNGLGETVERTEXATTRIBDVPROC = void(APIENTRY*)(GLuint index, GLenum pname, GLdouble* params);
	using PFNGLGETVERTEXATTRIBFVPROC = void(APIENTRY*)(GLuint index, GLenum pname, GLfloat* params);
	using PFNGLGETVERTEXATTRIBIVPROC = void(APIENTRY*)(GLuint index, GLenum pname, GLint* params);
	using PFNGLGETVERTEXATTRIBIIVPROC = void(APIENTRY*)(GLuint index, GLenum pname, GLint* params);
	using PFNGLGETVERTEXATTRIBIUIVPROC = void(APIENTRY*)(GLuint index, GLenum pname, GLuint* params);
	using PFNGLGETVERTEXATTRIBPOINTERVPROC = void (APIENTRY*)(GLuint index, GLenum pname, GLvoid** pointer);
	using PFNGLISBUFFERPROC = GLboolean (APIENTRY*)(GLuint buffer);
	using PFNGLMAPBUFFERPROC = void* (APIENTRY*)(GLenum target, GLenum access);
	using PFNGLMAPBUFFERRANGEPROC = void* (APIENTRY*)(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
	using PFNGLMULTIDRAWARRAYSPROC = void (APIENTRY*)(GLenum mode, const GLint* first, const GLsizei* count, GLsizei primcount);
	using PFNGLMULTIDRAWELEMENTSPROC = void (APIENTRY*)(GLenum mode, const GLsizei* count, GLenum type, const GLvoid** indices, GLsizei primcount);
	using PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC = void (APIENTRY*)(GLenum mode, const GLsizei* count, GLenum type, const GLvoid** indices, GLsizei primcount, GLint* basevertex);
	using PFNGLPRIMITIVERESTARTINDEXPROC = void (APIENTRY*)(GLuint index);
	using PFNGLPROVOKINGVERTEXPROC = void (APIENTRY*)(GLenum provokeMode);
	using PFNGLUNMAPBUFFERPROC = void* (APIENTRY*)(GLenum target, GLenum access);
	using PFNGLVERTEXATTRIBPOINTERPROC = void (APIENTRY*)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer);
	using PFNGLVERTEXATTRIBIPOINTERPROC = void (APIENTRY*)(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);
	using PFNGLVERTEXATTRIBDIVISORPROC = void (APIENTRY*)(GLuint index, GLuint divisor);

	using PFNGLVERTEXATTRIB1FPROC = void (APIENTRY*)(GLuint index, GLfloat v0);
	using PFNGLVERTEXATTRIB1SPROC = void (APIENTRY*)(GLuint index, GLshort v0);
	using PFNGLVERTEXATTRIB1DPROC = void (APIENTRY*)(GLuint index, GLdouble v0);
	using PFNGLVERTEXATTRIB1FPROC = void (APIENTRY*)(GLuint index, GLfloat v0);
	using PFNGLVERTEXATTRIBI1IPROC = void (APIENTRY*)(GLuint index, GLint v0);
	using PFNGLVERTEXATTRIBI1UIPROC = void (APIENTRY*)(GLuint index, GLuint v0);

	using PFNGLVERTEXATTRIB2FPROC = void (APIENTRY*)(GLuint index, GLfloat v0, GLfloat v1);
	using PFNGLVERTEXATTRIB2SPROC = void (APIENTRY*)(GLuint index, GLshort v0, GLshort v1);
	using PFNGLVERTEXATTRIB2DPROC = void (APIENTRY*)(GLuint index, GLdouble v0, GLdouble v1);
	using PFNGLVERTEXATTRIB2FPROC = void (APIENTRY*)(GLuint index, GLfloat v0, GLfloat v1);
	using PFNGLVERTEXATTRIBI2IPROC = void (APIENTRY*)(GLuint index, GLint v0, GLint v1);
	using PFNGLVERTEXATTRIBI2UIPROC = void (APIENTRY*)(GLuint index, GLuint v0, GLuint v1);

	using PFNGLVERTEXATTRIB3FPROC = void (APIENTRY*)(GLuint index, GLfloat v0, GLfloat v1, GLfloat v2);
	using PFNGLVERTEXATTRIB3SPROC = void (APIENTRY*)(GLuint index, GLshort v0, GLshort v1, GLshort v2);
	using PFNGLVERTEXATTRIB3DPROC = void (APIENTRY*)(GLuint index, GLdouble v0, GLdouble v1, GLdouble v2);
	using PFNGLVERTEXATTRIB3FPROC = void (APIENTRY*)(GLuint index, GLfloat v0, GLfloat v1, GLfloat v2);
	using PFNGLVERTEXATTRIBI3IPROC = void (APIENTRY*)(GLuint index, GLint v0, GLint v1, GLint v2);
	using PFNGLVERTEXATTRIBI3UIPROC = void (APIENTRY*)(GLuint index, GLuint v0, GLuint v1, GLuint v2); 

	using PFNGLVERTEXATTRIB4FPROC = void (APIENTRY*)(GLuint index, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
	using PFNGLVERTEXATTRIB4SPROC = void (APIENTRY*)(GLuint index, GLshort v0, GLshort v1, GLshort v2, GLshort v3);
	using PFNGLVERTEXATTRIB4DPROC = void (APIENTRY*)(GLuint index, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
	using PFNGLVERTEXATTRIB4FPROC = void (APIENTRY*)(GLuint index, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
	using PFNGLVERTEXATTRIBI4IPROC = void (APIENTRY*)(GLuint index, GLint v0, GLint v1, GLint v2, GLint v3);
	using PFNGLVERTEXATTRIBI4UIPROC = void (APIENTRY*)(GLuint index, GLuint v0, GLuint v1, GLuint v2, GLuint v3); 

	using PFNGLVERTEXATTRIB1FVPROC = void (APIENTRY*)(GLuint index, const GLfloat* v); 
	using PFNGLVERTEXATTRIB1SVPROC = void (APIENTRY*)(GLuint index, const GLshort* v); 
	using PFNGLVERTEXATTRIB1DVPROC = void (APIENTRY*)(GLuint index, const GLdouble* v); 
	using PFNGLVERTEXATTRIBI1IVPROC = void (APIENTRY*)(GLuint index, const GLint* v); 
	using PFNGLVERTEXATTRIBI1UIVPROC = void (APIENTRY*)(GLuint index, const GLuint* v); 

	using PFNGLVERTEXATTRIB2FVPROC = void (APIENTRY*)(GLuint index, const GLfloat* v); 
	using PFNGLVERTEXATTRIB2SVPROC = void (APIENTRY*)(GLuint index, const GLshort* v); 
	using PFNGLVERTEXATTRIB2DVPROC = void (APIENTRY*)(GLuint index, const GLdouble* v); 
	using PFNGLVERTEXATTRIBI2IVPROC = void (APIENTRY*)(GLuint index, const GLint* v); 
	using PFNGLVERTEXATTRIBI2UIVPROC = void (APIENTRY*)(GLuint index, const GLuint* v); 

	using PFNGLVERTEXATTRIB3FVPROC = void (APIENTRY*)(GLuint index, const GLfloat* v); 
	using PFNGLVERTEXATTRIB3SVPROC = void (APIENTRY*)(GLuint index, const GLshort* v); 
	using PFNGLVERTEXATTRIB3DVPROC = void (APIENTRY*)(GLuint index, const GLdouble* v); 
	using PFNGLVERTEXATTRIBI3IVPROC = void (APIENTRY*)(GLuint index, const GLint* v); 
	using PFNGLVERTEXATTRIBI3UIVPROC = void (APIENTRY*)(GLuint index, const GLuint* v); 

	using PFNGLVERTEXATTRIB4FVPROC = void (APIENTRY*)(GLuint index, const GLfloat* v); 
	using PFNGLVERTEXATTRIB4SVPROC = void (APIENTRY*)(GLuint index, const GLshort* v); 
	using PFNGLVERTEXATTRIB4DVPROC = void (APIENTRY*)(GLuint index, const GLdouble* v); 
	using PFNGLVERTEXATTRIBI4IVPROC = void (APIENTRY*)(GLuint index, const GLint* v); 
	using PFNGLVERTEXATTRIBI4UIVPROC = void (APIENTRY*)(GLuint index, const GLuint* v); 

	using PFNGLVERTEXATTRIB4FVPROC = void (APIENTRY*)(GLuint index, const GLfloat* v); 
	using PFNGLVERTEXATTRIB4SVPROC = void (APIENTRY*)(GLuint index, const GLshort* v); 
	using PFNGLVERTEXATTRIB4DVPROC = void (APIENTRY*)(GLuint index, const GLdouble* v); 
	using PFNGLVERTEXATTRIB4IVPROC = void (APIENTRY*)(GLuint index, const GLint* v); 
	using PFNGLVERTEXATTRIB4BVPROC = void (APIENTRY*)(GLuint index, const GLbyte* v); 
	using PFNGLVERTEXATTRIB4UBVPROC = void (APIENTRY*)(GLuint index, const GLubyte* v); 
	using PFNGLVERTEXATTRIB4USVPROC = void (APIENTRY*)(GLuint index, const GLushort* v); 
	using PFNGLVERTEXATTRIB4UIVPROC = void (APIENTRY*)(GLuint index, const GLuint* v); 

	using PFNGLVERTEXATTRIBNBVPROC = void (APIENTRY*)(GLuint index, const GLbyte* v); 
	using PFNGLVERTEXATTRIBNSVPROC = void (APIENTRY*)(GLuint index, const GLshort* v); 
	using PFNGLVERTEXATTRIBNIVPROC = void (APIENTRY*)(GLuint index, const GLint* v); 
	using PFNGLVERTEXATTRIBNUBVPROC = void (APIENTRY*)(GLuint index, const GLubyte* v); 
	using PFNGLVERTEXATTRIBNUSVPROC = void (APIENTRY*)(GLuint index, const GLushort* v); 
	using PFNGLVERTEXATTRIBNUIVPROC = void (APIENTRY*)(GLuint index, const GLuint* v); 
		
	using PFNGLVERTEXATTRIBI4BVPROC = void (APIENTRY*)(GLuint index, const GLbyte* v);
	using PFNGLVERTEXATTRIBI4UBVPROC = void (APIENTRY*)(GLuint index, const GLubyte* v);
	using PFNGLVERTEXATTRIBI4SVPROC = void (APIENTRY*)(GLuint index, const GLshort* v);
	using PFNGLVERTEXATTRIBI4USVPROC = void (APIENTRY*)(GLuint index, const GLushort* v);
	using PFNGLVERTEXATTRIBI4IVPROC = void (APIENTRY*)(GLuint index, const GLint* v);
	using PFNGLVERTEXATTRIBI4UIVPROC = void (APIENTRY*)(GLuint index, const GLuint* v);

	using PFNGLVERTEXATTRIBP1UIPROC = void (APIENTRY*)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
	using PFNGLVERTEXATTRIBP2UIPROC = void (APIENTRY*)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
	using PFNGLVERTEXATTRIBP3UIPROC = void (APIENTRY*)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
	using PFNGLVERTEXATTRIBP4UIPROC = void (APIENTRY*)(GLuint index, GLenum type, GLboolean normalized, GLuint value);

	// STATE MANAGEMENT
	using PFNGLBLENDCOLORPROC = void (APIENTRY*)(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
	using PFNGLBLENDEQUATIONPROC = void (APIENTRY*)(GLenum mode);
	using PFNGLBLENDEQUATIONSEPARATEPROC = void (APIENTRY*)(GLenum modeRGB, GLenum modeAlpha);
	using PFNGLBLENDFUNCSEPARATEPROC = void (APIENTRY*)(GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
	using PFNGLPOINTPARAMETERFPROC = void (APIENTRY*)(GLenum pname, GLfloat param);
	using PFNGLPOINTPARAMETERIPROC = void (APIENTRY*)(GLenum pname, GLint param);
	using PFNGLSAMPLECOVERAGEPROC = void (APIENTRY*)(GLclampf value, GLboolean invert);
	using PFNGLSTENCILFUNCSEPARATEPROC = void (APIENTRY*)(GLenum func, GLint ref, GLuint mask);
	using PFNGLSTENCILMASKSEPARATEPROC = void (APIENTRY*)(GLenum face, GLuint mask);
	using PFNGLSTENCILOPSEPARATEPROC = void (APIENTRY*)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);

	// TRANSFORM FEEDBACK
	using PFNGLBEGINTRANSFORMFEEDBACKPROC = void (APIENTRY*)(GLenum primitiveMode);
	using PFNGLENDTRANSFORMFEEDBACKPROC = void (APIENTRY*)(GLenum primitiveMode);
	using PFNGLGETTRANSFORMFEEDBACKVARYINGPROC = void (APIENTRY*)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum* type, char *name);
	using PFNGLTRANSFORMFEEDBACKVARYINGSPROC = void (APIENTRY*)(GLuint program, GLsizei count, const char** varyings, GLenum bufferMode);

	// UTILITY
	using PFNGLGETMULTISAMPLEPROC = void (APIENTRY*)(GLenum pname, GLuint index, GLfloat* val);

	// QUERIES
	using PFNGLBEGINCONDITIONALRENDERPROC = void (APIENTRY*)(GLenum pname, GLuint index, GLfloat* val);
	using PFNGLBEGINCONDITIONALRENDERPROC = void (APIENTRY*)(GLenum pname, GLuint index, GLfloat* val);
	using PFNGLBEGINQUERYPROC = void (APIENTRY*)(GLenum target, GLuint id);
	using PFNGLDELETEQUERIESPROC = void (APIENTRY*)(GLsizei n, const GLuint* ids);
	using PFNGLENDCONDITIONALRENDERPROC = void (APIENTRY*)(GLuint id, GLenum mode);
	using PFNGLENDQUERYPROC = void (APIENTRY*)(GLenum target, GLuint id);
	using PFNGLGENQUERIESPROC = void (APIENTRY*)(GLsizei n, GLuint* ids);

	using PFNGLGETQUERYOBJECTIVPROC = void (APIENTRY*)(GLuint id, GLenum pname, GLint* params);
	using PFNGLGETQUERYOBJECTUIVPROC = void (APIENTRY*)(GLuint id, GLenum pname, GLuint* params);
	using PFNGLGETQUERYOBJECTI64VPROC = void (APIENTRY*)(GLuint id, GLenum pname, GLint64* params);
	using PFNGLGETQUERYOBJECTUIVPROC = void (APIENTRY*)(GLuint id, GLenum pname, GLuint64* params);
	using PFNGLGETQUERYIVPROC = void (APIENTRY*)(GLenum target, GLenum pname, GLint* params);
	using PFNGLISQUERYPROC = GLboolean (APIENTRY*)(GLuint id);
	using PFNGLQUERYCOUNTERPROC = void (APIENTRY*)(GLuint id, GLenum target);

	// SYNCING -- EXTENSION


	// VERTEX ARRATY OBJECTS
	using PFNGLGENVERTEXARRAYSPROC = void (APIENTRY*)(GLsizei n, GLuint* arrays);
	using PFNGLBINDVERTEXARRAYPROC = void (APIENTRY*)(GLuint array);
	using PFNGLDELETEVERTEXARRAYSPROC = void (APIENTRY*)(GLsizei n, const GLuint* arrays);
	using PFNGLISVERTEXARRAYPROC = GLboolean (APIENTRY*)(GLuint array);

	// SAMPLERS
	using PFNGLBINDSAMPLERPROC = void (APIENTRY*)(GLuint unit, GLuint sampler);
	using PFNGLDELETESAMPLERSPROC = void (APIENTRY*)(GLsizei n, const GLuint* samplers);
	using PFNGLGENSAMPLERSPROC = void (APIENTRY*)(GLsizei n, GLuint* samplers);

	using PFNGLGETSAMPLERPARAMETERFVPROC = void (APIENTRY*)(GLuint sampler, GLenum pname, GLfloat* params);
	using PFNGLGETSAMPLERPARAMETERIVPROC = void (APIENTRY*)(GLuint sampler, GLenum pname, GLint* params);
	using PFNGLGETSAMPLERPARAMETERIIVPROC = void (APIENTRY*)(GLuint sampler, GLenum pname, GLint* params);
	using PFNGLGETSAMPLERPARAMETERIUIVPROC = void (APIENTRY*)(GLuint sampler, GLenum pname, GLuint* params);

	using PFNGLISSAMPLERPROC = GLboolean (APIENTRY*)(GLuint id);

	using PFNGLSAMPLERPARAMETERFPROC = void (APIENTRY*)(GLuint sampler, GLenum pname, GLfloat param);
	using PFNGLSAMPLERPARAMETERIPROC = void (APIENTRY*)(GLuint sampler, GLenum pname, GLint param);
	
	// WGL EXTENSIONS
	using PFNGLCHOOSEPIXELFORMATARBPROC = BOOL(APIENTRY*)(HDC hdc, const int* piAttribIList, const FLOAT* pfAttribFList, UINT nMaxFormats, int* piFormats, UINT* nNumFormats);
	using PFNGLCREATECONTEXTATTRIBSARB = HGLRC(APIENTRY*)(HDC hdc, HGLRC hShareContext, const int* attribList);
}