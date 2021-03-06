#include "lib/vertex attributes.glsl"

layout (location=POSITION) in vec3 position_modelSpace;
layout (location=NORMAL) in vec3 normal_modelSpace;
layout (location=TEXCOORD) in vec2 texCoord0_tangentSpace;
layout (location=TANGENT) in vec3 tangent_modelSpace;

#ifdef SKELETAL_ANIMATION
layout (location=BONE_INDEX) in vec4 boneIndices;
layout (location=BONE_WEIGHT) in vec4 boneWeights;
#endif

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

uniform mat4 projectionViewMatrix;
uniform vec3 cameraPosition;

uniform sampler2D matrixTexture;

#ifdef SKELETAL_ANIMATION
layout (std140) uniform bonePositionData
{
    mat4 boneMatrices[256];
};

layout (std140) uniform boneNormalData
{
    mat4 boneNormalMatrices[256];
};
#endif

void main()
{
#ifdef SKELETAL_ANIMATION
    mat4 transform = boneMatrices[int(boneIndices.x)] * boneWeights.x;
    transform += boneMatrices[int(boneIndices.y)] * boneWeights.y;
    transform += boneMatrices[int(boneIndices.z)] * boneWeights.z;
    transform += boneMatrices[int(boneIndices.w)] * boneWeights.w;

    vec3 pos_modelSpace = vec3(transform * vec4(position_modelSpace, 1.0));

    mat3 normalTransform = mat3(boneNormalMatrices[int(boneIndices.x)]) * boneWeights.x;
    normalTransform += mat3(boneNormalMatrices[int(boneIndices.y)]) * boneWeights.y;
    normalTransform += mat3(boneNormalMatrices[int(boneIndices.z)]) * boneWeights.z;
    normalTransform += mat3(boneNormalMatrices[int(boneIndices.w)]) * boneWeights.w;

    vec3 norm_modelSpace = vec3(normalTransform * normal_modelSpace);
    norm_modelSpace = normalize(norm_modelSpace);
#else
    vec3 pos_modelSpace = position_modelSpace;
    vec3 norm_modelSpace = normal_modelSpace;
#endif

    uvec2 texSize = textureSize(matrixTexture, 0);
    ivec2 offset = ivec2(gl_InstanceID*8%texSize.x, gl_InstanceID*8/texSize.x);

    mat4 worldMatrix = transpose(mat4(texelFetch(matrixTexture, offset, 0),
                                      texelFetch(matrixTexture, offset+ivec2(1, 0), 0),
                                      texelFetch(matrixTexture, offset+ivec2(2, 0), 0),
                                      texelFetch(matrixTexture, offset+ivec2(3, 0), 0)));
    mat3 normalMatrix = mat3(transpose(mat4(texelFetch(matrixTexture, offset, 0),
                                            texelFetch(matrixTexture, offset+ivec2(1, 0), 0),
                                            texelFetch(matrixTexture, offset+ivec2(2, 0), 0),
                                            texelFetch(matrixTexture, offset+ivec2(3, 0), 0))));

    gl_Position = projectionViewMatrix * worldMatrix * vec4(pos_modelSpace, 1.0);
    frag_normal_worldSpace = normalize(normalMatrix * norm_modelSpace);
    frag_uv_tangentSpace = texCoord0_tangentSpace;
    frag_position_worldSpace = (worldMatrix * vec4(pos_modelSpace, 1.0)).xyz;

    frag_viewDir_worldSpace = normalize(cameraPosition - frag_position_worldSpace);

    frag_tangent_worldSpace = normalize(normalMatrix * tangent_modelSpace);
    
    frag_tangent_worldSpace = normalize(frag_tangent_worldSpace - dot(frag_tangent_worldSpace, frag_normal_worldSpace) * frag_normal_worldSpace);
    frag_bitangent_worldSpace = cross(frag_tangent_worldSpace, frag_normal_worldSpace);
}
