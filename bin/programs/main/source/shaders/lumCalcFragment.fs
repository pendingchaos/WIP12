#include "lib/uniform.glsl"

layout (location = 0) out float result_lum;

in vec2 frag_uv;

DECLUNIFORM(sampler2D, colorTexture)

float calcLum(vec3 color)
{
    return dot(color, vec3(0.2126, 0.7152, 0.0722));
}

void main()
{
    result_lum = log(max(calcLum(texture(U(colorTexture), frag_uv).rgb), 0.0001));
}

