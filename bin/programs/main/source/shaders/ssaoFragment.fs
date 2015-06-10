layout (location = 0) out float result_ao;

in vec2 frag_uv;

uniform sampler2D depthTexture;
uniform sampler2D normalTexture;
uniform float cameraNear;
uniform float cameraFar;
uniform mat3 normalMatrix;

float linearizeDepth(float depth)
{
    return cameraNear * cameraFar / ((depth * (cameraFar - cameraNear)) - cameraFar);
}

const vec3 random[] = {vec3(-0.99, -0.15, 0.00),
                       vec3(-0.50, 0.87, 0.00),
                       vec3(0.97, -0.24, 0.00),
                       vec3(0.65, 0.76, 0.00),
                       vec3(-0.81, 0.59, 0.00),
                       vec3(0.90, -0.44, 0.00),
                       vec3(-1.00, 0.07, 0.00),
                       vec3(0.79, 0.61, 0.00),
                       vec3(0.20, -0.98, 0.00),
                       vec3(0.93, -0.36, 0.00),
                       vec3(0.99, -0.15, 0.00),
                       vec3(-0.74, -0.67, 0.00),
                       vec3(0.87, 0.49, 0.00),
                       vec3(0.71, -0.70, 0.00),
                       vec3(-0.66, -0.75, 0.00),
                       vec3(-1.00, 0.07, 0.00)};

vec3 getRandom(int x, int y)
{
    x %= 4;
    y %= 4;    
    
    return random[x+y*4];
}

const vec3 kernel[] = {vec3(-0.021705, 0.061174, 0.076070),
                       vec3(-0.059246, 0.022466, 0.078497),
                       vec3(0.027279, -0.098184, 0.018202),
                       vec3(-0.028377, 0.096082, 0.040096),
                       vec3(-0.077052, -0.067115, 0.050682),
                       vec3(-0.081984, 0.087470, 0.022471),
                       vec3(0.016880, 0.105354, 0.077103),
                       vec3(0.092991, 0.075487, 0.078246),
                       vec3(0.124298, 0.090585, 0.027539),
                       vec3(0.134415, 0.095001, 0.047051),
                       vec3(0.103106, -0.108602, 0.113479),
                       vec3(-0.063310, -0.194990, 0.023455),
                       vec3(0.017814, -0.103700, 0.200648),
                       vec3(-0.069504, -0.145266, 0.189306),
                       vec3(-0.090322, 0.221064, 0.130772),
                       vec3(0.215415, 0.205492, 0.005190),
                       vec3(0.159416, 0.120552, 0.256279),
                       vec3(0.344563, 0.029439, 0.075688),
                       vec3(-0.114333, 0.361992, 0.062724),
                       vec3(-0.409849, -0.003138, 0.078364),
                       vec3(-0.286618, 0.188601, 0.293579),
                       vec3(-0.011728, -0.337581, 0.351644),
                       vec3(0.359209, -0.366484, 0.112666),
                       vec3(0.416884, 0.024438, 0.380486),
                       vec3(0.111629, -0.015451, 0.595684),
                       vec3(0.538785, -0.083810, 0.352560),
                       vec3(-0.383228, 0.564943, 0.125727),
                       vec3(-0.365297, 0.440068, 0.470711),
                       vec3(-0.468366, 0.149180, 0.617250),
                       vec3(-0.531191, 0.292589, 0.580015),
                       vec3(-0.502290, 0.454897, 0.578517),
                       vec3(0.311337, -0.725261, 0.519028)};

#define RADIUS 0.1

#define SAMPLE(i) {\
    vec3 samplePos = tbn * kernel[i] * RADIUS + origin;\
    vec2 texPos = (samplePos.xy + 1.0) / 2.0;\
    float sampleDepth = linearizeDepth(texture(depthTexture, texPos));\
    float rangeCheck = smoothstep(0.0, 1.0, RADIUS / abs(samplePos.z - sampleDepth));\
    result_ao += samplePos.z >= sampleDepth ? 0.0 : 1.0 * rangeCheck;\
}\

void main()
{
    float depth = linearizeDepth(texture(depthTexture, frag_uv).r);
    vec3 origin = vec3(frag_uv * 2.0 - 1.0, depth);
    
    vec3 normal = normalize(normalMatrix * texture(normalTexture, frag_uv).xyz);
    vec3 rvec = getRandom(int(gl_FragCoord.x), int(gl_FragCoord.y));
    vec3 tangent = normalize(rvec - normal * dot(rvec, normal));
    vec3 bitangent = cross(tangent, normal);
    mat3 tbn = mat3(tangent, bitangent, normal);

    SAMPLE(0)
    SAMPLE(1)
    SAMPLE(2)
    SAMPLE(3)
    SAMPLE(4)
    SAMPLE(5)
    SAMPLE(6)
    SAMPLE(7)
    SAMPLE(8)
    SAMPLE(9)
    SAMPLE(10)
    SAMPLE(11)
    SAMPLE(12)
    SAMPLE(13)
    SAMPLE(14)
    SAMPLE(15)
    SAMPLE(16)
    SAMPLE(17)
    SAMPLE(18)
    SAMPLE(19)
    SAMPLE(20)
    SAMPLE(21)
    SAMPLE(22)
    SAMPLE(23)
    SAMPLE(24)
    SAMPLE(25)
    SAMPLE(26)
    SAMPLE(27)
    SAMPLE(28)
    SAMPLE(29)
    SAMPLE(30)
    SAMPLE(31)
    
    result_ao = 1.0 - result_ao / 32.0;
}

