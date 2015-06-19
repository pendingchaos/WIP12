#include "lib/color.glsl"
#include "lib/lighting.glsl"

in vec3 frag_normal_worldSpace;
in vec2 frag_uv_tangentSpace;
in vec3 frag_position_worldSpace;
in vec3 frag_viewDir_worldSpace;
in vec3 frag_tangent_worldSpace;
in vec3 frag_bitangent_worldSpace;

layout (location = 0) out vec4 result_color;

uniform vec4 albedo;
uniform float smoothness;
uniform float metalMask;

#ifdef ALBEDO_MAP
uniform sampler2D albedoMap;
#endif

#ifdef ENVIRONMENT_MAP
uniform samplerCube environment;
#endif

#ifdef SMOOTHNESS_MAP
uniform sampler2D smoothnessMap;
#endif

#ifdef METAL_MASK_MAP
uniform sampler2D metalMaskMap;
#endif

#ifdef NORMAL_MAP
uniform sampler2D normalMap;
#endif

void main()
{
    vec4 albedo_ = albedo;

    #ifdef ALBEDO_MAP
    albedo_ *= texture(albedoMap, frag_uv_tangentSpace);
    #endif

    float roughness_ = 1.0 - smoothness;

    #ifdef SMOOTHNESS_MAP
    roughness_ *= texture(smoothnessMap, frag_uv_tangentSpace).r;
    #endif

    float metallic_ = metalMask;

    #ifdef METAL_MASK_MAP
    metallic_ *= texture(metalMaskMap, frag_uv_tangentSpace).r;
    #endif

    vec3 normal_worldSpace = normalize(frag_normal_worldSpace);

    #ifdef NORMAL_MAP
    vec3 tangent = normalize(frag_tangent_worldSpace);
    vec3 bitangent = normalize(frag_bitangent_worldSpace);

    normal_worldSpace = mat3(tangent, bitangent, normal_worldSpace) * normalize(texture(normalMap, frag_uv_tangentSpace).xyz * 2.0 - 1.0);

    normal_worldSpace = normalize(normal_worldSpace);
    #endif

    result_color.rgb = lighting(albedo_.rgb,
                                roughness_,
                                metallic_,
                                normal_worldSpace,
                                normalize(frag_viewDir_worldSpace),
                                frag_position_worldSpace);
    result_color.a = albedo_.a;

    //result_color.rgb = (normal + 1.0) / 2.0;
}
