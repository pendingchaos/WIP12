layout (location = 0) out float result_ao;

in vec2 frag_uv;

uniform sampler2D depthTexture;
uniform sampler2D normalTexture;
uniform sampler2D randomTex;
uniform float cameraNear;
uniform float cameraFar;
uniform mat3 normalMatrix;
uniform float radius;

float linearizeDepth(float depth)
{
    return cameraNear * cameraFar / ((depth * (cameraFar - cameraNear)) - cameraFar);
}

vec3 getRandom(vec2 pos)
{
    return texelFetch(randomTex, ivec2(pos) % 4, 0).xyz;
}

#define SAMPLE(kernel) {\
    vec3 samplePos = tbn * kernel * radius + origin;\
    vec2 texPos = (samplePos.xy + 1.0) / 2.0;\
    float sampleDepth = linearizeDepth(texture(depthTexture, texPos));\
    float rangeCheck = smoothstep(0.0, 1.0, radius / abs(samplePos.z - sampleDepth));\
    result_ao += samplePos.z >= sampleDepth ? 0.0 : 1.0 * rangeCheck;\
}\

void main()
{
    float depth = linearizeDepth(texture(depthTexture, frag_uv).r);
    vec3 origin = vec3(frag_uv * 2.0 - 1.0, depth);
    
    vec3 normal = normalize(normalMatrix * texture(normalTexture, frag_uv).xyz);
    vec3 rvec = getRandom(gl_FragCoord.xy);
    vec3 tangent = normalize(rvec - normal * dot(rvec, normal));
    vec3 bitangent = cross(tangent, normal);
    mat3 tbn = mat3(tangent, bitangent, normal);

    result_ao = 0.0;

    SAMPLE(vec3(-0.021705, 0.061174, 0.076070))
    SAMPLE(vec3(-0.059246, 0.022466, 0.078497))
    SAMPLE(vec3(0.027279, -0.098184, 0.018202))
    SAMPLE(vec3(-0.028377, 0.096082, 0.040096))
    SAMPLE(vec3(-0.077052, -0.067115, 0.050682))
    SAMPLE(vec3(-0.081984, 0.087470, 0.022471))
    SAMPLE(vec3(0.016880, 0.105354, 0.077103))
    SAMPLE(vec3(0.092991, 0.075487, 0.078246))
    SAMPLE(vec3(0.124298, 0.090585, 0.027539))
    SAMPLE(vec3(0.134415, 0.095001, 0.047051))
    SAMPLE(vec3(0.103106, -0.108602, 0.113479))
    SAMPLE(vec3(-0.063310, -0.194990, 0.023455))
    SAMPLE(vec3(0.017814, -0.103700, 0.200648))
    SAMPLE(vec3(-0.069504, -0.145266, 0.189306))
    SAMPLE(vec3(-0.090322, 0.221064, 0.130772))
    SAMPLE(vec3(0.215415, 0.205492, 0.005190))
    SAMPLE(vec3(0.159416, 0.120552, 0.256279))
    SAMPLE(vec3(0.344563, 0.029439, 0.075688))
    SAMPLE(vec3(-0.114333, 0.361992, 0.062724))
    SAMPLE(vec3(-0.409849, -0.003138, 0.078364))
    SAMPLE(vec3(-0.286618, 0.188601, 0.293579))
    SAMPLE(vec3(-0.011728, -0.337581, 0.351644))
    SAMPLE(vec3(0.359209, -0.366484, 0.112666))
    SAMPLE(vec3(0.416884, 0.024438, 0.380486))
    SAMPLE(vec3(0.111629, -0.015451, 0.595684))
    SAMPLE(vec3(0.538785, -0.083810, 0.352560))
    SAMPLE(vec3(-0.383228, 0.564943, 0.125727))
    SAMPLE(vec3(-0.365297, 0.440068, 0.470711))
    SAMPLE(vec3(-0.468366, 0.149180, 0.617250))
    SAMPLE(vec3(-0.531191, 0.292589, 0.580015))
    SAMPLE(vec3(-0.502290, 0.454897, 0.578517))
    SAMPLE(vec3(0.311337, -0.725261, 0.519028))

    result_ao = 1.0 - result_ao / 32.0;
}

