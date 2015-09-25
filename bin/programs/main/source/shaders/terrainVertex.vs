#include "lib/vertex attributes.glsl"

layout (location=POSITION) in vec3 position_modelSpace;

out gl_PerVertex
{
    vec4 gl_Position;
};

out vec3 position_worldSpace;

uniform uint sizeInChunks;
uniform float chunkSize;

void main()
{
    position_worldSpace = position_modelSpace;
    
    float x = float(gl_InstanceID % sizeInChunks);
    float z = float(gl_InstanceID / sizeInChunks);
    
    x -= float(sizeInChunks) / 2.0;
    z -= float(sizeInChunks) / 2.0;
    
    position_worldSpace.xz += vec2(x, z) * chunkSize;
    
    gl_Position = vec4(position_worldSpace, 1.0);
}
