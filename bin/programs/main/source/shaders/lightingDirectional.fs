#include "lib/lighting.glsl"

layout (location = 0) out vec4 result_color;

in vec2 frag_uv;

uniform sampler2D albedoTexture;
uniform sampler2D materialTexture;
uniform sampler2D normalTexture;
uniform sampler2D geomNormalTexture;
uniform sampler2D depthTexture;
uniform sampler2D aoTexture;
uniform mat4 viewProjection;

#ifdef SHADOW_MAP
uniform sampler2DArrayShadow shadowmap;
uniform sampler2DArray depthmap;
uniform mat4 shadowmapViewMatrices[4];
uniform mat4 shadowmapProjectionMatrices[4];
uniform float shadowMinBias;
uniform float shadowBiasScale;
uniform float shadowFixedBias;
#endif

uniform vec3 cameraPosition;

uniform vec3 lightColor;
uniform float lightAmbientStrength;
uniform vec3 lightNegDir;

#ifdef SHADOW_MAP
bvec2 greater(vec2 a, vec2 b)
{
    return bvec2(a.x > b.x, a.y > b.y);
}

bvec2 less(vec2 a, vec2 b)
{
    return bvec2(a.x < b.x, a.y < b.y);
}

bool cascadeTest(in vec3 pos, in int index)
{
    vec4 pos_ = shadowmapProjectionMatrices[index] *
                shadowmapViewMatrices[index] *
                vec4(pos, 1.0);
    pos_.xy /= pos_.w;
    
    bvec2 result = greater(pos_.xy, vec2(-1.0)) && less(pos_.xy, vec2(1.0));
    return result.x && result.y;
}
#endif

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
    uint cascade = 3;
    
    if (cascadeTest(position, 0))
    {
        cascade = 0;
    } else if (cascadeTest(position, 1))
    {
        cascade = 1;
    } else if (cascadeTest(position, 2))
    {
        cascade = 2;
    }
    
    //vec3 cascadeColor = vec3[](vec3(1.0, 0.0, 0.0), vec3(1.0, 1.0, 0.0), vec3(0.0, 1.0, 0.0), vec3(0.0, 0.0, 1.0))[cascade];
    //albedo = cascadeColor + vec3(0.1);
    //metallic = 0.0;
    //roughness = 1.0;
    
    vec4 shadowCoord = shadowmapProjectionMatrices[cascade] *
                       shadowmapViewMatrices[cascade] *
                       vec4(position, 1.0);
    
    shadowCoord.xyz /= shadowCoord.w;
    shadowCoord.z -= max(shadowBiasScale * (1.0 - dot(texture(geomNormalTexture, frag_uv).rgb, lightNegDir)), shadowMinBias);
    shadowCoord.z -= shadowFixedBias;
    shadowCoord.xyz += 1.0;
    shadowCoord.xyz /= 2.0;
    #endif
    
    float ao = texture(aoTexture, frag_uv).r;
    
    result_color.rgb = directionalLight(lightNegDir, lightColor, lightAmbientStrength,
                                        albedo, metallic, roughness, normal, viewDir, ao
    #ifdef SHADOW_MAP
    , shadowCoord, shadowmap, depthmap, float(cascade)
    #endif
    );
    result_color.a = 1.0;
}

