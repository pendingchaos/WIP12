#include "lib/vertex attributes.glsl"

layout (location=POSITION) in vec2 position;

out vec3 frag_color;

out gl_PerVertex
{
    vec4 gl_Position;
};

uniform vec2 offset;
uniform vec2 size;
uniform float gradientStart; //0.85
uniform float gradientSize; //0.15
uniform float gradientPower; //2.2
uniform vec3 color;

void main()
{
    gl_Position = vec4(position * size + offset, 0.0, 1.0);
    
    frag_color = vec3(pow(position.y * gradientSize + gradientStart, gradientPower));
    frag_color *= color;
}
