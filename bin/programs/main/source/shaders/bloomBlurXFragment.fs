#include "lib/color.glsl"
#include "lib/uniform.glsl"

layout (location = 0) out vec3 result_color;

in vec2 frag_uv;

DECLUNIFORM(sampler2D, colorTexture)
DECLUNIFORM(float, threshold)
DECLUNIFORM(float, divisor)
DECLUNIFORM(int, radius)
DECLUNIFORM(float, sigma)
DECLUNIFORM(float, step)

vec3 sampleTexture(vec2 uv)
{
    vec3 color = texture(U(colorTexture), uv).rgb;
    
    vec3 xyY = RGBToxyY(color);
    
    return (xyY.z > U(threshold)) ? xyYToRGB(xyY - vec3(0.0, 0.0, 1.0)) : vec3(0.0);
}

float gauss(float x)
{
    return (1.0 / (U(sigma)*sqrt(2.0*3.141529))) *
           exp(-(x*x) / (2.0*U(sigma)*U(sigma)));
}

void main()
{
    vec2 onePixel = 1.0 / vec2(textureSize(U(colorTexture), 0));
    result_color = vec3(0.0);
    
    for (float x = -U(radius); x < U(radius)+1; x += U(step))
    {
        result_color += sampleTexture(frag_uv+vec2(x*onePixel.x, 0.0)) * gauss(x);
    }
    
    result_color /= U(divisor);
}

