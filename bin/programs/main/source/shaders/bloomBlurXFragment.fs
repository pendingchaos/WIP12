#include "lib/uniform.glsl"

layout (location = 0) out vec3 result_color;

in vec2 frag_uv;

DECLUNIFORM(sampler2D, bloomTexture)
DECLUNIFORM(int, radius)
DECLUNIFORM(float, sigma)

float gauss(float x)
{
    return U(radius) == 0 ?
           1.0 :
           ((1.0 / (U(sigma)*sqrt(2.0*3.141529))) *
            exp(-(x*x) / (2.0*U(sigma)*U(sigma))));
}

void main()
{
    vec2 onePixel = 1.0 / vec2(textureSize(U(bloomTexture), 0));
    result_color = texture(U(bloomTexture), frag_uv).rgb * gauss(0.0);
    
    float sum = gauss(0.0);
    
    for (float x = 1.0; x < U(radius); x += 2.0)
    {
        float offset1 = x;
        float offset2 = offset1 + 1.0;
        
        float weight1 = gauss(offset1);
        float weight2 = gauss(offset2);
        
        float weight = weight1 + weight2;
        
        float offset = (offset1 * weight1 + offset2 * weight2) / weight;
        
        result_color += texture(U(bloomTexture), frag_uv+vec2(offset*onePixel.x, 0.0)).rgb * weight;
        result_color += texture(U(bloomTexture), frag_uv-vec2(offset*onePixel.x, 0.0)).rgb * weight;
        
        sum += weight * 2.0;
    }
    
    result_color /= sum;
}

