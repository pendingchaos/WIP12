#include "lib/uniform.glsl"

in vec3 frag_position;

DECLUNIFORM(vec3, lightPos)
DECLUNIFORM(float, lightFar)
DECLUNIFORM(float, biasScale)

void main()
{
    float dist = distance(U(lightPos), frag_position) / U(lightFar);
    
    gl_FragDepth = dist + (abs(dFdx(dist)) + abs(dFdy(dist))) * U(biasScale);
}
