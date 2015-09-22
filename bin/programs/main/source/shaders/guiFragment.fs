#include "lib/uniform.glsl"

in vec3 frag_color;

layout (location = 0) out vec4 result_color;

DECLUNIFORM(vec2, topRight)
DECLUNIFORM(vec2, bottomLeft)
DECLUNIFORM(float, brightness)

#define ROUNDED_SIZE 10.0

float aastep(float value, float threshold) {
    return 1.0 - smoothstep(threshold-1, threshold+1, value);
}

void main()
{
    vec2 cornerBottomLeft = U(bottomLeft) + vec2(ROUNDED_SIZE);
    vec2 cornerBottomRight = vec2(U(topRight).x, U(bottomLeft).y) + vec2(-ROUNDED_SIZE, ROUNDED_SIZE);
    vec2 cornerTopLeft = vec2(U(bottomLeft).x, U(topRight).y) + vec2(ROUNDED_SIZE, -ROUNDED_SIZE);
    vec2 cornerTopRight = U(topRight) - vec2(ROUNDED_SIZE);

    float alpha = 1.0;

    if (gl_FragCoord.x < cornerBottomLeft.x &&
        gl_FragCoord.y < cornerBottomLeft.y)
    {
        alpha *= aastep(distance(gl_FragCoord.xy, cornerBottomLeft), 10.0);
    }

    if (gl_FragCoord.x > cornerBottomRight.x &&
        gl_FragCoord.y < cornerBottomRight.y)
    {
        alpha *= aastep(distance(gl_FragCoord.xy, cornerBottomRight), 10.0);
    }

    if (gl_FragCoord.x < cornerTopLeft.x &&
        gl_FragCoord.y > cornerTopLeft.y)
    {
        alpha *= aastep(distance(gl_FragCoord.xy, cornerTopLeft), 10.0);
    }

    if (gl_FragCoord.x > cornerTopRight.x &&
        gl_FragCoord.y > cornerTopRight.y)
    {
        alpha *= aastep(distance(gl_FragCoord.xy, cornerTopRight), 10.0);
    }

    result_color = vec4(frag_color * U(brightness), alpha);
}
