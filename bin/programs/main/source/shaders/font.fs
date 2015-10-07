in vec2 frag_uv;

uniform vec3 color;
uniform sampler2D glyphTexture;

layout (location = 0) out vec4 result_color;

void main()
{
    result_color.rgb = color;
    result_color.a = texture(glyphTexture, frag_uv).r;
}
