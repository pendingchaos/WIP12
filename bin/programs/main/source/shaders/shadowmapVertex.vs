#include "lib/vertex attributes.glsl"
#include "lib/uniform.glsl"

layout (location=POSITION) in vec3 position_modelSpace;

#ifdef TESSELATION
layout (location=NORMAL) in vec3 normal_modelSpace;
layout (location=TEXCOORD) in vec2 uv_tangentSpace;

out vec3 control_normal_worldSpace;
out vec2 control_uv_tangentSpace;
out vec3 control_position_worldSpace;
#endif

#ifdef SKELETAL_ANIMATION
layout (location=BONE_INDEX) in vec4 boneIndices;
layout (location=BONE_WEIGHT) in vec4 boneWeights;
#endif

out gl_PerVertex
{
    vec4 gl_Position;
};

#ifndef TESSELATION
uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;

out vec3 frag_position;
#endif

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

#ifdef TESSELATION
    mat3 normalMatrix = mat3(mat4(texelFetch(matrixTexture, ivec2(gl_InstanceID*8+4, 0), 0),
                                  texelFetch(matrixTexture, ivec2(gl_InstanceID*8+5, 0), 0),
                                  texelFetch(matrixTexture, ivec2(gl_InstanceID*8+6, 0), 0),
                                  texelFetch(matrixTexture, ivec2(gl_InstanceID*8+7, 0), 0)));
#endif
    
#ifdef SKELETAL_ANIMATION
    mat4 transform = boneMatrices[int(boneIndices.x)] * boneWeights.x;
    transform += boneMatrices[int(boneIndices.y)] * boneWeights.y;
    transform += boneMatrices[int(boneIndices.z)] * boneWeights.z;
    transform += boneMatrices[int(boneIndices.w)] * boneWeights.w;

    vec3 pos_modelSpace = vec3(transform * vec4(position_modelSpace, 1.0));

#ifdef TESSELATION
    mat3 normalTransform = mat3(boneNormalMatrices[int(boneIndices.x)]) * boneWeights.x;
    normalTransform += mat3(boneNormalMatrices[int(boneIndices.y)]) * boneWeights.y;
    normalTransform += mat3(boneNormalMatrices[int(boneIndices.z)]) * boneWeights.z;
    normalTransform += mat3(boneNormalMatrices[int(boneIndices.w)]) * boneWeights.w;

    vec3 norm_modelSpace = vec3(normalTransform * normal_modelSpace);
    norm_modelSpace = normalize(norm_modelSpace);
#endif
#else
    vec3 pos_modelSpace = position_modelSpace;
    
    #ifdef TESSELATION
    vec3 norm_modelSpace = normal_modelSpace;
    #endif
#endif

    gl_Position =
    #ifndef TESSELATION
    projectionMatrix * viewMatrix * 
    #endif
    worldMatrix * vec4(pos_modelSpace, 1.0);

    #ifdef TESSELATION
    control_normal_worldSpace = normalize(normalMatrix * norm_modelSpace);
    control_uv_tangentSpace = uv_tangentSpace;
    control_position_worldSpace = (worldMatrix * vec4(pos_modelSpace, 1.0)).xyz;
    #else
    frag_position = (worldMatrix * vec4(pos_modelSpace, 1.0)).xyz;
    #endif
}
