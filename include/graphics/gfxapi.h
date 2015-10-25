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
#include "scripting/bindings.h"

class GfxShaderImpl;
class GfxCompiledShader;
class GfxBuffer;
class GfxFramebuffer;
class GPUTimer;

enum class GfxDriver
{
    Nvidia,
    Mesa,
    Unknown
} BIND ENUM_CLASS;

struct TextureSampler
{
    TextureSampler() : maxAnisotropy(1.0f),
                       minFilter(GfxFilter::Bilinear),
                       magFilter(GfxFilter::Bilinear),
                       mipmapMode(GfxMipmapMode::None),
                       wrapMode(GfxWrapMode::Repeat),
                       shadowmap(false) {}
    TextureSampler(GfxTexture *tex) : maxAnisotropy(tex->getMaximumAnisotropy()),
                                      minFilter(tex->getMinFilter()),
                                      magFilter(tex->getMagFilter()),
                                      mipmapMode(tex->getMipmapMode()),
                                      wrapMode(tex->getWrapMode()),
                                      shadowmap(tex->getShadowmap()) {}

    TextureSampler(float maxAnisotropy_,
                   GfxFilter minFilter_,
                   GfxFilter magFilter_,
                   GfxMipmapMode mipmapMode_,
                   GfxWrapMode wrapMode_,
                   bool shadowmap_) : maxAnisotropy(maxAnisotropy_),
                                      minFilter(minFilter_),
                                      magFilter(magFilter_),
                                      mipmapMode(mipmapMode_),
                                      wrapMode(wrapMode_),
                                      shadowmap(shadowmap_) {}

    inline static TextureSampler createShadowmap() NO_BIND
    {
        return TextureSampler(1.0f,
                              GfxFilter::Bilinear,
                              GfxFilter::Bilinear,
                              GfxMipmapMode::None,
                              GfxWrapMode::Stretch,
                              true);
    }

    float maxAnisotropy;
    GfxFilter minFilter;
    GfxFilter magFilter;
    GfxMipmapMode mipmapMode;
    GfxWrapMode wrapMode;
    bool shadowmap;
} BIND;

class GfxShaderCombination;

class GfxApi
{
    public:
        GfxApi() {}
        virtual ~GfxApi();

        virtual GfxDriver getDriver() const=0;

        virtual size_t getMaxTextureSize() const=0;

        virtual GfxBuffer *createBuffer() RET_PTR_NO_CPP_REF =0;
        virtual GfxTextureImpl *createTextureImpl() NO_BIND=0;
        virtual GfxFramebuffer *createFramebuffer() RET_PTR_NO_CPP_REF=0;
        virtual GPUTimer *createTimer() RET_PTR_NO_CPP_REF=0;

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
        void begin(GfxShaderCombination *shaders, GfxMesh *mesh);
        virtual void draw(size_t instanceCount=1)=0;
        virtual void end()=0;

        //Workaround for shadow.rkt.
        //TODO: Get rid of this.
        inline void begin(GfxCompiledShader *vertex,
                          GfxCompiledShader *geometry,
                          GfxCompiledShader *fragment,
                          GfxMesh *mesh)
        {
            begin(vertex, nullptr, nullptr, geometry, fragment, mesh);
        }

        inline void begin(GfxCompiledShader *vertex,
                          GfxCompiledShader *fragment,
                          GfxMesh *mesh)
        {
            begin(vertex, nullptr, nullptr, nullptr, fragment, mesh);
        }

        virtual GfxCompiledShader *getVertexShader()=0;
        virtual GfxCompiledShader *getTessControlShader()=0;
        virtual GfxCompiledShader *getTessEvalShader()=0;
        virtual GfxCompiledShader *getGeometryShader()=0;
        virtual GfxCompiledShader *getFragmentShader()=0;

        virtual void uniform(GfxCompiledShader *shader, const char *name, float value)=0;
        virtual void uniform(GfxCompiledShader *shader, const char *name, const Float2& value)=0;
        virtual void uniform(GfxCompiledShader *shader, const char *name, const Float3& value)=0;
        virtual void uniform(GfxCompiledShader *shader, const char *name, const Float4& value)=0;

