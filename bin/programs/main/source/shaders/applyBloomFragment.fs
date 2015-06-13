layout (location = 0) out vec3 result_color;

in vec2 frag_uv;

uniform sampler2D bloomTexture;

void main()
{
    result_color = texture(bloomTexture, frag_uv).rgb;
}

