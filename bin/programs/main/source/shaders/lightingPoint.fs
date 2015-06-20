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

uniform vec3 lightNegDir;
uniform vec3 lightPos;
uniform float lightRadius;
uniform vec3 lightColor;

float random(vec3 seed, int i)
{
    vec4 seed4 = vec4(seed,i);
    float dot_product = dot(seed4, vec4(12.9898,78.233,45.164,94.673));
    return fract(sin(dot_product) * 43758.5453);
}

vec2 poissonDisk[16] = vec2[]( 
   vec2( -0.94201624, -0.39906216 ), 
   vec2( 0.94558609, -0.76890725 ), 
   vec2( -0.094184101, -0.92938870 ), 
   vec2( 0.34495938, 0.29387760 ), 
   vec2( -0.91588581, 0.45771432 ), 
   vec2( -0.81544232, -0.87912464 ), 
   vec2( -0.38277543, 0.27676845 ), 
   vec2( 0.97484398, 0.75648379 ), 
   vec2( 0.44323325, -0.97511554 ), 
   vec2( 0.53742981, -0.47373420 ), 
   vec2( -0.26496911, -0.41893023 ), 
   vec2( 0.79197514, 0.19090188 ), 
   vec2( -0.24188840, 0.99706507 ), 
   vec2( -0.81409955, 0.91437590 ), 
   vec2( 0.19984126, 0.78641367 ), 
   vec2( 0.14383161, -0.14100790 ) 
);

#define RADIUS 0.01
//#define ROUNDING 1000.0
//#define RANDOM_SEED (vec3(ivec3((position.xyz * ROUNDING))) / ROUNDING)
#define RANDOM_SEED gl_FragCoord.xyy

#define SAMPLE_SHADOW(i) poisson.xy = poissonDisk[i];\
poisson = vec3(poisson.x * c + poisson.y * s,\
               poisson.x * -s + poisson.y * c,\
               0.0) * RADIUS;\
shadow += texture(shadowmap, vec4(normalize(-dir + xAxis * poisson + cross(xAxis, dir) * poisson), shadowDist / lightFar));

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
    
    float intensity = 1.0 / pow(dist / lightRadius + 1.0, 2.0);
    
    _lighting(dir,
              specular,
              diffuse,
              mix(vec3(1.0), albedo, metallic),
              roughness,
              metallic,
              normal,
              viewDir);
    
    #ifdef SHADOW_MAP
    float shadow = 0.0;
    float shadowDist = dist - max(shadowBiasScale * (1.0 - dot(normal, dir)), shadowMinBias);
    
    float angle = random(RANDOM_SEED, 0) * 6.283285;
    float s = sin(angle);
    float c = cos(angle);
    
    vec3 xAxis = vec3(0.0, 1.0, 0.0);

    if (abs(dot(xAxis, dir)) >= 1.0)
    {
        xAxis = vec3(0.0, 0.0, 1.0);
    }
    
    vec3 left = normalize(cross(dir, xAxis));
    xAxis = normalize(cross(dir, left));
    
    int index;
    vec3 poisson;

    SAMPLE_SHADOW(0)
    SAMPLE_SHADOW(1)
    SAMPLE_SHADOW(2)
    SAMPLE_SHADOW(3)
    SAMPLE_SHADOW(4)
    SAMPLE_SHADOW(5)
    SAMPLE_SHADOW(6)
    SAMPLE_SHADOW(7)
    SAMPLE_SHADOW(8)
    SAMPLE_SHADOW(9)
    SAMPLE_SHADOW(10)
    SAMPLE_SHADOW(11)
    SAMPLE_SHADOW(12)
    SAMPLE_SHADOW(13)
    SAMPLE_SHADOW(14)
    SAMPLE_SHADOW(15)
    
    shadow /= 16.0;
    
    shadow += dFdx(shadow) + shadow +
              dFdy(shadow) + shadow;
    
    shadow /= 3.0;
    
    intensity = min(intensity, shadow);
    #endif
    
    float ao = max(texture(aoTexture, frag_uv).r * clamp(1.0 - diffuse * intensity, 0.0, 1.0), 0.0);
    
    result_color.rgb = albedo * 0.01 * (1.0 - metallic) * ao;
    result_color.a = 1.0;
    
    vec3 diffuseResult = mix(albedo, vec3(0.0), metallic) * diffuse;
    
    result_color.rgb += (diffuseResult + specular) * lightColor * intensity;
}

