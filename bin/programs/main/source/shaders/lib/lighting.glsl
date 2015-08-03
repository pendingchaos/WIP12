#include "uniform.glsl"

#ifndef LIGHTING_INCLUDED
#define LIGHTING_INCLUDED

#define PI 3.14159265358979323846

#ifdef FORWARD_LIGHTING
#define MAX_SPOT_LIGHTS 112
#define MAX_POINT_LIGHTS 256
#define MAX_DIRECTIONAL_LIGHTS 32

struct SpotLight
{
    vec4 negDir;
    vec4 position;
    vec4 color;
    vec4 data; //x = cosInnerCutoff;
               //y = cosOuterCutoff;
               //z = radius;
               //w = ambientStrength;
};

struct PointLight
{
    vec4 positionAndRadius;
    vec4 colorAndAmbientStrength;
};

struct DirectionalLight
{
    vec4 colorAndAmbientStrength;
    vec4 negDir;
};

DECLUNIFORM(uint, numSpotLights)
DECLUNIFORM(uint, numPointLights)
DECLUNIFORM(uint, numDirectionalLights)

layout (std140) uniform lights_
{
    SpotLight spotLights[MAX_SPOT_LIGHTS];
    PointLight pointLights[MAX_POINT_LIGHTS];
    DirectionalLight directionalLights[MAX_DIRECTIONAL_LIGHTS];
};
#endif

vec3 GGX(float nh, float roughness)
{
    float a = roughness * roughness;

    float a2 = a * a;

    float v = nh*nh * (a2 - 1.0) + 1.0;

    return vec3(a2 / (PI * v*v));
}

float _G1(float nv, float k)
{
    return nv / (nv * (1.0 - k) + k);
}

vec3 SchlickG(float nl, float nv, float roughness)
{
    //Remap roughness
    float roughness2 = (roughness + 1.0) / 2.0;

    float k = roughness2 + 1.0;
    k *= k;
    k /= 8.0;

    return vec3(_G1(nl, k) * _G1(nv, k));
}

vec3 SchlickF(float vh, float lh, vec3 specularColor, float metallic)
{
    vec3 f0 = mix(0.04, 1.0, metallic) * specularColor;

    return f0 + (1.0 - f0) * pow(2.0, (-5.55473 * vh - 6.98316) * vh);
}

void _lighting(vec3 lightDir, out vec3 specular, out float diffuse, vec3 specularColor, float roughness, float metallic, vec3 normal, vec3 viewDir)
{
    vec3 n = normalize(normal);
    vec3 v = normalize(viewDir);
    vec3 l = lightDir;
    vec3 h = normalize(l + v);
    float nl = max(dot(n, l), 0.0);
    float nh = max(dot(n, h), 0.0);
    float vh = max(dot(v, h), 0.0);
    float nv = max(dot(n, v), 0.0);
    float lh = max(dot(l, h), 0.0);

    vec3 D = max(GGX(nh, roughness), 0.0);
    vec3 F = max(SchlickF(vh, lh, specularColor, metallic), 0.0);
    vec3 G = max(SchlickG(nl, nv, roughness), 0.0);

    specular = max((D*F*G) / (4.0*nl*nv), 0.0) * nl;
    diffuse = nl * mix(0.96, 0.0, metallic);
}

vec3 directionalLight(vec3 lightNegDir, vec3 lightColor, float lightAmbient,
                      vec3 albedo, float metallic, float roughness, vec3 normal, vec3 viewDir, float ao)
{
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
    
    albedo /= PI;    
    
    vec3 diffuseResult = albedo * diffuse;
    
    vec3 ambient = albedo * lightAmbient * mix(ao, 1.0, diffuse) * lightColor;
    
    return (diffuseResult + specular) * lightColor + mix(ambient, vec3(0.0), metallic);
}

