#include "lib/uniform.glsl"

layout (points) in;
layout (triangle_strip, max_vertices = 4) out;

out gl_PerVertex
{
    vec4 gl_Position;
};

out vec2 frag_uv;

DECLUNIFORM(vec2, glyphSize)
DECLUNIFORM(vec2, glyphPosition)

void main()
{
    gl_Position = vec4(U(glyphPosition), 0.0, 1.0);
    frag_uv = vec2(0.0, 1.0);
    EmitVertex();
    
    gl_Position = vec4(U(glyphPosition) + vec2(U(glyphSize).x, 0.0), 0.0, 1.0);
    frag_uv = vec2(1.0, 1.0);
    EmitVertex();
    
    gl_Position = vec4(U(glyphPosition) + vec2(0.0, U(glyphSize).y), 0.0, 1.0);
    frag_uv = vec2(0.0, 0.0);
    EmitVertex();
    
    gl_Position = vec4(U(glyphPosition) + U(glyphSize), 0.0, 1.0);
    frag_uv = vec2(1.0, 0.0);
    EmitVertex();
    
    EndPrimitive();
}
