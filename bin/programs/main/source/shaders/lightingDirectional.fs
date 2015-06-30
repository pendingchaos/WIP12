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
uniform float lightAmbientStrength;
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
    
    #ifdef SHADOW_MAP
    vec4 shadowCoord = shadowmapProjectionMatrix * shadowmapViewMatrix * vec4(position, 1.0);
    
    shadowCoord.xyz /= shadowCoord.w;
    shadowCoord.z -= max(shadowBiasScale * (1.0 - dot(normal, lightNegDir)), shadowMinBias);
    shadowCoord.xyz += 1.0;
    shadowCoord.xyz /= 2.0;
    #endif
    
    float ao = texture(aoTexture, frag_uv).r;
    
    result_color.rgb = directionalLight(lightNegDir, lightColor, lightAmbientStrength,
                                        albedo, metallic, roughness, normal, viewDir, ao
    #ifdef SHADOW_MAP
    , shadowCoord, shadowmap
    #endif
    );
    result_color.a = 1.0;
}

