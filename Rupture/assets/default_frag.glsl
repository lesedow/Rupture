#version 330 core

out vec4 FragColor;
in vec2 TexCoord;

uniform sampler2D oTex;

void main()
{
	FragColor = texture(oTex, TexCoord);
}