#include "lib/vertex attributes.glsl"

layout (location=POSITION) in vec3 position_modelSpace;

out gl_PerVertex
{
    vec4 gl_Position;
};

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 worldMatrix;

out vec4 frag_pos;

void main()
{
    vec4 pos = viewMatrix * worldMatrix * vec4(position_modelSpace, 1.0);
    
    frag_pos = pos;
    
    gl_Position = projectionMatrix * pos;
}
