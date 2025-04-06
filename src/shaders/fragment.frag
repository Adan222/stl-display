#version 330 core

out vec4 FragColor;

in vec3 Color;
in vec2 TexCoord;

uniform sampler2D Texture0;
uniform sampler2D Texture1;

void main()
{
    vec4 tex0 = texture(Texture0, TexCoord);
    vec4 tex1 = texture(Texture1, vec2(-TexCoord.x, TexCoord.y));

    FragColor = mix(tex0, tex1, 0.2) * vec4(Color, 1.0);
}
