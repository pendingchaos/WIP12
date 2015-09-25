in vec3 frag_position;

uniform vec3 lightPos;
uniform float lightFar;
uniform float biasScale;

void main()
{
    float dist = distance(lightPos, frag_position) / lightFar;
    
    gl_FragDepth = dist + (abs(dFdx(dist)) + abs(dFdy(dist))) * biasScale;
}
