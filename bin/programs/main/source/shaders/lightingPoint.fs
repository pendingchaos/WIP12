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
uniform samplerCubeShadow shadowmap;
uniform mat4 shadowmapViewMatrix;
uniform mat4 shadowmapProjectionMatrix;
uniform float shadowMinBias;
uniform float shadowBiasScale;
uniform float lightFar;
#endif

uniform vec3 cameraPosition;

uniform vec3 lightPos;
uniform float lightRadius;
uniform vec3 lightColor;

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

    float ao = max(texture(aoTexture, frag_uv).r, 0.0);
    
    result_color.rgb = pointLight(lightPos, lightRadius, lightColor, 0.05,
                                  albedo, metallic, roughness, normal, viewDir, ao, position
    #ifdef SHADOW_MAP
    , shadowmap, 0.01, shadowBiasScale, shadowMinBias, lightFar
    #endif
    );
    result_color.a = 1.0;
}

