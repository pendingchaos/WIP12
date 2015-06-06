#ifndef LIGHTING_INCLUDED
#define LIGHTING_INCLUDED

#define PI 3.14159265358979323846

#define MAX_LIGHTS 64
#define LIGHT_DIRECTIONAL 0u
#define LIGHT_SPOT 1u
#define LIGHT_POINT 2u

struct Light
{
    vec4 f0; //R, G, B, NegDirPosX
    vec4 f1; //NegDirPosY, NegDirPosZ, NegSpotDirX, NegSpotDirY
    vec4 f2; //NegSpotDirZ, InnerCosCut, OuterCosCut, type
    vec4 f3; //Radius, unused, unused, unused
};

uniform uint numLights;
layout (std140) uniform lights_
{
    Light lights[MAX_LIGHTS];
};

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
    diffuse = nl;
}

vec3 lighting(vec3 albedo, float roughness, float metallic, vec3 normal, vec3 viewDir, vec3 position)
{
    vec3 result = vec3(0.0);
    
    for (uint i = 0; i < numLights; ++i)
    {
        result += albedo * 0.001 * (1.0 - metallic);
        
        Light light = lights[i];
        
        switch (uint(light.f2.w))
        {
        case LIGHT_DIRECTIONAL:
        {
            vec3 specular;
            float diffuse;
            
            vec3 dir = vec3(light.f0.w, light.f1.x, light.f1.y);
            
            _lighting(dir,
                      specular,
                      diffuse,
                      mix(vec3(1.0), albedo.rgb, metallic),
                      roughness,
                      metallic,
                      normal,
                      viewDir);
            
            vec3 diffuseResult = mix(albedo, vec3(0.0), metallic) * diffuse;
            
            result += (diffuseResult + specular) * light.f0.rgb;
            break;
        }
        case LIGHT_SPOT:
        {
            vec3 specular;
            float diffuse;
            
            vec3 spotDir = vec3(light.f1.z, light.f1.w, light.f2.x);
            
            vec3 dir = vec3(light.f0.w, light.f1.x, light.f1.y) - position;
            float dist = length(dir);
            dir = normalize(dir);
            
            _lighting(spotDir,
                      specular,
                      diffuse,
                      mix(vec3(1.0), albedo, metallic),
                      roughness,
                      metallic,
                      normal,
                      viewDir);
            
            float outer = light.f2.z;
            float inner = clamp(light.f2.y, (1.0-outer)+0.0001, 1.0);
            
            vec3 diffuseResult = mix(albedo, vec3(0.0), metallic) * diffuse;
            
            float epsilon = inner - outer;
            float intensity = clamp((dot(dir, spotDir) - outer) / epsilon, 0.0, 1.0);
            //float intensity = (dot(dir, spotDir) > outer) ? 1.0 : 0.0;
            intensity *= 1.0 / pow(dist / light.f3.x + 1.0, 2.0);
            
            result += (diffuseResult + specular) * light.f0.rgb * intensity;
            break;
        }
        case LIGHT_POINT:
        {
            vec3 specular;
            float diffuse;
            
            vec3 dir = vec3(light.f0.w, light.f1.x, light.f1.y) - position;
            float dist = length(dir);
            dir = normalize(dir);
            
            _lighting(dir,
                      specular,
                      diffuse,
                      mix(vec3(1.0), albedo, metallic),
                      roughness,
                      metallic,
                      normal,
                      viewDir);
            
            vec3 diffuseResult = mix(albedo, vec3(0.0), metallic) * diffuse;
            
            float intensity = 1.0 / pow(dist / light.f3.x + 1.0, 2.0);
            //float intensity = clamp((light.f3.x - dist) / light.f3.x, 0.0, 1.0);
            
            //const float cutoff = 0.001;
            
            //float radius = light.f3.x / (sqrt(1.0 / cutoff) - 1.0);
            //float intensity = 1.0 / pow(dist / radius + 1.0, 2.0);
            //intensity = (intensity - cutoff) / (1.0 - cutoff);
            //intensity = max(intensity, 0.0);
            
            result += (diffuseResult + specular) * light.f0.rgb * intensity;
            //result += albedo * intensity > 0.00001 ? 1.0 : 0.0;
            break;
        }
        }
    }
    
    return result;
}
#endif

