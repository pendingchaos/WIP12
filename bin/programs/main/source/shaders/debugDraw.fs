layout (location = 0) out vec4 result_color;

in vec4 frag_color;

void main()
{
    result_color = frag_color;
}
