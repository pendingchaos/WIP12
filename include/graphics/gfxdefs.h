#ifndef GFXDEFS_H
#define GFXDEFS_H

#include "containers/string.h"

class GfxBuffer;

enum GfxPrimitive
{
    GfxPoints,
    GfxLineStrip,
    GfxLineLoop,
    GfxLines,
    GfxTriangleStrip,
    GfxTriangleFan,
    GfxTriangles,
    GfxPatches
};

enum GfxDepthFunction
{
    GfxNever,
    GfxLess,
    GfxEqual,
    GfxLessEqual,
    GfxGreater,
    GfxNotEqual,
    GfxGreaterEqual,
    GfxAlways
};

enum GfxBlendMode
{
    GfxAdd,
    GfxSubtract,
    GfxReverseSubtract
};

enum GfxBlendFactor
{
    GfxZero,
    GfxOne,
    GfxSrcColor,
    GfxOneMinusSrcColor,
    GfxDstColor,
    GfxOneMinusDstColor,
    GfxSrcAlpha,
    GfxOneMinusSrcAlpha,
    GfxDstAlpha,
    GfxOneMinusDstAlpha,
    GfxConstantColor,
    GfxOneMinusConstantColor,
    GfxConstantAlpha,
    GfxOneMinusConstantAlpha
};

enum GfxCullMode
{
    GfxCullNone,
    GfxCullFront,
    GfxCullBack
};

enum GfxWinding
{
    GfxCW,
    GfxCCW
};

#define GFX_VERTEX_ATTRIB_PURPOSE_COUNT 6

enum GfxVertexAttribPurpose
{
    GfxPosition = 0,
    GfxNormal = 1,
    GfxTangent = 2,
    GfxBitangent = 3,
    GfxColor = 4,
    GfxTexCoord = 5,
};

enum GfxVertexAttribType
{
    GfxHalfFloat,
    GfxFloat,
    GfxDouble,
    GfxByte,
    GfxUnsignedByte,
    GfxShort,
    GfxUnsignedShort,
    GfxInteger,
    GfxUnsignedInteger,
    GfxNormalizedByte,
    GfxNormalizedUnsignedByte,
    GfxNormalizedShort,
    GfxNormalizedUnsignedShort,
    GfxNormalizedInteger,
    GfxNormalizedUnsignedInteger
};

#endif // GFXDEFS_H
