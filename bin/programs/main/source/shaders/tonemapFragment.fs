layout (location = 0) out vec3 result_color;

in vec2 frag_uv;

uniform sampler2D colorTexture;
uniform float averageLuminance;

#define REINHARD

#ifdef REINHARD
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
#else
float A = 0.15;
float B = 0.50;
float C = 0.10;
float D = 0.20;
float E = 0.02;
float F = 0.30;
float W = 11.2;
 
vec3 Uncharted2Tonemap(vec3 x)
{
    return ((x*(A*x+C*B)+D*E)/(x*(A*x+B)+D*F))-E/F;
}
#endif

void main()
{
    result_color = texture(colorTexture, frag_uv).rgb;

    float exposure = 1.0 / exp(max(averageLuminance, 0.0001));
    
    result_color *= exposure;
    
    #ifdef REINHARD
    vec3 xyY = RGBToxyY(result_color);
    
    xyY.z /= xyY.z + 1.0;
    
    result_color = xyYToRGB(xyY);
    #else
    float exposureBias = 2.0;
    
    result_color = Uncharted2Tonemap(result_color * exposureBias);
    
    result_color *= 1.0 / Uncharted2Tonemap(vec3(W));
    #endif
}

