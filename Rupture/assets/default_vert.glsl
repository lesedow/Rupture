#version 330 core

// Fixed data
layout (location = 0) in vec3 a_Position;
layout (location = 1) in vec2 a_UV;

// Per instance data
layout (location = 2) in vec4 a_Color;
layout (location = 3) in int a_TextureID;
layout (location = 4) in mat4 a_ModelMatrix;

uniform mat4 m_View;
uniform mat4 m_Projection;

out vec2 f_UV;
out vec4 f_Color;
out int f_TextureID;

void main()
{
	gl_Position = m_Projection * m_View * a_ModelMatrix * vec4(a_Position, 1.0);
	f_UV = a_UV;
	f_Color = a_Color;
	f_TextureID = a_TextureID;
}