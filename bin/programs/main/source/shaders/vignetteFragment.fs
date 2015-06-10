layout (location = 0) out vec4 result_color;

in vec2 frag_uv;

uniform sampler2D colorTexture;
uniform float vignetteRadius;
uniform float vignetteSoftness;
uniform float vignetteIntensity;

float getVignette()
{
    float vignette = distance(vec2(0.5), frag_uv);
    
    vignette = smoothstep(vignetteRadius/2.0, (vignetteRadius-vignetteSoftness)/2.0, vignette);
    
    return mix(1.0, vignette, vignetteIntensity);
}

void main()
{
    result_color = texture(colorTexture, frag_uv);
    
    result_color *= getVignette();
}

