#include "lib/uniform.glsl"

layout (location = 0) out vec3 result_color;

in vec2 frag_uv;

DECLUNIFORM(sampler2D, bloomTexture)
DECLUNIFORM(sampler2D, colorTexture)
DECLUNIFORM(float, divisor)
DECLUNIFORM(int, radius)
DECLUNIFORM(float, sigma)
DECLUNIFORM(float, step)

float gauss(float x)
{
    return (1.0 / (U(sigma)*sqrt(2.0*3.141529))) *
           exp(-(x*x) / (2.0*U(sigma)*U(sigma)));
}

void main()
{
    vec2 onePixel = 1.0 / vec2(textureSize(U(bloomTexture), 0));
    result_color = vec3(0.0);
    
    for (float y = -U(radius); y < U(radius)+1; y += U(step))
    {
        result_color += texture(U(bloomTexture), frag_uv+vec2(0.0, y*onePixel.y)).rgb * gauss(y);
    }
    
    result_color /= U(divisor);
    
    result_color += texture(U(colorTexture), frag_uv).rgb;
}

