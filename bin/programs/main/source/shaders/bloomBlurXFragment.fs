layout (location = 0) out vec3 result_color;

in vec2 frag_uv;

uniform sampler2D colorTexture;
uniform float threshold;
uniform float divisor;
uniform int radius;
uniform float sigma;
uniform float step;

float sampleTexture(vec2 uv)
{
    return max(texture(colorTexture, uv).rgb - threshold, 0.0);
}

float gauss(float x)
{
    return (1.0 / (sigma*sqrt(2.0*3.141529))) *
           exp(-(x*x) / (2.0*sigma*sigma));
}

void main()
{
    vec2 onePixel = 1.0 / vec2(textureSize(colorTexture, 0));
    result_color = vec3(0.0);
    
    for (float x = -radius; x < radius+1; x += step)
    {
        result_color += sampleTexture(frag_uv+vec2(x*onePixel.x, 0.0)) * gauss(x);
    }
    
    result_color /= divisor;
}

