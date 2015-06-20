#include "lib/vertex attributes.glsl"

layout (location=POSITION) in vec3 position_modelSpace;

out gl_PerVertex
{
    vec4 gl_Position;
};

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 worldMatrix;

void main()
{
    gl_Position = projectionMatrix * viewMatrix * worldMatrix * vec4(position_modelSpace, 1.0);
}
