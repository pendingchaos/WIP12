#include "lib/color.glsl"

layout (location = 0) out vec3 result_color;

in vec2 frag_uv;

uniform sampler2D colorTexture;

void main()
{
    vec3 xyY = RGBToxyY(texture(colorTexture, frag_uv).rgb);
    xyY.z /= xyY.z + 1.0;
    result_color = xyYToRGB(xyY);
}

