#include "lib/vertex attributes.glsl"

layout (location=POSITION) in vec3 position_modelSpace;

out gl_PerVertex
{
    vec4 gl_Position;
};

out vec3 position_worldSpace;

void main()
{
    gl_Position = vec4(position_modelSpace, 1.0);
    position_worldSpace = position_modelSpace;
}
