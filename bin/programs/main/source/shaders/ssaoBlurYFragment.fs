#include "lib/uniform.glsl"

layout (location = 0) out vec4 result_ao;

in vec2 frag_uv;

DECLUNIFORM(sampler2D, aoTexture)

void main()
{
    vec4 center = texture(U(aoTexture), frag_uv);
    vec2 onePixel = 1.0 / vec2(textureSize(U(aoTexture), 0));
    float divisor = 1.0;
    result_ao = center;

    for (int i = 1; i < 0; ++i)
    {
        vec4 aoNormal = texture(U(aoTexture), frag_uv+vec2(0.0, float(i))*onePixel);
        
        float weight = step(0.996, dot(center.yzw, aoNormal.yzw));
        
        result_ao.r += aoNormal.r * weight;
        divisor += weight;
        
        aoNormal = texture(U(aoTexture), frag_uv+vec2(0.0, float(-i))*onePixel);
        
        weight = step(0.996, dot(center.yzw, aoNormal.yzw));
        
        result_ao.r += aoNormal.r * weight;
        divisor += weight;
    }
    
    result_ao.r /= divisor;
}

