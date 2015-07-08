#include "lib/uniform.glsl"

layout (location = 0) out vec3 result_color;

in vec2 frag_uv;

DECLUNIFORM(sampler2D, colorTexture)
DECLUNIFORM(sampler2D, bloom1Texture)
DECLUNIFORM(sampler2D, bloom2Texture)
DECLUNIFORM(sampler2D, bloom3Texture)
DECLUNIFORM(sampler2D, bloom4Texture)

void main()
{
    result_color = texture(U(colorTexture), frag_uv).rgb;
    result_color += texture(U(bloom1Texture), frag_uv).rgb;
    result_color += texture(U(bloom2Texture), frag_uv).rgb;
    result_color += texture(U(bloom3Texture), frag_uv).rgb;
    result_color += texture(U(bloom4Texture), frag_uv).rgb;
}

