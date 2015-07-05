#extension GL_ARB_gpu_shader5 : enable

#ifndef GL_ARB_gpu_shader5
#extension GL_EXT_gpu_shader4 : enable
#endif

#include "lib/uniform.glsl"

layout (location = 0) out vec4 result_color;

in vec2 frag_uv;

DECLUNIFORM(sampler2D, colorTexture)

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

void main()
{
	FxaaFloat4 fxaaConsolePosPos = vec4(0);
	FxaaFloat2 fxaaQualityRcpFrame = vec2(1.0) / vec2(textureSize(U(colorTexture), 0));
	FxaaFloat4 fxaaConsoleRcpFrameOpt = vec4(0);
	FxaaFloat4 fxaaConsoleRcpFrameOpt2 = vec4(0);
	FxaaFloat4 fxaaConsole360RcpFrameOpt2 = vec4(0);
	FxaaFloat fxaaQualitySubpix = 0.75;
	
	#if QUALITY == 0
	FxaaFloat fxaaQualityEdgeThreshold = 0.25;
	FxaaFloat fxaaQualityEdgeThresholdMin = 0.0833;
	#elif QUALITY == 1
	FxaaFloat fxaaQualityEdgeThreshold = 0.166;
	FxaaFloat fxaaQualityEdgeThresholdMin = 0.0625;
	#else
	FxaaFloat fxaaQualityEdgeThreshold = 0.125;
	FxaaFloat fxaaQualityEdgeThresholdMin = 0.0312;
	#endif
	
	FxaaFloat fxaaConsoleEdgeSharpness = 8.0;
	FxaaFloat fxaaConsoleEdgeThreshold = 0.125;
	FxaaFloat fxaaConsoleEdgeThresholdMin = 0.05;
	FxaaFloat4 fxaaConsole360ConstDir = vec4(0);
	
    result_color = FxaaPixelShader(frag_uv, fxaaConsolePosPos, U(colorTexture), U(colorTexture), U(colorTexture), fxaaQualityRcpFrame, 
    			                   fxaaConsoleRcpFrameOpt, fxaaConsoleRcpFrameOpt2, fxaaConsole360RcpFrameOpt2, fxaaQualitySubpix, fxaaQualityEdgeThreshold, 
    				               fxaaQualityEdgeThresholdMin, fxaaConsoleEdgeSharpness, fxaaConsoleEdgeThreshold, fxaaConsoleEdgeThresholdMin, fxaaConsole360ConstDir);

}

