layout (points) in;
layout (triangle_strip, max_vertices = 4) out;

out gl_PerVertex
{
    vec4 gl_Position;
};

out vec2 frag_uv;

uniform vec2 glyphSize;
uniform vec2 glyphPosition;

void main()
{
    gl_Position = vec4(glyphPosition, 0.0, 1.0);
    frag_uv = vec2(0.0, 1.0);
    EmitVertex();
    
    gl_Position = vec4(glyphPosition + vec2(glyphSize.x, 0.0), 0.0, 1.0);
    frag_uv = vec2(1.0, 1.0);
    EmitVertex();
    
    gl_Position = vec4(glyphPosition + vec2(0.0, glyphSize.y), 0.0, 1.0);
    frag_uv = vec2(0.0, 0.0);
    EmitVertex();
    
    gl_Position = vec4(glyphPosition + glyphSize, 0.0, 1.0);
    frag_uv = vec2(1.0, 0.0);
    EmitVertex();
    
    EndPrimitive();
}
