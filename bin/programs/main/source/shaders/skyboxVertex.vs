#include "lib/vertex attributes.glsl"

layout (location=POSITION) in vec3 position;

out vec3 frag_position;

out gl_PerVertex
{
    vec4 gl_Position;
};

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;

void main()
{
    gl_Position = projectionMatrix * viewMatrix * vec4(position, 1.0);
    gl_Position = gl_Position.xyww;
    frag_position = position;
}
