#include "lib/uniform.glsl"
#include "lib/vertex attributes.glsl"

layout (location=POSITION) in vec3 position;
layout (location=COLOR) in vec4 color;

out gl_PerVertex
{
    vec4 gl_Position;
};

out vec4 frag_color;

DECLUNIFORM(mat4, projectionMatrix)
DECLUNIFORM(mat4, viewMatrix)

void main()
{
    gl_Position = U(projectionMatrix) * U(viewMatrix) * vec4(position, 1.0);

    frag_color = color;
}
