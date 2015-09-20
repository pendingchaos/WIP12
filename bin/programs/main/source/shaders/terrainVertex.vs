#include "lib/vertex attributes.glsl"
#include "lib/uniform.glsl"

layout (location=POSITION) in vec3 position_modelSpace;

out gl_PerVertex
{
    vec4 gl_Position;
};

out vec3 position_worldSpace;

DECLUNIFORM(uint, sizeInChunks)
DECLUNIFORM(float, chunkSize)

void main()
{
    position_worldSpace = position_modelSpace;
    
    float x = float(gl_InstanceID % U(sizeInChunks));
    float z = float(gl_InstanceID / U(sizeInChunks));
    
    x -= float(U(sizeInChunks)) / 2.0;
    z -= float(U(sizeInChunks)) / 2.0;
    
    position_worldSpace.xz += vec2(x, z) * U(chunkSize);
    
    gl_Position = vec4(position_worldSpace, 1.0);
}
