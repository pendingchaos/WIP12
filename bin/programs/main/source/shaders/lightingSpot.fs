#include "lib/lighting.glsl"
#include "lib/uniform.glsl"

layout (location = 0) out vec4 result_color;

in vec2 frag_uv;

DECLUNIFORM(sampler2D, albedoTexture)
DECLUNIFORM(sampler2D, materialTexture)
DECLUNIFORM(sampler2D, normalTexture)
DECLUNIFORM(sampler2D, geomNormalTexture)
DECLUNIFORM(sampler2D, depthTexture)
DECLUNIFORM(sampler2D, aoTexture)

#ifdef SHADOW_MAP
DECLUNIFORM(sampler2DShadow, shadowmap)
DECLUNIFORM(mat4, shadowmapViewMatrix)
DECLUNIFORM(mat4, shadowmapProjectionMatrix)
DECLUNIFORM(float, shadowMinBias)
DECLUNIFORM(float, shadowBiasScale)
DECLUNIFORM(float, shadowFixedBias)
#endif

DECLUNIFORM(mat4, viewProjection)

DECLUNIFORM(vec3, cameraPosition)

DECLUNIFORM(vec3, lightNegDir)
DECLUNIFORM(vec3, lightPos)
DECLUNIFORM(float, lightCosInnerCutoff)
DECLUNIFORM(float, lightCosOuterCutoff)
DECLUNIFORM(float, lightRadius)
DECLUNIFORM(vec3, lightColor)
DECLUNIFORM(float, lightAmbientStrength)

void main()
{
    vec3 albedo = texture(U(albedoTexture), frag_uv).rgb;
    vec2 material = texture(U(materialTexture), frag_uv).rg;
    vec3 normal = normalize(texture(U(normalTexture), frag_uv).rgb);
    
    vec3 position = vec3(frag_uv, texture(U(depthTexture), frag_uv).r);
    position = position * 2.0 - 1.0;
    vec4 position4 = inverse(U(viewProjection)) * vec4(position, 1.0);
    position = position4.xyz / position4.w;
    
    float metallic = material.x;
    float roughness = material.y;
    
    vec3 viewDir = normalize(U(cameraPosition) - position);

    #ifdef SHADOW_MAP
    vec4 shadowCoord = U(shadowmapProjectionMatrix) * U(shadowmapViewMatrix) * vec4(position, 1.0);
    
    shadowCoord.xyz /= shadowCoord.w;
    shadowCoord.z -= max(U(shadowBiasScale) * (1.0 - dot(texture(U(geomNormalTexture), frag_uv).rgb, U(lightNegDir))), U(shadowMinBias));
    shadowCoord.z -= U(shadowFixedBias);
    shadowCoord.xyz += 1.0;
    shadowCoord.xyz /= 2.0;
    #endif
    
    float ao = max(texture(U(aoTexture), frag_uv).r, 0.0);
    
    result_color.rgb = spotLight(U(lightNegDir), U(lightPos), U(lightCosInnerCutoff), U(lightCosOuterCutoff), U(lightRadius), U(lightColor),
                                 U(lightAmbientStrength), albedo, metallic, roughness, normal, viewDir, ao, position
#ifdef SHADOW_MAP
, shadowCoord, U(shadowmap)
#endif
);
    result_color.a = 1.0;
}

