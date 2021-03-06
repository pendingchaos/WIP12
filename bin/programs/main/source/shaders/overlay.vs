#include "lib/vertex attributes.glsl"

layout (location=POSITION) in vec2 position;

out vec2 frag_uv;

out gl_PerVertex
{
    vec4 gl_Position;
};

uniform mat4 transform;

void main()
{
    gl_Position = transform * vec4(position, 0.0, 1.0);
    
    frag_uv = (position + 1.0) / 2.0;
}
