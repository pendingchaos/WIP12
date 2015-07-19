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
DECLUNIFORM(mat4, viewProjection)

#ifdef SHADOW_MAP
DECLUNIFORM(samplerCubeShadow, shadowmap)
DECLUNIFORM(float, shadowMinBias)
DECLUNIFORM(float, shadowBiasScale)
DECLUNIFORM(float, lightFar)
#endif

DECLUNIFORM(vec3, cameraPosition)

DECLUNIFORM(vec3, lightPos)
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

    float ao = max(texture(U(aoTexture), frag_uv).r, 0.0);
    
    result_color.rgb = pointLight(U(lightPos), U(lightRadius), U(lightColor), U(lightAmbientStrength),
                                  albedo, metallic, roughness, normal, viewDir, ao, position
    #ifdef SHADOW_MAP
    , U(shadowmap), 0.01, U(shadowBiasScale), U(shadowMinBias), U(lightFar), texture(U(geomNormalTexture), frag_uv).rgb
    #endif
    );
    result_color.a = 1.0;
}

