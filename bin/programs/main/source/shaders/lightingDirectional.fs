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
    
    float ao = texture(aoTexture, frag_uv).r * (1.0 - diffuse);
    
    result_color.rgb = albedo * 0.1 * (1.0 - metallic) * ao;
    result_color.a = 1.0;
    
    vec3 diffuseResult = mix(albedo, vec3(0.0), metallic) * diffuse;
            
    result_color.rgb += (diffuseResult + specular) * lightColor;
    
    //result_color = vec4(material, 0.0, 1.0);
    //result_color = vec4((normal + 1.0) / 2.0, 1.0);
    
    //result_color.rgb = position;
    
    //result_color.rgb = vec3(texture(aoTexture, frag_uv).r);
}

