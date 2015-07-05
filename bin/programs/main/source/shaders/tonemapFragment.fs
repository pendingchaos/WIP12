#include "lib/uniform.glsl"

layout (location = 0) out vec3 result_color;

in vec2 frag_uv;

DECLUNIFORM(sampler2D, colorTexture)

vec3 RGBToxyY(vec3 rgb)
{
	const mat3 RGB2XYZ = mat3(0.4124, 0.3576, 0.1805,
							  0.2126, 0.7152, 0.0722,
							  0.0193, 0.1192, 0.9505);
	vec3 XYZ = RGB2XYZ * rgb;
	
	// XYZ to xyY
	return vec3(XYZ.x / (XYZ.x + XYZ.y + XYZ.z),
				XYZ.y / (XYZ.x + XYZ.y + XYZ.z),
				XYZ.y);
}

vec3 xyYToRGB(vec3 xyY)
{
	// xyY to XYZ
	vec3 XYZ = vec3((xyY.z / xyY.y) * xyY.x,
					xyY.z,
					(xyY.z / xyY.y) * (1.0 - xyY.x - xyY.y));

	const mat3 XYZ2RGB = mat3(3.2406, -1.5372, -0.4986,
                              -0.9689, 1.8758, 0.0415, 
                              0.0557, -0.2040, 1.0570);
	
	return XYZ2RGB * XYZ;
}

void main()
{
    result_color = texture(U(colorTexture), frag_uv).rgb;

    vec3 xyY = RGBToxyY(result_color);
    
    xyY.z /= xyY.z + 1.0;
    
    result_color = xyYToRGB(xyY);
}

