#include "lib/color.glsl"
#include "lib/uniform.glsl"

in vec2 frag_uv;

layout (location = 0) out vec4 result_color;

DECLUNIFORM(sampler2D, colorTexture)

void main()
{
    result_color = toSRGB(texture(U(colorTexture), frag_uv));
}
