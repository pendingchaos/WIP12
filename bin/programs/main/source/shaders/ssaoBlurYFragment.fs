#include "lib/uniform.glsl"

layout (location = 0) out float result_ao;

in vec2 frag_uv;

DECLUNIFORM(sampler2D, aoTexture)

void main()
{
    result_ao = (texture(U(aoTexture), frag_uv) +
                 textureOffset(U(aoTexture), frag_uv, ivec2(0, -1)) * 0.5 +
                 textureOffset(U(aoTexture), frag_uv, ivec2(0, -2)) * 0.25 +
                 textureOffset(U(aoTexture), frag_uv, ivec2(0, 1)) * 0.5 +
                 textureOffset(U(aoTexture), frag_uv, ivec2(0, 2)) * 0.25) / 2.5;
}

