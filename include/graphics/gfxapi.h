#ifndef GFXAPI_H
#define GFXAPI_H

#include "misc_macros.h"
#include "math/t2.h"
#include "math/t3.h"
#include "math/t4.h"
#include "math/matrix3x3.h"
#include "math/matrix4x4.h"
#include "graphics/gfxdefs.h"
#include "graphics/gfxtexture.h"
#include "graphics/gfxmesh.h"

class GfxShaderImpl;
class GfxCompiledShader;
class GfxBuffer;
class GfxFramebuffer;
class GPUTimer;

class GfxApi
{
    public:
        enum Driver
        {
            Nvidia,
            Mesa,
            Unknown
        };

        GfxApi() {}
        virtual ~GfxApi();

        virtual Driver getDriver() const=0;

        virtual bool tesselationSupported()=0;

        virtual GfxShaderImpl *createShaderImpl()=0;
        virtual GfxBuffer *createBuffer()=0;
        virtual GfxTextureImpl *createTextureImpl()=0;
        virtual GfxMeshImpl *createMeshImpl(GfxMesh *mesh)=0;
        virtual GfxFramebuffer *createFramebuffer()=0;
        virtual GPUTimer *createTimer()=0;

        virtual void setCurrentFramebuffer(GfxFramebuffer *framebuffer)=0;

        virtual void clearDepth(float depthValue=1.0f)=0;
        virtual void clearColor(size_t rtIndex, Float4 value)=0;
        virtual void clearColor(size_t rtIndex, Int4 value)=0;
        virtual void clearColor(size_t rtIndex, UInt4 value)=0;

        virtual void begin(GfxCompiledShader *vertex,
                           GfxCompiledShader *tessControl,
                           GfxCompiledShader *tessEval,
                           GfxCompiledShader *geometry,
                           GfxCompiledShader *fragment,
                           GfxMesh *mesh)=0;
        virtual void end(GfxPrimitive primitive, uint32_t count, GfxWinding winding, size_t instanceCount=1)=0;
        virtual void endIndexed(GfxPrimitive primitive,
                                GfxVertexAttribType type,
                                uint32_t count,
                                size_t offset,
                                GfxBuffer *indices,
                                GfxWinding winding,
                                size_t instanceCount=1)=0;

        virtual void uniform(GfxCompiledShader *shader, const char *name, float value)=0;
        virtual void uniform(GfxCompiledShader *shader, const char *name, const Float2& value)=0;
        virtual void uniform(GfxCompiledShader *shader, const char *name, const Float3& value)=0;
        virtual void uniform(GfxCompiledShader *shader, const char *name, const Float4& value)=0;

        virtual void uniform(GfxCompiledShader *shader, const char *name, int32_t value)=0;
        virtual void uniform(GfxCompiledShader *shader, const char *name, const Int2& value)=0;
        virtual void uniform(GfxCompiledShader *shader, const char *name, const Int3& value)=0;
        virtual void uniform(GfxCompiledShader *shader, const char *name, const Int4& value)=0;

        virtual void uniform(GfxCompiledShader *shader, const char *name, uint32_t value)=0;
        virtual void uniform(GfxCompiledShader *shader, const char *name, const UInt2& value)=0;
        virtual void uniform(GfxCompiledShader *shader, const char *name, const UInt3& value)=0;
        virtual void uniform(GfxCompiledShader *shader, const char *name, const UInt4& value)=0;

        virtual void uniform(GfxCompiledShader *shader, const char *name, size_t count, const float *values)=0;
        virtual void uniform(GfxCompiledShader *shader, const char *name, size_t count, const Float2 *values)=0;
        virtual void uniform(GfxCompiledShader *shader, const char *name, size_t count, const Float3 *values)=0;
        virtual void uniform(GfxCompiledShader *shader, const char *name, size_t count, const Float4 *values)=0;

