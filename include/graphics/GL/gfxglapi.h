#ifndef GFXGLAPI_H
#define GFXGLAPI_H

#include "graphics/gfxapi.h"
#include "containers/hashmap.h"

class GfxGLApi : public GfxApi
{
    public:
        GfxGLApi();
        virtual ~GfxGLApi();

        virtual GfxShaderImpl *createShaderImpl();
        virtual GfxBuffer *createBuffer();
        virtual GfxTextureImpl *createTextureImpl();
        virtual GfxMeshImpl *createMeshImpl();
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
                           GfxCompiledShader *fragment,
                           ResPtr<GfxMesh> mesh);
        virtual void end(GfxPrimitive primitive, uint32_t count, GfxWinding winding);
        virtual void endIndexed(GfxPrimitive primitive,
                                GfxVertexAttribType type,
                                uint32_t count,
                                size_t offset,
                                GfxBuffer *indices,
                                GfxWinding winding);

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
        virtual void addTextureBinding(GfxCompiledShader *shader, const char *name, ResPtr<GfxTexture> texture);

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

        virtual void setCullMode(GfxCullMode cullMode);
        virtual GfxCullMode getCullMode() const;

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
            GfxCullMode cullMode;
            bool scissorEnabled:1;
        };

        GLuint pipeline;
        State currentState;
        State stateStack[64];
        uint8_t stateStackSize;
        bool inBeginEnd;

        struct TextureBinding
        {
            ResPtr<GfxTexture> texture;
            GLuint target;
            GLint location;
            GLuint program;
            GLenum bindingGet;
            GLint lastTexture;
        };

        struct UBOBinding
        {
            const GfxBuffer *buffer;
            GLint location;
            GLuint program;
        };

        uint8_t textureBindingCount;
        TextureBinding textureBindings[64];

        uint8_t uboBindingCount;
        UBOBinding uboBindings[64];

        void useState(const State& state);
        void beginEndTest();

        struct ProgramCombination
        {
            GLuint vertex;
            GLuint tessControl;
            GLuint tessEval;
            GLuint geometry;
            GLuint fragment;

            inline bool operator == (const ProgramCombination& other) const
            {
                return vertex == other.vertex and
                       tessControl == other.tessControl and
                       tessEval == other.tessEval and
                       geometry == other.geometry and
                       fragment == other.fragment;
            }
        };

        HashMap<ProgramCombination, GLuint> programs;
};

#endif // GFXGLAPI_H
