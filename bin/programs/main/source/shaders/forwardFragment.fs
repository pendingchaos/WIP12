#include "lib/color.glsl"
#define FORWARD_LIGHTING
#include "lib/lighting.glsl"
#include "lib/parallax.glsl"

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

#ifdef MATERIAL_MAP
uniform sampler2D materialMap;
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
    float metallic_ = metalMask;

    #ifdef MATERIAL_MAP
    vec2 material = texture(materialMap, texCoord).rg;

    roughness_ *= 1.0 - material.r;
    metallic_ *= material.g;
    #endif

    #ifdef NORMAL_MAP
    normal_worldSpace = fromTangentSpace * normalize(texture(normalMap, texCoord).xyz * 2.0 - 1.0);

    normal_worldSpace = normalize(normal_worldSpace);
    #endif

    result_color.rgb = lighting(albedo_.rgb,
                                roughness_,
                                metallic_,
                                normal_worldSpace,
                                normalize(frag_viewDir_worldSpace),
                                frag_position_worldSpace);
    result_color.a = albedo_.a;
}
