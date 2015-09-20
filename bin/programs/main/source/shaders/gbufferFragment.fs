#extension GL_ARB_shader_image_load_store : enable

#include "lib/color.glsl"
#include "lib/lighting.glsl"
#include "lib/parallax.glsl"
#include "lib/uniform.glsl"

#ifdef GL_ARB_shader_image_load_store
#if defined(PARALLAX_MAPPING) || defined(POM)
#else
layout(early_fragment_tests) in;
#endif
#endif

in vec3 frag_normal_worldSpace;
in vec2 frag_uv_tangentSpace;
in vec3 frag_position_worldSpace;
in vec3 frag_viewDir_worldSpace;
in vec3 frag_tangent_worldSpace;
in vec3 frag_bitangent_worldSpace;
#ifdef TERRAIN
in vec2 frag_terruv_tangentSpace;
#endif

layout (location = 0) out vec3 result_albedo;
layout (location = 1) out vec2 result_material;
layout (location = 2) out vec3 result_normal;
layout (location = 3) out vec3 result_geom_normal;

DECLUNIFORM(vec4, albedo)
DECLUNIFORM(float, smoothness)
DECLUNIFORM(float, metalMask)

#ifdef ALBEDO_MAP
DECLUNIFORM(sampler2D, albedoMap)
#endif

#ifdef SMOOTHNESS_MAP
DECLUNIFORM(sampler2D, smoothnessMap)
#endif

#ifdef METAL_MASK_MAP
DECLUNIFORM(sampler2D, metalMaskMap)
#endif

#ifdef NORMAL_MAP
DECLUNIFORM(sampler2D, normalMap)
#endif

#ifdef TERRAIN
DECLUNIFORM(sampler2D, weightMap)
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
    #ifdef TERRAIN
    float weight = texture(U(weightMap), frag_terruv_tangentSpace).r;
    #endif

    //It is important that this if before parallax mapping. Doing this before fixes artifacts with parallax edge discard.
    result_geom_normal = normalize(cross(dFdx(frag_position_worldSpace), dFdy(frag_position_worldSpace)));
    
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

    #ifdef SMOOTHNESS_MAP
    roughness_ *= 1.0 - texture(U(smoothnessMap), texCoord).r;
    #endif

    float metallic_ = U(metalMask);

    #ifdef METAL_MASK_MAP
    metallic_ *= texture((metalMaskMap), texCoord).r;
    #endif

    #ifdef NORMAL_MAP
    normal_worldSpace = fromTangentSpace * normalize(texture(U(normalMap), texCoord).xyz * 2.0 - 1.0);

    normal_worldSpace = normalize(normal_worldSpace);
    #endif

    #ifdef TERRAIN
    result_albedo = albedo_.rgb * weight;
    result_material = vec2(metallic_, roughness_) * weight;
    result_normal = normal_worldSpace * weight;
    #else
    result_albedo = albedo_.rgb;
    result_material = vec2(metallic_, roughness_);
    result_normal = normal_worldSpace;
    #endif
}
