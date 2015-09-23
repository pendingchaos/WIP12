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
DECLUNIFORM(float, gradientStart) //0.85
DECLUNIFORM(float, gradientSize) //0.15
DECLUNIFORM(float, gradientPower) //2.2
DECLUNIFORM(vec3, color)

void main()
{
    gl_Position = vec4(position * U(size) + U(offset), 0.0, 1.0);
    
    frag_color = vec3(pow(position.y * U(gradientSize) + U(gradientStart), U(gradientPower)));
    frag_color *= U(color);
}
