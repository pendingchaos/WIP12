#ifndef GFXGLAPI_H
#define GFXGLAPI_H

#include "graphics/gfxapi.h"
#include "containers/hashmap.h"

class GfxGLApi : public GfxApi
{
    public:
        GfxGLApi();
        virtual ~GfxGLApi();

        virtual GfxDriver getDriver() const;

        virtual size_t getMaxTextureSize() const;

        unsigned int getOpenGLMinorVersion() const
        {
            return glMinor;
        }

        unsigned int getOpenGLMajorVersion() const
        {
            return glMajor;
        }

        virtual GfxBuffer *createBuffer();
        virtual GfxTextureImpl *createTextureImpl();
        virtual GfxFramebuffer *createFramebuffer();
        virtual GPUTimer *createTimer();

        virtual void setCurrentFramebuffer(GfxFramebuffer *framebuffer);

        virtual void clearDepth(float depthValue=1.0f);
        virtual void clearColor(size_t rtIndex, Float4 value);
        virtual void clearColor(size_t rtIndex, Int4 value);
        virtual void clearColor(size_t rtIndex, UInt4 value);

        virtual void begin(GfxCompiledShader *vertex,
                           GfxCompiledShader *tessControl,
                           GfxCompiledShader *tessEval,
                           GfxCompiledShader *geometry,
                           GfxCompiledShader *fragment);
        virtual void draw(size_t instanceCount=1);
        virtual void end();

        virtual void setMesh(GfxMesh *mesh);

        virtual GfxCompiledShader *getVertexShader();
        virtual GfxCompiledShader *getTessControlShader();
        virtual GfxCompiledShader *getTessEvalShader();
        virtual GfxCompiledShader *getGeometryShader();
        virtual GfxCompiledShader *getFragmentShader();

        virtual void uniform(GfxCompiledShader *shader, const char *name, float value);
        virtual void uniform(GfxCompiledShader *shader, const char *name, const Float2& value);
        virtual void uniform(GfxCompiledShader *shader, const char *name, const Float3& value);
        virtual void uniform(GfxCompiledShader *shader, const char *name, const Float4& value);

        virtual void uniform(GfxCompiledShader *shader, const char *name, int32_t value);
        virtual void uniform(GfxCompiledShader *shader, const char *name, const Int2& value);
        virtual void uniform(GfxCompiledShader *shader, const char *name, const Int3& value);
        virtual void uniform(GfxCompiledShader *shader, const char *name, const Int4& value);

        virtual void uniform(GfxCompiledShader *shader, const char *name, uint32_t value);
        virtual void uniform(GfxCompiledShader *shader, const char *name, const UInt2& value);
        virtual void uniform(GfxCompiledShader *shader, const char *name, const UInt3& value);
        virtual void uniform(GfxCompiledShader *shader, const char *name, const UInt4& value);

        virtual void uniform(GfxCompiledShader *shader, const char *name, size_t count, const float *values);
        virtual void uniform(GfxCompiledShader *shader, const char *name, size_t count, const Float2 *values);
        virtual void uniform(GfxCompiledShader *shader, const char *name, size_t count, const Float3 *values);
        virtual void uniform(GfxCompiledShader *shader, const char *name, size_t count, const Float4 *values);

        virtual void uniform(GfxCompiledShader *shader, const char *name, size_t count, const int32_t *values);
        virtual void uniform(GfxCompiledShader *shader, const char *name, size_t count, const Int2 *values);
        virtual void uniform(GfxCompiledShader *shader, const char *name, size_t count, const Int3 *values);
        virtual void uniform(GfxCompiledShader *shader, const char *name, size_t count, const Int4 *values);

        virtual void uniform(GfxCompiledShader *shader, const char *name, size_t count, const uint32_t *values);
        virtual void uniform(GfxCompiledShader *shader, const char *name, size_t count, const UInt2 *values);
        virtual void uniform(GfxCompiledShader *shader, const char *name, size_t count, const UInt3 *values);
        virtual void uniform(GfxCompiledShader *shader, const char *name, size_t count, const UInt4 *values);

        virtual void addUBOBinding(GfxCompiledShader *shader, const char *name, const GfxBuffer *buffer);
        virtual void addTextureBinding(GfxCompiledShader *shader,
                                       const char *name,
                                       GfxTexture *texture,
                                       TextureSampler sampler);

