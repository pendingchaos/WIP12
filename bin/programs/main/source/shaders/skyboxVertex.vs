#include "lib/vertex attributes.glsl"
#include "lib/uniform.glsl"

layout (location=POSITION) in vec3 position;

out vec3 frag_position;

out gl_PerVertex
{
    vec4 gl_Position;
};

DECLUNIFORM(mat4, projectionMatrix)
DECLUNIFORM(mat4, viewMatrix)

void main()
{
    gl_Position = U(projectionMatrix) * U(viewMatrix) * vec4(position, 1.0);
    gl_Position = gl_Position.xyww;
    frag_position = position;
}
