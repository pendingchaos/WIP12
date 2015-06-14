#include "lib/lighting.glsl"

layout (location = 0) out vec4 result_color;

in vec2 frag_uv;

uniform sampler2D albedoTexture;
uniform sampler2D materialTexture;
uniform sampler2D normalTexture;
uniform sampler2D depthTexture;
uniform sampler2D aoTexture;
uniform mat4 viewProjection;

uniform vec3 cameraPosition;

uniform vec3 lightNegDir;
uniform vec3 lightPos;
uniform float lightCosInnerCutoff;
uniform float lightCosOuterCutoff;
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

    vec3 specular;
    float diffuse;
    
    vec3 dir = lightPos - position;
    float dist = length(dir);
    dir = normalize(dir);
    
    float outer = lightCosOuterCutoff;
    float inner = clamp(lightCosInnerCutoff, (1.0-outer)+0.0001, 1.0);
    
    float epsilon = inner - outer;
    float intensity = clamp((dot(dir, lightNegDir) - outer) / epsilon, 0.0, 1.0);
    intensity *= 1.0 / pow(dist / lightRadius + 1.0, 2.0);
    
    _lighting(lightNegDir,
              specular,
              diffuse,
              mix(vec3(1.0), albedo, metallic),
              roughness,
              metallic,
              normal,
              viewDir);
    
    float ao = max(texture(aoTexture, frag_uv).r * (1.0 - diffuse * intensity), 0.0);
    
    result_color.rgb = albedo * 0.1 * (1.0 - metallic) * ao;
    result_color.a = 1.0;
    
    vec3 diffuseResult = mix(albedo, vec3(0.0), metallic) * diffuse;
    
    result_color.rgb += (diffuseResult + specular) * lightColor * intensity;
}

