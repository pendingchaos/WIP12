#include "lib/vertex attributes.glsl"

layout (location=POSITION) in vec3 position_modelSpace;
layout (location=NORMAL) in vec3 normal_modelSpace;
layout (location=TEXCOORD) in vec2 texCoord0_tangentSpace;
layout (location=TANGENT) in vec3 tangent_modelSpace;
layout (location=BITANGENT) in vec3 bitangent_modelSpace;

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

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 worldMatrix;
uniform mat3 normalMatrix;
uniform vec3 cameraPosition;

void main()
{
    gl_Position = projectionMatrix * viewMatrix * worldMatrix * vec4(position_modelSpace, 1.0);
    frag_normal_worldSpace = normalize(normalMatrix * normal_modelSpace);
    frag_uv_tangentSpace = texCoord0_tangentSpace;
    frag_position_worldSpace = (worldMatrix * vec4(position_modelSpace, 1.0)).xyz;

    frag_viewDir_worldSpace = normalize(cameraPosition - frag_position_worldSpace);

    frag_tangent_worldSpace = normalize(normalMatrix * tangent_modelSpace);
    frag_bitangent_worldSpace = normalize(normalMatrix * bitangent_modelSpace);
}
