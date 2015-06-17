layout (location = 0) out float result_ao;

in vec2 frag_uv;

uniform sampler2D aoTexture;

void main()
{
    result_ao = (texture(aoTexture, frag_uv) +
                 textureOffset(aoTexture, frag_uv, ivec2(-3, 0)) +
                 textureOffset(aoTexture, frag_uv, ivec2(-1, 0)) +
                 textureOffset(aoTexture, frag_uv, ivec2(-2, 0)) +
                 textureOffset(aoTexture, frag_uv, ivec2(1, 0)) +
                 textureOffset(aoTexture, frag_uv, ivec2(2, 0)) +
                 textureOffset(aoTexture, frag_uv, ivec2(3, 0))) / 7.0;
}