        virtual void uniform(GfxCompiledShader *shader, const char *name, size_t count, const int32_t *values)=0;
        virtual void uniform(GfxCompiledShader *shader, const char *name, size_t count, const Int2 *values)=0;
        virtual void uniform(GfxCompiledShader *shader, const char *name, size_t count, const Int3 *values)=0;
        virtual void uniform(GfxCompiledShader *shader, const char *name, size_t count, const Int4 *values)=0;

        virtual void uniform(GfxCompiledShader *shader, const char *name, size_t count, const uint32_t *values)=0;
        virtual void uniform(GfxCompiledShader *shader, const char *name, size_t count, const UInt2 *values)=0;
        virtual void uniform(GfxCompiledShader *shader, const char *name, size_t count, const UInt3 *values)=0;
        virtual void uniform(GfxCompiledShader *shader, const char *name, size_t count, const UInt4 *values)=0;

        virtual void addUBOBinding(GfxCompiledShader *shader, const char *name, const GfxBuffer *buffer)=0;
        virtual void addTextureBinding(GfxCompiledShader *shader, const char *name, GfxTexture *texture)=0;

        virtual void uniform(GfxCompiledShader *shader, const char *name, const Matrix3x3& value)=0;
        virtual void uniform(GfxCompiledShader *shader, const char *name, const Matrix4x4& value)=0;

        virtual void uniform(GfxCompiledShader *shader, const char *name, size_t count, const Matrix3x3 *values)=0;
        virtual void uniform(GfxCompiledShader *shader, const char *name, size_t count, const Matrix4x4 *values)=0;

        virtual void pushState()=0;
        virtual void popState()=0;
        virtual void resetState()=0;

        virtual void setBlendingEnabled(bool enabled)=0;
        virtual bool isBlendingEnabled() const=0;

        virtual void setBlendConstantColor(const uint8_t constantColor[4])=0;
        virtual const uint8_t *getBlendConstantColor() const=0;
        virtual uint8_t *getBlendConstantColor()=0;

        virtual void setBlendFactors(GfxBlendFactor srcFactorRGB,
                                     GfxBlendFactor srcFactorAlpha,
                                     GfxBlendFactor dstFactorRGB,
                                     GfxBlendFactor dstFactorAlpha)=0;
        virtual GfxBlendFactor getBlendSrcFactorRGB() const=0;
        virtual GfxBlendFactor getBlendSrcFactorAlpha() const=0;
        virtual GfxBlendFactor getBlendDstFactorRGB() const=0;
        virtual GfxBlendFactor getBlendDstFactorAlpha() const=0;

        virtual void setBlendMode(GfxBlendMode blendRGB, GfxBlendMode blendAlpha)=0;
        virtual GfxBlendMode getBlendModeRGB() const=0;
        virtual GfxBlendMode getBlendModeAlpha() const=0;

        virtual void setWriteDepth(bool depth)=0;
        virtual bool getWriteDepth() const=0;

        virtual void setDepthFunction(GfxDepthFunction depthFunc)=0;
        virtual GfxDepthFunction getDepthFunction() const=0;

        virtual void setCullMode(GfxCullMode cullMode)=0;
        virtual GfxCullMode getCullMode() const=0;

        virtual void setViewport(uint16_t left,
                                 uint16_t bottom,
                                 uint16_t width,
                                 uint16_t height)=0;
        virtual uint16_t getViewportLeft() const=0;
        virtual uint16_t getViewportBottom() const=0;
        virtual uint16_t getViewportWidth() const=0;
        virtual uint16_t getViewportHeight() const=0;

        virtual void setScissor(uint16_t left,
                                uint16_t bottom,
                                uint16_t width,
                                uint16_t height)=0;
        virtual uint16_t getScissorLeft() const=0;
        virtual uint16_t getScissorBottom() const=0;
        virtual uint16_t getScissorWidth() const=0;
        virtual uint16_t getScissorHeight() const=0;

        virtual void setScissorEnabled(bool enabled)=0;
        virtual bool getScissorEnabled()=0;

        virtual void setTessPatchSize(size_t size)=0;
        virtual size_t getTessPatchSize()=0;

    NO_COPY(GfxApi)
};

#endif // GFXAPI_H
