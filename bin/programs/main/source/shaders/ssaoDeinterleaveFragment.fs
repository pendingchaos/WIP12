#include "lib/uniform.glsl"

layout (location = 0) out float result_depth;

in vec2 frag_uv;

DECLUNIFORM(sampler2D, depthTexture)

void main()
{
    ivec2 tileSize = textureSize(U(depthTexture), 0) / 4;
    ivec2 uv = ivec2(gl_FragCoord.xy) % tileSize * 4;
    ivec2 offset = ivec2(gl_FragCoord.xy) / tileSize;
    
    result_depth = texelFetch(U(depthTexture), uv + offset, 0).r;
}

