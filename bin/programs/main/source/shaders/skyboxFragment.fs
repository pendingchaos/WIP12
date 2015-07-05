#include "lib/uniform.glsl"

in vec3 frag_position;

layout (location = 0) out vec4 result_color;

DECLUNIFORM(samplerCube, enviroment)

void main()
{
    result_color = texture(U(enviroment), normalize(frag_position));
}