vec3 directionalLight(vec3 lightNegDir, vec3 lightColor, float lightAmbient,
                      vec3 albedo, float metallic, float roughness, vec3 normal, vec3 viewDir, float ao,
                      vec4 shadowCoord, sampler2DShadow shadowmap)
{
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
    
    float shadow = 0.0;
    
    shadow += textureOffset(shadowmap, shadowCoord.xyz, ivec2(-2, -2));
    shadow += textureOffset(shadowmap, shadowCoord.xyz, ivec2(-2, -1));
    shadow += textureOffset(shadowmap, shadowCoord.xyz, ivec2(-2, 0));
    shadow += textureOffset(shadowmap, shadowCoord.xyz, ivec2(-2, 1));
    shadow += textureOffset(shadowmap, shadowCoord.xyz, ivec2(-2, 2));
    shadow += textureOffset(shadowmap, shadowCoord.xyz, ivec2(-1, -2));
    shadow += textureOffset(shadowmap, shadowCoord.xyz, ivec2(-1, -1));
    shadow += textureOffset(shadowmap, shadowCoord.xyz, ivec2(-1, 0));
    shadow += textureOffset(shadowmap, shadowCoord.xyz, ivec2(-1, 1));
    shadow += textureOffset(shadowmap, shadowCoord.xyz, ivec2(-1, 2));
    shadow += textureOffset(shadowmap, shadowCoord.xyz, ivec2(0, -2));
    shadow += textureOffset(shadowmap, shadowCoord.xyz, ivec2(0, -1));
    shadow += textureOffset(shadowmap, shadowCoord.xyz, ivec2(0, 0));
    shadow += textureOffset(shadowmap, shadowCoord.xyz, ivec2(0, 1));
    shadow += textureOffset(shadowmap, shadowCoord.xyz, ivec2(0, 2));
    shadow += textureOffset(shadowmap, shadowCoord.xyz, ivec2(2, -2));
    shadow += textureOffset(shadowmap, shadowCoord.xyz, ivec2(2, -1));
    shadow += textureOffset(shadowmap, shadowCoord.xyz, ivec2(2, 0));
    shadow += textureOffset(shadowmap, shadowCoord.xyz, ivec2(2, 1));
    shadow += textureOffset(shadowmap, shadowCoord.xyz, ivec2(2, 2));
    shadow += textureOffset(shadowmap, shadowCoord.xyz, ivec2(1, -2));
    shadow += textureOffset(shadowmap, shadowCoord.xyz, ivec2(1, -1));
    shadow += textureOffset(shadowmap, shadowCoord.xyz, ivec2(1, 0));
    shadow += textureOffset(shadowmap, shadowCoord.xyz, ivec2(1, 1));
    shadow += textureOffset(shadowmap, shadowCoord.xyz, ivec2(1, 2));
   
    shadow /= 25.0;
    
    shadow = pow(shadow, 2.2);
    
    albedo /= PI;
    
    vec3 diffuseResult = albedo * min(diffuse, shadow);
    
    vec3 ambient = albedo * lightAmbient * mix(ao, 1.0, min(diffuse, shadow)) * lightColor;
    
    return (diffuseResult + specular * shadow) * lightColor + mix(ambient, vec3(0.0), metallic);
}

vec3 spotLight(vec3 lightNegDir, vec3 lightPos, float lightCosInnerCutoff, float lightCosOuterCutoff,
               float lightRadius, vec3 lightColor, float lightAmbient,
               vec3 albedo, float metallic, float roughness, vec3 normal, vec3 viewDir, float ao, vec3 position)
{
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
    
    albedo /= PI;
    
    vec3 diffuseResult = albedo * diffuse;
    
    vec3 ambient = albedo * lightAmbient * mix(ao, 1.0, diffuse) * lightColor;
    
    return (diffuseResult + specular) * lightColor * intensity + mix(ambient, vec3(0.0), metallic);
}

vec3 spotLight(vec3 lightNegDir, vec3 lightPos, float lightCosInnerCutoff, float lightCosOuterCutoff,
               float lightRadius, vec3 lightColor, float lightAmbient,
               vec3 albedo, float metallic, float roughness, vec3 normal, vec3 viewDir, float ao, vec3 position,
               vec4 shadowCoord, sampler2DShadow shadowmap)
{
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
    
    albedo /= PI;
    
    vec3 diffuseResult = albedo * diffuse;
    
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
    
    intensity = min(intensity, shadow);
    
    vec3 ambient = albedo * lightAmbient * mix(ao, 1.0, min(diffuse, shadow)) * lightColor;
    
    return (diffuseResult + specular) * lightColor * intensity + mix(ambient, vec3(0.0), metallic);
}

vec3 pointLight(vec3 lightPos, float lightRadius, vec3 lightColor, float lightAmbient,
                vec3 albedo, float metallic, float roughness, vec3 normal, vec3 viewDir, float ao, vec3 position)
{
    vec3 specular;
    float diffuse;
    
    vec3 dir = lightPos - position;
    float dist = length(dir);
    dir = normalize(dir);
    
    float intensity = 1.0 / pow(dist / lightRadius + 1.0, 2.0);
    
    _lighting(dir,
              specular,
              diffuse,
              mix(vec3(1.0), albedo, metallic),
              roughness,
              metallic,
              normal,
              viewDir);
    
    albedo /= PI;
    
    vec3 ambient = albedo * lightAmbient * mix(ao, 1.0, diffuse) * lightColor;
    
    vec3 diffuseResult = albedo * diffuse;
    
    return (diffuseResult + specular) * lightColor * intensity + mix(ambient, vec3(0.0), metallic);
}

float _pointLightRandom(vec3 seed, int i)
{
    vec4 seed4 = vec4(seed,i);
    float dot_product = dot(seed4, vec4(12.9898,78.233,45.164,94.673));
    return fract(sin(dot_product) * 43758.5453);
}

#define SAMPLE_SHADOW(poissonValue) poisson = vec3(poissonValue.x * c + poissonValue.y * s,\
                                                   poissonValue.x * -s + poissonValue.y * c,\
                                                   0.0) * shadowRadius;\
shadow += texture(shadowmap, vec4(normalize(-dir + xAxis * poisson + cross(xAxis, dir) * poisson), shadowDist / lightFar));

