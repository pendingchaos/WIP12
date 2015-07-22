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
DECLUNIFORM(vec3, cameraPosition)

struct Instance
{
    mat4 worldMatrix;
    mat4 normalMatrix;
};

layout (std140) uniform instanceData
{
    //16384 (minimum value of GL_MAX_UNIFORM_BLOCK_SIZE) / sizeof(Instance) (128) = 128
    Instance instances[128];
};

//DECLUNIFORM(sampler2D, matrixTexture)

void main()
{
    mat4 worldMatrix = instances[gl_InstanceID].worldMatrix;
    mat3 normalMatrix = mat3(instances[gl_InstanceID].normalMatrix);
    
    /*mat4 worldMatrix = mat4(texelFetch(U(matrixTexture), ivec2(gl_InstanceID*8, 0), 0),
                            texelFetch(U(matrixTexture), ivec2(gl_InstanceID*8+1, 0), 0),
                            texelFetch(U(matrixTexture), ivec2(gl_InstanceID*8+2, 0), 0),
                            texelFetch(U(matrixTexture), ivec2(gl_InstanceID*8+3, 0), 0));
    mat3 normalMatrix = mat3(mat4(texelFetch(U(matrixTexture), ivec2(gl_InstanceID*8+4, 0), 0),
                                  texelFetch(U(matrixTexture), ivec2(gl_InstanceID*8+5, 0), 0),
                                  texelFetch(U(matrixTexture), ivec2(gl_InstanceID*8+6, 0), 0),
                                  texelFetch(U(matrixTexture), ivec2(gl_InstanceID*8+7, 0), 0)));*/
    
    gl_Position = U(projectionViewMatrix) * worldMatrix * vec4(position_modelSpace, 1.0);
    frag_normal_worldSpace = normalize(normalMatrix * normal_modelSpace);
    frag_uv_tangentSpace = texCoord0_tangentSpace;
    frag_position_worldSpace = (worldMatrix * vec4(position_modelSpace, 1.0)).xyz;

    frag_viewDir_worldSpace = normalize(U(cameraPosition) - frag_position_worldSpace);

    frag_tangent_worldSpace = normalize(normalMatrix * tangent_modelSpace);
    
    frag_tangent_worldSpace = normalize(frag_tangent_worldSpace - dot(frag_tangent_worldSpace, frag_normal_worldSpace) * frag_normal_worldSpace);
    frag_bitangent_worldSpace = cross(frag_tangent_worldSpace, frag_normal_worldSpace);
}
