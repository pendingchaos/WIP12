in vec2 frag_uv;

layout (location = 0) out vec4 result_color;

uniform sampler2D colorTexture;
uniform vec3 color;

void main()
{
    result_color = texture(colorTexture, frag_uv) * vec4(color, 1.0);
}
