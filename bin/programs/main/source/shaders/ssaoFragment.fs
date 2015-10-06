#define PI 3.14159265f

#define NUM_STEPS 4
#define NUM_DIRECTIONS 4

layout (location = 0) out vec4 result_ao;

in vec2 frag_uv;

uniform sampler2D depthTexture;
uniform sampler2D normalTexture;
uniform sampler2D randomTexture;
uniform mat4 inverseProjectionMatrix;
uniform mat3 normalMatrix;
uniform float radius;
uniform float exponent;
uniform float multiplier;
uniform float cosAngleBias;

vec3 minDiff(vec3 P, vec3 P1, vec3 P2)
{
    vec3 V1 = P1 - P;
    vec3 V2 = P - P2;
    return (dot(V1, V1) < dot(V2, V2)) ? V1 : V2;
}

vec3 getPosition(vec2 uv, vec2 resolution)
{
    uv = clamp(uv, 0.0, 1.0);

    vec3 position = vec3(uv, texelFetch(depthTexture, ivec2(uv*resolution), 0).r);
    position = position * 2.0 - 1.0;
    vec4 position4 = inverseProjectionMatrix * vec4(position, 1.0);
    vec3 result = position4.xyz / position4.w;
    return result;
}

float falloff(float dist)
{
    return dist * (-1.0 / radius) + 1.0;
}

void main()
{
    vec2 resolution = vec2(textureSize(depthTexture, 0));
    vec2 onePixel = 1.0 / resolution;
    
    vec3 position = getPosition(frag_uv, resolution);
    
    vec3 normal = normalize(normalMatrix * normalize(texture(normalTexture, frag_uv).xyz));
    
    float radiusPixels = radius * resolution.y / abs(position.z);
    
    float stepSize = radiusPixels / (NUM_STEPS + 1);
    
    vec3 random = texelFetch(randomTexture, ivec2(gl_FragCoord.xy) % 4, 0).xyz;
    
    mat2 rotationMatrix = mat2(random.x, -random.y, 
                               random.y, random.x);
    
    float AO = 0;
    
    for (uint i = uint(0); i < uint(NUM_DIRECTIONS); ++i)
    {
        float angle = 2.0 * PI / float(NUM_DIRECTIONS) * float(i);
        
        float c = cos(angle);
        float s = sin(angle);
        
        vec2 dir = rotationMatrix * vec2(s, c);
        
        float rayPixels = stepSize * random.z + 1.0;
        
        for (uint j = uint(0); j < uint(NUM_STEPS); ++j)
        {
            vec2 uv = frag_uv + round(rayPixels * dir) * onePixel;
            
            if ((clamp(uv.x, 0.0, 1.0) == uv.x) &&
                (clamp(uv.y, 0.0, 1.0) == uv.y))
            {
                vec3 samplePos = getPosition(uv, resolution);
                
                rayPixels += stepSize;
                
                vec3 V = samplePos - position;
                float Vlength = length(V);
                float NdotV = dot(normal, V) / Vlength;
                
                AO += clamp(NdotV - cosAngleBias, 0.0, 1.0) * clamp(falloff(Vlength), 0.0, 1.0);
            }
        }
    }
    
    AO *= multiplier / (NUM_DIRECTIONS * NUM_STEPS);
    AO = clamp(1.0 - AO, 0.0, 1.0);
    
    result_ao = vec4(pow(AO, exponent), normal);
}
