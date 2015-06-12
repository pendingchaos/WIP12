layout (location = 0) out vec3 result_color;

in vec2 frag_uv;

uniform sampler2D colorTexture;
uniform float divisor;
uniform int radius;
uniform float sigma;

float gauss(float x)
{
    return (1.0 / (sigma*sqrt(2.0*3.141529))) *
           exp(-(x*x) / (2.0*sigma*sigma));
}

void main()
{
    vec2 onePixel = 1.0 / vec2(textureSize(colorTexture, 0));
    result_color = vec3(0.0);
    
    for (int y = -radius; y < radius+1; ++y)
    {
        result_color += texture(colorTexture, frag_uv+vec2(0.0, y*onePixel.y)).rgb * gauss(float(y));
    }
    
    result_color /= divisor;
}

