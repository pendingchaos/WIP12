#include "lib/uniform.glsl"

layout (triangles) in;
layout (triangle_strip, max_vertices=18) out;

in gl_PerVertex
{
    vec4 gl_Position;
} gl_in[];

out gl_PerVertex
{
    vec4 gl_Position;
};

out vec3 frag_position;

DECLUNIFORM(mat4, matrix0)
DECLUNIFORM(mat4, matrix1)
DECLUNIFORM(mat4, matrix2)
DECLUNIFORM(mat4, matrix3)
DECLUNIFORM(mat4, matrix4)
DECLUNIFORM(mat4, matrix5)

void main()
{
    gl_Layer = 0;
    frag_position = gl_in[0].gl_Position.xyz;
    gl_Position = U(matrix0) * gl_in[0].gl_Position;
    EmitVertex();
    frag_position = gl_in[1].gl_Position.xyz;
    gl_Position = U(matrix0) * gl_in[1].gl_Position;
    EmitVertex();
    frag_position = gl_in[2].gl_Position.xyz;
    gl_Position = U(matrix0) * gl_in[2].gl_Position;
    EmitVertex();
    EndPrimitive();
    
    gl_Layer = 1;
    frag_position = gl_in[0].gl_Position.xyz;
    gl_Position = U(matrix1) * gl_in[0].gl_Position;
    EmitVertex();
    frag_position = gl_in[1].gl_Position.xyz;
    gl_Position = U(matrix1) * gl_in[1].gl_Position;
    EmitVertex();
    frag_position = gl_in[2].gl_Position.xyz;
    gl_Position = U(matrix1) * gl_in[2].gl_Position;
    EmitVertex();
    EndPrimitive();
    
    gl_Layer = 2;
    frag_position = gl_in[0].gl_Position.xyz;
    gl_Position = U(matrix2) * gl_in[0].gl_Position;
    EmitVertex();
    frag_position = gl_in[1].gl_Position.xyz;
    gl_Position = U(matrix2) * gl_in[1].gl_Position;
    EmitVertex();
    frag_position = gl_in[2].gl_Position.xyz;
    gl_Position = U(matrix2) * gl_in[2].gl_Position;
    EmitVertex();
    EndPrimitive();
    
    gl_Layer = 3;
    frag_position = gl_in[0].gl_Position.xyz;
    gl_Position = U(matrix3) * gl_in[0].gl_Position;
    EmitVertex();
    frag_position = gl_in[1].gl_Position.xyz;
    gl_Position = U(matrix3) * gl_in[1].gl_Position;
    EmitVertex();
    frag_position = gl_in[2].gl_Position.xyz;
    gl_Position = U(matrix3) * gl_in[2].gl_Position;
    EmitVertex();
    EndPrimitive();
    
    gl_Layer = 4;
    frag_position = gl_in[0].gl_Position.xyz;
    gl_Position = U(matrix4) * gl_in[0].gl_Position;
    EmitVertex();
    frag_position = gl_in[1].gl_Position.xyz;
    gl_Position = U(matrix4) * gl_in[1].gl_Position;
    EmitVertex();
    frag_position = gl_in[2].gl_Position.xyz;
    gl_Position = U(matrix4) * gl_in[2].gl_Position;
    EmitVertex();
    EndPrimitive();
    
    gl_Layer = 5;
    frag_position = gl_in[0].gl_Position.xyz;
    gl_Position = U(matrix5) * gl_in[0].gl_Position;
    EmitVertex();
    frag_position = gl_in[1].gl_Position.xyz;
    gl_Position = U(matrix5) * gl_in[1].gl_Position;
    EmitVertex();
    frag_position = gl_in[2].gl_Position.xyz;
    gl_Position = U(matrix5) * gl_in[2].gl_Position;
    EmitVertex();
    EndPrimitive();
}