vec3 pointLight(vec3 lightPos, float lightRadius, vec3 lightColor, float lightAmbient,
                vec3 albedo, float metallic, float roughness, vec3 normal, vec3 viewDir, float ao, vec3 position,
                samplerCubeShadow shadowmap, float shadowRadius, float shadowBiasScale, float shadowMinBias, float lightFar, vec3 geomNormal)
{
    vec3 specular;
    float diffuse;
    
    vec3 dir = lightPos - position;
    float dist = length(dir);
    dir = normalize(dir);
    
    float intensity = 1.0 / pow(dist / lightRadius + 1.0, 2.0);
    
    _lighting(dir,
              specular,
              diffuse,
              mix(vec3(1.0), albedo, metallic),
              roughness,
              metallic,
              normal,
              viewDir);
    
    float shadow = 0.0;
    float shadowDist = dist - max(shadowBiasScale * (1.0 - dot(geomNormal, dir)), shadowMinBias);
    
    float angle = _pointLightRandom(gl_FragCoord.xyy, 0) * 6.283285;
    float s = sin(angle);
    float c = cos(angle);
    
    vec3 xAxis = vec3(0.0, 1.0, 0.0);

    if (abs(dot(xAxis, dir)) >= 1.0)
    {
        xAxis = vec3(0.0, 0.0, 1.0);
    }
    
    vec3 left = normalize(cross(dir, xAxis));
    xAxis = normalize(cross(dir, left));
    
    vec3 poisson;
    
    SAMPLE_SHADOW(vec2(-0.94201624, -0.39906216))
    SAMPLE_SHADOW(vec2(0.94558609, -0.76890725))
    SAMPLE_SHADOW(vec2(-0.094184101, -0.92938870))
    SAMPLE_SHADOW(vec2(0.34495938, 0.29387760))
    SAMPLE_SHADOW(vec2(-0.91588581, 0.45771432))
    SAMPLE_SHADOW(vec2(-0.81544232, -0.87912464))
    SAMPLE_SHADOW(vec2(-0.38277543, 0.27676845))
    SAMPLE_SHADOW(vec2(0.97484398, 0.75648379))
    SAMPLE_SHADOW(vec2(0.44323325, -0.97511554))
    SAMPLE_SHADOW(vec2(0.53742981, -0.47373420))
    SAMPLE_SHADOW(vec2(-0.26496911, -0.41893023))
    SAMPLE_SHADOW(vec2(0.79197514, 0.19090188))
    SAMPLE_SHADOW(vec2(-0.24188840, 0.99706507))
    SAMPLE_SHADOW(vec2(-0.81409955, 0.91437590))
    SAMPLE_SHADOW(vec2(0.19984126, 0.78641367))
    SAMPLE_SHADOW(vec2(0.14383161, -0.14100790)) 
   
    shadow /= 16.0;
    
    //Disabled because it causes artifacts around edges of objects.
    /*shadow += dFdx(shadow) + shadow +
              dFdy(shadow) + shadow;
    
    shadow /= 3.0;*/
    
    intensity = min(intensity, shadow);
    
    albedo /= PI;
    
    vec3 ambient = albedo * lightAmbient * mix(ao, 1.0, min(diffuse, shadow)) * lightColor;
    
    vec3 diffuseResult = albedo * diffuse;
    
    return (diffuseResult + specular) * lightColor * intensity + mix(ambient, vec3(0.0), metallic);
}

#ifdef FORWARD_LIGHTING
vec3 lighting(vec3 albedo, float roughness, float metallic, vec3 normal, vec3 viewDir, vec3 position)
{
    vec3 result = vec3(0.0);
    
    for (uint i = 0; i < U(numSpotLights); ++i)
    {
        SpotLight light = spotLights[i];
        
        result += spotLight(light.negDir.xyz,
                            light.position.xyz,
                            light.data.x,
                            light.data.y,
                            light.data.z,
                            light.color.xyz,
                            light.data.w,
                            albedo,
                            metallic,
                            roughness,
                            normal,
                            viewDir,
                            1.0,
                            position);
    }
    
    for (uint i = 0; i < U(numPointLights); ++i)
    {
        PointLight light = pointLights[i];
        
        result += pointLight(light.positionAndRadius.xyz,
                             light.positionAndRadius.w,
                             light.colorAndAmbientStrength.xyz,
                             light.colorAndAmbientStrength.w,
                             albedo,
                             metallic,
                             roughness,
                             normal,
                             viewDir,
                             1.0,
                             position);
    }
    
    for (uint i = 0; i < U(numDirectionalLights); ++i)
    {
        DirectionalLight light = directionalLights[i];
        
        result += directionalLight(light.negDir.xyz,
                                   light.colorAndAmbientStrength.xyz,
                                   light.colorAndAmbientStrength.w,
                                   albedo,
                                   metallic,
                                   roughness,
                                   normal,
                                   viewDir,
                                   1.0);
    }
    
    return result;
}
#endif
#endif

