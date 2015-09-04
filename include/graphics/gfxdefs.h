#ifndef GFXDEFS_H
#define GFXDEFS_H

#include "containers/string.h"
#include "scripting/bindings.h"

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
} BIND;

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
} BIND;

enum GfxBlendMode
{
    GfxAdd,
    GfxSubtract,
    GfxReverseSubtract
} BIND;

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
} BIND;

enum GfxCullMode
{
    GfxCullNone,
    GfxCullFront,
    GfxCullBack
} BIND;

enum GfxWinding
{
    GfxCW,
    GfxCCW
} BIND;

#define GFX_VERTEX_ATTRIB_PURPOSE_COUNT 5

enum GfxVertexAttribPurpose
{
    GfxPosition = 0,
    GfxNormal = 1,
    GfxTangent = 2,
    GfxColor = 3,
    GfxTexCoord = 4,
} BIND;

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
} BIND;

#endif // GFXDEFS_H
