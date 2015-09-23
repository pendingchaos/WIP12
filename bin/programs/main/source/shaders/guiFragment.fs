#include "lib/uniform.glsl"

in vec3 frag_color;

layout (location = 0) out vec4 result_color;

DECLUNIFORM(vec2, topRight)
DECLUNIFORM(vec2, bottomLeft)
DECLUNIFORM(float, brightness)
DECLUNIFORM(float, topRightCornerRoundness)
DECLUNIFORM(float, topLeftCornerRoundness)
DECLUNIFORM(float, bottomRightCornerRoundness)
DECLUNIFORM(float, bottomLeftCornerRoundness)

float aastep(float value, float threshold)
{
    return 1.0 - smoothstep(threshold-1.0, threshold+1.0, value);
}

void main()
{
    vec2 cornerBottomLeft = U(bottomLeft) + vec2(U(bottomLeftCornerRoundness));
    vec2 cornerBottomRight = vec2(U(topRight).x, U(bottomLeft).y) + vec2(-U(bottomRightCornerRoundness), U(bottomRightCornerRoundness));
    vec2 cornerTopLeft = vec2(U(bottomLeft).x, U(topRight).y) + vec2(U(topLeftCornerRoundness), -U(topLeftCornerRoundness));
    vec2 cornerTopRight = U(topRight) - vec2(U(topRightCornerRoundness));

    float alpha = 1.0;

    if (gl_FragCoord.x < cornerBottomLeft.x &&
        gl_FragCoord.y < cornerBottomLeft.y)
    {
        alpha *= aastep(distance(gl_FragCoord.xy, cornerBottomLeft), U(bottomLeftCornerRoundness));
    }

    if (gl_FragCoord.x > cornerBottomRight.x &&
        gl_FragCoord.y < cornerBottomRight.y)
    {
        alpha *= aastep(distance(gl_FragCoord.xy, cornerBottomRight), U(bottomRightCornerRoundness));
    }

    if (gl_FragCoord.x < cornerTopLeft.x &&
        gl_FragCoord.y > cornerTopLeft.y)
    {
        alpha *= aastep(distance(gl_FragCoord.xy, cornerTopLeft), U(topLeftCornerRoundness));
    }

    if (gl_FragCoord.x > cornerTopRight.x &&
        gl_FragCoord.y > cornerTopRight.y)
    {
        alpha *= aastep(distance(gl_FragCoord.xy, cornerTopRight), U(topRightCornerRoundness));
    }

    result_color = vec4(frag_color * U(brightness), alpha);
}
