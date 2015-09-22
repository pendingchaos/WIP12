#include "lib/color.glsl"
#define FORWARD_LIGHTING
#include "lib/lighting.glsl"
#include "lib/parallax.glsl"
#include "lib/uniform.glsl"

in vec3 frag_normal_worldSpace;
in vec2 frag_uv_tangentSpace;
in vec3 frag_position_worldSpace;
in vec3 frag_viewDir_worldSpace;
in vec3 frag_tangent_worldSpace;
in vec3 frag_bitangent_worldSpace;

layout (location = 0) out vec4 result_color;

DECLUNIFORM(vec4, albedo)
DECLUNIFORM(float, smoothness)
DECLUNIFORM(float, metalMask)

#ifdef ALBEDO_MAP
DECLUNIFORM(sampler2D, albedoMap)
#endif

#ifdef MATERIAL_MAP
DECLUNIFORM(sampler2D, materialMap)
#endif

#ifdef NORMAL_MAP
DECLUNIFORM(sampler2D, normalMap)
#endif

#if defined(PARALLAX_MAPPING) || defined(POM)
DECLUNIFORM(sampler2D, heightMap)
DECLUNIFORM(float, heightScale)
DECLUNIFORM(bool, parallaxEdgeDiscard)
#endif

#ifdef POM
DECLUNIFORM(uint, pomMinLayers)
DECLUNIFORM(uint, pomMaxLayers)
#endif

void main()
{
    vec4 albedo_ = U(albedo);
    vec3 normal_worldSpace = normalize(frag_normal_worldSpace);

    #if defined(NORMAL_MAP) || defined(PARALLAX_MAPPING) || defined(POM)
    mat3 fromTangentSpace = mat3(normalize(frag_tangent_worldSpace), normalize(frag_bitangent_worldSpace), normal_worldSpace);
    mat3 toTangentSpace = transpose(fromTangentSpace);
    #endif

    #ifdef PARALLAX_MAPPING
    vec2 texCoord = parallaxMapping(U(heightMap),
                                    mod(frag_uv_tangentSpace, vec2(1.0)),
                                    normalize(toTangentSpace * normalize(frag_viewDir_worldSpace)),
                                    U(heightScale));
    #elif defined(POM)
    vec2 texCoord = pom(U(heightMap),
                        mod(frag_uv_tangentSpace, vec2(1.0)),
                        normalize(toTangentSpace * normalize(frag_viewDir_worldSpace)),
                        U(heightScale),
                        U(pomMinLayers),
                        U(pomMaxLayers));
    #else
    vec2 texCoord = frag_uv_tangentSpace;
    #endif

    #if defined(PARALLAX_MAPPING) || defined(POM)
    if ((texCoord.x > 1.0 || texCoord.y > 1.0 || texCoord.x < 0.0 || texCoord.y < 0.0) &&
        U(parallaxEdgeDiscard))
    {
        discard;
    }
    #endif

    #ifdef ALBEDO_MAP
    albedo_ *= texture(U(albedoMap), texCoord);
    #endif

    float roughness_ = 1.0 - U(smoothness);
    float metallic_ = U(metalMask);

    #ifdef MATERIAL_MAP
    vec2 material = texture(U(materialMap), texCoord).rg;

    roughness_ *= 1.0 - material.r;
    metallic_ *= material.g;
    #endif

    #ifdef NORMAL_MAP
    normal_worldSpace = fromTangentSpace * normalize(texture(U(normalMap), texCoord).xyz * 2.0 - 1.0);

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
