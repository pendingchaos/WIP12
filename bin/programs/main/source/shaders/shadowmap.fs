uniform float biasScale;

void main()
{
    gl_FragDepth = gl_FragCoord.z + (abs(dFdx(gl_FragCoord.z)) + abs(dFdy(gl_FragCoord.z))) * biasScale;
}
