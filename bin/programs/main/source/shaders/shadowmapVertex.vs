#include "lib/vertex attributes.glsl"

layout (location=POSITION) in vec3 position_modelSpace;
#ifdef TESSELATION
layout (location=NORMAL) in vec3 normal_modelSpace;
layout (location=TEXCOORD) in vec2 uv_tangentSpace;

out vec3 control_normal_worldSpace;
out vec2 control_uv_tangentSpace;
out vec3 control_position_worldSpace;

uniform mat3 normalMatrix;
#endif

out gl_PerVertex
{
    vec4 gl_Position;
};

#ifndef TESSELATION
uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
#endif

uniform mat4 worldMatrix;

void main()
{
    gl_Position =
    #ifndef TESSELATION
    projectionMatrix * viewMatrix * 
    #endif
    worldMatrix * vec4(position_modelSpace, 1.0);

    #ifdef TESSELATION
    control_normal_worldSpace = normalize(normalMatrix * normal_modelSpace);
    control_uv_tangentSpace = uv_tangentSpace;
    control_position_worldSpace = (worldMatrix * vec4(position_modelSpace, 1.0)).xyz;
    #endif
}
