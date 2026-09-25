#version 330 core

in vec2 f_UV;
in vec4 f_Color;
flat in uint f_TextureID;

out vec4 FragColor;

// Supposedly the system supports 32 texture slots
uniform sampler2D u_Textures[32];

void main()
{
	FragColor = texture(u_Textures[f_TextureID], f_UV) * f_Color;
}