        virtual void uniform(GfxCompiledShader *shader, const char *name, const Matrix3x3& value);
        virtual void uniform(GfxCompiledShader *shader, const char *name, const Matrix4x4& value);

        virtual void uniform(GfxCompiledShader *shader, const char *name, size_t count, const Matrix3x3 *values);
        virtual void uniform(GfxCompiledShader *shader, const char *name, size_t count, const Matrix4x4 *values);

        virtual void pushState();
        virtual void popState();
        virtual void resetState();

        virtual void setBlendingEnabled(bool enabled);
        virtual bool isBlendingEnabled() const;

        virtual void setBlendConstantColor(const uint8_t constantColor[4]);
        virtual const uint8_t *getBlendConstantColor() const;
        virtual uint8_t *getBlendConstantColor();

        virtual void setBlendFactors(GfxBlendFactor srcFactorRGB,
                                     GfxBlendFactor srcFactorAlpha,
                                     GfxBlendFactor dstFactorRGB,
                                     GfxBlendFactor dstFactorAlpha);
        virtual GfxBlendFactor getBlendSrcFactorRGB() const;
        virtual GfxBlendFactor getBlendSrcFactorAlpha() const;
        virtual GfxBlendFactor getBlendDstFactorRGB() const;
        virtual GfxBlendFactor getBlendDstFactorAlpha() const;

        virtual void setBlendMode(GfxBlendMode blendRGB, GfxBlendMode blendAlpha);
        virtual GfxBlendMode getBlendModeRGB() const;
        virtual GfxBlendMode getBlendModeAlpha() const;

        virtual void setWriteDepth(bool depth);
        virtual bool getWriteDepth() const;

        virtual void setDepthFunction(GfxDepthFunction depthFunc);
        virtual GfxDepthFunction getDepthFunction() const;

        virtual void setViewport(uint16_t left,
                                 uint16_t bottom,
                                 uint16_t width,
                                 uint16_t height);
        virtual uint16_t getViewportLeft() const;
        virtual uint16_t getViewportBottom() const;
        virtual uint16_t getViewportWidth() const;
        virtual uint16_t getViewportHeight() const;

        virtual void setScissor(uint16_t left,
                                uint16_t bottom,
                                uint16_t width,
                                uint16_t height);
        virtual uint16_t getScissorLeft() const;
        virtual uint16_t getScissorBottom() const;
        virtual uint16_t getScissorWidth() const;
        virtual uint16_t getScissorHeight() const;

        virtual void setScissorEnabled(bool enabled);
        virtual bool getScissorEnabled();

        virtual void setTessPatchSize(size_t size);
        virtual size_t getTessPatchSize();
    private:
        struct State
        {
            size_t patchSize;
            uint8_t constantColor[4];
            GfxBlendFactor srcFactorRGB:4;
            GfxBlendFactor srcFactorAlpha:4;
            GfxBlendFactor dstFactorRGB:4;
            GfxBlendFactor dstFactorAlpha:4;
            GfxBlendMode blendRGB:2;
            GfxBlendMode blendAlpha:2;
            bool writeDepth:1;
            GfxDepthFunction depthFunc:3;
            bool blendingEnabled:1;
            uint16_t viewportLeft;
            uint16_t viewportBottom;
            uint16_t viewportWidth;
            uint16_t viewportHeight;
            uint16_t scissorLeft;
            uint16_t scissorBottom;
            uint16_t scissorWidth;
            uint16_t scissorHeight;
            bool scissorEnabled:1;
        };

        unsigned int glMajor;
        unsigned int glMinor;
        GfxDriver driver;

        GLuint pipeline;
        State currentState;
        State stateStack[64];
        uint8_t stateStackSize;

        uint8_t textureBindingCount;
        GLuint textureBindings[128];

        uint8_t uboBindingCount;

        GfxMesh *mesh;
        bool tesselation;

        GfxCompiledShader *vertex;
        GfxCompiledShader *tessControl;
        GfxCompiledShader *tessEval;
        GfxCompiledShader *geometry;
        GfxCompiledShader *fragment;

        GLuint samplers[4096];
        GLuint getSampler(const TextureSampler& params);

        void useState(const State& state);
};

#endif // GFXGLAPI_H
