#version 330 core

out vec4 FragColor;

in vec3 Color;
in vec2 TexCoord;

uniform sampler2D Texture0;
uniform sampler2D Texture1;

void main()
{
    FragColor = mix(texture(Texture0, TexCoord), texture(Texture1, TexCoord), 0.2);
}