        virtual void uniform(GfxCompiledShader *shader, const char *name, int32_t value)=0;
        virtual void uniform(GfxCompiledShader *shader, const char *name, const Int2& value)=0;
        virtual void uniform(GfxCompiledShader *shader, const char *name, const Int3& value)=0;
        virtual void uniform(GfxCompiledShader *shader, const char *name, const Int4& value)=0;

        virtual void uniform(GfxCompiledShader *shader, const char *name, uint32_t value)=0 NO_BIND;
        virtual void uniform(GfxCompiledShader *shader, const char *name, const UInt2& value)=0;
        virtual void uniform(GfxCompiledShader *shader, const char *name, const UInt3& value)=0;
        virtual void uniform(GfxCompiledShader *shader, const char *name, const UInt4& value)=0;

        inline void uniformU(GfxCompiledShader *shader, const char *name, uint32_t value)
        {
            uniform(shader, name, value);
        }

        virtual void uniform(GfxCompiledShader *shader, const char *name, size_t count, const float *values) NO_BIND=0;
        virtual void uniform(GfxCompiledShader *shader, const char *name, size_t count, const Float2 *values) NO_BIND=0;
        virtual void uniform(GfxCompiledShader *shader, const char *name, size_t count, const Float3 *values) NO_BIND=0;
        virtual void uniform(GfxCompiledShader *shader, const char *name, size_t count, const Float4 *values) NO_BIND=0;

        virtual void uniform(GfxCompiledShader *shader, const char *name, size_t count, const int32_t *values) NO_BIND=0;
        virtual void uniform(GfxCompiledShader *shader, const char *name, size_t count, const Int2 *values) NO_BIND=0;
        virtual void uniform(GfxCompiledShader *shader, const char *name, size_t count, const Int3 *values) NO_BIND=0;
        virtual void uniform(GfxCompiledShader *shader, const char *name, size_t count, const Int4 *values) NO_BIND=0;

        virtual void uniform(GfxCompiledShader *shader, const char *name, size_t count, const uint32_t *values) NO_BIND=0;
        virtual void uniform(GfxCompiledShader *shader, const char *name, size_t count, const UInt2 *values) NO_BIND=0;
        virtual void uniform(GfxCompiledShader *shader, const char *name, size_t count, const UInt3 *values) NO_BIND=0;
        virtual void uniform(GfxCompiledShader *shader, const char *name, size_t count, const UInt4 *values) NO_BIND=0;

        virtual void addUBOBinding(GfxCompiledShader *shader, const char *name, const GfxBuffer *buffer)=0;
        virtual void addTextureBinding(GfxCompiledShader *shader,
                                       const char *name,
                                       GfxTexture *texture,
                                       TextureSampler sampler)=0;

        inline void addTextureBinding(GfxCompiledShader *shader, const char *name, GfxTexture *texture)
        {
            addTextureBinding(shader, name, texture, TextureSampler(texture));
        }

        inline void addTextureBinding2(GfxCompiledShader *shader, const char *name, GfxTexture *texture)
        {
            addTextureBinding(shader, name, texture);
        }

        virtual void uniform(GfxCompiledShader *shader, const char *name, const Matrix3x3& value)=0;
        virtual void uniform(GfxCompiledShader *shader, const char *name, const Matrix4x4& value)=0;

        virtual void uniform(GfxCompiledShader *shader, const char *name, size_t count, const Matrix3x3 *values) NO_BIND=0;
        virtual void uniform(GfxCompiledShader *shader, const char *name, size_t count, const Matrix4x4 *values) NO_BIND=0;

        virtual void pushState()=0;
        virtual void popState()=0;
        virtual void resetState()=0;

        virtual void setBlendingEnabled(bool enabled)=0;
        virtual bool isBlendingEnabled() const=0;

        virtual void setBlendConstantColor(const uint8_t constantColor[4]) NO_BIND=0;
        virtual const uint8_t *getBlendConstantColor() NO_BIND const=0;

        inline void setBlendConstantColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
        {
            uint8_t c[] = {r, g, b, a};
            setBlendConstantColor(c);
        }

        inline uint8_t getBlendConstantColorR() const {return getBlendConstantColor()[0];}
        inline uint8_t getBlendConstantColorG() const {return getBlendConstantColor()[1];}
        inline uint8_t getBlendConstantColorB() const {return getBlendConstantColor()[2];}
        inline uint8_t getBlendConstantColorA() const {return getBlendConstantColor()[3];}

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
} BIND;

#endif // GFXAPI_H
