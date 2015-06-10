#include "lib/color.glsl"

layout (location = 0) out vec4 result_color;

in vec2 frag_uv;

uniform sampler2D colorTexture;

void main()
{
    result_color = toSRGB(texture(colorTexture, frag_uv));
}

