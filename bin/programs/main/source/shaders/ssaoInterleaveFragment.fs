#include "lib/uniform.glsl"

layout (location = 0) out vec4 result_ao;

in vec2 frag_uv;

DECLUNIFORM(sampler2D, aoTexture)
DECLUNIFORM(ivec2, size)

void main()
{
    ivec2 pos = ivec2(gl_FragCoord);
    
    result_ao = texelFetch(U(aoTexture), pos%4*U(size) + pos/4, 0);

    //result_ao = texture(U(aoTexture), frag_uv);
}

