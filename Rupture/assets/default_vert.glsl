#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aColor;
layout (location = 2) in vec2 aTexCoord;
layout (location = 3) in float aTexID;

uniform mat4 View;
uniform mat4 Projection;

out vec2 TexCoord;
out vec4 OutColor;

void main()
{
	gl_Position = Projection * View * vec4(aPos, 1.0);
	TexCoord = aTexCoord;
	OutColor = aColor;
}