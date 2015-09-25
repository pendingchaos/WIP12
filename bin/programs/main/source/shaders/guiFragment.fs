in vec3 frag_color;

layout (location = 0) out vec4 result_color;

uniform vec2 topRight;
uniform vec2 bottomLeft;
uniform float brightness;
uniform float topRightCornerRoundness;
uniform float topLeftCornerRoundness;
uniform float bottomRightCornerRoundness;
uniform float bottomLeftCornerRoundness;

float aastep(float value, float threshold)
{
    return 1.0 - smoothstep(threshold-1.0, threshold+1.0, value);
}

void main()
{
    vec2 cornerBottomLeft = bottomLeft + vec2(bottomLeftCornerRoundness);
    vec2 cornerBottomRight = vec2(topRight.x, bottomLeft.y) + vec2(-bottomRightCornerRoundness, bottomRightCornerRoundness);
    vec2 cornerTopLeft = vec2(bottomLeft.x, topRight.y) + vec2(topLeftCornerRoundness, -topLeftCornerRoundness);
    vec2 cornerTopRight = topRight - vec2(topRightCornerRoundness);

    float alpha = 1.0;

    if (gl_FragCoord.x < cornerBottomLeft.x &&
        gl_FragCoord.y < cornerBottomLeft.y)
    {
        alpha *= aastep(distance(gl_FragCoord.xy, cornerBottomLeft), bottomLeftCornerRoundness);
    }

    if (gl_FragCoord.x > cornerBottomRight.x &&
        gl_FragCoord.y < cornerBottomRight.y)
    {
        alpha *= aastep(distance(gl_FragCoord.xy, cornerBottomRight), bottomRightCornerRoundness);
    }

    if (gl_FragCoord.x < cornerTopLeft.x &&
        gl_FragCoord.y > cornerTopLeft.y)
    {
        alpha *= aastep(distance(gl_FragCoord.xy, cornerTopLeft), topLeftCornerRoundness);
    }

    if (gl_FragCoord.x > cornerTopRight.x &&
        gl_FragCoord.y > cornerTopRight.y)
    {
        alpha *= aastep(distance(gl_FragCoord.xy, cornerTopRight), topRightCornerRoundness);
    }

    result_color = vec4(frag_color * brightness, alpha);
}
