in vec3 frag_position;

layout (location = 0) out vec4 result_color;

uniform samplerCube enviroment;

void main()
{
    result_color = texture(enviroment, normalize(frag_position));
}
