#include "lib/vertex attributes.glsl"

layout (location=POSITION) in vec3 position_modelSpace;
#include "lib/uniform.glsl"

#ifdef TESSELATION
layout (location=NORMAL) in vec3 normal_modelSpace;
layout (location=TEXCOORD) in vec2 uv_tangentSpace;

out vec3 control_normal_worldSpace;
out vec2 control_uv_tangentSpace;
out vec3 control_position_worldSpace;

DECLUNIFORM(mat3, normalMatrix)
#endif

out gl_PerVertex
{
    vec4 gl_Position;
};

#ifndef TESSELATION
DECLUNIFORM(mat4, projectionMatrix)
DECLUNIFORM(mat4, viewMatrix)

out vec3 frag_position;
#endif

DECLUNIFORM(mat4, worldMatrix)

void main()
{
    gl_Position =
    #ifndef TESSELATION
    U(projectionMatrix) * U(viewMatrix) * 
    #endif
    U(worldMatrix) * vec4(position_modelSpace, 1.0);

    #ifdef TESSELATION
    control_normal_worldSpace = normalize(U(normalMatrix) * normal_modelSpace);
    control_uv_tangentSpace = uv_tangentSpace;
    control_position_worldSpace = (U(worldMatrix) * vec4(position_modelSpace, 1.0)).xyz;
    #endif
    
    #ifndef TESSELATION
    frag_position = (U(worldMatrix) * vec4(position_modelSpace, 1.0)).xyz;
    #endif
}
