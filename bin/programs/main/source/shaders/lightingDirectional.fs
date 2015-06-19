#include "lib/lighting.glsl"

layout (location = 0) out vec4 result_color;

in vec2 frag_uv;

uniform sampler2D albedoTexture;
uniform sampler2D materialTexture;
uniform sampler2D normalTexture;
uniform sampler2D depthTexture;
uniform sampler2D aoTexture;
uniform mat4 viewProjection;

#ifdef SHADOW_MAP
uniform sampler2DShadow shadowmap;
uniform mat4 shadowmapViewMatrix;
uniform mat4 shadowmapProjectionMatrix;
uniform float shadowMinBias;
uniform float shadowBiasScale;
#endif

uniform vec3 cameraPosition;

uniform vec3 lightColor;
uniform vec3 lightNegDir;

void main()
{
    vec3 albedo = texture(albedoTexture, frag_uv).rgb;
    vec2 material = texture(materialTexture, frag_uv).rg;
    vec3 normal = normalize(texture(normalTexture, frag_uv).rgb);
    
    vec3 position = vec3(frag_uv, texture(depthTexture, frag_uv).r);
    position = position * 2.0 - 1.0;
    vec4 position4 = inverse(viewProjection) * vec4(position, 1.0);
    position = position4.xyz / position4.w;
    
    float metallic = material.x;
    float roughness = material.y;
    
    vec3 viewDir = normalize(cameraPosition - position);

    vec3 specular;
    float diffuse;
    
    _lighting(lightNegDir,
              specular,
              diffuse,
              mix(vec3(1.0), albedo.rgb, metallic),
              roughness,
              metallic,
              normal,
              viewDir);
    
    vec3 diffuseResult = mix(albedo, vec3(0.0), metallic) * diffuse;
    
    #ifdef SHADOW_MAP
    vec4 shadowCoord = shadowmapProjectionMatrix * shadowmapViewMatrix * vec4(position, 1.0);
    
    shadowCoord.xyz /= shadowCoord.w;
    shadowCoord.z -= max(shadowBiasScale * (1.0 - dot(normal, lightNegDir)), shadowMinBias);
    shadowCoord.xyz += 1.0;
    shadowCoord.xyz /= 2.0;
    
    float shadow = 0.0;
    
    shadow += textureOffset(shadowmap, shadowCoord.xyz, ivec2(0, 0));
    shadow += textureOffset(shadowmap, shadowCoord.xyz, ivec2(0, 1));
    shadow += textureOffset(shadowmap, shadowCoord.xyz, ivec2(1, -1));
    shadow += textureOffset(shadowmap, shadowCoord.xyz, ivec2(1, 0));
    shadow += textureOffset(shadowmap, shadowCoord.xyz, ivec2(1, 1));
    shadow += textureOffset(shadowmap, shadowCoord.xyz, ivec2(-2, -1));
    shadow += textureOffset(shadowmap, shadowCoord.xyz, ivec2(-2, 0));
    shadow += textureOffset(shadowmap, shadowCoord.xyz, ivec2(-2, 2));
    shadow += textureOffset(shadowmap, shadowCoord.xyz, ivec2(0, -2));
    shadow += textureOffset(shadowmap, shadowCoord.xyz, ivec2(0, 2));
    shadow += textureOffset(shadowmap, shadowCoord.xyz, ivec2(2, -2));
    shadow += textureOffset(shadowmap, shadowCoord.xyz, ivec2(2, 0));
    shadow += textureOffset(shadowmap, shadowCoord.xyz, ivec2(2, 2));
   
    shadow /= 17.0;
    
    shadow = pow(shadow, 2.2);
    #endif
    
    float ao = max(texture(aoTexture, frag_uv).r * (1.0 -
    #ifdef SHADOW_MAP
    min(diffuse, shadow)
    #else
    diffuse
    #endif
    ), 0.0);
    
    result_color.rgb = albedo * 0.05 * (1.0 - metallic) * ao;
    result_color.a = 1.0;
    
    result_color.rgb += (diffuseResult + specular) * lightColor
    #ifdef SHADOW_MAP
    * shadow
    #endif
    ;
}

