layout (location = 0) out vec4 result_ao;

in vec2 frag_uv;

uniform sampler2D aoTexture;
uniform ivec2 size;

void main()
{
    ivec2 pos = ivec2(gl_FragCoord);
    
    result_ao = texelFetch(aoTexture, pos%4*size + pos/4, 0);

    //result_ao = texture(aoTexture, frag_uv);
}

