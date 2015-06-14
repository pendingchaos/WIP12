layout (location = 0) out vec3 result_color;

in vec2 frag_uv;

uniform sampler2D bloomTexture;
uniform sampler2D colorTexture;
uniform float divisor;
uniform int radius;
uniform float sigma;
uniform float step;

float gauss(float x)
{
    return (1.0 / (sigma*sqrt(2.0*3.141529))) *
           exp(-(x*x) / (2.0*sigma*sigma));
}

void main()
{
    vec2 onePixel = 1.0 / vec2(textureSize(bloomTexture, 0));
    result_color = vec3(0.0);
    
    for (float y = -radius; y < radius+1; y += step)
    {
        result_color += texture(bloomTexture, frag_uv+vec2(0.0, y*onePixel.y)).rgb * gauss(y);
    }
    
    result_color /= divisor;
    
    result_color += texture(colorTexture, frag_uv).rgb;
}

