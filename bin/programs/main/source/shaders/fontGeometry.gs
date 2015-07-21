#include "lib/uniform.glsl"

layout (points) in;
layout (triangle_strip, max_vertices = 4) out;

in int geom_instanceID[1];

out gl_PerVertex
{
    vec4 gl_Position;
};

out vec2 frag_uv;

DECLUNIFORM(vec2, glyphSize)
DECLUNIFORMARRAY(vec2, 100, glyphPositions)

void main()
{
    gl_Position = vec4(U(glyphPositions)[geom_instanceID[0]], 0.0, 1.0);
    frag_uv = vec2(0.0, 1.0);
    EmitVertex();
    
    gl_Position = vec4(U(glyphPositions)[geom_instanceID[0]] + vec2(U(glyphSize).x, 0.0), 0.0, 1.0);
    frag_uv = vec2(1.0, 1.0);
    EmitVertex();
    
    gl_Position = vec4(U(glyphPositions)[geom_instanceID[0]] + vec2(0.0, U(glyphSize).y), 0.0, 1.0);
    frag_uv = vec2(0.0, 0.0);
    EmitVertex();
    
    gl_Position = vec4(U(glyphPositions)[geom_instanceID[0]] + U(glyphSize), 0.0, 1.0);
    frag_uv = vec2(1.0, 0.0);
    EmitVertex();
    
    EndPrimitive();
}
