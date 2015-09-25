layout (location = 0) out vec3 result_color;

in vec2 frag_uv;

uniform sampler2D bloomTexture;
uniform int radius;
uniform float sigma;

float gauss(float x)
{
    return radius == 0 ?
           1.0 :
           ((1.0 / (sigma*sqrt(2.0*3.141529))) *
            exp(-(x*x) / (2.0*sigma*sigma)));
}

void main()
{
    vec2 onePixel = 1.0 / vec2(textureSize(bloomTexture, 0));
    result_color = texture(bloomTexture, frag_uv).rgb * gauss(0.0);
     
    float sum = gauss(0.0);
    
    for (float y = 1.0; y < radius; y += 2.0)
    {
        float offset1 = y;
        float offset2 = offset1 + 1.0;
        
        float weight1 = gauss(offset1);
        float weight2 = gauss(offset2);
        
        float weight = weight1 + weight2;
        
        float offset = (offset1 * weight1 + offset2 * weight2) / weight;
        
        result_color += texture(bloomTexture, frag_uv+vec2(0.0, offset*onePixel.y)).rgb * weight;
        result_color += texture(bloomTexture, frag_uv-vec2(0.0, offset*onePixel.y)).rgb * weight;
        
        sum += weight * 2.0;
    }
    
    result_color /= sum;
}

