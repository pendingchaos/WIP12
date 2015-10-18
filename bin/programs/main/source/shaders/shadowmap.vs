#include "lib/vertex attributes.glsl"
#include "lib/uniform.glsl"

layout (location=POSITION) in vec3 position_modelSpace;

#ifdef SKELETAL_ANIMATION
layout (location=BONE_INDEX) in vec4 boneIndices;
layout (location=BONE_WEIGHT) in vec4 boneWeights;
#endif

out gl_PerVertex
{
    vec4 gl_Position;
};

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;

out vec3 frag_position;

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
    mat4 worldMatrix = mat4(texelFetch(matrixTexture, ivec2(gl_InstanceID*8, 0), 0),
                            texelFetch(matrixTexture, ivec2(gl_InstanceID*8+1, 0), 0),
                            texelFetch(matrixTexture, ivec2(gl_InstanceID*8+2, 0), 0),
                            texelFetch(matrixTexture, ivec2(gl_InstanceID*8+3, 0), 0));

#ifdef SKELETAL_ANIMATION
    mat4 transform = boneMatrices[int(boneIndices.x)] * boneWeights.x;
    transform += boneMatrices[int(boneIndices.y)] * boneWeights.y;
    transform += boneMatrices[int(boneIndices.z)] * boneWeights.z;
    transform += boneMatrices[int(boneIndices.w)] * boneWeights.w;

    vec3 pos_modelSpace = vec3(transform * vec4(position_modelSpace, 1.0));

#else
    vec3 pos_modelSpace = position_modelSpace;
#endif

    gl_Position = projectionMatrix * viewMatrix * worldMatrix * vec4(pos_modelSpace, 1.0);

    frag_position = (worldMatrix * vec4(pos_modelSpace, 1.0)).xyz;
}
