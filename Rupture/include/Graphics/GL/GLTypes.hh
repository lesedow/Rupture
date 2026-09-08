#pragma once

#include <windows.h>
#include <gl/GL.h>
#include <cstdint>

#pragma comment(lib, "opengl32.lib")

#ifndef APIENTRYP
#define APIENTRYP APIENTRY *
#endif

namespace Rupture::Graphics::GL
{
	// GL 1.0
	using GLvoid = void;
	using GLenum = unsigned int;
	using GLfloat = float;
	using GLint = int;
	using GLsizei = int;
	using GLbitfield = unsigned int;
	using GLdouble = double;
	using GLuint = unsigned int;
	using GLboolean = unsigned char;
	using GLubyte = std::uint8_t;

	#undef GL_DEPTH_BUFFER_BIT
	#undef GL_STENCIL_BUFFER_BIT             
	#undef GL_COLOR_BUFFER_BIT               
	#undef GL_FALSE                          
	#undef GL_TRUE                           
	#undef GL_POINTS                         
	#undef GL_LINES                          
	#undef GL_LINE_LOOP                      
	#undef GL_LINE_STRIP                     
	#undef GL_TRIANGLES                      
	#undef GL_TRIANGLE_STRIP                 
	#undef GL_TRIANGLE_FAN                   
	#undef GL_QUADS                          
	#undef GL_NEVER                          
	#undef GL_LESS                           
	#undef GL_EQUAL                          
	#undef GL_LEQUAL                         
	#undef GL_GREATER                        
	#undef GL_NOTEQUAL                       
	#undef GL_GEQUAL                         
	#undef GL_ALWAYS                         
	#undef GL_ZERO                           
	#undef GL_ONE                            
	#undef GL_SRC_COLOR                      
	#undef GL_ONE_MINUS_SRC_COLOR            
	#undef GL_SRC_ALPHA                      
	#undef GL_ONE_MINUS_SRC_ALPHA            
	#undef GL_DST_ALPHA                      
	#undef GL_ONE_MINUS_DST_ALPHA            
	#undef GL_DST_COLOR                      
	#undef GL_ONE_MINUS_DST_COLOR            
	#undef GL_SRC_ALPHA_SATURATE             
	#undef GL_NONE                           
	#undef GL_FRONT_LEFT                     
	#undef GL_FRONT_RIGHT                    
	#undef GL_BACK_LEFT                      
	#undef GL_BACK_RIGHT                     
	#undef GL_FRONT                          
	#undef GL_BACK                           
	#undef GL_LEFT                           
	#undef GL_RIGHT                          
	#undef GL_FRONT_AND_BACK                 
	#undef GL_NO_ERROR                       
	#undef GL_INVALID_ENUM                   
	#undef GL_INVALID_VALUE                  
	#undef GL_INVALID_OPERATION              
	#undef GL_OUT_OF_MEMORY                  
	#undef GL_CW                             
	#undef GL_CCW                            
	#undef GL_POINT_SIZE                     
	#undef GL_POINT_SIZE_RANGE               
	#undef GL_POINT_SIZE_GRANULARITY         
	#undef GL_LINE_SMOOTH                    
	#undef GL_LINE_WIDTH                     
	#undef GL_LINE_WIDTH_RANGE               
	#undef GL_LINE_WIDTH_GRANULARITY         
	#undef GL_POLYGON_MODE                   
	#undef GL_POLYGON_SMOOTH                 
	#undef GL_CULL_FACE                      
	#undef GL_CULL_FACE_MODE                 
	#undef GL_FRONT_FACE                     
	#undef GL_DEPTH_RANGE                    
	#undef GL_DEPTH_TEST                     
	#undef GL_DEPTH_WRITEMASK                
	#undef GL_DEPTH_CLEAR_VALUE              
	#undef GL_DEPTH_FUNC                     
	#undef GL_STENCIL_TEST                   
	#undef GL_STENCIL_CLEAR_VALUE            
	#undef GL_STENCIL_FUNC                   
	#undef GL_STENCIL_VALUE_MASK             
	#undef GL_STENCIL_FAIL                   
	#undef GL_STENCIL_PASS_DEPTH_FAIL        
	#undef GL_STENCIL_PASS_DEPTH_PASS        
	#undef GL_STENCIL_REF                    
	#undef GL_STENCIL_WRITEMASK              
	#undef GL_VIEWPORT                       
	#undef GL_DITHER                         
	#undef GL_BLEND_DST                      
	#undef GL_BLEND_SRC                      
	#undef GL_BLEND                          
	#undef GL_LOGIC_OP_MODE                  
	#undef GL_DRAW_BUFFER                    
	#undef GL_READ_BUFFER                    
	#undef GL_SCISSOR_BOX                    
	#undef GL_SCISSOR_TEST                   
	#undef GL_COLOR_CLEAR_VALUE              
	#undef GL_COLOR_WRITEMASK                
	#undef GL_DOUBLEBUFFER                   
	#undef GL_STEREO                         
	#undef GL_LINE_SMOOTH_HINT               
	#undef GL_POLYGON_SMOOTH_HINT            
	#undef GL_UNPACK_SWAP_BYTES              
	#undef GL_UNPACK_LSB_FIRST               
	#undef GL_UNPACK_ROW_LENGTH              
	#undef GL_UNPACK_SKIP_ROWS               
	#undef GL_UNPACK_SKIP_PIXELS             
	#undef GL_UNPACK_ALIGNMENT               
	#undef GL_PACK_SWAP_BYTES                
	#undef GL_PACK_LSB_FIRST                 
	#undef GL_PACK_ROW_LENGTH                
	#undef GL_PACK_SKIP_ROWS                 
	#undef GL_PACK_SKIP_PIXELS               
	#undef GL_PACK_ALIGNMENT                 
	#undef GL_MAX_TEXTURE_SIZE               
	#undef GL_MAX_VIEWPORT_DIMS              
	#undef GL_SUBPIXEL_BITS                  
	#undef GL_TEXTURE_1D                     
	#undef GL_TEXTURE_2D                     
	#undef GL_TEXTURE_WIDTH                  
	#undef GL_TEXTURE_HEIGHT                 
	#undef GL_TEXTURE_BORDER_COLOR           
	#undef GL_DONT_CARE                      
	#undef GL_FASTEST                        
	#undef GL_NICEST                         
	#undef GL_BYTE                           
	#undef GL_UNSIGNED_BYTE                  
	#undef GL_SHORT                          
	#undef GL_UNSIGNED_SHORT                 
	#undef GL_INT                            
	#undef GL_UNSIGNED_INT                   
	#undef GL_FLOAT                          
	#undef GL_STACK_OVERFLOW                 
	#undef GL_STACK_UNDERFLOW                
	#undef GL_CLEAR                          
	#undef GL_AND                            
	#undef GL_AND_REVERSE                    
	#undef GL_COPY                           
	#undef GL_AND_INVERTED                   
	#undef GL_NOOP                           
	#undef GL_XOR                            
	#undef GL_OR                             
	#undef GL_NOR                            
	#undef GL_EQUIV                          
	#undef GL_INVERT                         
	#undef GL_OR_REVERSE                     
	#undef GL_COPY_INVERTED                  
	#undef GL_OR_INVERTED                    
	#undef GL_NAND                           
	#undef GL_SET                            
	#undef GL_TEXTURE                        
	#undef GL_COLOR                          
	#undef GL_DEPTH                          
	#undef GL_STENCIL                        
	#undef GL_STENCIL_INDEX                  
	#undef GL_DEPTH_COMPONENT                
	#undef GL_RED                            
	#undef GL_GREEN                          
	#undef GL_BLUE                           
	#undef GL_ALPHA                          
	#undef GL_RGB                            
	#undef GL_RGBA                           
	#undef GL_POINT                          
	#undef GL_LINE                           
	#undef GL_FILL                           
	#undef GL_KEEP                           
	#undef GL_REPLACE                        
	#undef GL_INCR                           
	#undef GL_DECR                           
	#undef GL_VENDOR                         
	#undef GL_RENDERER                       
	#undef GL_VERSION                        
	#undef GL_EXTENSIONS                     
	#undef GL_NEAREST                        
	#undef GL_LINEAR                         
	#undef GL_NEAREST_MIPMAP_NEAREST         
	#undef GL_LINEAR_MIPMAP_NEAREST          
	#undef GL_NEAREST_MIPMAP_LINEAR          
	#undef GL_LINEAR_MIPMAP_LINEAR           
	#undef GL_TEXTURE_MAG_FILTER             
	#undef GL_TEXTURE_MIN_FILTER             
	#undef GL_TEXTURE_WRAP_S                 
	#undef GL_TEXTURE_WRAP_T                 
	#undef GL_REPEAT                         

	constexpr int GL_DEPTH_BUFFER_BIT               = 0x00000100;
	constexpr int GL_STENCIL_BUFFER_BIT             = 0x00000400;
	constexpr int GL_COLOR_BUFFER_BIT               = 0x00004000;
	constexpr int GL_FALSE                          = 0;
	constexpr int GL_TRUE                           = 1;
	constexpr int GL_POINTS                         = 0x0000;
	constexpr int GL_LINES                          = 0x0001;
	constexpr int GL_LINE_LOOP                      = 0x0002;
	constexpr int GL_LINE_STRIP                     = 0x0003;
	constexpr int GL_TRIANGLES                      = 0x0004;
	constexpr int GL_TRIANGLE_STRIP                 = 0x0005;
	constexpr int GL_TRIANGLE_FAN                   = 0x0006;
	constexpr int GL_QUADS                          = 0x0007;
	constexpr int GL_NEVER                          = 0x0200;
	constexpr int GL_LESS                           = 0x0201;
	constexpr int GL_EQUAL                          = 0x0202;
	constexpr int GL_LEQUAL                         = 0x0203;
	constexpr int GL_GREATER                        = 0x0204;
	constexpr int GL_NOTEQUAL                       = 0x0205;
	constexpr int GL_GEQUAL                         = 0x0206;
	constexpr int GL_ALWAYS                         = 0x0207;
	constexpr int GL_ZERO                           = 0;
	constexpr int GL_ONE                            = 1;
	constexpr int GL_SRC_COLOR                      = 0x0300;
	constexpr int GL_ONE_MINUS_SRC_COLOR            = 0x0301;
	constexpr int GL_SRC_ALPHA                      = 0x0302;
	constexpr int GL_ONE_MINUS_SRC_ALPHA            = 0x0303;
	constexpr int GL_DST_ALPHA                      = 0x0304;
	constexpr int GL_ONE_MINUS_DST_ALPHA            = 0x0305;
	constexpr int GL_DST_COLOR                      = 0x0306;
	constexpr int GL_ONE_MINUS_DST_COLOR            = 0x0307;
	constexpr int GL_SRC_ALPHA_SATURATE             = 0x0308;
	constexpr int GL_NONE                           = 0;
	constexpr int GL_FRONT_LEFT                     = 0x0400;
	constexpr int GL_FRONT_RIGHT                    = 0x0401;
	constexpr int GL_BACK_LEFT                      = 0x0402;
	constexpr int GL_BACK_RIGHT                     = 0x0403;
	constexpr int GL_FRONT                          = 0x0404;
	constexpr int GL_BACK                           = 0x0405;
	constexpr int GL_LEFT                           = 0x0406;
	constexpr int GL_RIGHT                          = 0x0407;
	constexpr int GL_FRONT_AND_BACK                 = 0x0408;
	constexpr int GL_NO_ERROR                       = 0;
	constexpr int GL_INVALID_ENUM                   = 0x0500;
	constexpr int GL_INVALID_VALUE                  = 0x0501;
	constexpr int GL_INVALID_OPERATION              = 0x0502;
	constexpr int GL_OUT_OF_MEMORY                  = 0x0505;
	constexpr int GL_CW                             = 0x0900;
	constexpr int GL_CCW                            = 0x0901;
	constexpr int GL_POINT_SIZE                     = 0x0B11;
	constexpr int GL_POINT_SIZE_RANGE               = 0x0B12;
	constexpr int GL_POINT_SIZE_GRANULARITY         = 0x0B13;
	constexpr int GL_LINE_SMOOTH                    = 0x0B20;
	constexpr int GL_LINE_WIDTH                     = 0x0B21;
	constexpr int GL_LINE_WIDTH_RANGE               = 0x0B22;
	constexpr int GL_LINE_WIDTH_GRANULARITY         = 0x0B23;
	constexpr int GL_POLYGON_MODE                   = 0x0B40;
	constexpr int GL_POLYGON_SMOOTH                 = 0x0B41;
	constexpr int GL_CULL_FACE                      = 0x0B44;
	constexpr int GL_CULL_FACE_MODE                 = 0x0B45;
	constexpr int GL_FRONT_FACE                     = 0x0B46;
	constexpr int GL_DEPTH_RANGE                    = 0x0B70;
	constexpr int GL_DEPTH_TEST                     = 0x0B71;
	constexpr int GL_DEPTH_WRITEMASK                = 0x0B72;
	constexpr int GL_DEPTH_CLEAR_VALUE              = 0x0B73;
	constexpr int GL_DEPTH_FUNC                     = 0x0B74;
	constexpr int GL_STENCIL_TEST                   = 0x0B90;
	constexpr int GL_STENCIL_CLEAR_VALUE            = 0x0B91;
	constexpr int GL_STENCIL_FUNC                   = 0x0B92;
	constexpr int GL_STENCIL_VALUE_MASK             = 0x0B93;
	constexpr int GL_STENCIL_FAIL                   = 0x0B94;
	constexpr int GL_STENCIL_PASS_DEPTH_FAIL        = 0x0B95;
	constexpr int GL_STENCIL_PASS_DEPTH_PASS        = 0x0B96;
	constexpr int GL_STENCIL_REF                    = 0x0B97;
	constexpr int GL_STENCIL_WRITEMASK              = 0x0B98;
	constexpr int GL_VIEWPORT                       = 0x0BA2;
	constexpr int GL_DITHER                         = 0x0BD0;
	constexpr int GL_BLEND_DST                      = 0x0BE0;
	constexpr int GL_BLEND_SRC                      = 0x0BE1;
	constexpr int GL_BLEND                          = 0x0BE2;
	constexpr int GL_LOGIC_OP_MODE                  = 0x0BF0;
	constexpr int GL_DRAW_BUFFER                    = 0x0C01;
	constexpr int GL_READ_BUFFER                    = 0x0C02;
	constexpr int GL_SCISSOR_BOX                    = 0x0C10;
	constexpr int GL_SCISSOR_TEST                   = 0x0C11;
	constexpr int GL_COLOR_CLEAR_VALUE              = 0x0C22;
	constexpr int GL_COLOR_WRITEMASK                = 0x0C23;
	constexpr int GL_DOUBLEBUFFER                   = 0x0C32;
	constexpr int GL_STEREO                         = 0x0C33;
	constexpr int GL_LINE_SMOOTH_HINT               = 0x0C52;
	constexpr int GL_POLYGON_SMOOTH_HINT            = 0x0C53;
	constexpr int GL_UNPACK_SWAP_BYTES              = 0x0CF0;
	constexpr int GL_UNPACK_LSB_FIRST               = 0x0CF1;
	constexpr int GL_UNPACK_ROW_LENGTH              = 0x0CF2;
	constexpr int GL_UNPACK_SKIP_ROWS               = 0x0CF3;
	constexpr int GL_UNPACK_SKIP_PIXELS             = 0x0CF4;
	constexpr int GL_UNPACK_ALIGNMENT               = 0x0CF5;
	constexpr int GL_PACK_SWAP_BYTES                = 0x0D00;
	constexpr int GL_PACK_LSB_FIRST                 = 0x0D01;
	constexpr int GL_PACK_ROW_LENGTH                = 0x0D02;
	constexpr int GL_PACK_SKIP_ROWS                 = 0x0D03;
	constexpr int GL_PACK_SKIP_PIXELS               = 0x0D04;
	constexpr int GL_PACK_ALIGNMENT                 = 0x0D05;
	constexpr int GL_MAX_TEXTURE_SIZE               = 0x0D33;
	constexpr int GL_MAX_VIEWPORT_DIMS              = 0x0D3A;
	constexpr int GL_SUBPIXEL_BITS                  = 0x0D50;
	constexpr int GL_TEXTURE_1D                     = 0x0DE0;
	constexpr int GL_TEXTURE_2D                     = 0x0DE1;
	constexpr int GL_TEXTURE_WIDTH                  = 0x1000;
	constexpr int GL_TEXTURE_HEIGHT                 = 0x1001;
	constexpr int GL_TEXTURE_BORDER_COLOR           = 0x1004;
	constexpr int GL_DONT_CARE                      = 0x1100;
	constexpr int GL_FASTEST                        = 0x1101;
	constexpr int GL_NICEST                         = 0x1102;
	constexpr int GL_BYTE                           = 0x1400;
	constexpr int GL_UNSIGNED_BYTE                  = 0x1401;
	constexpr int GL_SHORT                          = 0x1402;
	constexpr int GL_UNSIGNED_SHORT                 = 0x1403;
	constexpr int GL_INT                            = 0x1404;
	constexpr int GL_UNSIGNED_INT                   = 0x1405;
	constexpr int GL_FLOAT                          = 0x1406;
	constexpr int GL_STACK_OVERFLOW                 = 0x0503;
	constexpr int GL_STACK_UNDERFLOW                = 0x0504;
	constexpr int GL_CLEAR                          = 0x1500;
	constexpr int GL_AND                            = 0x1501;
	constexpr int GL_AND_REVERSE                    = 0x1502;
	constexpr int GL_COPY                           = 0x1503;
	constexpr int GL_AND_INVERTED                   = 0x1504;
	constexpr int GL_NOOP                           = 0x1505;
	constexpr int GL_XOR                            = 0x1506;
	constexpr int GL_OR                             = 0x1507;
	constexpr int GL_NOR                            = 0x1508;
	constexpr int GL_EQUIV                          = 0x1509;
	constexpr int GL_INVERT                         = 0x150A;
	constexpr int GL_OR_REVERSE                     = 0x150B;
	constexpr int GL_COPY_INVERTED                  = 0x150C;
	constexpr int GL_OR_INVERTED                    = 0x150D;
	constexpr int GL_NAND                           = 0x150E;
	constexpr int GL_SET                            = 0x150F;
	constexpr int GL_TEXTURE                        = 0x1702;
	constexpr int GL_COLOR                          = 0x1800;
	constexpr int GL_DEPTH                          = 0x1801;
	constexpr int GL_STENCIL                        = 0x1802;
	constexpr int GL_STENCIL_INDEX                  = 0x1901;
	constexpr int GL_DEPTH_COMPONENT                = 0x1902;
	constexpr int GL_RED                            = 0x1903;
	constexpr int GL_GREEN                          = 0x1904;
	constexpr int GL_BLUE                           = 0x1905;
	constexpr int GL_ALPHA                          = 0x1906;
	constexpr int GL_RGB                            = 0x1907;
	constexpr int GL_RGBA                           = 0x1908;
	constexpr int GL_POINT                          = 0x1B00;
	constexpr int GL_LINE                           = 0x1B01;
	constexpr int GL_FILL                           = 0x1B02;
	constexpr int GL_KEEP                           = 0x1E00;
	constexpr int GL_REPLACE                        = 0x1E01;
	constexpr int GL_INCR                           = 0x1E02;
	constexpr int GL_DECR                           = 0x1E03;
	constexpr int GL_VENDOR                         = 0x1F00;
	constexpr int GL_RENDERER                       = 0x1F01;
	constexpr int GL_VERSION                        = 0x1F02;
	constexpr int GL_EXTENSIONS                     = 0x1F03;
	constexpr int GL_NEAREST                        = 0x2600;
	constexpr int GL_LINEAR                         = 0x2601;
	constexpr int GL_NEAREST_MIPMAP_NEAREST         = 0x2700;
	constexpr int GL_LINEAR_MIPMAP_NEAREST          = 0x2701;
	constexpr int GL_NEAREST_MIPMAP_LINEAR          = 0x2702;
	constexpr int GL_LINEAR_MIPMAP_LINEAR           = 0x2703;
	constexpr int GL_TEXTURE_MAG_FILTER             = 0x2800;
	constexpr int GL_TEXTURE_MIN_FILTER             = 0x2801;
	constexpr int GL_TEXTURE_WRAP_S                 = 0x2802;
	constexpr int GL_TEXTURE_WRAP_T                 = 0x2803;
	constexpr int GL_REPEAT                         = 0x2901;

