#include "lib/uniform.glsl"

layout (location = 0) out vec3 result_normal;

in vec2 frag_uv;

DECLUNIFORM(sampler2D, depthTexture)
DECLUNIFORM(mat4, projectionMatrix)

vec3 minDiff(vec3 P, vec3 P1, vec3 P2)
{
    vec3 V1 = P1 - P;
    vec3 V2 = P - P2;
    return (dot(V1,V1) < dot(V2,V2)) ? V1 : V2;
}

vec3 getPosition(ivec2 uv)
{
    vec3 position = vec3(uv / vec2(textureSize(U(depthTexture), 0)), texelFetch(U(depthTexture), uv, 0).r);
    position = position * 2.0 - 1.0;
    vec4 position4 = inverse(U(projectionMatrix)) * vec4(position, 1.0);
    return position4.xyz / position4.w;
}

void main()
{
    ivec2 uv = ivec2(gl_FragCoord.xy);
    vec3 pos = getPosition(uv);
    vec3 rightPos = getPosition(uv + ivec2(1.0, 0.0));
    vec3 leftPos = getPosition(uv - ivec2(1.0, 0.0));
    vec3 topPos = getPosition(uv + ivec2(0.0, 1.0));
    vec3 bottomPos = getPosition(uv - ivec2(0.0, 1.0));

    result_normal = normalize(cross(minDiff(pos, rightPos, leftPos), minDiff(pos, topPos, bottomPos)));
}

