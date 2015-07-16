#include "lib/uniform.glsl"

layout (location = 0) out vec4 result_ao;

in vec2 frag_uv;

#define PI 3.14159265f

#define NUM_STEPS 4
#define NUM_DIRECTIONS 8

DECLUNIFORM(sampler2D, depthTexture)
DECLUNIFORM(sampler2D, normalTexture)
DECLUNIFORM(mat4, projectionMatrix)
DECLUNIFORM(mat3, normalMatrix)
DECLUNIFORM(float, radius)
DECLUNIFORM(float, exponent)
DECLUNIFORM(float, multiplier)
DECLUNIFORM(float, cosAngleBias)
DECLUNIFORM(vec3, random)
DECLUNIFORM(ivec2, tile)

vec3 minDiff(vec3 P, vec3 P1, vec3 P2)
{
  vec3 V1 = P1 - P;
  vec3 V2 = P - P2;
  return (dot(V1,V1) < dot(V2,V2)) ? V1 : V2;
}

vec3 getPosition(vec2 uv, vec2 resolution)
{
    uv = clamp(uv, 0.0, 1.0);

    vec3 position = vec3(uv, texelFetch(U(depthTexture), ivec2(uv*resolution) + U(tile), 0).r);
    position = position * 2.0 - 1.0;
    vec4 position4 = inverse(U(projectionMatrix)) * vec4(position, 1.0);
    return position4.xyz / position4.w;
}

float falloff(float dist)
{
    return dist * (-1.0 / U(radius)) + 1.0;
}

void main()
{
    vec2 resolution = vec2(textureSize(U(depthTexture), 0) / 4);
    vec2 onePixel = 1.0 / resolution;
    
    vec3 position = getPosition(frag_uv, resolution);
    
    vec3 normal = normalize(texture(U(normalTexture), frag_uv).xyz);
    
    float radiusPixels = U(radius) * resolution.y / position.z;
    
    float stepSize = radiusPixels / (NUM_STEPS + 1);
    
    float AO = 0;
    
    mat2 rotationMatrix = mat2(U(random).x, -U(random).y, 
                               U(random).y, U(random).x);
    
    for (uint i = uint(0); i < uint(NUM_DIRECTIONS); ++i)
    {
        float angle = 2.0 * PI / float(NUM_DIRECTIONS) * float(i);
        
        float c = cos(angle);
        float s = sin(angle);
        
        vec2 dir = rotationMatrix * vec2(s, c);
        
        float rayPixels = stepSize;
        
        for (uint j = uint(0); j < uint(NUM_STEPS); ++j)
        {
            vec3 samplePos = getPosition(round(rayPixels * dir) * onePixel + frag_uv, resolution);
            
            rayPixels += stepSize;
            
            vec3 V = samplePos - position;
            float Vlength = length(V);
            float NdotV = dot(normal, V) * 1.0/Vlength;
            
            AO += clamp(NdotV - U(cosAngleBias), 0.0, 1.0) * clamp(falloff(Vlength), 0.0, 1.0);
        }
    }
    
    AO *= U(multiplier) / (NUM_DIRECTIONS * NUM_STEPS);
    AO = clamp(1.0 - AO, 0.0, 1.0);
    
    result_ao = vec4(pow(AO, U(exponent)), normal);
}

