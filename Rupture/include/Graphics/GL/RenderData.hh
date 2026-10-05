#pragma once

#include "Precompiled.hh"
#include "Graphics/GL/GLTypes.hh"

namespace Rupture::Graphics
{
    struct Attribute
    {
        GL::GLint Size;
        GL::GLenum Type;
        GL::GLboolean Normalized;
        GL::GLsizei Stride;
        const GL::GLvoid* Pointer;
    };

    struct GenericQuad
    {
        glm::vec3 Position;
        glm::vec2 UV;

        static constexpr auto GetAttributes()
        {
            return std::vector<Attribute>{
                Attribute
                {
                    3, 
                    GL::GL_FLOAT, 
                    GL::GL_FALSE, 
                    sizeof(GenericQuad), 
                    reinterpret_cast<const GL::GLvoid*>(offsetof(GenericQuad, Position))
                },
                Attribute
                {
                    2,
                    GL::GL_FLOAT, 
                    GL::GL_FALSE, 
                    sizeof(GenericQuad), 
                    reinterpret_cast<const GL::GLvoid*>(offsetof(GenericQuad, UV))
                }
            };
        };
    };
    
    struct InstancedQuad
    {
        glm::vec4 Color;
        GL::GLuint TextureID; 
        glm::mat4 ModelMatrix;
    };
}
