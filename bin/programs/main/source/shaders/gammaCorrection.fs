#include "lib/color.glsl"

in vec2 frag_uv;

layout (location = 0) out vec4 result_color;

uniform sampler2D colorTexture;

void main()
{
    result_color = toSRGB(texture(colorTexture, frag_uv));
}