	using PFNGLCULLFACEPROC = void(APIENTRYP) (GLenum mode);
	using PFNGLFRONTFACEPROC = void(APIENTRYP) (GLenum mode);
	using PFNGLHINTPROC = void(APIENTRYP) (GLenum target, GLenum mode);
	using PFNGLLINEWIDTHPROC = void(APIENTRYP) (GLfloat width);
	using PFNGLPOINTSIZEPROC = void(APIENTRYP) (GLfloat size);
	using PFNGLPOLYGONMODEPROC = void(APIENTRYP) (GLenum face, GLenum mode);
	using PFNGLSCISSORPROC = void(APIENTRYP) (GLint x, GLint y, GLsizei width, GLsizei height);
	using PFNGLTEXPARAMETERFPROC = void(APIENTRYP) (GLenum target, GLenum pname, GLfloat param);
	using PFNGLTEXPARAMETERFVPROC = void(APIENTRYP) (GLenum target, GLenum pname, const GLfloat* params);
	using PFNGLTEXPARAMETERIPROC = void(APIENTRYP) (GLenum target, GLenum pname, GLint param);
	using PFNGLTEXPARAMETERIVPROC = void(APIENTRYP) (GLenum target, GLenum pname, const GLint* params);
	using PFNGLTEXIMAGE1DPROC = void(APIENTRYP) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void* pixels);
	using PFNGLTEXIMAGE2DPROC = void(APIENTRYP) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void* pixels);
	using PFNGLDRAWBUFFERPROC = void(APIENTRYP) (GLenum buf);
	using PFNGLCLEARPROC = void(APIENTRYP) (GLbitfield mask);
	using PFNGLCLEARCOLORPROC = void(APIENTRYP) (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
	using PFNGLCLEARSTENCILPROC = void(APIENTRYP) (GLint s);
	using PFNGLCLEARDEPTHPROC = void(APIENTRYP) (GLdouble depth);
	using PFNGLSTENCILMASKPROC = void(APIENTRYP) (GLuint mask);
	using PFNGLCOLORMASKPROC = void(APIENTRYP) (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
	using PFNGLDEPTHMASKPROC = void(APIENTRYP) (GLboolean flag);
	using PFNGLDISABLEPROC = void(APIENTRYP) (GLenum cap);
	using PFNGLENABLEPROC = void(APIENTRYP) (GLenum cap);
	using PFNGLFINISHPROC = void(APIENTRYP) (void);
	using PFNGLFLUSHPROC = void(APIENTRYP) (void);
	using PFNGLBLENDFUNCPROC = void(APIENTRYP) (GLenum sfactor, GLenum dfactor);
	using PFNGLLOGICOPPROC = void(APIENTRYP) (GLenum opcode);
	using PFNGLSTENCILFUNCPROC = void(APIENTRYP) (GLenum func, GLint ref, GLuint mask);
	using PFNGLSTENCILOPPROC = void(APIENTRYP) (GLenum fail, GLenum zfail, GLenum zpass);
	using PFNGLDEPTHFUNCPROC = void(APIENTRYP) (GLenum func);
	using PFNGLPIXELSTOREFPROC = void(APIENTRYP) (GLenum pname, GLfloat param);
	using PFNGLPIXELSTOREIPROC = void(APIENTRYP) (GLenum pname, GLint param);
	using PFNGLREADBUFFERPROC = void(APIENTRYP) (GLenum src);
	using PFNGLREADPIXELSPROC = void(APIENTRYP) (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void* pixels);
	using PFNGLGETBOOLEANVPROC = void(APIENTRYP) (GLenum pname, GLboolean* data);
	using PFNGLGETDOUBLEVPROC = void (APIENTRYP ) (GLenum pname, GLdouble* data);
	using PFNGLGETERRORPROC = GLenum(APIENTRYP ) (void);
	using PFNGLGETFLOATVPROC = void(APIENTRYP) (GLenum pname, GLfloat* data);
	using PFNGLGETINTEGERVPROC = void (APIENTRYP ) (GLenum pname, GLint* data);
	using PFNGLGETSTRINGPROC = const GLubyte* (APIENTRYP ) (GLenum name);
	using PFNGLGETTEXIMAGEPROC = void(APIENTRYP) (GLenum target, GLint level, GLenum format, GLenum type, void* pixels);
	using PFNGLGETTEXPARAMETERFVPROC = void(APIENTRYP) (GLenum target, GLenum pname, GLfloat* params);
	using PFNGLGETTEXPARAMETERIVPROC = void(APIENTRYP) (GLenum target, GLenum pname, GLint* params);
	using PFNGLGETTEXLEVELPARAMETERFVPROC = void(APIENTRYP) (GLenum target, GLint level, GLenum pname, GLfloat* params);
	using PFNGLGETTEXLEVELPARAMETERIVPROC = void (APIENTRYP ) (GLenum target, GLint level, GLenum pname, GLint* params);
	using PFNGLISENABLEDPROC = GLboolean(APIENTRYP ) (GLenum cap);
	using PFNGLDEPTHRANGEPROC = void(APIENTRYP) (GLdouble n, GLdouble f);
	using PFNGLVIEWPORTPROC = void (APIENTRYP ) (GLint x, GLint y, GLsizei width, GLsizei height);

	// GL 1.1
	using GLclampf = float;
	using GLclampd = double;

	#undef GL_COLOR_LOGIC_OP                 
	#undef GL_POLYGON_OFFSET_UNITS           
	#undef GL_POLYGON_OFFSET_POINT           
	#undef GL_POLYGON_OFFSET_LINE            
	#undef GL_POLYGON_OFFSET_FILL            
	#undef GL_POLYGON_OFFSET_FACTOR          
	#undef GL_TEXTURE_BINDING_1D             
	#undef GL_TEXTURE_BINDING_2D             
	#undef GL_TEXTURE_INTERNAL_FORMAT        
	#undef GL_TEXTURE_RED_SIZE               
	#undef GL_TEXTURE_GREEN_SIZE             
	#undef GL_TEXTURE_BLUE_SIZE              
	#undef GL_TEXTURE_ALPHA_SIZE             
	#undef GL_DOUBLE                         
	#undef GL_PROXY_TEXTURE_1D               
	#undef GL_PROXY_TEXTURE_2D               
	#undef GL_R3_G3_B2                       
	#undef GL_RGB4                           
	#undef GL_RGB5                           
	#undef GL_RGB8                           
	#undef GL_RGB10                          
	#undef GL_RGB12                          
	#undef GL_RGB16                          
	#undef GL_RGBA2                          
	#undef GL_RGBA4                          
	#undef GL_RGB5_A1                        
	#undef GL_RGBA8                          
	#undef GL_RGB10_A2                       
	#undef GL_RGBA12                         
	#undef GL_RGBA16                         
	#undef GL_VERTEX_ARRAY   

	constexpr int GL_COLOR_LOGIC_OP                 = 0x0BF2;
	constexpr int GL_POLYGON_OFFSET_UNITS           = 0x2A00;
	constexpr int GL_POLYGON_OFFSET_POINT           = 0x2A01;
	constexpr int GL_POLYGON_OFFSET_LINE            = 0x2A02;
	constexpr int GL_POLYGON_OFFSET_FILL            = 0x8037;
	constexpr int GL_POLYGON_OFFSET_FACTOR          = 0x8038;
	constexpr int GL_TEXTURE_BINDING_1D             = 0x8068;
	constexpr int GL_TEXTURE_BINDING_2D             = 0x8069;
	constexpr int GL_TEXTURE_INTERNAL_FORMAT        = 0x1003;
	constexpr int GL_TEXTURE_RED_SIZE               = 0x805C;
	constexpr int GL_TEXTURE_GREEN_SIZE             = 0x805D;
	constexpr int GL_TEXTURE_BLUE_SIZE              = 0x805E;
	constexpr int GL_TEXTURE_ALPHA_SIZE             = 0x805F;
	constexpr int GL_DOUBLE                         = 0x140A;
	constexpr int GL_PROXY_TEXTURE_1D               = 0x8063;
	constexpr int GL_PROXY_TEXTURE_2D               = 0x8064;
	constexpr int GL_R3_G3_B2                       = 0x2A10;
	constexpr int GL_RGB4                           = 0x804F;
	constexpr int GL_RGB5                           = 0x8050;
	constexpr int GL_RGB8                           = 0x8051;
	constexpr int GL_RGB10                          = 0x8052;
	constexpr int GL_RGB12                          = 0x8053;
	constexpr int GL_RGB16                          = 0x8054;
	constexpr int GL_RGBA2                          = 0x8055;
	constexpr int GL_RGBA4                          = 0x8056;
	constexpr int GL_RGB5_A1                        = 0x8057;
	constexpr int GL_RGBA8                          = 0x8058;
	constexpr int GL_RGB10_A2                       = 0x8059;
	constexpr int GL_RGBA12                         = 0x805A;
	constexpr int GL_RGBA16                         = 0x805B;
	constexpr int GL_VERTEX_ARRAY                   = 0x8074;

	using PFNGLDRAWARRAYSPROC = void(APIENTRYP) (GLenum mode, GLint first, GLsizei count);
	using PFNGLDRAWELEMENTSPROC = void(APIENTRYP) (GLenum mode, GLsizei count, GLenum type, const void* indices);
	using PFNGLGETPOINTERVPROC = void(APIENTRYP) (GLenum pname, void** params);
	using PFNGLPOLYGONOFFSETPROC = void(APIENTRYP) (GLfloat factor, GLfloat units);
	using PFNGLCOPYTEXIMAGE1DPROC = void(APIENTRYP) (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
	using PFNGLCOPYTEXIMAGE2DPROC = void(APIENTRYP) (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
	using PFNGLCOPYTEXSUBIMAGE1DPROC = void(APIENTRYP) (GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
	using PFNGLCOPYTEXSUBIMAGE2DPROC = void(APIENTRYP) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
	using PFNGLTEXSUBIMAGE1DPROC = void(APIENTRYP) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels);
	using PFNGLTEXSUBIMAGE2DPROC = void(APIENTRYP) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels);
	using PFNGLBINDTEXTUREPROC = void(APIENTRYP) (GLenum target, GLuint texture);
	using PFNGLDELETETEXTURESPROC = void(APIENTRYP) (GLsizei n, const GLuint* textures);
	using PFNGLGENTEXTURESPROC = void (APIENTRYP ) (GLsizei n, GLuint* textures);
	using PFNGLISTEXTUREPROC = GLboolean(APIENTRYP ) (GLuint texture);

	// GL 1.2
	constexpr int GL_UNSIGNED_BYTE_3_3_2            = 0x8032;
	constexpr int GL_UNSIGNED_SHORT_4_4_4_4         = 0x8033;
	constexpr int GL_UNSIGNED_SHORT_5_5_5_1         = 0x8034;
	constexpr int GL_UNSIGNED_INT_8_8_8_8           = 0x8035;
	constexpr int GL_UNSIGNED_INT_10_10_10_2        = 0x8036;
	constexpr int GL_TEXTURE_BINDING_3D             = 0x806A;
	constexpr int GL_PACK_SKIP_IMAGES               = 0x806B;
	constexpr int GL_PACK_IMAGE_HEIGHT              = 0x806C;
	constexpr int GL_UNPACK_SKIP_IMAGES             = 0x806D;
	constexpr int GL_UNPACK_IMAGE_HEIGHT            = 0x806E;
	constexpr int GL_TEXTURE_3D                     = 0x806F;
	constexpr int GL_PROXY_TEXTURE_3D               = 0x8070;
	constexpr int GL_TEXTURE_DEPTH                  = 0x8071;
	constexpr int GL_TEXTURE_WRAP_R                 = 0x8072;
	constexpr int GL_MAX_3D_TEXTURE_SIZE            = 0x8073;
	constexpr int GL_UNSIGNED_BYTE_2_3_3_REV        = 0x8362;
	constexpr int GL_UNSIGNED_SHORT_5_6_5           = 0x8363;
	constexpr int GL_UNSIGNED_SHORT_5_6_5_REV       = 0x8364;
	constexpr int GL_UNSIGNED_SHORT_4_4_4_4_REV     = 0x8365;
	constexpr int GL_UNSIGNED_SHORT_1_5_5_5_REV     = 0x8366;
	constexpr int GL_UNSIGNED_INT_8_8_8_8_REV       = 0x8367;
	constexpr int GL_UNSIGNED_INT_2_10_10_10_REV    = 0x8368;
	constexpr int GL_BGR                            = 0x80E0;
	constexpr int GL_BGRA                           = 0x80E1;
	constexpr int GL_MAX_ELEMENTS_VERTICES          = 0x80E8;
	constexpr int GL_MAX_ELEMENTS_INDICES           = 0x80E9;
	constexpr int GL_CLAMP_TO_EDGE                  = 0x812F;
	constexpr int GL_TEXTURE_MIN_LOD                = 0x813A;
	constexpr int GL_TEXTURE_MAX_LOD                = 0x813B;
	constexpr int GL_TEXTURE_BASE_LEVEL             = 0x813C;
	constexpr int GL_TEXTURE_MAX_LEVEL              = 0x813D;
	constexpr int GL_SMOOTH_POINT_SIZE_RANGE        = 0x0B12;
	constexpr int GL_SMOOTH_POINT_SIZE_GRANULARITY  = 0x0B13;
	constexpr int GL_SMOOTH_LINE_WIDTH_RANGE        = 0x0B22;
	constexpr int GL_SMOOTH_LINE_WIDTH_GRANULARITY  = 0x0B23;
	constexpr int GL_ALIASED_LINE_WIDTH_RANGE       = 0x846E;

	using PFNGLDRAWRANGEELEMENTSPROC = void(APIENTRYP) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices);
	using PFNGLTEXIMAGE3DPROC = void(APIENTRYP) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void* pixels);
	using PFNGLTEXSUBIMAGE3DPROC = void(APIENTRYP) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels);
	using PFNGLCOPYTEXSUBIMAGE3DPROC = void (APIENTRYP ) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);

	// GL 1.3
	constexpr int GL_TEXTURE0                       = 0x84C0;
	constexpr int GL_TEXTURE1                       = 0x84C1;
	constexpr int GL_TEXTURE2                       = 0x84C2;
	constexpr int GL_TEXTURE3                       = 0x84C3;
	constexpr int GL_TEXTURE4                       = 0x84C4;
	constexpr int GL_TEXTURE5                       = 0x84C5;
	constexpr int GL_TEXTURE6                       = 0x84C6;
	constexpr int GL_TEXTURE7                       = 0x84C7;
	constexpr int GL_TEXTURE8                       = 0x84C8;
	constexpr int GL_TEXTURE9                       = 0x84C9;
	constexpr int GL_TEXTURE10                      = 0x84CA;
	constexpr int GL_TEXTURE11                      = 0x84CB;
	constexpr int GL_TEXTURE12                      = 0x84CC;
	constexpr int GL_TEXTURE13                      = 0x84CD;
	constexpr int GL_TEXTURE14                      = 0x84CE;
	constexpr int GL_TEXTURE15                      = 0x84CF;
	constexpr int GL_TEXTURE16                      = 0x84D0;
	constexpr int GL_TEXTURE17                      = 0x84D1;
	constexpr int GL_TEXTURE18                      = 0x84D2;
	constexpr int GL_TEXTURE19                      = 0x84D3;
	constexpr int GL_TEXTURE20                      = 0x84D4;
	constexpr int GL_TEXTURE21                      = 0x84D5;
	constexpr int GL_TEXTURE22                      = 0x84D6;
	constexpr int GL_TEXTURE23                      = 0x84D7;
	constexpr int GL_TEXTURE24                      = 0x84D8;
	constexpr int GL_TEXTURE25                      = 0x84D9;
	constexpr int GL_TEXTURE26                      = 0x84DA;
	constexpr int GL_TEXTURE27                      = 0x84DB;
	constexpr int GL_TEXTURE28                      = 0x84DC;
	constexpr int GL_TEXTURE29                      = 0x84DD;
	constexpr int GL_TEXTURE30                      = 0x84DE;
	constexpr int GL_TEXTURE31                      = 0x84DF;
	constexpr int GL_ACTIVE_TEXTURE                 = 0x84E0;
	constexpr int GL_MULTISAMPLE                    = 0x809D;
	constexpr int GL_SAMPLE_ALPHA_TO_COVERAGE       = 0x809E;
	constexpr int GL_SAMPLE_ALPHA_TO_ONE            = 0x809F;
	constexpr int GL_SAMPLE_COVERAGE                = 0x80A0;
	constexpr int GL_SAMPLE_BUFFERS                 = 0x80A8;
	constexpr int GL_SAMPLES                        = 0x80A9;
	constexpr int GL_SAMPLE_COVERAGE_VALUE          = 0x80AA;
	constexpr int GL_SAMPLE_COVERAGE_INVERT         = 0x80AB;
	constexpr int GL_TEXTURE_CUBE_MAP               = 0x8513;
	constexpr int GL_TEXTURE_BINDING_CUBE_MAP       = 0x8514;
	constexpr int GL_TEXTURE_CUBE_MAP_POSITIVE_X    = 0x8515;
	constexpr int GL_TEXTURE_CUBE_MAP_NEGATIVE_X    = 0x8516;
	constexpr int GL_TEXTURE_CUBE_MAP_POSITIVE_Y    = 0x8517;
	constexpr int GL_TEXTURE_CUBE_MAP_NEGATIVE_Y    = 0x8518;
	constexpr int GL_TEXTURE_CUBE_MAP_POSITIVE_Z    = 0x8519;
	constexpr int GL_TEXTURE_CUBE_MAP_NEGATIVE_Z    = 0x851A;
	constexpr int GL_PROXY_TEXTURE_CUBE_MAP         = 0x851B;
	constexpr int GL_MAX_CUBE_MAP_TEXTURE_SIZE      = 0x851C;
	constexpr int GL_COMPRESSED_RGB                 = 0x84ED;
	constexpr int GL_COMPRESSED_RGBA                = 0x84EE;
	constexpr int GL_TEXTURE_COMPRESSION_HINT       = 0x84EF;
	constexpr int GL_TEXTURE_COMPRESSED_IMAGE_SIZE  = 0x86A0;
	constexpr int GL_TEXTURE_COMPRESSED             = 0x86A1;
	constexpr int GL_NUM_COMPRESSED_TEXTURE_FORMATS = 0x86A2;
	constexpr int GL_COMPRESSED_TEXTURE_FORMATS     = 0x86A3;
	constexpr int GL_CLAMP_TO_BORDER                = 0x812D;

	using PFNGLACTIVETEXTUREPROC = void(APIENTRYP) (GLenum texture);
	using PFNGLSAMPLECOVERAGEPROC = void(APIENTRYP) (GLfloat value, GLboolean invert);
	using PFNGLCOMPRESSEDTEXIMAGE3DPROC = void(APIENTRYP) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void* data);
	using PFNGLCOMPRESSEDTEXIMAGE2DPROC = void(APIENTRYP) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void* data);
	using PFNGLCOMPRESSEDTEXIMAGE1DPROC = void(APIENTRYP) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void* data);
	using PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC = void(APIENTRYP) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data);
	using PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC = void(APIENTRYP) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data);
	using PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC = void(APIENTRYP) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data);
	using PFNGLGETCOMPRESSEDTEXIMAGEPROC = void (APIENTRYP ) (GLenum target, GLint level, void* img);

	// GL 1.4
	constexpr int GL_BLEND_DST_RGB                  = 0x80C8;
	constexpr int GL_BLEND_SRC_RGB                  = 0x80C9;
	constexpr int GL_BLEND_DST_ALPHA                = 0x80CA;
	constexpr int GL_BLEND_SRC_ALPHA                = 0x80CB;
	constexpr int GL_POINT_FADE_THRESHOLD_SIZE      = 0x8128;
	constexpr int GL_DEPTH_COMPONENT16              = 0x81A5;
	constexpr int GL_DEPTH_COMPONENT24              = 0x81A6;
	constexpr int GL_DEPTH_COMPONENT32              = 0x81A7;
	constexpr int GL_MIRRORED_REPEAT                = 0x8370;
	constexpr int GL_MAX_TEXTURE_LOD_BIAS           = 0x84FD;
	constexpr int GL_TEXTURE_LOD_BIAS               = 0x8501;
	constexpr int GL_INCR_WRAP                      = 0x8507;
	constexpr int GL_DECR_WRAP                      = 0x8508;
	constexpr int GL_TEXTURE_DEPTH_SIZE             = 0x884A;
	constexpr int GL_TEXTURE_COMPARE_MODE           = 0x884C;
	constexpr int GL_TEXTURE_COMPARE_FUNC           = 0x884D;
	constexpr int GL_BLEND_COLOR                    = 0x8005;
	constexpr int GL_BLEND_EQUATION                 = 0x8009;
	constexpr int GL_CONSTANT_COLOR                 = 0x8001;
	constexpr int GL_ONE_MINUS_CONSTANT_COLOR       = 0x8002;
	constexpr int GL_CONSTANT_ALPHA                 = 0x8003;
	constexpr int GL_ONE_MINUS_CONSTANT_ALPHA       = 0x8004;
	constexpr int GL_FUNC_ADD                       = 0x8006;
	constexpr int GL_FUNC_REVERSE_SUBTRACT          = 0x800B;
	constexpr int GL_FUNC_SUBTRACT                  = 0x800A;
	constexpr int GL_MIN                            = 0x8007;
	constexpr int GL_MAX                            = 0x8008;

	using PFNGLBLENDFUNCSEPARATEPROC = void(APIENTRYP) (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
	using PFNGLMULTIDRAWARRAYSPROC = void(APIENTRYP) (GLenum mode, const GLint* first, const GLsizei* count, GLsizei drawcount);
	using PFNGLMULTIDRAWELEMENTSPROC = void(APIENTRYP) (GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei drawcount);
	using PFNGLPOINTPARAMETERFPROC = void(APIENTRYP) (GLenum pname, GLfloat param);
	using PFNGLPOINTPARAMETERFVPROC = void(APIENTRYP) (GLenum pname, const GLfloat* params);
	using PFNGLPOINTPARAMETERIPROC = void(APIENTRYP) (GLenum pname, GLint param);
	using PFNGLPOINTPARAMETERIVPROC = void(APIENTRYP) (GLenum pname, const GLint* params);
	using PFNGLBLENDCOLORPROC = void(APIENTRYP) (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
	using PFNGLBLENDEQUATIONPROC = void (APIENTRYP ) (GLenum mode);

	// GL 1.5
	using GLsizeiptr = std::intptr_t;
	using GLintptr = std::intptr_t;

	constexpr int GL_BUFFER_SIZE						= 0x8764;
	constexpr int GL_BUFFER_USAGE						= 0x8765;
	constexpr int GL_QUERY_COUNTER_BITS					= 0x8864;
	constexpr int GL_CURRENT_QUERY						= 0x8865;
	constexpr int GL_QUERY_RESULT						= 0x8866;
	constexpr int GL_QUERY_RESULT_AVAILABLE				= 0x8867;
	constexpr int GL_ARRAY_BUFFER						= 0x8892;
	constexpr int GL_ELEMENT_ARRAY_BUFFER				= 0x8893;
	constexpr int GL_ARRAY_BUFFER_BINDING				= 0x8894;
	constexpr int GL_ELEMENT_ARRAY_BUFFER_BINDING		= 0x8895;
	constexpr int GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING = 0x889F;
	constexpr int GL_READ_ONLY							= 0x88B8;
	constexpr int GL_WRITE_ONLY							= 0x88B9;
	constexpr int GL_READ_WRITE							= 0x88BA;
	constexpr int GL_BUFFER_ACCESS						= 0x88BB;
	constexpr int GL_BUFFER_MAPPED						= 0x88BC;
	constexpr int GL_BUFFER_MAP_POINTER					= 0x88BD;
	constexpr int GL_STREAM_DRAW						= 0x88E0;
	constexpr int GL_STREAM_READ						= 0x88E1;
	constexpr int GL_STREAM_COPY						= 0x88E2;
	constexpr int GL_STATIC_DRAW						= 0x88E4;
	constexpr int GL_STATIC_READ						= 0x88E5;
	constexpr int GL_STATIC_COPY						= 0x88E6;
	constexpr int GL_DYNAMIC_DRAW						= 0x88E8;
	constexpr int GL_DYNAMIC_READ						= 0x88E9;
	constexpr int GL_DYNAMIC_COPY						= 0x88EA;
	constexpr int GL_SAMPLES_PASSED						= 0x8914;
	constexpr int GL_SRC1_ALPHA							= 0x8589;

	using PFNGLGENQUERIESPROC = void(APIENTRYP) (GLsizei n, GLuint* ids);
	using PFNGLDELETEQUERIESPROC = void(APIENTRYP) (GLsizei n, const GLuint* ids);
	using PFNGLISQUERYPROC = GLboolean(APIENTRYP) (GLuint id);
	using PFNGLBEGINQUERYPROC = void(APIENTRYP) (GLenum target, GLuint id);
	using PFNGLENDQUERYPROC = void(APIENTRYP) (GLenum target);
	using PFNGLGETQUERYIVPROC = void(APIENTRYP) (GLenum target, GLenum pname, GLint* params);
	using PFNGLGETQUERYOBJECTIVPROC = void(APIENTRYP) (GLuint id, GLenum pname, GLint* params);
	using PFNGLGETQUERYOBJECTUIVPROC = void(APIENTRYP) (GLuint id, GLenum pname, GLuint* params);
	using PFNGLBINDBUFFERPROC = void(APIENTRYP) (GLenum target, GLuint buffer);
	using PFNGLDELETEBUFFERSPROC = void(APIENTRYP) (GLsizei n, const GLuint* buffers);
	using PFNGLGENBUFFERSPROC = void(APIENTRYP) (GLsizei n, GLuint* buffers);
	using PFNGLISBUFFERPROC = GLboolean(APIENTRYP) (GLuint buffer);
	using PFNGLBUFFERDATAPROC = void(APIENTRYP) (GLenum target, GLsizeiptr size, const void* data, GLenum usage);
	using PFNGLBUFFERSUBDATAPROC = void(APIENTRYP) (GLenum target, GLintptr offset, GLsizeiptr size, const void* data);
	using PFNGLGETBUFFERSUBDATAPROC = void(APIENTRYP) (GLenum target, GLintptr offset, GLsizeiptr size, void* data);
	using PFNGLMAPBUFFERPROC = void* (APIENTRYP)(GLenum target, GLenum access);
	using PFNGLUNMAPBUFFERPROC = GLboolean(APIENTRYP) (GLenum target);
	using PFNGLGETBUFFERPARAMETERIVPROC = void(APIENTRYP) (GLenum target, GLenum pname, GLint* params);
	using PFNGLGETBUFFERPOINTERVPROC = void (APIENTRYP ) (GLenum target, GLenum pname, void** params);

	// GL 2.0
	using GLchar = char;
	using GLshort = std::int16_t;
	using GLbyte = std::uint8_t;
	using GLushort = std::uint16_t;

	constexpr int GL_BLEND_EQUATION_RGB					= 0x8009;
	constexpr int GL_VERTEX_ATTRIB_ARRAY_ENABLED		= 0x8622;
	constexpr int GL_VERTEX_ATTRIB_ARRAY_SIZE			= 0x8623;
	constexpr int GL_VERTEX_ATTRIB_ARRAY_STRIDE			= 0x8624;
	constexpr int GL_VERTEX_ATTRIB_ARRAY_TYPE			= 0x8625;
	constexpr int GL_CURRENT_VERTEX_ATTRIB				= 0x8626;
	constexpr int GL_VERTEX_PROGRAM_POINT_SIZE			= 0x8642;
	constexpr int GL_VERTEX_ATTRIB_ARRAY_POINTER		= 0x8645;
	constexpr int GL_STENCIL_BACK_FUNC					= 0x8800;
	constexpr int GL_STENCIL_BACK_FAIL					= 0x8801;
	constexpr int GL_STENCIL_BACK_PASS_DEPTH_FAIL		= 0x8802;
	constexpr int GL_STENCIL_BACK_PASS_DEPTH_PASS		= 0x8803;
	constexpr int GL_MAX_DRAW_BUFFERS					= 0x8824;
	constexpr int GL_DRAW_BUFFER0						= 0x8825;
	constexpr int GL_DRAW_BUFFER1						= 0x8826;
	constexpr int GL_DRAW_BUFFER2						= 0x8827;
	constexpr int GL_DRAW_BUFFER3						= 0x8828;
	constexpr int GL_DRAW_BUFFER4						= 0x8829;
	constexpr int GL_DRAW_BUFFER5						= 0x882A;
	constexpr int GL_DRAW_BUFFER6						= 0x882B;
	constexpr int GL_DRAW_BUFFER7						= 0x882C;
	constexpr int GL_DRAW_BUFFER8						= 0x882D;
	constexpr int GL_DRAW_BUFFER9						= 0x882E;
	constexpr int GL_DRAW_BUFFER10						= 0x882F;
	constexpr int GL_DRAW_BUFFER11						= 0x8830;
	constexpr int GL_DRAW_BUFFER12						= 0x8831;
	constexpr int GL_DRAW_BUFFER13						= 0x8832;
	constexpr int GL_DRAW_BUFFER14						= 0x8833;
	constexpr int GL_DRAW_BUFFER15						= 0x8834;
	constexpr int GL_BLEND_EQUATION_ALPHA				= 0x883D;
	constexpr int GL_MAX_VERTEX_ATTRIBS					= 0x8869;
	constexpr int GL_VERTEX_ATTRIB_ARRAY_NORMALIZED		= 0x886A;
	constexpr int GL_MAX_TEXTURE_IMAGE_UNITS			= 0x8872;
	constexpr int GL_FRAGMENT_SHADER					= 0x8B30;
	constexpr int GL_VERTEX_SHADER						= 0x8B31;
	constexpr int GL_MAX_FRAGMENT_UNIFORM_COMPONENTS	= 0x8B49;
	constexpr int GL_MAX_VERTEX_UNIFORM_COMPONENTS		= 0x8B4A;
	constexpr int GL_MAX_VARYING_FLOATS					= 0x8B4B;
	constexpr int GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS		= 0x8B4C;
	constexpr int GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS	= 0x8B4D;
	constexpr int GL_SHADER_TYPE						= 0x8B4F;
	constexpr int GL_FLOAT_VEC2							= 0x8B50;
	constexpr int GL_FLOAT_VEC3							= 0x8B51;
	constexpr int GL_FLOAT_VEC4							= 0x8B52;
	constexpr int GL_INT_VEC2							= 0x8B53;
	constexpr int GL_INT_VEC3							= 0x8B54;
	constexpr int GL_INT_VEC4							= 0x8B55;
	constexpr int GL_BOOL								= 0x8B56;
	constexpr int GL_BOOL_VEC2							= 0x8B57;
	constexpr int GL_BOOL_VEC3							= 0x8B58;
	constexpr int GL_BOOL_VEC4							= 0x8B59;
	constexpr int GL_FLOAT_MAT2							= 0x8B5A;
	constexpr int GL_FLOAT_MAT3							= 0x8B5B;
	constexpr int GL_FLOAT_MAT4							= 0x8B5C;
	constexpr int GL_SAMPLER_1D							= 0x8B5D;
	constexpr int GL_SAMPLER_2D							= 0x8B5E;
	constexpr int GL_SAMPLER_3D							= 0x8B5F;
	constexpr int GL_SAMPLER_CUBE						= 0x8B60;
	constexpr int GL_SAMPLER_1D_SHADOW					= 0x8B61;
	constexpr int GL_SAMPLER_2D_SHADOW					= 0x8B62;
	constexpr int GL_DELETE_STATUS						= 0x8B80;
	constexpr int GL_COMPILE_STATUS						= 0x8B81;
	constexpr int GL_LINK_STATUS						= 0x8B82;
	constexpr int GL_VALIDATE_STATUS					= 0x8B83;
	constexpr int GL_INFO_LOG_LENGTH					= 0x8B84;
	constexpr int GL_ATTACHED_SHADERS					= 0x8B85;
	constexpr int GL_ACTIVE_UNIFORMS					= 0x8B86;
	constexpr int GL_ACTIVE_UNIFORM_MAX_LENGTH			= 0x8B87;
	constexpr int GL_SHADER_SOURCE_LENGTH				= 0x8B88;
	constexpr int GL_ACTIVE_ATTRIBUTES					= 0x8B89;
	constexpr int GL_ACTIVE_ATTRIBUTE_MAX_LENGTH		= 0x8B8A;
	constexpr int GL_FRAGMENT_SHADER_DERIVATIVE_HINT	= 0x8B8B;
	constexpr int GL_SHADING_LANGUAGE_VERSION			= 0x8B8C;
	constexpr int GL_CURRENT_PROGRAM					= 0x8B8D;
	constexpr int GL_POINT_SPRITE_COORD_ORIGIN			= 0x8CA0;
	constexpr int GL_LOWER_LEFT							= 0x8CA1;
	constexpr int GL_UPPER_LEFT							= 0x8CA2;
	constexpr int GL_STENCIL_BACK_REF					= 0x8CA3;
	constexpr int GL_STENCIL_BACK_VALUE_MASK			= 0x8CA4;
	constexpr int GL_STENCIL_BACK_WRITEMASK				= 0x8CA5;

	using PFNGLBLENDEQUATIONSEPARATEPROC = void(APIENTRYP) (GLenum modeRGB, GLenum modeAlpha);
	using PFNGLDRAWBUFFERSPROC = void(APIENTRYP) (GLsizei n, const GLenum* bufs);
	using PFNGLSTENCILOPSEPARATEPROC = void(APIENTRYP) (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
	using PFNGLSTENCILFUNCSEPARATEPROC = void(APIENTRYP) (GLenum face, GLenum func, GLint ref, GLuint mask);
	using PFNGLSTENCILMASKSEPARATEPROC = void(APIENTRYP) (GLenum face, GLuint mask);
	using PFNGLATTACHSHADERPROC = void(APIENTRYP) (GLuint program, GLuint shader);
	using PFNGLBINDATTRIBLOCATIONPROC = void(APIENTRYP) (GLuint program, GLuint index, const GLchar* name);
	using PFNGLCOMPILESHADERPROC = void (APIENTRYP ) (GLuint shader);
	using PFNGLCREATEPROGRAMPROC = GLuint(APIENTRYP) (void);
	using PFNGLCREATESHADERPROC = GLuint(APIENTRYP ) (GLenum type);
	using PFNGLDELETEPROGRAMPROC = void(APIENTRYP) (GLuint program);
	using PFNGLDELETESHADERPROC = void(APIENTRYP) (GLuint shader);
	using PFNGLDETACHSHADERPROC = void(APIENTRYP) (GLuint program, GLuint shader);
	using PFNGLDISABLEVERTEXATTRIBARRAYPROC = void(APIENTRYP) (GLuint index);
	using PFNGLENABLEVERTEXATTRIBARRAYPROC = void(APIENTRYP) (GLuint index);
	using PFNGLGETACTIVEATTRIBPROC = void(APIENTRYP) (GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name);
	using PFNGLGETACTIVEUNIFORMPROC = void(APIENTRYP) (GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name);
	using PFNGLGETATTACHEDSHADERSPROC = void(APIENTRYP) (GLuint program, GLsizei maxCount, GLsizei* count, GLuint* shaders);
	using PFNGLGETATTRIBLOCATIONPROC = GLint(APIENTRYP) (GLuint program, const GLchar* name);
	using PFNGLGETPROGRAMIVPROC = void(APIENTRYP) (GLuint program, GLenum pname, GLint* params);
	using PFNGLGETPROGRAMINFOLOGPROC = void(APIENTRYP) (GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
	using PFNGLGETSHADERIVPROC = void(APIENTRYP) (GLuint shader, GLenum pname, GLint* params);
	using PFNGLGETSHADERINFOLOGPROC = void(APIENTRYP) (GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
	using PFNGLGETSHADERSOURCEPROC = void(APIENTRYP) (GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* source);
	using PFNGLGETUNIFORMLOCATIONPROC = GLint(APIENTRYP) (GLuint program, const GLchar* name);
	using PFNGLGETUNIFORMFVPROC = void(APIENTRYP) (GLuint program, GLint location, GLfloat* params);
	using PFNGLGETUNIFORMIVPROC = void(APIENTRYP) (GLuint program, GLint location, GLint* params);
	using PFNGLGETVERTEXATTRIBDVPROC = void(APIENTRYP) (GLuint index, GLenum pname, GLdouble* params);
	using PFNGLGETVERTEXATTRIBFVPROC = void(APIENTRYP) (GLuint index, GLenum pname, GLfloat* params);
	using PFNGLGETVERTEXATTRIBIVPROC = void(APIENTRYP) (GLuint index, GLenum pname, GLint* params);
	using PFNGLGETVERTEXATTRIBPOINTERVPROC = void (APIENTRYP ) (GLuint index, GLenum pname, void** pointer);
	using PFNGLISPROGRAMPROC = GLboolean(APIENTRYP) (GLuint program);
	using PFNGLISSHADERPROC = GLboolean(APIENTRYP ) (GLuint shader);
	using PFNGLLINKPROGRAMPROC = void(APIENTRYP) (GLuint program);
	using PFNGLSHADERSOURCEPROC = void(APIENTRYP) (GLuint shader, GLsizei count, const GLchar* const* string, const GLint* length);
	using PFNGLUSEPROGRAMPROC = void(APIENTRYP) (GLuint program);
	using PFNGLUNIFORM1FPROC = void(APIENTRYP) (GLint location, GLfloat v0);
	using PFNGLUNIFORM2FPROC = void(APIENTRYP) (GLint location, GLfloat v0, GLfloat v1);
	using PFNGLUNIFORM3FPROC = void(APIENTRYP) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
	using PFNGLUNIFORM4FPROC = void(APIENTRYP) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
	using PFNGLUNIFORM1IPROC = void(APIENTRYP) (GLint location, GLint v0);
	using PFNGLUNIFORM2IPROC = void(APIENTRYP) (GLint location, GLint v0, GLint v1);
	using PFNGLUNIFORM3IPROC = void(APIENTRYP) (GLint location, GLint v0, GLint v1, GLint v2);
	using PFNGLUNIFORM4IPROC = void(APIENTRYP) (GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
	using PFNGLUNIFORM1FVPROC = void(APIENTRYP) (GLint location, GLsizei count, const GLfloat* value);
	using PFNGLUNIFORM2FVPROC = void(APIENTRYP) (GLint location, GLsizei count, const GLfloat* value);
	using PFNGLUNIFORM3FVPROC = void(APIENTRYP) (GLint location, GLsizei count, const GLfloat* value);
	using PFNGLUNIFORM4FVPROC = void(APIENTRYP) (GLint location, GLsizei count, const GLfloat* value);
	using PFNGLUNIFORM1IVPROC = void(APIENTRYP) (GLint location, GLsizei count, const GLint* value);
	using PFNGLUNIFORM2IVPROC = void(APIENTRYP) (GLint location, GLsizei count, const GLint* value);
	using PFNGLUNIFORM3IVPROC = void(APIENTRYP) (GLint location, GLsizei count, const GLint* value);
	using PFNGLUNIFORM4IVPROC = void(APIENTRYP) (GLint location, GLsizei count, const GLint* value);
	using PFNGLUNIFORMMATRIX2FVPROC = void(APIENTRYP) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	using PFNGLUNIFORMMATRIX3FVPROC = void(APIENTRYP) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	using PFNGLUNIFORMMATRIX4FVPROC = void(APIENTRYP) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	using PFNGLVALIDATEPROGRAMPROC = void(APIENTRYP) (GLuint program);
	using PFNGLVERTEXATTRIB1DPROC = void(APIENTRYP) (GLuint index, GLdouble x);
	using PFNGLVERTEXATTRIB1DVPROC = void(APIENTRYP) (GLuint index, const GLdouble* v);
	using PFNGLVERTEXATTRIB1FPROC = void(APIENTRYP) (GLuint index, GLfloat x);
	using PFNGLVERTEXATTRIB1FVPROC = void(APIENTRYP) (GLuint index, const GLfloat* v);
	using PFNGLVERTEXATTRIB1SPROC = void(APIENTRYP) (GLuint index, GLshort x);
	using PFNGLVERTEXATTRIB1SVPROC = void(APIENTRYP) (GLuint index, const GLshort* v);
	using PFNGLVERTEXATTRIB2DPROC = void(APIENTRYP) (GLuint index, GLdouble x, GLdouble y);
	using PFNGLVERTEXATTRIB2DVPROC = void(APIENTRYP) (GLuint index, const GLdouble* v);
	using PFNGLVERTEXATTRIB2FPROC = void(APIENTRYP) (GLuint index, GLfloat x, GLfloat y);
	using PFNGLVERTEXATTRIB2FVPROC = void(APIENTRYP) (GLuint index, const GLfloat* v);
	using PFNGLVERTEXATTRIB2SPROC = void(APIENTRYP) (GLuint index, GLshort x, GLshort y);
	using PFNGLVERTEXATTRIB2SVPROC = void(APIENTRYP) (GLuint index, const GLshort* v);
	using PFNGLVERTEXATTRIB3DPROC = void(APIENTRYP) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
	using PFNGLVERTEXATTRIB3DVPROC = void(APIENTRYP) (GLuint index, const GLdouble* v);
	using PFNGLVERTEXATTRIB3FPROC = void(APIENTRYP) (GLuint index, GLfloat x, GLfloat y, GLfloat z);
	using PFNGLVERTEXATTRIB3FVPROC = void(APIENTRYP) (GLuint index, const GLfloat* v);
	using PFNGLVERTEXATTRIB3SPROC = void(APIENTRYP) (GLuint index, GLshort x, GLshort y, GLshort z);
	using PFNGLVERTEXATTRIB3SVPROC = void(APIENTRYP) (GLuint index, const GLshort* v);
	using PFNGLVERTEXATTRIB4NBVPROC = void(APIENTRYP) (GLuint index, const GLbyte* v);
	using PFNGLVERTEXATTRIB4NIVPROC = void(APIENTRYP) (GLuint index, const GLint* v);
	using PFNGLVERTEXATTRIB4NSVPROC = void(APIENTRYP) (GLuint index, const GLshort* v);
	using PFNGLVERTEXATTRIB4NUBPROC = void(APIENTRYP) (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
	using PFNGLVERTEXATTRIB4NUBVPROC = void(APIENTRYP) (GLuint index, const GLubyte* v);
	using PFNGLVERTEXATTRIB4NUIVPROC = void(APIENTRYP) (GLuint index, const GLuint* v);
	using PFNGLVERTEXATTRIB4NUSVPROC = void(APIENTRYP) (GLuint index, const GLushort* v);
	using PFNGLVERTEXATTRIB4BVPROC = void(APIENTRYP) (GLuint index, const GLbyte* v);
	using PFNGLVERTEXATTRIB4DPROC = void(APIENTRYP) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	using PFNGLVERTEXATTRIB4DVPROC = void(APIENTRYP) (GLuint index, const GLdouble* v);
	using PFNGLVERTEXATTRIB4FPROC = void(APIENTRYP) (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	using PFNGLVERTEXATTRIB4FVPROC = void(APIENTRYP) (GLuint index, const GLfloat* v);
	using PFNGLVERTEXATTRIB4IVPROC = void(APIENTRYP) (GLuint index, const GLint* v);
	using PFNGLVERTEXATTRIB4SPROC = void(APIENTRYP) (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
	using PFNGLVERTEXATTRIB4SVPROC = void(APIENTRYP) (GLuint index, const GLshort* v);
	using PFNGLVERTEXATTRIB4UBVPROC = void(APIENTRYP) (GLuint index, const GLubyte* v);
	using PFNGLVERTEXATTRIB4UIVPROC = void(APIENTRYP) (GLuint index, const GLuint* v);
	using PFNGLVERTEXATTRIB4USVPROC = void(APIENTRYP) (GLuint index, const GLushort* v);
	using PFNGLVERTEXATTRIBPOINTERPROC = void (APIENTRYP ) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer);

	// GL 2.1
	constexpr int GL_PIXEL_PACK_BUFFER              = 0x88EB;
	constexpr int GL_PIXEL_UNPACK_BUFFER            = 0x88EC;
	constexpr int GL_PIXEL_PACK_BUFFER_BINDING      = 0x88ED;
	constexpr int GL_PIXEL_UNPACK_BUFFER_BINDING    = 0x88EF;
	constexpr int GL_FLOAT_MAT2x3                   = 0x8B65;
	constexpr int GL_FLOAT_MAT2x4                   = 0x8B66;
	constexpr int GL_FLOAT_MAT3x2                   = 0x8B67;
	constexpr int GL_FLOAT_MAT3x4                   = 0x8B68;
	constexpr int GL_FLOAT_MAT4x2                   = 0x8B69;
	constexpr int GL_FLOAT_MAT4x3                   = 0x8B6A;
	constexpr int GL_SRGB                           = 0x8C40;
	constexpr int GL_SRGB8                          = 0x8C41;
	constexpr int GL_SRGB_ALPHA                     = 0x8C42;
	constexpr int GL_SRGB8_ALPHA8                   = 0x8C43;
	constexpr int GL_COMPRESSED_SRGB                = 0x8C48;
	constexpr int GL_COMPRESSED_SRGB_ALPHA          = 0x8C49;

	using PFNGLUNIFORMMATRIX2X3FVPROC = void(APIENTRYP) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	using PFNGLUNIFORMMATRIX3X2FVPROC = void(APIENTRYP) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	using PFNGLUNIFORMMATRIX2X4FVPROC = void(APIENTRYP) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	using PFNGLUNIFORMMATRIX4X2FVPROC = void(APIENTRYP) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	using PFNGLUNIFORMMATRIX3X4FVPROC = void(APIENTRYP) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	using PFNGLUNIFORMMATRIX4X3FVPROC = void (APIENTRYP ) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);

	// GL 3.0
	using GLhalf = std::uint16_t;

	constexpr int GL_COMPARE_REF_TO_TEXTURE							= 0x884E;
	constexpr int GL_CLIP_DISTANCE0									= 0x3000;
	constexpr int GL_CLIP_DISTANCE1									= 0x3001;
	constexpr int GL_CLIP_DISTANCE2									= 0x3002;
	constexpr int GL_CLIP_DISTANCE3									= 0x3003;
	constexpr int GL_CLIP_DISTANCE4									= 0x3004;
	constexpr int GL_CLIP_DISTANCE5									= 0x3005;
	constexpr int GL_CLIP_DISTANCE6									= 0x3006;
	constexpr int GL_CLIP_DISTANCE7									= 0x3007;
	constexpr int GL_MAX_CLIP_DISTANCES								= 0x0D32;
	constexpr int GL_MAJOR_VERSION									= 0x821B;
	constexpr int GL_MINOR_VERSION									= 0x821C;
	constexpr int GL_NUM_EXTENSIONS									= 0x821D;
	constexpr int GL_CONTEXT_FLAGS									= 0x821E;
	constexpr int GL_COMPRESSED_RED									= 0x8225;
	constexpr int GL_COMPRESSED_RG									= 0x8226;
	constexpr int GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT			= 0x00000001;
	constexpr int GL_RGBA32F										= 0x8814;
	constexpr int GL_RGB32F											= 0x8815;
	constexpr int GL_RGBA16F										= 0x881A;
	constexpr int GL_RGB16F											= 0x881B;
	constexpr int GL_VERTEX_ATTRIB_ARRAY_INTEGER					= 0x88FD;
	constexpr int GL_MAX_ARRAY_TEXTURE_LAYERS						= 0x88FF;
	constexpr int GL_MIN_PROGRAM_TEXEL_OFFSET						= 0x8904;
	constexpr int GL_MAX_PROGRAM_TEXEL_OFFSET						= 0x8905;
	constexpr int GL_CLAMP_READ_COLOR								= 0x891C;
	constexpr int GL_FIXED_ONLY										= 0x891D;
	constexpr int GL_MAX_VARYING_COMPONENTS							= 0x8B4B;
	constexpr int GL_TEXTURE_1D_ARRAY								= 0x8C18;
	constexpr int GL_PROXY_TEXTURE_1D_ARRAY							= 0x8C19;
	constexpr int GL_TEXTURE_2D_ARRAY								= 0x8C1A;
	constexpr int GL_PROXY_TEXTURE_2D_ARRAY							= 0x8C1B;
	constexpr int GL_TEXTURE_BINDING_1D_ARRAY						= 0x8C1C;
	constexpr int GL_TEXTURE_BINDING_2D_ARRAY						= 0x8C1D;
	constexpr int GL_R11F_G11F_B10F									= 0x8C3A;
	constexpr int GL_UNSIGNED_INT_10F_11F_11F_REV					= 0x8C3B;
	constexpr int GL_RGB9_E5										= 0x8C3D;
	constexpr int GL_UNSIGNED_INT_5_9_9_9_REV						= 0x8C3E;
	constexpr int GL_TEXTURE_SHARED_SIZE							= 0x8C3F;
	constexpr int GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH			= 0x8C76;
	constexpr int GL_TRANSFORM_FEEDBACK_BUFFER_MODE					= 0x8C7F;
	constexpr int GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS		= 0x8C80;
	constexpr int GL_TRANSFORM_FEEDBACK_VARYINGS					= 0x8C83;
	constexpr int GL_TRANSFORM_FEEDBACK_BUFFER_START				= 0x8C84;
	constexpr int GL_TRANSFORM_FEEDBACK_BUFFER_SIZE					= 0x8C85;
	constexpr int GL_PRIMITIVES_GENERATED							= 0x8C87;
	constexpr int GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN			= 0x8C88;
	constexpr int GL_RASTERIZER_DISCARD								= 0x8C89;
	constexpr int GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS	= 0x8C8A;
	constexpr int GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS		= 0x8C8B;
	constexpr int GL_INTERLEAVED_ATTRIBS							= 0x8C8C;
	constexpr int GL_SEPARATE_ATTRIBS								= 0x8C8D;
	constexpr int GL_TRANSFORM_FEEDBACK_BUFFER						= 0x8C8E;
	constexpr int GL_TRANSFORM_FEEDBACK_BUFFER_BINDING				= 0x8C8F;
	constexpr int GL_RGBA32UI										= 0x8D70;
	constexpr int GL_RGB32UI										= 0x8D71;
	constexpr int GL_RGBA16UI										= 0x8D76;
	constexpr int GL_RGB16UI										= 0x8D77;
	constexpr int GL_RGBA8UI										= 0x8D7C;
	constexpr int GL_RGB8UI											= 0x8D7D;
	constexpr int GL_RGBA32I										= 0x8D82;
	constexpr int GL_RGB32I											= 0x8D83;
	constexpr int GL_RGBA16I										= 0x8D88;
	constexpr int GL_RGB16I											= 0x8D89;
	constexpr int GL_RGBA8I											= 0x8D8E;
	constexpr int GL_RGB8I											= 0x8D8F;
	constexpr int GL_RED_INTEGER									= 0x8D94;
	constexpr int GL_GREEN_INTEGER									= 0x8D95;
	constexpr int GL_BLUE_INTEGER									= 0x8D96;
	constexpr int GL_RGB_INTEGER									= 0x8D98;
	constexpr int GL_RGBA_INTEGER									= 0x8D99;
	constexpr int GL_BGR_INTEGER									= 0x8D9A;
	constexpr int GL_BGRA_INTEGER									= 0x8D9B;
	constexpr int GL_SAMPLER_1D_ARRAY								= 0x8DC0;
	constexpr int GL_SAMPLER_2D_ARRAY								= 0x8DC1;
	constexpr int GL_SAMPLER_1D_ARRAY_SHADOW						= 0x8DC3;
	constexpr int GL_SAMPLER_2D_ARRAY_SHADOW						= 0x8DC4;
	constexpr int GL_SAMPLER_CUBE_SHADOW							= 0x8DC5;
	constexpr int GL_UNSIGNED_INT_VEC2								= 0x8DC6;
	constexpr int GL_UNSIGNED_INT_VEC3								= 0x8DC7;
	constexpr int GL_UNSIGNED_INT_VEC4								= 0x8DC8;
	constexpr int GL_INT_SAMPLER_1D									= 0x8DC9;
	constexpr int GL_INT_SAMPLER_2D									= 0x8DCA;
	constexpr int GL_INT_SAMPLER_3D									= 0x8DCB;
	constexpr int GL_INT_SAMPLER_CUBE								= 0x8DCC;
	constexpr int GL_INT_SAMPLER_1D_ARRAY							= 0x8DCE;
	constexpr int GL_INT_SAMPLER_2D_ARRAY							= 0x8DCF;
	constexpr int GL_UNSIGNED_INT_SAMPLER_1D						= 0x8DD1;
	constexpr int GL_UNSIGNED_INT_SAMPLER_2D						= 0x8DD2;
	constexpr int GL_UNSIGNED_INT_SAMPLER_3D						= 0x8DD3;
	constexpr int GL_UNSIGNED_INT_SAMPLER_CUBE						= 0x8DD4;
	constexpr int GL_UNSIGNED_INT_SAMPLER_1D_ARRAY					= 0x8DD6;
	constexpr int GL_UNSIGNED_INT_SAMPLER_2D_ARRAY					= 0x8DD7;
	constexpr int GL_QUERY_WAIT										= 0x8E13;
	constexpr int GL_QUERY_NO_WAIT									= 0x8E14;
	constexpr int GL_QUERY_BY_REGION_WAIT							= 0x8E15;
	constexpr int GL_QUERY_BY_REGION_NO_WAIT						= 0x8E16;
	constexpr int GL_BUFFER_ACCESS_FLAGS							= 0x911F;
	constexpr int GL_BUFFER_MAP_LENGTH								= 0x9120;
	constexpr int GL_BUFFER_MAP_OFFSET								= 0x9121;
	constexpr int GL_DEPTH_COMPONENT32F								= 0x8CAC;
	constexpr int GL_DEPTH32F_STENCIL8								= 0x8CAD;
	constexpr int GL_FLOAT_32_UNSIGNED_INT_24_8_REV					= 0x8DAD;
	constexpr int GL_INVALID_FRAMEBUFFER_OPERATION					= 0x0506;
	constexpr int GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING			= 0x8210;
	constexpr int GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE			= 0x8211;
	constexpr int GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE				= 0x8212;
	constexpr int GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE				= 0x8213;
	constexpr int GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE				= 0x8214;
	constexpr int GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE				= 0x8215;
	constexpr int GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE				= 0x8216;
	constexpr int GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE			= 0x8217;
	constexpr int GL_FRAMEBUFFER_DEFAULT							= 0x8218;
	constexpr int GL_FRAMEBUFFER_UNDEFINED							= 0x8219;
	constexpr int GL_DEPTH_STENCIL_ATTACHMENT						= 0x821A;
	constexpr int GL_MAX_RENDERBUFFER_SIZE							= 0x84E8;
	constexpr int GL_DEPTH_STENCIL									= 0x84F9;
	constexpr int GL_UNSIGNED_INT_24_8								= 0x84FA;
	constexpr int GL_DEPTH24_STENCIL8								= 0x88F0;
	constexpr int GL_TEXTURE_STENCIL_SIZE							= 0x88F1;
	constexpr int GL_TEXTURE_RED_TYPE								= 0x8C10;
	constexpr int GL_TEXTURE_GREEN_TYPE								= 0x8C11;
	constexpr int GL_TEXTURE_BLUE_TYPE								= 0x8C12;
	constexpr int GL_TEXTURE_ALPHA_TYPE								= 0x8C13;
	constexpr int GL_TEXTURE_DEPTH_TYPE								= 0x8C16;
	constexpr int GL_UNSIGNED_NORMALIZED							= 0x8C17;
	constexpr int GL_FRAMEBUFFER_BINDING							= 0x8CA6;
	constexpr int GL_DRAW_FRAMEBUFFER_BINDING						= 0x8CA6;
	constexpr int GL_RENDERBUFFER_BINDING							= 0x8CA7;
	constexpr int GL_READ_FRAMEBUFFER								= 0x8CA8;
	constexpr int GL_DRAW_FRAMEBUFFER								= 0x8CA9;
	constexpr int GL_READ_FRAMEBUFFER_BINDING						= 0x8CAA;
	constexpr int GL_RENDERBUFFER_SAMPLES							= 0x8CAB;
	constexpr int GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE				= 0x8CD0;
	constexpr int GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME				= 0x8CD1;
	constexpr int GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL			= 0x8CD2;
	constexpr int GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE	= 0x8CD3;
	constexpr int GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER			= 0x8CD4;
	constexpr int GL_FRAMEBUFFER_COMPLETE							= 0x8CD5;
	constexpr int GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT				= 0x8CD6;
	constexpr int GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT		= 0x8CD7;
	constexpr int GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER				= 0x8CDB;
	constexpr int GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER				= 0x8CDC;
	constexpr int GL_FRAMEBUFFER_UNSUPPORTED						= 0x8CDD;
	constexpr int GL_MAX_COLOR_ATTACHMENTS							= 0x8CDF;
	constexpr int GL_COLOR_ATTACHMENT0								= 0x8CE0;
	constexpr int GL_COLOR_ATTACHMENT1								= 0x8CE1;
	constexpr int GL_COLOR_ATTACHMENT2								= 0x8CE2;
	constexpr int GL_COLOR_ATTACHMENT3								= 0x8CE3;
	constexpr int GL_COLOR_ATTACHMENT4								= 0x8CE4;
	constexpr int GL_COLOR_ATTACHMENT5								= 0x8CE5;
	constexpr int GL_COLOR_ATTACHMENT6								= 0x8CE6;
	constexpr int GL_COLOR_ATTACHMENT7								= 0x8CE7;
	constexpr int GL_COLOR_ATTACHMENT8								= 0x8CE8;
	constexpr int GL_COLOR_ATTACHMENT9								= 0x8CE9;
	constexpr int GL_COLOR_ATTACHMENT10								= 0x8CEA;
	constexpr int GL_COLOR_ATTACHMENT11								= 0x8CEB;
	constexpr int GL_COLOR_ATTACHMENT12								= 0x8CEC;
	constexpr int GL_COLOR_ATTACHMENT13								= 0x8CED;
	constexpr int GL_COLOR_ATTACHMENT14								= 0x8CEE;
	constexpr int GL_COLOR_ATTACHMENT15								= 0x8CEF;
	constexpr int GL_COLOR_ATTACHMENT16								= 0x8CF0;
	constexpr int GL_COLOR_ATTACHMENT17								= 0x8CF1;
	constexpr int GL_COLOR_ATTACHMENT18								= 0x8CF2;
	constexpr int GL_COLOR_ATTACHMENT19								= 0x8CF3;
	constexpr int GL_COLOR_ATTACHMENT20								= 0x8CF4;
	constexpr int GL_COLOR_ATTACHMENT21								= 0x8CF5;
	constexpr int GL_COLOR_ATTACHMENT22								= 0x8CF6;
	constexpr int GL_COLOR_ATTACHMENT23								= 0x8CF7;
	constexpr int GL_COLOR_ATTACHMENT24								= 0x8CF8;
	constexpr int GL_COLOR_ATTACHMENT25								= 0x8CF9;
	constexpr int GL_COLOR_ATTACHMENT26								= 0x8CFA;
	constexpr int GL_COLOR_ATTACHMENT27								= 0x8CFB;
	constexpr int GL_COLOR_ATTACHMENT28								= 0x8CFC;
	constexpr int GL_COLOR_ATTACHMENT29								= 0x8CFD;
	constexpr int GL_COLOR_ATTACHMENT30								= 0x8CFE;
	constexpr int GL_COLOR_ATTACHMENT31								= 0x8CFF;
	constexpr int GL_DEPTH_ATTACHMENT								= 0x8D00;
	constexpr int GL_STENCIL_ATTACHMENT								= 0x8D20;
	constexpr int GL_FRAMEBUFFER									= 0x8D40;
	constexpr int GL_RENDERBUFFER									= 0x8D41;
	constexpr int GL_RENDERBUFFER_WIDTH								= 0x8D42;
	constexpr int GL_RENDERBUFFER_HEIGHT							= 0x8D43;
	constexpr int GL_RENDERBUFFER_INTERNAL_FORMAT					= 0x8D44;
	constexpr int GL_STENCIL_INDEX1									= 0x8D46;
	constexpr int GL_STENCIL_INDEX4									= 0x8D47;
	constexpr int GL_STENCIL_INDEX8									= 0x8D48;
	constexpr int GL_STENCIL_INDEX16								= 0x8D49;
	constexpr int GL_RENDERBUFFER_RED_SIZE							= 0x8D50;
	constexpr int GL_RENDERBUFFER_GREEN_SIZE						= 0x8D51;
	constexpr int GL_RENDERBUFFER_BLUE_SIZE							= 0x8D52;
	constexpr int GL_RENDERBUFFER_ALPHA_SIZE						= 0x8D53;
	constexpr int GL_RENDERBUFFER_DEPTH_SIZE						= 0x8D54;
	constexpr int GL_RENDERBUFFER_STENCIL_SIZE						= 0x8D55;
	constexpr int GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE				= 0x8D56;
	constexpr int GL_MAX_SAMPLES									= 0x8D57;
	constexpr int GL_FRAMEBUFFER_SRGB								= 0x8DB9;
	constexpr int GL_HALF_FLOAT										= 0x140B;
	constexpr int GL_MAP_READ_BIT									= 0x0001;
	constexpr int GL_MAP_WRITE_BIT									= 0x0002;
	constexpr int GL_MAP_INVALIDATE_RANGE_BIT						= 0x0004;
	constexpr int GL_MAP_INVALIDATE_BUFFER_BIT						= 0x0008;
	constexpr int GL_MAP_FLUSH_EXPLICIT_BIT							= 0x0010;
	constexpr int GL_MAP_UNSYNCHRONIZED_BIT							= 0x0020;
	constexpr int GL_COMPRESSED_RED_RGTC1							= 0x8DBB;
	constexpr int GL_COMPRESSED_SIGNED_RED_RGTC1					= 0x8DBC;
	constexpr int GL_COMPRESSED_RG_RGTC2							= 0x8DBD;
	constexpr int GL_COMPRESSED_SIGNED_RG_RGTC2						= 0x8DBE;
	constexpr int GL_RG												= 0x8227;
	constexpr int GL_RG_INTEGER										= 0x8228;
	constexpr int GL_R8												= 0x8229;
	constexpr int GL_R16											= 0x822A;
	constexpr int GL_RG8											= 0x822B;
	constexpr int GL_RG16											= 0x822C;
	constexpr int GL_R16F											= 0x822D;
	constexpr int GL_R32F											= 0x822E;
	constexpr int GL_RG16F											= 0x822F;
	constexpr int GL_RG32F											= 0x8230;
	constexpr int GL_R8I											= 0x8231;
	constexpr int GL_R8UI											= 0x8232;
	constexpr int GL_R16I											= 0x8233;
	constexpr int GL_R16UI											= 0x8234;
	constexpr int GL_R32I											= 0x8235;
	constexpr int GL_R32UI											= 0x8236;
	constexpr int GL_RG8I											= 0x8237;
	constexpr int GL_RG8UI											= 0x8238;
	constexpr int GL_RG16I											= 0x8239;
	constexpr int GL_RG16UI											= 0x823A;
	constexpr int GL_RG32I											= 0x823B;
	constexpr int GL_RG32UI											= 0x823C;
	constexpr int GL_VERTEX_ARRAY_BINDING							= 0x85B5;

	using PFNGLCOLORMASKIPROC = void(APIENTRYP) (GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
	using PFNGLGETBOOLEANI_VPROC = void(APIENTRYP) (GLenum target, GLuint index, GLboolean* data);
	using PFNGLGETINTEGERI_VPROC = void(APIENTRYP) (GLenum target, GLuint index, GLint* data);
	using PFNGLENABLEIPROC = void(APIENTRYP) (GLenum target, GLuint index);
	using PFNGLDISABLEIPROC = void (APIENTRYP ) (GLenum target, GLuint index);
	using PFNGLISENABLEDIPROC = GLboolean(APIENTRYP ) (GLenum target, GLuint index);
	using PFNGLBEGINTRANSFORMFEEDBACKPROC = void(APIENTRYP) (GLenum primitiveMode);
	using PFNGLENDTRANSFORMFEEDBACKPROC = void(APIENTRYP) (void);
	using PFNGLBINDBUFFERRANGEPROC = void(APIENTRYP) (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
	using PFNGLBINDBUFFERBASEPROC = void(APIENTRYP) (GLenum target, GLuint index, GLuint buffer);
	using PFNGLTRANSFORMFEEDBACKVARYINGSPROC = void(APIENTRYP) (GLuint program, GLsizei count, const GLchar* const* varyings, GLenum bufferMode);
	using PFNGLGETTRANSFORMFEEDBACKVARYINGPROC = void(APIENTRYP) (GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, GLchar* name);
	using PFNGLCLAMPCOLORPROC = void(APIENTRYP) (GLenum target, GLenum clamp);
	using PFNGLBEGINCONDITIONALRENDERPROC = void(APIENTRYP) (GLuint id, GLenum mode);
	using PFNGLENDCONDITIONALRENDERPROC = void(APIENTRYP) (void);
	using PFNGLVERTEXATTRIBIPOINTERPROC = void(APIENTRYP) (GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer);
	using PFNGLGETVERTEXATTRIBIIVPROC = void(APIENTRYP) (GLuint index, GLenum pname, GLint* params);
	using PFNGLGETVERTEXATTRIBIUIVPROC = void(APIENTRYP) (GLuint index, GLenum pname, GLuint* params);
	using PFNGLVERTEXATTRIBI1IPROC = void(APIENTRYP) (GLuint index, GLint x);
	using PFNGLVERTEXATTRIBI2IPROC = void(APIENTRYP) (GLuint index, GLint x, GLint y);
	using PFNGLVERTEXATTRIBI3IPROC = void(APIENTRYP) (GLuint index, GLint x, GLint y, GLint z);
	using PFNGLVERTEXATTRIBI4IPROC = void(APIENTRYP) (GLuint index, GLint x, GLint y, GLint z, GLint w);
	using PFNGLVERTEXATTRIBI1UIPROC = void(APIENTRYP) (GLuint index, GLuint x);
	using PFNGLVERTEXATTRIBI2UIPROC = void(APIENTRYP) (GLuint index, GLuint x, GLuint y);
	using PFNGLVERTEXATTRIBI3UIPROC = void(APIENTRYP) (GLuint index, GLuint x, GLuint y, GLuint z);
	using PFNGLVERTEXATTRIBI4UIPROC = void(APIENTRYP) (GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
	using PFNGLVERTEXATTRIBI1IVPROC = void(APIENTRYP) (GLuint index, const GLint* v);
	using PFNGLVERTEXATTRIBI2IVPROC = void(APIENTRYP) (GLuint index, const GLint* v);
	using PFNGLVERTEXATTRIBI3IVPROC = void(APIENTRYP) (GLuint index, const GLint* v);
	using PFNGLVERTEXATTRIBI4IVPROC = void(APIENTRYP) (GLuint index, const GLint* v);
	using PFNGLVERTEXATTRIBI1UIVPROC = void(APIENTRYP) (GLuint index, const GLuint* v);
	using PFNGLVERTEXATTRIBI2UIVPROC = void(APIENTRYP) (GLuint index, const GLuint* v);
	using PFNGLVERTEXATTRIBI3UIVPROC = void(APIENTRYP) (GLuint index, const GLuint* v);
	using PFNGLVERTEXATTRIBI4UIVPROC = void(APIENTRYP) (GLuint index, const GLuint* v);
	using PFNGLVERTEXATTRIBI4BVPROC = void(APIENTRYP) (GLuint index, const GLbyte* v);
	using PFNGLVERTEXATTRIBI4SVPROC = void(APIENTRYP) (GLuint index, const GLshort* v);
	using PFNGLVERTEXATTRIBI4UBVPROC = void(APIENTRYP) (GLuint index, const GLubyte* v);
	using PFNGLVERTEXATTRIBI4USVPROC = void(APIENTRYP) (GLuint index, const GLushort* v);
	using PFNGLGETUNIFORMUIVPROC = void(APIENTRYP) (GLuint program, GLint location, GLuint* params);
	using PFNGLBINDFRAGDATALOCATIONPROC = void(APIENTRYP) (GLuint program, GLuint color, const GLchar* name);
	using PFNGLGETFRAGDATALOCATIONPROC = GLint(APIENTRYP) (GLuint program, const GLchar* name);
	using PFNGLUNIFORM1UIPROC = void(APIENTRYP) (GLint location, GLuint v0);
	using PFNGLUNIFORM2UIPROC = void(APIENTRYP) (GLint location, GLuint v0, GLuint v1);
	using PFNGLUNIFORM3UIPROC = void(APIENTRYP) (GLint location, GLuint v0, GLuint v1, GLuint v2);
	using PFNGLUNIFORM4UIPROC = void(APIENTRYP) (GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
	using PFNGLUNIFORM1UIVPROC = void(APIENTRYP) (GLint location, GLsizei count, const GLuint* value);
	using PFNGLUNIFORM2UIVPROC = void(APIENTRYP) (GLint location, GLsizei count, const GLuint* value);
	using PFNGLUNIFORM3UIVPROC = void(APIENTRYP) (GLint location, GLsizei count, const GLuint* value);
	using PFNGLUNIFORM4UIVPROC = void(APIENTRYP) (GLint location, GLsizei count, const GLuint* value);
	using PFNGLTEXPARAMETERIIVPROC = void(APIENTRYP) (GLenum target, GLenum pname, const GLint* params);
	using PFNGLTEXPARAMETERIUIVPROC = void(APIENTRYP) (GLenum target, GLenum pname, const GLuint* params);
	using PFNGLGETTEXPARAMETERIIVPROC = void(APIENTRYP) (GLenum target, GLenum pname, GLint* params);
	using PFNGLGETTEXPARAMETERIUIVPROC = void(APIENTRYP) (GLenum target, GLenum pname, GLuint* params);
	using PFNGLCLEARBUFFERIVPROC = void(APIENTRYP) (GLenum buffer, GLint drawbuffer, const GLint* value);
	using PFNGLCLEARBUFFERUIVPROC = void(APIENTRYP) (GLenum buffer, GLint drawbuffer, const GLuint* value);
	using PFNGLCLEARBUFFERFVPROC = void(APIENTRYP) (GLenum buffer, GLint drawbuffer, const GLfloat* value);
	using PFNGLCLEARBUFFERFIPROC = void (APIENTRYP ) (GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
	using PFNGLGETSTRINGIPROC = const GLubyte* (APIENTRYP ) (GLenum name, GLuint index);
	using PFNGLISRENDERBUFFERPROC = GLboolean(APIENTRYP ) (GLuint renderbuffer);
	using PFNGLBINDRENDERBUFFERPROC = void(APIENTRYP) (GLenum target, GLuint renderbuffer);
	using PFNGLDELETERENDERBUFFERSPROC = void(APIENTRYP) (GLsizei n, const GLuint* renderbuffers);
	using PFNGLGENRENDERBUFFERSPROC = void(APIENTRYP) (GLsizei n, GLuint* renderbuffers);
	using PFNGLRENDERBUFFERSTORAGEPROC = void(APIENTRYP) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
	using PFNGLGETRENDERBUFFERPARAMETERIVPROC = void (APIENTRYP ) (GLenum target, GLenum pname, GLint* params);
	using PFNGLISFRAMEBUFFERPROC = GLboolean(APIENTRYP ) (GLuint framebuffer);
	using PFNGLBINDFRAMEBUFFERPROC = void(APIENTRYP) (GLenum target, GLuint framebuffer);
	using PFNGLDELETEFRAMEBUFFERSPROC = void(APIENTRYP) (GLsizei n, const GLuint* framebuffers);
	using PFNGLGENFRAMEBUFFERSPROC = void (APIENTRYP ) (GLsizei n, GLuint* framebuffers);
	using PFNGLCHECKFRAMEBUFFERSTATUSPROC = GLenum(APIENTRYP ) (GLenum target);
	using PFNGLFRAMEBUFFERTEXTURE1DPROC = void(APIENTRYP) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
	using PFNGLFRAMEBUFFERTEXTURE2DPROC = void(APIENTRYP) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
	using PFNGLFRAMEBUFFERTEXTURE3DPROC = void(APIENTRYP) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
	using PFNGLFRAMEBUFFERRENDERBUFFERPROC = void(APIENTRYP) (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
	using PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC = void(APIENTRYP) (GLenum target, GLenum attachment, GLenum pname, GLint* params);
	using PFNGLGENERATEMIPMAPPROC = void(APIENTRYP) (GLenum target);
	using PFNGLBLITFRAMEBUFFERPROC = void(APIENTRYP) (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
	using PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC = void(APIENTRYP) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
	using PFNGLFRAMEBUFFERTEXTURELAYERPROC = void (APIENTRYP ) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
	using PFNGLMAPBUFFERRANGEPROC = void* (APIENTRYP ) (GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
	using PFNGLFLUSHMAPPEDBUFFERRANGEPROC = void(APIENTRYP) (GLenum target, GLintptr offset, GLsizeiptr length);
	using PFNGLBINDVERTEXARRAYPROC = void(APIENTRYP) (GLuint array);
	using PFNGLDELETEVERTEXARRAYSPROC = void(APIENTRYP) (GLsizei n, const GLuint* arrays);
	using PFNGLGENVERTEXARRAYSPROC = void (APIENTRYP ) (GLsizei n, GLuint* arrays);
	using PFNGLISVERTEXARRAYPROC = GLboolean(APIENTRYP ) (GLuint array);

	// GL 3.1
	constexpr int GL_SAMPLER_2D_RECT								= 0x8B63;
	constexpr int GL_SAMPLER_2D_RECT_SHADOW							= 0x8B64;
	constexpr int GL_SAMPLER_BUFFER									= 0x8DC2;
	constexpr int GL_INT_SAMPLER_2D_RECT							= 0x8DCD;
	constexpr int GL_INT_SAMPLER_BUFFER								= 0x8DD0;
	constexpr int GL_UNSIGNED_INT_SAMPLER_2D_RECT					= 0x8DD5;
	constexpr int GL_UNSIGNED_INT_SAMPLER_BUFFER					= 0x8DD8;
	constexpr int GL_TEXTURE_BUFFER									= 0x8C2A;
	constexpr int GL_MAX_TEXTURE_BUFFER_SIZE						= 0x8C2B;
	constexpr int GL_TEXTURE_BINDING_BUFFER							= 0x8C2C;
	constexpr int GL_TEXTURE_BUFFER_DATA_STORE_BINDING				= 0x8C2D;
	constexpr int GL_TEXTURE_RECTANGLE								= 0x84F5;
	constexpr int GL_TEXTURE_BINDING_RECTANGLE						= 0x84F6;
	constexpr int GL_PROXY_TEXTURE_RECTANGLE						= 0x84F7;
	constexpr int GL_MAX_RECTANGLE_TEXTURE_SIZE						= 0x84F8;
	constexpr int GL_R8_SNORM										= 0x8F94;
	constexpr int GL_RG8_SNORM										= 0x8F95;
	constexpr int GL_RGB8_SNORM										= 0x8F96;
	constexpr int GL_RGBA8_SNORM									= 0x8F97;
	constexpr int GL_R16_SNORM										= 0x8F98;
	constexpr int GL_RG16_SNORM										= 0x8F99;
	constexpr int GL_RGB16_SNORM									= 0x8F9A;
	constexpr int GL_RGBA16_SNORM									= 0x8F9B;
	constexpr int GL_SIGNED_NORMALIZED								= 0x8F9C;
	constexpr int GL_PRIMITIVE_RESTART								= 0x8F9D;
	constexpr int GL_PRIMITIVE_RESTART_INDEX						= 0x8F9E;
	constexpr int GL_COPY_READ_BUFFER								= 0x8F36;
	constexpr int GL_COPY_WRITE_BUFFER								= 0x8F37;
	constexpr int GL_UNIFORM_BUFFER									= 0x8A11;
	constexpr int GL_UNIFORM_BUFFER_BINDING							= 0x8A28;
	constexpr int GL_UNIFORM_BUFFER_START							= 0x8A29;
	constexpr int GL_UNIFORM_BUFFER_SIZE							= 0x8A2A;
	constexpr int GL_MAX_VERTEX_UNIFORM_BLOCKS						= 0x8A2B;
	constexpr int GL_MAX_GEOMETRY_UNIFORM_BLOCKS					= 0x8A2C;
	constexpr int GL_MAX_FRAGMENT_UNIFORM_BLOCKS					= 0x8A2D;
	constexpr int GL_MAX_COMBINED_UNIFORM_BLOCKS					= 0x8A2E;
	constexpr int GL_MAX_UNIFORM_BUFFER_BINDINGS					= 0x8A2F;
	constexpr int GL_MAX_UNIFORM_BLOCK_SIZE							= 0x8A30;
	constexpr int GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS			= 0x8A31;
	constexpr int GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS		= 0x8A32;
	constexpr int GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS		= 0x8A33;
	constexpr int GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT				= 0x8A34;
	constexpr int GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH			= 0x8A35;
	constexpr int GL_ACTIVE_UNIFORM_BLOCKS							= 0x8A36;
	constexpr int GL_UNIFORM_TYPE									= 0x8A37;
	constexpr int GL_UNIFORM_SIZE									= 0x8A38;
	constexpr int GL_UNIFORM_NAME_LENGTH							= 0x8A39;
	constexpr int GL_UNIFORM_BLOCK_INDEX							= 0x8A3A;
	constexpr int GL_UNIFORM_OFFSET									= 0x8A3B;
	constexpr int GL_UNIFORM_ARRAY_STRIDE							= 0x8A3C;
	constexpr int GL_UNIFORM_MATRIX_STRIDE							= 0x8A3D;
	constexpr int GL_UNIFORM_IS_ROW_MAJOR							= 0x8A3E;
	constexpr int GL_UNIFORM_BLOCK_BINDING							= 0x8A3F;
	constexpr int GL_UNIFORM_BLOCK_DATA_SIZE						= 0x8A40;
	constexpr int GL_UNIFORM_BLOCK_NAME_LENGTH						= 0x8A41;
	constexpr int GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS					= 0x8A42;
	constexpr int GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES			= 0x8A43;
	constexpr int GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER		= 0x8A44;
	constexpr int GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER	= 0x8A45;
	constexpr int GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER	= 0x8A46;
	constexpr std::uint32_t GL_INVALID_INDEX						= 0xFFFFFFFFu;

	using PFNGLDRAWARRAYSINSTANCEDPROC = void(APIENTRYP) (GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
	using PFNGLDRAWELEMENTSINSTANCEDPROC = void(APIENTRYP) (GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount);
	using PFNGLTEXBUFFERPROC = void(APIENTRYP) (GLenum target, GLenum internalformat, GLuint buffer);
	using PFNGLPRIMITIVERESTARTINDEXPROC = void(APIENTRYP) (GLuint index);
	using PFNGLCOPYBUFFERSUBDATAPROC = void(APIENTRYP) (GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
	using PFNGLGETUNIFORMINDICESPROC = void(APIENTRYP) (GLuint program, GLsizei uniformCount, const GLchar* const* uniformNames, GLuint* uniformIndices);
	using PFNGLGETACTIVEUNIFORMSIVPROC = void(APIENTRYP) (GLuint program, GLsizei uniformCount, const GLuint* uniformIndices, GLenum pname, GLint* params);
	using PFNGLGETACTIVEUNIFORMNAMEPROC = void (APIENTRYP ) (GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformName);
	using PFNGLGETUNIFORMBLOCKINDEXPROC = GLuint(APIENTRYP ) (GLuint program, const GLchar* uniformBlockName);
	using PFNGLGETACTIVEUNIFORMBLOCKIVPROC = void(APIENTRYP) (GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint* params);
	using PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC = void(APIENTRYP) (GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformBlockName);
	using PFNGLUNIFORMBLOCKBINDINGPROC = void (APIENTRYP ) (GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);

	// GL 3.2
	using GLsync = struct __GLsync*;
	using GLuint64 = std::uint64_t;
	using GLint64 = std::int64_t;

	constexpr int GL_CONTEXT_CORE_PROFILE_BIT					= 0x00000001;
	constexpr int GL_CONTEXT_COMPATIBILITY_PROFILE_BIT			= 0x00000002;
	constexpr int GL_LINES_ADJACENCY							= 0x000A;
	constexpr int GL_LINE_STRIP_ADJACENCY						= 0x000B;
	constexpr int GL_TRIANGLES_ADJACENCY						= 0x000C;
	constexpr int GL_TRIANGLE_STRIP_ADJACENCY					= 0x000D;
	constexpr int GL_PROGRAM_POINT_SIZE							= 0x8642;
	constexpr int GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS			= 0x8C29;
	constexpr int GL_FRAMEBUFFER_ATTACHMENT_LAYERED				= 0x8DA7;
	constexpr int GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS		= 0x8DA8;
	constexpr int GL_GEOMETRY_SHADER							= 0x8DD9;
	constexpr int GL_GEOMETRY_VERTICES_OUT						= 0x8916;
	constexpr int GL_GEOMETRY_INPUT_TYPE						= 0x8917;
	constexpr int GL_GEOMETRY_OUTPUT_TYPE						= 0x8918;
	constexpr int GL_MAX_GEOMETRY_UNIFORM_COMPONENTS			= 0x8DDF;
	constexpr int GL_MAX_GEOMETRY_OUTPUT_VERTICES				= 0x8DE0;
	constexpr int GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS		= 0x8DE1;
	constexpr int GL_MAX_VERTEX_OUTPUT_COMPONENTS				= 0x9122;
	constexpr int GL_MAX_GEOMETRY_INPUT_COMPONENTS				= 0x9123;
	constexpr int GL_MAX_GEOMETRY_OUTPUT_COMPONENTS				= 0x9124;
	constexpr int GL_MAX_FRAGMENT_INPUT_COMPONENTS				= 0x9125;
	constexpr int GL_CONTEXT_PROFILE_MASK						= 0x9126;
	constexpr int GL_DEPTH_CLAMP								= 0x864F;
	constexpr int GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION	= 0x8E4C;
	constexpr int GL_FIRST_VERTEX_CONVENTION					= 0x8E4D;
	constexpr int GL_LAST_VERTEX_CONVENTION						= 0x8E4E;
	constexpr int GL_PROVOKING_VERTEX							= 0x8E4F;
	constexpr int GL_TEXTURE_CUBE_MAP_SEAMLESS					= 0x884F;
	constexpr int GL_MAX_SERVER_WAIT_TIMEOUT					= 0x9111;
	constexpr int GL_OBJECT_TYPE								= 0x9112;
	constexpr int GL_SYNC_CONDITION								= 0x9113;
	constexpr int GL_SYNC_STATUS								= 0x9114;
	constexpr int GL_SYNC_FLAGS									= 0x9115;
	constexpr int GL_SYNC_FENCE									= 0x9116;
	constexpr int GL_SYNC_GPU_COMMANDS_COMPLETE					= 0x9117;
	constexpr int GL_UNSIGNALED									= 0x9118;
	constexpr int GL_SIGNALED									= 0x9119;
	constexpr int GL_ALREADY_SIGNALED							= 0x911A;
	constexpr int GL_TIMEOUT_EXPIRED							= 0x911B;
	constexpr int GL_CONDITION_SATISFIED						= 0x911C;
	constexpr int GL_WAIT_FAILED								= 0x911D;
	constexpr std::uint64_t GL_TIMEOUT_IGNORED					= 0xFFFFFFFFFFFFFFFFull;
	constexpr int GL_SYNC_FLUSH_COMMANDS_BIT					= 0x00000001;
	constexpr int GL_SAMPLE_POSITION							= 0x8E50;
	constexpr int GL_SAMPLE_MASK								= 0x8E51;
	constexpr int GL_SAMPLE_MASK_VALUE							= 0x8E52;
	constexpr int GL_MAX_SAMPLE_MASK_WORDS						= 0x8E59;
	constexpr int GL_TEXTURE_2D_MULTISAMPLE						= 0x9100;
	constexpr int GL_PROXY_TEXTURE_2D_MULTISAMPLE				= 0x9101;
	constexpr int GL_TEXTURE_2D_MULTISAMPLE_ARRAY				= 0x9102;
	constexpr int GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY			= 0x9103;
	constexpr int GL_TEXTURE_BINDING_2D_MULTISAMPLE				= 0x9104;
	constexpr int GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY		= 0x9105;
	constexpr int GL_TEXTURE_SAMPLES							= 0x9106;
	constexpr int GL_TEXTURE_FIXED_SAMPLE_LOCATIONS				= 0x9107;
	constexpr int GL_SAMPLER_2D_MULTISAMPLE						= 0x9108;
	constexpr int GL_INT_SAMPLER_2D_MULTISAMPLE					= 0x9109;
	constexpr int GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE		= 0x910A;
	constexpr int GL_SAMPLER_2D_MULTISAMPLE_ARRAY				= 0x910B;
	constexpr int GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY			= 0x910C;
	constexpr int GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY	= 0x910D;
	constexpr int GL_MAX_COLOR_TEXTURE_SAMPLES					= 0x910E;
	constexpr int GL_MAX_DEPTH_TEXTURE_SAMPLES					= 0x910F;
	constexpr int GL_MAX_INTEGER_SAMPLES						= 0x9110;

	using PFNGLDRAWELEMENTSBASEVERTEXPROC = void(APIENTRYP) (GLenum mode, GLsizei count, GLenum type, const void* indices, GLint basevertex);
	using PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC = void(APIENTRYP) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices, GLint basevertex);
	using PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC = void(APIENTRYP) (GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLint basevertex);
	using PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC = void(APIENTRYP) (GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei drawcount, const GLint* basevertex);
	using PFNGLPROVOKINGVERTEXPROC = void (APIENTRYP ) (GLenum mode);
	using PFNGLFENCESYNCPROC = GLsync(APIENTRYP ) (GLenum condition, GLbitfield flags);
	using PFNGLISSYNCPROC = GLboolean(APIENTRYP ) (GLsync sync);
	using PFNGLDELETESYNCPROC = void (APIENTRYP ) (GLsync sync);
	using PFNGLCLIENTWAITSYNCPROC = GLenum(APIENTRYP ) (GLsync sync, GLbitfield flags, GLuint64 timeout);
	using PFNGLWAITSYNCPROC = void(APIENTRYP) (GLsync sync, GLbitfield flags, GLuint64 timeout);
	using PFNGLGETINTEGER64VPROC = void(APIENTRYP) (GLenum pname, GLint64* data);
	using PFNGLGETSYNCIVPROC = void(APIENTRYP) (GLsync sync, GLenum pname, GLsizei count, GLsizei* length, GLint* values);
	using PFNGLGETINTEGER64I_VPROC = void(APIENTRYP) (GLenum target, GLuint index, GLint64* data);
	using PFNGLGETBUFFERPARAMETERI64VPROC = void(APIENTRYP) (GLenum target, GLenum pname, GLint64* params);
	using PFNGLFRAMEBUFFERTEXTUREPROC = void(APIENTRYP) (GLenum target, GLenum attachment, GLuint texture, GLint level);
	using PFNGLTEXIMAGE2DMULTISAMPLEPROC = void(APIENTRYP) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
	using PFNGLTEXIMAGE3DMULTISAMPLEPROC = void(APIENTRYP) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
	using PFNGLGETMULTISAMPLEFVPROC = void(APIENTRYP) (GLenum pname, GLuint index, GLfloat* val);
	using PFNGLSAMPLEMASKIPROC = void (APIENTRYP ) (GLuint maskNumber, GLbitfield mask);

	// GL 3.3
	constexpr int GL_VERTEX_ATTRIB_ARRAY_DIVISOR	= 0x88FE;
	constexpr int GL_SRC1_COLOR						= 0x88F9;
	constexpr int GL_ONE_MINUS_SRC1_COLOR			= 0x88FA;
	constexpr int GL_ONE_MINUS_SRC1_ALPHA			= 0x88FB;
	constexpr int GL_MAX_DUAL_SOURCE_DRAW_BUFFERS	= 0x88FC;
	constexpr int GL_ANY_SAMPLES_PASSED				= 0x8C2F;
	constexpr int GL_SAMPLER_BINDING				= 0x8919;
	constexpr int GL_RGB10_A2UI						= 0x906F;
	constexpr int GL_TEXTURE_SWIZZLE_R				= 0x8E42;
	constexpr int GL_TEXTURE_SWIZZLE_G				= 0x8E43;
	constexpr int GL_TEXTURE_SWIZZLE_B				= 0x8E44;
	constexpr int GL_TEXTURE_SWIZZLE_A				= 0x8E45;
	constexpr int GL_TEXTURE_SWIZZLE_RGBA			= 0x8E46;
	constexpr int GL_TIME_ELAPSED					= 0x88BF;
	constexpr int GL_TIMESTAMP						= 0x8E28;
	constexpr int GL_INT_2_10_10_10_REV				= 0x8D9F;

	using PFNGLBINDFRAGDATALOCATIONINDEXEDPROC = void(APIENTRYP) (GLuint program, GLuint colorNumber, GLuint index, const GLchar* name);
	using PFNGLGETFRAGDATAINDEXPROC = GLint(APIENTRYP) (GLuint program, const GLchar* name);
	using PFNGLGENSAMPLERSPROC = void(APIENTRYP) (GLsizei count, GLuint* samplers);
	using PFNGLDELETESAMPLERSPROC = void (APIENTRYP ) (GLsizei count, const GLuint* samplers);
	using PFNGLISSAMPLERPROC = GLboolean(APIENTRYP ) (GLuint sampler);
	using PFNGLBINDSAMPLERPROC = void(APIENTRYP) (GLuint unit, GLuint sampler);
	using PFNGLSAMPLERPARAMETERIPROC = void(APIENTRYP) (GLuint sampler, GLenum pname, GLint param);
	using PFNGLSAMPLERPARAMETERIVPROC = void(APIENTRYP) (GLuint sampler, GLenum pname, const GLint* param);
	using PFNGLSAMPLERPARAMETERFPROC = void(APIENTRYP) (GLuint sampler, GLenum pname, GLfloat param);
	using PFNGLSAMPLERPARAMETERFVPROC = void(APIENTRYP) (GLuint sampler, GLenum pname, const GLfloat* param);
	using PFNGLSAMPLERPARAMETERIIVPROC = void(APIENTRYP) (GLuint sampler, GLenum pname, const GLint* param);
	using PFNGLSAMPLERPARAMETERIUIVPROC = void(APIENTRYP) (GLuint sampler, GLenum pname, const GLuint* param);
	using PFNGLGETSAMPLERPARAMETERIVPROC = void(APIENTRYP) (GLuint sampler, GLenum pname, GLint* params);
	using PFNGLGETSAMPLERPARAMETERIIVPROC = void(APIENTRYP) (GLuint sampler, GLenum pname, GLint* params);
	using PFNGLGETSAMPLERPARAMETERFVPROC = void(APIENTRYP) (GLuint sampler, GLenum pname, GLfloat* params);
	using PFNGLGETSAMPLERPARAMETERIUIVPROC = void(APIENTRYP) (GLuint sampler, GLenum pname, GLuint* params);
	using PFNGLQUERYCOUNTERPROC = void(APIENTRYP) (GLuint id, GLenum target);
	using PFNGLGETQUERYOBJECTI64VPROC = void(APIENTRYP) (GLuint id, GLenum pname, GLint64* params);
	using PFNGLGETQUERYOBJECTUI64VPROC = void(APIENTRYP) (GLuint id, GLenum pname, GLuint64* params);
	using PFNGLVERTEXATTRIBDIVISORPROC = void(APIENTRYP) (GLuint index, GLuint divisor);
	using PFNGLVERTEXATTRIBP1UIPROC = void(APIENTRYP) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
	using PFNGLVERTEXATTRIBP1UIVPROC = void(APIENTRYP) (GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
	using PFNGLVERTEXATTRIBP2UIPROC = void(APIENTRYP) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
	using PFNGLVERTEXATTRIBP2UIVPROC = void(APIENTRYP) (GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
	using PFNGLVERTEXATTRIBP3UIPROC = void(APIENTRYP) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
	using PFNGLVERTEXATTRIBP3UIVPROC = void(APIENTRYP) (GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
	using PFNGLVERTEXATTRIBP4UIPROC = void(APIENTRYP) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
	using PFNGLVERTEXATTRIBP4UIVPROC = void (APIENTRYP ) (GLuint index, GLenum type, GLboolean normalized, const GLuint* value);

	// EXT
	constexpr int WGL_DRAW_TO_WINDOW_ARB = 0x2001;
	constexpr int WGL_SUPPORT_OPENGL_ARB = 0x2010;
	constexpr int WGL_DOUBLE_BUFFER_ARB = 0x2011;
	constexpr int WGL_PIXEL_TYPE_ARB = 0x2013;
	constexpr int WGL_TYPE_RGBA_ARB = 0x202B;
	constexpr int WGL_COLOR_BITS_ARB = 0x2014;
	constexpr int WGL_DEPTH_BITS_ARB = 0x2022;
	constexpr int WGL_STENCIL_BITS_ARB = 0x2023;

	constexpr int WGL_CONTEXT_MAJOR_VERSION_ARB = 0x2091;
	constexpr int WGL_CONTEXT_MINOR_VERSION_ARB = 0x2092;
	constexpr int WGL_CONTEXT_LAYER_PLANE_ARB = 0x2093;
	constexpr int WGL_CONTEXT_FLAGS_ARB = 0x2094;

	constexpr int WGL_CONTEXT_PROFILE_MASK_ARB = 0x9126;
	constexpr int WGL_CONTEXT_CORE_PROFILE_BIT_ARB = 0x00000001;
	constexpr int WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB = 0x00000002;

	using PFNGLCREATECONTEXTARBPROC = HGLRC(APIENTRYP)(HDC hdc, HGLRC hShareContext, const int *attribList);
	using PFNGLCHOOSEPIXELFORMATARBPROC = BOOL(APIENTRYP)(HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);

	inline PFNGLCREATECONTEXTARBPROC wglCreateContextAttribsARB{ nullptr };
	inline PFNGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB{ nullptr };

	// DECLARATIONS
	
	// 1.0
	inline PFNGLCULLFACEPROC glCullFace{ nullptr };
	inline PFNGLFRONTFACEPROC glFrontFace{ nullptr };
	inline PFNGLHINTPROC glHint{ nullptr };
	inline PFNGLLINEWIDTHPROC glLineWidth{ nullptr };
	inline PFNGLPOINTSIZEPROC glPointSize{ nullptr };
	inline PFNGLPOLYGONMODEPROC glPolygonMode{ nullptr };
	inline PFNGLSCISSORPROC glScissor{ nullptr };
	inline PFNGLTEXPARAMETERFPROC glTexParameterf{ nullptr };
	inline PFNGLTEXPARAMETERFVPROC glTexParameterfv{ nullptr };
	inline PFNGLTEXPARAMETERIPROC glTexParameteri{ nullptr };
	inline PFNGLTEXPARAMETERIVPROC glTexParameteriv{ nullptr };
	inline PFNGLTEXIMAGE1DPROC glTexImage1D{ nullptr };
	inline PFNGLTEXIMAGE2DPROC glTexImage2D{ nullptr };
	inline PFNGLDRAWBUFFERPROC glDrawBuffer{ nullptr };
	inline PFNGLCLEARPROC glClear{ nullptr };
	inline PFNGLCLEARCOLORPROC glClearColor{ nullptr };
	inline PFNGLCLEARSTENCILPROC glClearStencil{ nullptr };
	inline PFNGLCLEARDEPTHPROC glClearDepth{ nullptr };
	inline PFNGLSTENCILMASKPROC glStencilMask{ nullptr };
	inline PFNGLCOLORMASKPROC glColorMask{ nullptr };
	inline PFNGLDEPTHMASKPROC glDepthMask{ nullptr };
	inline PFNGLDISABLEPROC glDisable{ nullptr };
	inline PFNGLENABLEPROC glEnable{ nullptr };
	inline PFNGLFINISHPROC glFinish{ nullptr };
	inline PFNGLFLUSHPROC glFlush{ nullptr };
	inline PFNGLBLENDFUNCPROC glBlendFunc{ nullptr };
	inline PFNGLLOGICOPPROC glLogicOp{ nullptr };
	inline PFNGLSTENCILFUNCPROC glStencilFunc{ nullptr };
	inline PFNGLSTENCILOPPROC glStencilOp{ nullptr };
	inline PFNGLDEPTHFUNCPROC glDepthFunc{ nullptr };
	inline PFNGLPIXELSTOREFPROC glPixelStoref{ nullptr };
	inline PFNGLPIXELSTOREIPROC glPixelStorei{ nullptr };
	inline PFNGLREADBUFFERPROC glReadBuffer{ nullptr };
	inline PFNGLREADPIXELSPROC glReadPixels{ nullptr };
	inline PFNGLGETBOOLEANVPROC glGetBooleanv{ nullptr };
	inline PFNGLGETDOUBLEVPROC glGetDoublev{ nullptr };
	inline PFNGLGETERRORPROC glGetError{ nullptr };
	inline PFNGLGETFLOATVPROC glGetFloatv{ nullptr };
	inline PFNGLGETINTEGERVPROC glGetIntegerv{ nullptr };
	inline PFNGLGETSTRINGPROC glGetString{ nullptr };
	inline PFNGLGETTEXIMAGEPROC glGetTexImage{ nullptr };
	inline PFNGLGETTEXPARAMETERFVPROC glGetTexParameterfv{ nullptr };
	inline PFNGLGETTEXPARAMETERIVPROC glGetTexParameteriv{ nullptr };
	inline PFNGLGETTEXLEVELPARAMETERFVPROC glGetTexLevelParameterfv{ nullptr };
	inline PFNGLGETTEXLEVELPARAMETERIVPROC glGetTexLevelParameteriv{ nullptr };
	inline PFNGLISENABLEDPROC glIsEnabled{ nullptr };
	inline PFNGLDEPTHRANGEPROC glDepthRange{ nullptr };
	inline PFNGLVIEWPORTPROC glViewport{ nullptr };

	// 1.1
	inline PFNGLDRAWARRAYSPROC glDrawArrays{ nullptr };
	inline PFNGLDRAWELEMENTSPROC glDrawElements{ nullptr };
	inline PFNGLGETPOINTERVPROC glGetPointerv{ nullptr };
	inline PFNGLPOLYGONOFFSETPROC glPolygonOffset{ nullptr };
	inline PFNGLCOPYTEXIMAGE1DPROC glCopyTexImage1D{ nullptr };
	inline PFNGLCOPYTEXIMAGE2DPROC glCopyTexImage2D{ nullptr };
	inline PFNGLCOPYTEXSUBIMAGE1DPROC glCopyTexSubImage1D{ nullptr };
	inline PFNGLCOPYTEXSUBIMAGE2DPROC glCopyTexSubImage2D{ nullptr };
	inline PFNGLTEXSUBIMAGE1DPROC glTexSubImage1D{ nullptr };
	inline PFNGLTEXSUBIMAGE2DPROC glTexSubImage2D{ nullptr };
	inline PFNGLBINDTEXTUREPROC glBindTexture{ nullptr };
	inline PFNGLDELETETEXTURESPROC glDeleteTextures{ nullptr };
	inline PFNGLGENTEXTURESPROC glGenTextures{ nullptr };
	inline PFNGLISTEXTUREPROC glIsTexture{ nullptr };

	// 1.2
	inline PFNGLDRAWRANGEELEMENTSPROC glDrawRangeElements{ nullptr };
	inline PFNGLTEXIMAGE3DPROC glTexImage3D{ nullptr };
	inline PFNGLTEXSUBIMAGE3DPROC glTexSubImage3D{ nullptr };
	inline PFNGLCOPYTEXSUBIMAGE3DPROC glCopyTexSubImage3D{ nullptr };
	
	// 1.3
	inline PFNGLACTIVETEXTUREPROC glActiveTexture{ nullptr };
	inline PFNGLSAMPLECOVERAGEPROC glSampleCoverage{ nullptr };
	inline PFNGLCOMPRESSEDTEXIMAGE3DPROC glCompressedTexImage3D{ nullptr };
	inline PFNGLCOMPRESSEDTEXIMAGE2DPROC glCompressedTexImage2D{ nullptr };
	inline PFNGLCOMPRESSEDTEXIMAGE1DPROC glCompressedTexImage1D{ nullptr };
	inline PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glCompressedTexSubImage3D{ nullptr };
	inline PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glCompressedTexSubImage2D{ nullptr };
	inline PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC glCompressedTexSubImage1D{ nullptr };
	inline PFNGLGETCOMPRESSEDTEXIMAGEPROC glGetCompressedTexImage{ nullptr };

	// 1.4
	inline PFNGLBLENDFUNCSEPARATEPROC glBlendFuncSeparate{ nullptr };
	inline PFNGLMULTIDRAWARRAYSPROC glMultiDrawArrays{ nullptr };
	inline PFNGLMULTIDRAWELEMENTSPROC glMultiDrawElements{ nullptr };
	inline PFNGLPOINTPARAMETERFPROC glPointParameterf{ nullptr };
	inline PFNGLPOINTPARAMETERFVPROC glPointParameterfv{ nullptr };
	inline PFNGLPOINTPARAMETERIPROC glPointParameteri{ nullptr };
	inline PFNGLPOINTPARAMETERIVPROC glPointParameteriv{ nullptr };
	inline PFNGLBLENDCOLORPROC glBlendColor{ nullptr };
	inline PFNGLBLENDEQUATIONPROC glBlendEquation{ nullptr };

	// 1.5
	inline PFNGLGENQUERIESPROC glGenQueries{ nullptr };
	inline PFNGLDELETEQUERIESPROC glDeleteQueries{ nullptr };
	inline PFNGLISQUERYPROC glIsQuery{ nullptr };
	inline PFNGLBEGINQUERYPROC glBeginQuery{ nullptr };
	inline PFNGLENDQUERYPROC glEndQuery{ nullptr };
	inline PFNGLGETQUERYIVPROC glGetQueryiv{ nullptr };
	inline PFNGLGETQUERYOBJECTIVPROC glGetQueryObjectiv{ nullptr };
	inline PFNGLGETQUERYOBJECTUIVPROC glGetQueryObjectuiv{ nullptr };
	inline PFNGLBINDBUFFERPROC glBindBuffer{ nullptr };
	inline PFNGLDELETEBUFFERSPROC glDeleteBuffers{ nullptr };
	inline PFNGLGENBUFFERSPROC glGenBuffers{ nullptr };
	inline PFNGLISBUFFERPROC glIsBuffer{ nullptr };
	inline PFNGLBUFFERDATAPROC glBufferData{ nullptr };
	inline PFNGLBUFFERSUBDATAPROC glBufferSubData{ nullptr };
	inline PFNGLGETBUFFERSUBDATAPROC glGetBufferSubData;
	inline PFNGLMAPBUFFERPROC glMapBuffer{ nullptr };
	inline PFNGLUNMAPBUFFERPROC glUnmapBuffer{ nullptr };
	inline PFNGLGETBUFFERPARAMETERIVPROC glGetBufferParameteriv{ nullptr };
	inline PFNGLGETBUFFERPOINTERVPROC glGetBufferPointerv{ nullptr };

	// 2.0
	inline PFNGLBLENDEQUATIONSEPARATEPROC glBlendEquationSeparate{ nullptr };
	inline PFNGLDRAWBUFFERSPROC glDrawBuffers{ nullptr };
	inline PFNGLSTENCILOPSEPARATEPROC glStencilOpSeparate{ nullptr };
	inline PFNGLSTENCILFUNCSEPARATEPROC glStencilFuncSeparate{ nullptr };
	inline PFNGLSTENCILMASKSEPARATEPROC glStencilMaskSeparate{ nullptr };
	inline PFNGLATTACHSHADERPROC glAttachShader{ nullptr };
	inline PFNGLBINDATTRIBLOCATIONPROC glBindAttribLocation{ nullptr };
	inline PFNGLCOMPILESHADERPROC glCompileShader{ nullptr };
	inline PFNGLCREATEPROGRAMPROC glCreateProgram{ nullptr };
	inline PFNGLCREATESHADERPROC glCreateShader{ nullptr };
	inline PFNGLDELETEPROGRAMPROC glDeleteProgram{ nullptr };
	inline PFNGLDELETESHADERPROC glDeleteShader{ nullptr };
	inline PFNGLDETACHSHADERPROC glDetachShader{ nullptr };
	inline PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray{ nullptr };
	inline PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray{ nullptr };
	inline PFNGLGETACTIVEATTRIBPROC glGetActiveAttrib{ nullptr };
	inline PFNGLGETACTIVEUNIFORMPROC glGetActiveUniform{ nullptr };
	inline PFNGLGETATTACHEDSHADERSPROC glGetAttachedShaders{ nullptr };
	inline PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation{ nullptr };
	inline PFNGLGETPROGRAMIVPROC glGetProgramiv{ nullptr };
	inline PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog{ nullptr };
	inline PFNGLGETSHADERIVPROC glGetShaderiv{ nullptr };
	inline PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog{ nullptr };
	inline PFNGLGETSHADERSOURCEPROC glGetShaderSource{ nullptr };
	inline PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation{ nullptr };
	inline PFNGLGETUNIFORMFVPROC glGetUniformfv{ nullptr };
	inline PFNGLGETUNIFORMIVPROC glGetUniformiv{ nullptr };
	inline PFNGLGETVERTEXATTRIBDVPROC glGetVertexAttribdv{ nullptr };
	inline PFNGLGETVERTEXATTRIBFVPROC glGetVertexAttribfv{ nullptr };
	inline PFNGLGETVERTEXATTRIBIVPROC glGetVertexAttribiv{ nullptr };
	inline PFNGLGETVERTEXATTRIBPOINTERVPROC glGetVertexAttribPointerv{ nullptr };
	inline PFNGLISPROGRAMPROC glIsProgram{ nullptr };
	inline PFNGLISSHADERPROC glIsShader{ nullptr };
	inline PFNGLLINKPROGRAMPROC glLinkProgram{ nullptr };
	inline PFNGLSHADERSOURCEPROC glShaderSource{ nullptr };
	inline PFNGLUSEPROGRAMPROC glUseProgram{ nullptr };
	inline PFNGLUNIFORM1FPROC glUniform1f{ nullptr };
	inline PFNGLUNIFORM2FPROC glUniform2f{ nullptr };
	inline PFNGLUNIFORM3FPROC glUniform3f{ nullptr };
	inline PFNGLUNIFORM4FPROC glUniform4f{ nullptr };
	inline PFNGLUNIFORM1IPROC glUniform1i{ nullptr };
	inline PFNGLUNIFORM2IPROC glUniform2i{ nullptr };
	inline PFNGLUNIFORM3IPROC glUniform3i{ nullptr };
	inline PFNGLUNIFORM4IPROC glUniform4i{ nullptr };
	inline PFNGLUNIFORM1FVPROC glUniform1fv{ nullptr };
	inline PFNGLUNIFORM2FVPROC glUniform2fv{ nullptr };
	inline PFNGLUNIFORM3FVPROC glUniform3fv{ nullptr };
	inline PFNGLUNIFORM4FVPROC glUniform4fv{ nullptr };
	inline PFNGLUNIFORM1IVPROC glUniform1iv{ nullptr };
	inline PFNGLUNIFORM2IVPROC glUniform2iv{ nullptr };
	inline PFNGLUNIFORM3IVPROC glUniform3iv{ nullptr };
	inline PFNGLUNIFORM4IVPROC glUniform4iv{ nullptr };
	inline PFNGLUNIFORMMATRIX2FVPROC glUniformMatrix2fv{ nullptr };
	inline PFNGLUNIFORMMATRIX3FVPROC glUniformMatrix3fv{ nullptr };
	inline PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv{ nullptr };
	inline PFNGLVALIDATEPROGRAMPROC glValidateProgram{ nullptr };
	inline PFNGLVERTEXATTRIB1DPROC glVertexAttrib1d{ nullptr };
	inline PFNGLVERTEXATTRIB1DVPROC glVertexAttrib1dv{ nullptr };
	inline PFNGLVERTEXATTRIB1FPROC glVertexAttrib1f{ nullptr };
	inline PFNGLVERTEXATTRIB1FVPROC glVertexAttrib1fv{ nullptr };
	inline PFNGLVERTEXATTRIB1SPROC glVertexAttrib1s{ nullptr };
	inline PFNGLVERTEXATTRIB1SVPROC glVertexAttrib1sv{ nullptr };
	inline PFNGLVERTEXATTRIB2DPROC glVertexAttrib2d{ nullptr };
	inline PFNGLVERTEXATTRIB2DVPROC glVertexAttrib2dv{ nullptr };
	inline PFNGLVERTEXATTRIB2FPROC glVertexAttrib2f{ nullptr };
	inline PFNGLVERTEXATTRIB2FVPROC glVertexAttrib2fv{ nullptr };
	inline PFNGLVERTEXATTRIB2SPROC glVertexAttrib2s{ nullptr };
	inline PFNGLVERTEXATTRIB2SVPROC glVertexAttrib2sv{ nullptr };
	inline PFNGLVERTEXATTRIB3DPROC glVertexAttrib3d{ nullptr };
	inline PFNGLVERTEXATTRIB3DVPROC glVertexAttrib3dv{ nullptr };
	inline PFNGLVERTEXATTRIB3FPROC glVertexAttrib3f{ nullptr };
	inline PFNGLVERTEXATTRIB3FVPROC glVertexAttrib3fv{ nullptr };
	inline PFNGLVERTEXATTRIB3SPROC glVertexAttrib3s{ nullptr };
	inline PFNGLVERTEXATTRIB3SVPROC glVertexAttrib3sv{ nullptr };
	inline PFNGLVERTEXATTRIB4NBVPROC glVertexAttrib4Nbv{ nullptr };
	inline PFNGLVERTEXATTRIB4NIVPROC glVertexAttrib4Niv{ nullptr };
	inline PFNGLVERTEXATTRIB4NSVPROC glVertexAttrib4Nsv{ nullptr };
	inline PFNGLVERTEXATTRIB4NUBPROC glVertexAttrib4Nub{ nullptr };
	inline PFNGLVERTEXATTRIB4NUBVPROC glVertexAttrib4Nubv{ nullptr };
	inline PFNGLVERTEXATTRIB4NUIVPROC glVertexAttrib4Nuiv{ nullptr };
	inline PFNGLVERTEXATTRIB4NUSVPROC glVertexAttrib4Nusv{ nullptr };
	inline PFNGLVERTEXATTRIB4BVPROC glVertexAttrib4bv{ nullptr };
	inline PFNGLVERTEXATTRIB4DPROC glVertexAttrib4d{ nullptr };
	inline PFNGLVERTEXATTRIB4DVPROC glVertexAttrib4dv{ nullptr };
	inline PFNGLVERTEXATTRIB4FPROC glVertexAttrib4f{ nullptr };
	inline PFNGLVERTEXATTRIB4FVPROC glVertexAttrib4fv{ nullptr };
	inline PFNGLVERTEXATTRIB4IVPROC glVertexAttrib4iv{ nullptr };
	inline PFNGLVERTEXATTRIB4SPROC glVertexAttrib4s{ nullptr };
	inline PFNGLVERTEXATTRIB4SVPROC glVertexAttrib4sv{ nullptr };
	inline PFNGLVERTEXATTRIB4UBVPROC glVertexAttrib4ubv{ nullptr };
	inline PFNGLVERTEXATTRIB4UIVPROC glVertexAttrib4uiv{ nullptr };
	inline PFNGLVERTEXATTRIB4USVPROC glVertexAttrib4usv{ nullptr };
	inline PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer{ nullptr };

	// 2.0
	inline PFNGLUNIFORMMATRIX2X3FVPROC glUniformMatrix2x3fv{ nullptr };
	inline PFNGLUNIFORMMATRIX3X2FVPROC glUniformMatrix3x2fv{ nullptr };
	inline PFNGLUNIFORMMATRIX2X4FVPROC glUniformMatrix2x4fv{ nullptr };
	inline PFNGLUNIFORMMATRIX4X2FVPROC glUniformMatrix4x2fv{ nullptr };
	inline PFNGLUNIFORMMATRIX3X4FVPROC glUniformMatrix3x4fv{ nullptr };
	inline PFNGLUNIFORMMATRIX4X3FVPROC glUniformMatrix4x3fv{ nullptr };
	inline PFNGLCOLORMASKIPROC glColorMaski{ nullptr };
	inline PFNGLGETBOOLEANI_VPROC glGetBooleani_v{ nullptr };
	inline PFNGLGETINTEGERI_VPROC glGetIntegeri_v{ nullptr };
	inline PFNGLENABLEIPROC glEnablei{ nullptr };
	inline PFNGLDISABLEIPROC glDisablei{ nullptr };
	inline PFNGLISENABLEDIPROC glIsEnabledi{ nullptr };
	inline PFNGLBEGINTRANSFORMFEEDBACKPROC glBeginTransformFeedback{ nullptr };
	inline PFNGLENDTRANSFORMFEEDBACKPROC glEndTransformFeedback{ nullptr };
	inline PFNGLBINDBUFFERRANGEPROC glBindBufferRange{ nullptr };
	inline PFNGLBINDBUFFERBASEPROC glBindBufferBase{ nullptr };
	inline PFNGLTRANSFORMFEEDBACKVARYINGSPROC glTransformFeedbackVaryings{ nullptr };
	inline PFNGLGETTRANSFORMFEEDBACKVARYINGPROC glGetTransformFeedbackVarying{ nullptr };
	inline PFNGLCLAMPCOLORPROC glClampColor{ nullptr };
	inline PFNGLBEGINCONDITIONALRENDERPROC glBeginConditionalRender{ nullptr };
	inline PFNGLENDCONDITIONALRENDERPROC glEndConditionalRender{ nullptr };
	inline PFNGLVERTEXATTRIBIPOINTERPROC glVertexAttribIPointer{ nullptr };
	inline PFNGLGETVERTEXATTRIBIIVPROC glGetVertexAttribIiv{ nullptr };
	inline PFNGLGETVERTEXATTRIBIUIVPROC glGetVertexAttribIuiv{ nullptr };
	inline PFNGLVERTEXATTRIBI1IPROC glVertexAttribI1i{ nullptr };
	inline PFNGLVERTEXATTRIBI2IPROC glVertexAttribI2i{ nullptr };
	inline PFNGLVERTEXATTRIBI3IPROC glVertexAttribI3i{ nullptr };
	inline PFNGLVERTEXATTRIBI4IPROC glVertexAttribI4i{ nullptr };
	inline PFNGLVERTEXATTRIBI1UIPROC glVertexAttribI1ui{ nullptr };
	inline PFNGLVERTEXATTRIBI2UIPROC glVertexAttribI2ui{ nullptr };
	inline PFNGLVERTEXATTRIBI3UIPROC glVertexAttribI3ui{ nullptr };
	inline PFNGLVERTEXATTRIBI4UIPROC glVertexAttribI4ui{ nullptr };
	inline PFNGLVERTEXATTRIBI1IVPROC glVertexAttribI1iv{ nullptr };
	inline PFNGLVERTEXATTRIBI2IVPROC glVertexAttribI2iv{ nullptr };
	inline PFNGLVERTEXATTRIBI3IVPROC glVertexAttribI3iv{ nullptr };
	inline PFNGLVERTEXATTRIBI4IVPROC glVertexAttribI4iv{ nullptr };
	inline PFNGLVERTEXATTRIBI1UIVPROC glVertexAttribI1uiv{ nullptr };
	inline PFNGLVERTEXATTRIBI2UIVPROC glVertexAttribI2uiv{ nullptr };
	inline PFNGLVERTEXATTRIBI3UIVPROC glVertexAttribI3uiv{ nullptr };
	inline PFNGLVERTEXATTRIBI4UIVPROC glVertexAttribI4uiv{ nullptr };
	inline PFNGLVERTEXATTRIBI4BVPROC glVertexAttribI4bv{ nullptr };
	inline PFNGLVERTEXATTRIBI4SVPROC glVertexAttribI4sv{ nullptr };
	inline PFNGLVERTEXATTRIBI4UBVPROC glVertexAttribI4ubv{ nullptr };
	inline PFNGLVERTEXATTRIBI4USVPROC glVertexAttribI4usv{ nullptr };
	inline PFNGLGETUNIFORMUIVPROC glGetUniformuiv{ nullptr };
	inline PFNGLBINDFRAGDATALOCATIONPROC glBindFragDataLocation{ nullptr };
	inline PFNGLGETFRAGDATALOCATIONPROC glGetFragDataLocation{ nullptr };
	inline PFNGLUNIFORM1UIPROC glUniform1ui{ nullptr };
	inline PFNGLUNIFORM2UIPROC glUniform2ui{ nullptr };
	inline PFNGLUNIFORM3UIPROC glUniform3ui{ nullptr };
	inline PFNGLUNIFORM4UIPROC glUniform4ui{ nullptr };
	inline PFNGLUNIFORM1UIVPROC glUniform1uiv{ nullptr };
	inline PFNGLUNIFORM2UIVPROC glUniform2uiv{ nullptr };
	inline PFNGLUNIFORM3UIVPROC glUniform3uiv{ nullptr };
	inline PFNGLUNIFORM4UIVPROC glUniform4uiv{ nullptr };
	inline PFNGLTEXPARAMETERIIVPROC glTexParameterIiv{ nullptr };
	inline PFNGLTEXPARAMETERIUIVPROC glTexParameterIuiv{ nullptr };
	inline PFNGLGETTEXPARAMETERIIVPROC glGetTexParameterIiv{ nullptr };
	inline PFNGLGETTEXPARAMETERIUIVPROC glGetTexParameterIuiv{ nullptr };
	inline PFNGLCLEARBUFFERIVPROC glClearBufferiv{ nullptr };
	inline PFNGLCLEARBUFFERUIVPROC glClearBufferuiv{ nullptr };
	inline PFNGLCLEARBUFFERFVPROC glClearBufferfv{ nullptr };
	inline PFNGLCLEARBUFFERFIPROC glClearBufferfi{ nullptr };
	inline PFNGLGETSTRINGIPROC glGetStringi{ nullptr };
	inline PFNGLISRENDERBUFFERPROC glIsRenderbuffer{ nullptr };
	inline PFNGLBINDRENDERBUFFERPROC glBindRenderbuffer{ nullptr };
	inline PFNGLDELETERENDERBUFFERSPROC glDeleteRenderbuffers{ nullptr };
	inline PFNGLGENRENDERBUFFERSPROC glGenRenderbuffers{ nullptr };
	inline PFNGLRENDERBUFFERSTORAGEPROC glRenderbufferStorage{ nullptr };
	inline PFNGLGETRENDERBUFFERPARAMETERIVPROC glGetRenderbufferParameteriv{ nullptr };
	inline PFNGLISFRAMEBUFFERPROC glIsFramebuffer{ nullptr };
	inline PFNGLBINDFRAMEBUFFERPROC glBindFramebuffer{ nullptr };
	inline PFNGLDELETEFRAMEBUFFERSPROC glDeleteFramebuffers{ nullptr };
	inline PFNGLGENFRAMEBUFFERSPROC glGenFramebuffers{ nullptr };
	inline PFNGLCHECKFRAMEBUFFERSTATUSPROC glCheckFramebufferStatus{ nullptr };
	inline PFNGLFRAMEBUFFERTEXTURE1DPROC glFramebufferTexture1D{ nullptr };
	inline PFNGLFRAMEBUFFERTEXTURE2DPROC glFramebufferTexture2D{ nullptr };
	inline PFNGLFRAMEBUFFERTEXTURE3DPROC glFramebufferTexture3D{ nullptr };
	inline PFNGLFRAMEBUFFERRENDERBUFFERPROC glFramebufferRenderbuffer{ nullptr };
	inline PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glGetFramebufferAttachmentParameteriv{ nullptr };
	inline PFNGLGENERATEMIPMAPPROC glGenerateMipmap{ nullptr };
	inline PFNGLBLITFRAMEBUFFERPROC glBlitFramebuffer{ nullptr };
	inline PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC glRenderbufferStorageMultisample{ nullptr };
	inline PFNGLFRAMEBUFFERTEXTURELAYERPROC glFramebufferTextureLayer{ nullptr };
	inline PFNGLMAPBUFFERRANGEPROC glMapBufferRange{ nullptr };
	inline PFNGLFLUSHMAPPEDBUFFERRANGEPROC glFlushMappedBufferRange{ nullptr };
	inline PFNGLBINDVERTEXARRAYPROC glBindVertexArray{ nullptr };
	inline PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays{ nullptr };
	inline PFNGLGENVERTEXARRAYSPROC glGenVertexArrays{ nullptr };
	inline PFNGLISVERTEXARRAYPROC glIsVertexArray{ nullptr };	
	inline PFNGLDRAWARRAYSINSTANCEDPROC glDrawArraysInstanced{ nullptr };
	inline PFNGLDRAWELEMENTSINSTANCEDPROC glDrawElementsInstanced{ nullptr };
	inline PFNGLTEXBUFFERPROC glTexBuffer{ nullptr };
	inline PFNGLPRIMITIVERESTARTINDEXPROC glPrimitiveRestartIndex{ nullptr };
	inline PFNGLCOPYBUFFERSUBDATAPROC glCopyBufferSubData{ nullptr };
	inline PFNGLGETUNIFORMINDICESPROC glGetUniformIndices{ nullptr };
	inline PFNGLGETACTIVEUNIFORMSIVPROC glGetActiveUniformsiv{ nullptr };
	inline PFNGLGETACTIVEUNIFORMNAMEPROC glGetActiveUniformName{ nullptr };
	inline PFNGLGETUNIFORMBLOCKINDEXPROC glGetUniformBlockIndex{ nullptr };
	inline PFNGLGETACTIVEUNIFORMBLOCKIVPROC glGetActiveUniformBlockiv{ nullptr };
	inline PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC glGetActiveUniformBlockName{ nullptr };
	inline PFNGLUNIFORMBLOCKBINDINGPROC glUniformBlockBinding{ nullptr };
	inline PFNGLDRAWELEMENTSBASEVERTEXPROC glDrawElementsBaseVertex{ nullptr };
	inline PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC glDrawRangeElementsBaseVertex{ nullptr };
	inline PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC glDrawElementsInstancedBaseVertex{ nullptr };
	inline PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC glMultiDrawElementsBaseVertex;
	inline PFNGLPROVOKINGVERTEXPROC glProvokingVertex{ nullptr };
	inline PFNGLFENCESYNCPROC glFenceSync{ nullptr };
	inline PFNGLISSYNCPROC glIsSync{ nullptr };
	inline PFNGLDELETESYNCPROC glDeleteSync{ nullptr };
	inline PFNGLCLIENTWAITSYNCPROC glClientWaitSync{ nullptr };
	inline PFNGLWAITSYNCPROC glWaitSync{ nullptr };
	inline PFNGLGETINTEGER64VPROC glGetInteger64v{ nullptr };
	inline PFNGLGETSYNCIVPROC glGetSynciv{ nullptr };
	inline PFNGLGETINTEGER64I_VPROC glGetInteger64i_v{ nullptr };
	inline PFNGLGETBUFFERPARAMETERI64VPROC glGetBufferParameteri64v{ nullptr };
	inline PFNGLFRAMEBUFFERTEXTUREPROC glFramebufferTexture{ nullptr };
	inline PFNGLTEXIMAGE2DMULTISAMPLEPROC glTexImage2DMultisample{ nullptr };
	inline PFNGLTEXIMAGE3DMULTISAMPLEPROC glTexImage3DMultisample{ nullptr };
	inline PFNGLGETMULTISAMPLEFVPROC glGetMultisamplefv{ nullptr };
	inline PFNGLSAMPLEMASKIPROC glSampleMaski{ nullptr };
	inline PFNGLBINDFRAGDATALOCATIONINDEXEDPROC glBindFragDataLocationIndexed{ nullptr };
	inline PFNGLGETFRAGDATAINDEXPROC glGetFragDataIndex{ nullptr };
	inline PFNGLGENSAMPLERSPROC glGenSamplers{ nullptr };
	inline PFNGLDELETESAMPLERSPROC glDeleteSamplers{ nullptr };
	inline PFNGLISSAMPLERPROC glIsSampler{ nullptr };
	inline PFNGLBINDSAMPLERPROC glBindSampler{ nullptr };
	inline PFNGLSAMPLERPARAMETERIPROC glSamplerParameteri{ nullptr };
	inline PFNGLSAMPLERPARAMETERIVPROC glSamplerParameteriv{ nullptr };
	inline PFNGLSAMPLERPARAMETERFPROC glSamplerParameterf{ nullptr };
	inline PFNGLSAMPLERPARAMETERFVPROC glSamplerParameterfv{ nullptr };
	inline PFNGLSAMPLERPARAMETERIIVPROC glSamplerParameterIiv{ nullptr };
	inline PFNGLSAMPLERPARAMETERIUIVPROC glSamplerParameterIuiv{ nullptr };
	inline PFNGLGETSAMPLERPARAMETERIVPROC glGetSamplerParameteriv{ nullptr };
	inline PFNGLGETSAMPLERPARAMETERIIVPROC glGetSamplerParameterIiv{ nullptr };
	inline PFNGLGETSAMPLERPARAMETERFVPROC glGetSamplerParameterfv{ nullptr };
	inline PFNGLGETSAMPLERPARAMETERIUIVPROC glGetSamplerParameterIuiv{ nullptr };
	inline PFNGLQUERYCOUNTERPROC glQueryCounter{ nullptr };
	inline PFNGLGETQUERYOBJECTI64VPROC glGetQueryObjecti64v{ nullptr };
	inline PFNGLGETQUERYOBJECTUI64VPROC glGetQueryObjectui64v{ nullptr };
	inline PFNGLVERTEXATTRIBDIVISORPROC glVertexAttribDivisor{ nullptr };
	inline PFNGLVERTEXATTRIBP1UIPROC glVertexAttribP1ui{ nullptr };
	inline PFNGLVERTEXATTRIBP1UIVPROC glVertexAttribP1uiv{ nullptr };
	inline PFNGLVERTEXATTRIBP2UIPROC glVertexAttribP2ui{ nullptr };
	inline PFNGLVERTEXATTRIBP2UIVPROC glVertexAttribP2uiv{ nullptr };
	inline PFNGLVERTEXATTRIBP3UIPROC glVertexAttribP3ui{ nullptr };
	inline PFNGLVERTEXATTRIBP3UIVPROC glVertexAttribP3uiv{ nullptr };
	inline PFNGLVERTEXATTRIBP4UIPROC glVertexAttribP4ui{ nullptr };
	inline PFNGLVERTEXATTRIBP4UIVPROC glVertexAttribP4uiv{ nullptr };
}