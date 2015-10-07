layout (location = 0) out vec3 result_color;

in vec2 frag_uv;

uniform sampler2D colorTexture;
uniform sampler2D bloom1Texture;
uniform sampler2D bloom2Texture;
uniform sampler2D bloom3Texture;
uniform sampler2D bloom4Texture;
uniform float bloom1Strength;
uniform float bloom2Strength;
uniform float bloom3Strength;
uniform float bloom4Strength;

void main()
{
    result_color = texture(colorTexture, frag_uv).rgb;
    result_color += texture(bloom1Texture, frag_uv).rgb * bloom1Strength;
    result_color += texture(bloom2Texture, frag_uv).rgb * bloom2Strength;
    result_color += texture(bloom3Texture, frag_uv).rgb * bloom3Strength;
    result_color += texture(bloom4Texture, frag_uv).rgb * bloom4Strength;
}
