#include "lib/color.glsl"
#include "lib/lighting.glsl"
#include "lib/parallax.glsl"

in vec3 frag_normal_worldSpace;
in vec2 frag_uv_tangentSpace;
in vec3 frag_position_worldSpace;
in vec3 frag_viewDir_worldSpace;
in vec3 frag_tangent_worldSpace;
in vec3 frag_bitangent_worldSpace;

layout (location = 0) out vec3 result_albedo;
layout (location = 1) out vec2 result_material;
layout (location = 2) out vec3 result_normal;

uniform vec4 albedo;
uniform float smoothness;
uniform float metalMask;

#ifdef ALBEDO_MAP
uniform sampler2D albedoMap;
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

#if defined(PARALLAX_MAPPING) || defined(POM)
uniform sampler2D heightMap;
uniform float heightScale;
uniform bool parallaxEdgeDiscard;
#endif

#ifdef POM
uniform uint pomMinLayers;
uniform uint pomMaxLayers;
#endif

void main()
{
    vec4 albedo_ = albedo;
    vec3 normal_worldSpace = normalize(frag_normal_worldSpace);

    #if defined(NORMAL_MAP) || defined(PARALLAX_MAPPING) || defined(POM)
    mat3 fromTangentSpace = mat3(normalize(frag_tangent_worldSpace), normalize(frag_bitangent_worldSpace), normal_worldSpace);
    mat3 toTangentSpace = transpose(fromTangentSpace);
    #endif

    #ifdef PARALLAX_MAPPING
    vec2 texCoord = parallaxMapping(heightMap,
                                    mod(frag_uv_tangentSpace, vec2(1.0)),
                                    normalize(toTangentSpace * normalize(frag_viewDir_worldSpace)),
                                    heightScale);
    #elif defined(POM)
    vec2 texCoord = pom(heightMap,
                        mod(frag_uv_tangentSpace, vec2(1.0)),
                        normalize(toTangentSpace * normalize(frag_viewDir_worldSpace)),
                        heightScale,
                        pomMinLayers,
                        pomMaxLayers);
    #else
    vec2 texCoord = frag_uv_tangentSpace;
    #endif

    #if defined(PARALLAX_MAPPING) || defined(POM)
    if ((texCoord.x > 1.0 || texCoord.y > 1.0 || texCoord.x < 0.0 || texCoord.y < 0.0) &&
        parallaxEdgeDiscard)
    {
        discard;
    }
    #endif

    #ifdef ALBEDO_MAP
    albedo_ *= texture(albedoMap, texCoord);
    #endif

    float roughness_ = 1.0 - smoothness;

    #ifdef SMOOTHNESS_MAP
    roughness_ *= 1.0 - texture(smoothnessMap, texCoord).r;
    #endif

    float metallic_ = metalMask;

    #ifdef METAL_MASK_MAP
    metallic_ *= texture(metalMaskMap, texCoord).r;
    #endif

    #ifdef NORMAL_MAP
    normal_worldSpace = fromTangentSpace * normalize(texture(normalMap, texCoord).xyz * 2.0 - 1.0);

    normal_worldSpace = normalize(normal_worldSpace);
    #endif

    result_albedo = albedo_.rgb;
    result_material = vec2(metallic_, roughness_);
    result_normal.rgb = normal_worldSpace;
}
