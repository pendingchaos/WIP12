#include "lib/vertex attributes.glsl"
#include "lib/uniform.glsl"

layout (location=POSITION) in vec2 position;

out vec3 frag_color;

out gl_PerVertex
{
    vec4 gl_Position;
};

DECLUNIFORM(vec2, offset)
DECLUNIFORM(vec2, size)

void main()
{
    gl_Position = vec4(position * U(size) + U(offset), 0.0, 1.0);
    
    frag_color = vec3(pow(position.y * 0.15 + 0.85, 2.2));
}
