layout (location = 0) out vec3 result_color;

in vec2 frag_uv;

uniform sampler2D colorTexture;
uniform float threshold;

void main()
{
    vec3 color = vec3(0.0);
    
    vec2 onePixel = 1.0 / vec2(textureSize(colorTexture, 0));
    
    color += texture(colorTexture, frag_uv+onePixel).rgb;
    color += texture(colorTexture, frag_uv+onePixel*vec2(1.0, -1.0)).rgb;
    color += texture(colorTexture, frag_uv+onePixel*vec2(-1.0, 1.0)).rgb;
    color += texture(colorTexture, frag_uv+onePixel*-1.0).rgb;

    color /= 4.0;
    
    float brightness = dot(color, vec3(0.2126, 0.7152, 0.0722));
    
    result_color = step(0.0, brightness - threshold) * color;
}

