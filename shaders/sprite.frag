#version 300 es
in highp vec2 TexCoords;
out highp vec4 color;

uniform sampler2D image;
uniform highp vec3 spriteColor;

void main()
{
    color = vec4(spriteColor, 1.0) * texture(image, TexCoords);
}
