#include "lib/uniform.glsl"

layout (location = 0) out vec3 result_albedo;
layout (location = 1) out vec2 result_material;
layout (location = 2) out vec3 result_normal;
layout (location = 3) out vec3 result_geom_normal;

in vec3 frag_position_worldSpace;
in vec2 frag_uv_tangentSpace;

DECLUNIFORM(sampler2D, heightMap)
DECLUNIFORM(sampler2D, albedoTexture)
DECLUNIFORM(float, textureScale)

void main()
{
    float h0 = textureLodOffset(U(heightMap), frag_uv_tangentSpace, 0.0, ivec2(-1, -1)).r;
    float h1 = textureLodOffset(U(heightMap), frag_uv_tangentSpace, 0.0, ivec2( 0, -1)).r;
    float h2 = textureLodOffset(U(heightMap), frag_uv_tangentSpace, 0.0, ivec2( 1, -1)).r;
    float h3 = textureLodOffset(U(heightMap), frag_uv_tangentSpace, 0.0, ivec2(-1,  0)).r;
    float h4 = textureLod(U(heightMap), frag_uv_tangentSpace, 0.0).r;
    float h5 = textureLodOffset(U(heightMap), frag_uv_tangentSpace, 0.0, ivec2( 1,  0)).r;
    float h6 = textureLodOffset(U(heightMap), frag_uv_tangentSpace, 0.0, ivec2(-1,  1)).r;
    float h7 = textureLodOffset(U(heightMap), frag_uv_tangentSpace, 0.0, ivec2( 0,  1)).r;
    float h8 = textureLodOffset(U(heightMap), frag_uv_tangentSpace, 0.0, ivec2( 1,  1)).r;
    
    vec3 normal = vec3(-(h2-h0+2.0*(h5-h3)+h8-h6),
                       1.0,
                       -(h6-h0+2.0*(h7-h1)+h8-h2));
    
    normal = normalize(normal);
    
    result_albedo = texture(U(albedoTexture), frag_uv_tangentSpace * U(textureScale)).rgb;
    result_material = vec2(0.0, 0.5);
    result_normal = normal;
    result_geom_normal = normal; //normalize(cross(dFdx(frag_position_worldSpace), dFdy(frag_position_worldSpace)));
}
