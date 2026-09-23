#version 330 core

out vec4 FragColor;
in vec2 TexCoord;
in vec4 OutColor;

uniform sampler2D OutTexture;

void main()
{
	FragColor = texture(OutTexture, TexCoord) * OutColor;
}