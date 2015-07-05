#include "lib/uniform.glsl"

in vec2 frag_uv;

DECLUNIFORM(vec3, color)
DECLUNIFORM(sampler2D, glyphTexture)

layout (location = 0) out vec4 result_color;

void main()
{
    result_color.rgb = U(color);
    result_color.a = texture(U(glyphTexture), frag_uv);
}
