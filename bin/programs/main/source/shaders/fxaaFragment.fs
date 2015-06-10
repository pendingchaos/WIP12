
layout (location = 0) out vec4 result_color;

in vec2 frag_uv;

uniform sampler2D colorTexture;

#define QUALITY 2

#define FXAA_GREEN_AS_LUMA 1
 
#define FXAA_PC 1
#define FXAA_GLSL_130 1
 
#if QUALITY == 2
	#define FXAA_QUALITY__PRESET 39
#else
	#if QUALITY == 0
		#define FXAA_QUALITY__PRESET 12
	#else
		#define FXAA_QUALITY__PRESET 25
	#endif
#endif

#include "lib/FXAA3_11.h"

/*#define FXAA_SPAN_MAX 8.0
#define FXAA_REDUCE_MUL (1.0/8.0)
#define FXAA_REDUCE_MIN (1.0/128.0)*/

void main()
{
    /*vec2 onePixel = vec2(1.0) / vec2(textureSize(colorTexture, 0));    
    
	vec3 rgbNW = textureOffset(colorTexture, frag_uv, ivec2(-1, -1)).rgb;
	vec3 rgbNE = textureOffset(colorTexture, frag_uv, ivec2(1, -1)).rgb;
	vec3 rgbSW = textureOffset(colorTexture, frag_uv, ivec2(-1, 1)).rgb;
	vec3 rgbSE = textureOffset(colorTexture, frag_uv, ivec2(1, 1)).rgb;
	vec3 rgbM  = texture(colorTexture, frag_uv).rgb;
	
	vec3 luma = vec3(0.299, 0.587, 0.114);
	float lumaNW = dot(rgbNW, luma);
	float lumaNE = dot(rgbNE, luma);
	float lumaSW = dot(rgbSW, luma);
	float lumaSE = dot(rgbSE, luma);
	float lumaM  = dot(rgbM,  luma);
	
	float lumaMin = min(lumaM, min( min(lumaNW, lumaNE), min(lumaSW, lumaSE)));
	float lumaMax = max(lumaM, max( max(lumaNW, lumaNE), max(lumaSW, lumaSE)));
	
	vec2 dir;
	dir.x = -((lumaNW + lumaNE) - (lumaSW + lumaSE));
	dir.y =  ((lumaNW + lumaSW) - (lumaNE + lumaSE));

	float dirReduce = max(
		(lumaNW + lumaNE + lumaSW + lumaSE) * (0.25 * FXAA_REDUCE_MUL), FXAA_REDUCE_MIN);

	float rcpDirMin = 1.0 / (min( abs(dir.x), abs(dir.y)) + dirReduce);

	dir  =	min( vec2( FXAA_SPAN_MAX,  FXAA_SPAN_MAX),
		max( vec2(-FXAA_SPAN_MAX, -FXAA_SPAN_MAX),
			   dir * rcpDirMin)) * onePixel;

	vec3 rgbA = 0.5 * (texture(colorTexture, frag_uv + dir * (0.33333 - 0.5)).rgb +
			   texture(colorTexture, frag_uv + dir *  0.5).rgb);

	vec3 rgbB = rgbA * (1.0/2.0) + (1.0/4.0) *
			(texture(colorTexture, frag_uv + dir * -0.5).rgb +
			 texture(colorTexture, frag_uv + dir *  0.5).rgb);

	float lumaB = dot(rgbB, luma);
	
	if (lumaB < lumaMin || lumaB > lumaMax)
	{
	    result_color.rgb = rgbA;
	} else
	{
	    result_color.rgb = rgbB;
    }

    result_color.a = 1.0;*/
    
	FxaaFloat4 fxaaConsolePosPos = vec4(0);
	FxaaFloat2 fxaaQualityRcpFrame = vec2(1.0) / vec2(textureSize(colorTexture, 0));
	FxaaFloat4 fxaaConsoleRcpFrameOpt = vec4(0);
	FxaaFloat4 fxaaConsoleRcpFrameOpt2 = vec4(0);
	FxaaFloat4 fxaaConsole360RcpFrameOpt2 = vec4(0);
	FxaaFloat fxaaQualitySubpix = 0.75;
	
	#if QUALITY == 0
	FxaaFloat fxaaQualityEdgeThreshold = 0.25;
	#elif QUALITY == 1
	FxaaFloat fxaaQualityEdgeThreshold = 0.166;
	#else
	FxaaFloat fxaaQualityEdgeThreshold = 0.125;
	#endif
	
	FxaaFloat fxaaQualityEdgeThresholdMin = 0.0625;
	FxaaFloat fxaaConsoleEdgeSharpness = 0;
	FxaaFloat fxaaConsoleEdgeThreshold = 0;
	FxaaFloat fxaaConsoleEdgeThresholdMin = 0;
	FxaaFloat4 fxaaConsole360ConstDir = vec4(0);
	
    result_color = FxaaPixelShader(frag_uv, fxaaConsolePosPos, colorTexture, colorTexture, colorTexture, fxaaQualityRcpFrame, 
    			                   fxaaConsoleRcpFrameOpt, fxaaConsoleRcpFrameOpt2, fxaaConsole360RcpFrameOpt2, fxaaQualitySubpix, fxaaQualityEdgeThreshold, 
    				               fxaaQualityEdgeThresholdMin, fxaaConsoleEdgeSharpness, fxaaConsoleEdgeThreshold, fxaaConsoleEdgeThresholdMin, fxaaConsole360ConstDir);

}

