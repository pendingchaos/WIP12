#include "lib/vertex attributes.glsl"
#include "lib/uniform.glsl"

layout (location=POSITION) in vec3 position_modelSpace;
layout (location=NORMAL) in vec3 normal_modelSpace;
layout (location=TEXCOORD) in vec2 texCoord0_tangentSpace;
layout (location=TANGENT) in vec3 tangent_modelSpace;

out vec3 frag_normal_worldSpace;
out vec2 frag_uv_tangentSpace;
out vec3 frag_position_worldSpace;
out vec3 frag_viewDir_worldSpace;
out vec3 frag_tangent_worldSpace;
out vec3 frag_bitangent_worldSpace;

out gl_PerVertex
{
    vec4 gl_Position;
};

DECLUNIFORM(mat4, projectionViewMatrix)
DECLUNIFORM(mat4, worldMatrix)
DECLUNIFORM(mat3, normalMatrix)
DECLUNIFORM(vec3, cameraPosition)

void main()
{
    gl_Position = U(projectionViewMatrix) * U(worldMatrix) * vec4(position_modelSpace, 1.0);
    frag_normal_worldSpace = normalize(U(normalMatrix) * normal_modelSpace);
    frag_uv_tangentSpace = texCoord0_tangentSpace;
    frag_position_worldSpace = (U(worldMatrix) * vec4(position_modelSpace, 1.0)).xyz;

    frag_viewDir_worldSpace = normalize(U(cameraPosition) - frag_position_worldSpace);

    frag_tangent_worldSpace = normalize(U(normalMatrix) * tangent_modelSpace);
    
    frag_tangent_worldSpace = normalize(frag_tangent_worldSpace - dot(frag_tangent_worldSpace, frag_normal_worldSpace) * frag_normal_worldSpace);
    frag_bitangent_worldSpace = cross(frag_tangent_worldSpace, frag_normal_worldSpace);
}
