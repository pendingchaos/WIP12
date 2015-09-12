## HBAO
- https://gist.github.com/fisch0920/6770346
- https://github.com/nvpro-samples/gl_ssao/blob/master/hbao.frag.glsl
- https://a248.e.akamai.net/f/862/5658/3/developer.download.nvidia.com/presentations/2008/SIGGRAPH/HBAO_SIG08b.pdf
- Fix false occlusion at the borders.
- Interleaving is incorrect or HBAO is.

## IBL
- blog.selfshadow.com/publications/s2013-shading-course/karis/s2013_pbs_epic_notes_v2.pdf
- https://github.com/jMonkeyEngine/jmonkeyengine/compare/PBRisComing#diff-507f20304921a2bc77fb399401c5a7b8R138
- https://github.com/jMonkeyEngine/jmonkeyengine/compare/PBRisComing#diff-507f20304921a2bc77fb399401c5a7b8R138
- https://github.com/jMonkeyEngine/jmonkeyengine/blob/af35f27b938ca8ec7e2e6d2b479ea6e452cee835/jme3-core/src/main/resources/Common/ShaderLib/PBR.glsllib
- jmonkeyengine.org/301308/physically-based-rendering-part-3/
- https://github.com/jMonkeyEngine/jmonkeyengine/blob/af35f27b938ca8ec7e2e6d2b479ea6e452cee835/jme3-core/src/main/resources/Common/MatDefs/Light/PBRLighting.frag
- https://github.com/jMonkeyEngine/jmonkeyengine/compare/PBRisComing#diff-a76e40d1405edd3626e52286d1f179dfR441
- https://github.com/jMonkeyEngine/jmonkeyengine/compare/PBRisComing#diff-a76e40d1405edd3626e52286d1f179dfR476
- https://github.com/jMonkeyEngine/jmonkeyengine/tree/af35f27b938ca8ec7e2e6d2b479ea6e452cee835/jme3-core/src/main/java/com/jme3/texture/pbr

- Next Generation Post Processing in Call of Duty Advanced Warfare slide 120 (for point light filtering) (advances.realtimerendering.com).
    - https://github.com/tobspr/RenderPipeline/blob/master/Shader/Includes/Shadows.include#L31

- Use screen for bloom blending?
    - vec3 screen(vec3 a, vec3 b) {return vec3(1.0) - (vec3(1.0) - a) * (vec3(1.0) - b);}
    - Clamps result.
    - Looks nicer than addition.

## New rendering code

### Required:
- OpenGL 3.3
- GL_ARB_tessellation_shader
- GL_KHR_debug or similar extension
- GL_ARB_separate_shader_objects

### Optional:
- GL_ARB_internalformat_query2
    - For better max texture sizes.
    - glGetInternalFormati64v returns a width and height of 0 if the format is not natively supported by the GPU
        - Fallback on glGetIntegerv
- GPU Culling path
    - GL_ARB_multi_draw_indirect
    - GL_ARB_indirect_parameters
    - GL_ARB_compute_shader
    - GL_ARB_shader_storage_buffer_object
- Multi draw indirect path
    - GL_ARB_multi_draw_indirect
- GPU Particles path
    - GL_ARB_compute_shader
    - GL_ARB_shader_storage_buffer_object
- CPU Particles path
    - GL_ARB_buffer_storage (persistent buffers)

### API
```c++
enum class GfxShaderType
{
    Vertex,
    Geometry,
    Fragment,
    TessControl,
    TessEval,
    Compute
};
static const unsigned int GfxShaderTypeMax = 6;

enum class GfxDepthFunc
{
    Never,
    Less,
    Equal,
    LessEqual,
    Greater,
    NotEqual,
    GreaterEqual,
    Always
};
static const unsigned int GfxDepthFuncMax = 8;

enum class GfxBlendMode
{
    Add,
    Subtract,
    ReverseSubtract
};
static const unsigned int GfxBlendModeMax = 3;

enum class GfxBlendFactor
{
    Zero,
    One,
    SrcColor,
    OneMinusSrcColor,
    DstColor,
    OneMinusDstColor,
    SrcAlpha,
    OneMinusSrcAlpha,
    DstAlpha,
    OneMinusDstAlpha,
    ConstantColor,
    OneMinusConstantColor,
    ConstantAlpha,
    OneMinusConstantAlpha
};
static const unsigned int GfxBlendFactorMax = 14;

enum class GfxMeshAttribDataType
{
    F16_1,
    F16_2,
    F16_3,
    F16_4,
    F32_1,
    F32_2,
    F32_3,
    F32_4,
    U8_1,
    U8_2,
    U8_3,
    U8_4,
    S8_1,
    S8_2,
    S8_3,
    S8_4,
    U16_1,
    U16_2,
    U16_3,
    U16_4,
    S16_1,
    S16_2,
    S16_3,
    S16_4,
    U32_1,
    U32_2,
    U32_3,
    U32_4,
    S32_1,
    S32_2,
    S32_3,
    S32_4,
    U8_1Norm,
    U8_2Norm,
    U8_3Norm,
    U8_4Norm,
    S8_1Norm,
    S8_2Norm,
    S8_3Norm,
    S8_4Norm,
    U16_1Norm,
    U16_2Norm,
    U16_3Norm,
    U16_4Norm,
    S16_1Norm,
    S16_2Norm,
    S16_3Norm,
    S16_4Norm,
    U32_1Norm,
    U32_2Norm,
    U32_3Norm,
    U32_4Norm,
    S32_1Norm,
    S32_2Norm,
    S32_3Norm,
    S32_4Norm
};
static const unsigned int GfxBlendModeMax = 56;

enum class GfxMeshIndexDataType
{
    U8,
    U16,
    U24,
    U32
};
static const unsigned int GfxMeshIndexDataTypeMax = 4;

enum class GfxMeshAttribType
{
    Position,
    Normal,
    Tangent,
    Color,
    TexCoord
};
static const unsigned int GfxMeshAttribTypeMax = 5;

enum class GfxTextureFormat
{
    RedU8,
    RedI8,
    RedU16,
    RedI16,
    RedF32,
    RedF32_F16
    RedGreenU8,
    RedGreenI8,
    RedGreenU16,
    RedGreenI16,
    RedGreenF32,
    RedGreenF32_F16,
    RGBU8,
    RGBI8,
    RGBU16,
    RGBI16,
    RGBF32,
    RGBF32_F16,
    RGBAU8,
    RGBAI8,
    RGBAU16,
    RGBAI16,
    RGBAF32,
    RGBAF32_F16,
    SRGBU8,
    SRGBAU8,
    DepthF32_F16,
    DepthF32_F24,
    DepthF32
};
static const unsigned int GfxTextureFormatMax = 29;

enum class GfxTextureFilter
{
    Nearest,
    Linear
};
static const unsigned int GfxTextureFilterMax = 2;

enum class GfxTextureMipmapMode
{
    None,
    Nearest,
    Linear
};
static const unsigned int GfxTextureMipmapModeMax = 3;

enum class GfxTextureWrapMode
{
    Clamp,
    Repeat,
    Mirror
};
static const unsigned int GfxTextureWrapModeMax = 3;

struct TextureSampler
{
    GfxTextureFilter magFilter;
    GfxTextureFilter minFilter;
    GfxTextureMipmapMode mipmapMode;
    GfxTextureWrapMode wrapMode;
    float maxAnisotropy;
};

struct GfxSamplerOverride
{
    bool overrideMinFilter:1;
    bool overrideMagFilter:1;
    bool overrideMipmapMode:1;
    bool overrideWrapMode:1;
    bool overrideMaxAnisotropy:1;
    GfxTextureSampler sampler;
};

struct GfxMeshAttrib
{
    GfxMeshAttribDataType type;
    void *data;
};

struct GfxPerInstanceData
{
    size_t stride;
    ResizableData data;
};

enum class GfxFace
{
    PositiveX,
    NegativeX,
    PositiveY,
    NegativeY,
    PositiveZ,
    NegativeZ
};

class GfxContext;

class Texture2D
{
    public:
        Texture2D(GfxContext *context, GfxTextureFormat format, UInt2 size);
        ~Texture2D();

        void setData(size_t mipmap, const void *data);
        void getData(size_t mipmap, void *data);

        GfxTextureFormat getFormat();
        UInt2 getSize();
        GfxSamplerOverride getSamplerOverride();
        void setSamplerOverride(const GfxSamplerOverride& sampler);
};

class GfxTexture3D
{
    public:
        GfxTexture3D(GfxContext *context, GfxTextureFormat format, UInt3 size);
        ~GfxTexture3D();

        void setData(size_t mipmap, const void *data);
        void getData(size_t mipmap, void *data);

        GfxTextureFormat getFormat();
        UInt3 getSize();
        GfxSamplerOverride getSamplerOverride();
        void setSamplerOverride(const GfxSamplerOverride& sampler);
};

class GfxTextureCube
{
    public:
        GfxTextureCube(GfxContext *context, GfxTextureFormat format, UInt2 size);
        ~GfxTextureCube();

        void setData(GfxFace face, size_t mipmap, const void *data);
        void getData(GfxFace face, size_t mipmap, void *data);

        GfxTextureFormat getFormat();
        UInt2 getSize();
        GfxSamplerOverride getSamplerOverride();
        void setSamplerOverride(const GfxSamplerOverride& sampler);
};

class GfxShaderParamBuffer
{
    public:
        GfxShaderParamBuffer(Context *context);
        ~GfxShaderParamBuffer();

        void setInt(size_t offset, int32_t value);
        void setInt2(size_t offset, const Int2& value);
        void setInt3(size_t offset, const Int3& value);
        void setInt4(size_t offset, const Int4& value);
        void setUInt(size_t offset, size_t index, uint32_t value);
        void setUInt2(size_t offset, const UInt2& value);
        void setUInt3(size_t offset, const UInt3& value);
        void setUInt4(size_t offset, const UInt4& value);
        void setFloat(size_t offset, float value);
        void setFloat2(size_t offset, const Float2& value);
        void setFloat3(size_t offset, const Float3& value);
        void setFloat4(size_t offset, const Float4& value);
        void setMatrix3x3(size_t offset, const Matrix3x3& value);
        void setMatrix4x4(size_t offset, const Matrix4x4& value);
};

class GfxMesh
{
    public:
        GfxMesh(Context *context);
        ~GfxMesh();

        void initIndex(size_t numIndices,
                       GfxMeshIndexDataType indexType,
                       void *indices);
        void removeIndexData();
        bool hasIndexData() const;

        void initVertex(size_t numVertices,
                        size_t numAttribs,
                        const GfxMeshAttrib *attribs);

        size_t getNumIndices() const;
        size_t getNumVertices() const;

        IndexType getIndexType() const;
        void *getIndices();

        size_t getNumAttribs() const;
        GfxMeshAttrib getAttrib(GfxMeshAttribType type, bool data);

        void GfxCullMode getCullMode() const;
        void setCullMode(GfxCullMode mode);

        void GfxWinding getWinding() const;
        void setWinding(GfxWinding winding);

        AABB getAABB() const;
    private:
        AABB aabb;
};

class Shader
{
    public:
        GfxShader(Context *context);
        ~GfxShader();

        void setSource(size_t maxInstances, GfxShaderType type, const String& source);

        inline GfxShaderType getType() {...}
        inline size_t getMaxInstances() {...}

        GfxCompiledShader *getCompiled(const HashMap<String, String>& defines);
};

class GfxCompiledShader
{
    public:
        inline GfxShader *getShader() const {...}
};

class GfxShaderCombination
{
    public:
        GfxShaderCombination(GfxContext *context, const GfxShader *shaders[GfxShaderTypeMax]);
        ~GfxShaderCombination();

        void setDefine(GfxShaderType shader, const String& name, const String& content);
        const String& getDefine(GfxShaderType shader, const String& name);
        void removeDefine(GfxShaderType shader, const String& name);

        GfxCompiledShader *getShader(GfxShaderType type);
};

class PipelineState
{
    public:
        PipelineState(GfxContext *context);
        ~PipelineState();

        void setBlendingEnabled(bool enabled);
        bool isBlendingEnabled() const;

        void setBlendConstantColor(const uint8_t constantColor[4]);
        const uint8_t *getBlendConstantColor() const;

        void setBlendFactors(GfxBlendFactor srcFactorRGB,
                             GfxBlendFactor srcFactorAlpha,
                             GfxBlendFactor dstFactorRGB,
                             GfxBlendFactor dstFactorAlpha);
        GfxBlendFactor getBlendSrcFactorRGB() const;
        GfxBlendFactor getBlendSrcFactorAlpha() const;
        GfxBlendFactor getBlendDstFactorRGB() const;
        GfxBlendFactor getBlendDstFactorAlpha() const;

        void setBlendMode(GfxBlendMode blendRGB, GfxBlendMode blendAlpha);
        GfxBlendMode getBlendModeRGB() const;
        GfxBlendMode getBlendModeAlpha() const;

        void setWriteDepth(bool depth);
        bool getWriteDepth() const;

        void setDepthFunction(GfxDepthFunc depthFunc);
        GfxDepthFunc getDepthFunction() const;
};

//This can not be modified when it is used in a draw call.
class ShaderParams
{
    public:
        ShaderParams(Context *context);
        ~ShaderParams();

        void setInt(const String& name, int32_t value);
        void setInt2(const String& name, const Int2& value);
        void setInt3(const String& name, const Int3& value);
        void setInt4(const String& name, const Int4& value);
        void setUInt(const String& name, uint32_t value);
        void setUInt2(const String& name, const UInt2& value);
        void setUInt3(const String& name, const UInt3& value);
        void setUInt4(const String& name, const UInt4& value);
        void setFloat(const String& name, float value);
        void setFloat2(const String& name, const Float2& value);
        void setFloat3(const String& name, const Float3& value);
        void setFloat4(const String& name, const Float4& value);
        void setMatrix3x3(const String& name, const Matrix3x3& value);
        void setMatrix4x4(const String& name, const Matrix4x4& value);

        void setIntArray(const String& name, const List<int32_t>& values);
        void setInt2Array(const String& name, const List<Int2>& values);
        void setInt3Array(const String& name, const List<Int3>& values);
        void setInt4Array(const String& name, const List<Int4>& values);
        void setUIntArray(const String& name, const List<uint32_t>& values);
        void setUInt2Array(const String& name, const List<UInt2>& values);
        void setUInt3Array(const String& name, const List<UInt3>& values);
        void setUInt4Array(const String& name, const List<UInt4>& values);
        void setFloatArray(const String& name, const List<float>& values);
        void setFloat2Array(const String& name, const List<Float2>& values);
        void setFloat3Array(const String& name, const List<Float3>& values);
        void setFloat4Array(const String& name, const List<Float4>& values);
        void setMatrix3x3Array(const String& name, const List<Matrix3x3>& values);
        void setMatrix4x4Array(const String& name, const List<Matrix4x4>& values);

        void setTexture2D(const String& name, const GfxTexture2D *texture);
        void setTexture3D(const String& name, const GfxTexture3D *texture);
        void setTextureCube(const String& name, const GfxTextureCube *texture);
        void setUBO(const String& name, const GfxShaderParamBuffer *buffer);
        void setSSBO(const String& name, const GfxShaderParamBuffer *buffer, bool read, bool write);

        void setImage2D(const String& name, const GfxTexture2D *texture, bool read, bool write);
        void setImage3D(const String& name, const GfxTexture3D *texture, bool read, bool write);
        void setImageCube(const String& name, const GfxTextureCube *texture, bool read, bool write);

        void remove(const String& name);
};

class DrawCalls
{
    public:
        GfxDrawCalls(GfxContext *context);
        ~GfxDrawCalls();

        void clear();
        void addSetOrderedDraws(bool ordered);
        void addDraw(const GfxPipelineState *state,
                     const GfxShaderCombination *shaders,
                     const GfxMesh *mesh,
                     List<const GfxShaderParams *> params[GfxShaderTypeMax],
                     GfxPerInstanceData instanceData[GfxShaderTypeMax]);
        void addComputeDispatch(GfxShader *computeShader, UInt3 dimensions);
};

class RenderPass
{
    public:
        RenderPass(GfxContext *context,
                   GfxTexture2D *depth,
                   const List<GfxTexture2D *>& color)
        ~RenderPass();

        void clearDrawCalls();
        void addDrawCalls(const GfxDrawCalls *drawCalls);
        void executeDrawCalls(size_t viewLeft,
                              size_t viewBottom,
                              size_t viewWidth,
                              size_t viewHeight);

        void clearDepth(float value=1.0f);
        void clearColor(size_t index, Float4 value);
};

struct Caps
{
    bool indirectDraws;
    bool indirectDrawParameters;
    bool computeShader;
    bool shaderStorageBufferObject;

    size_t maxTexturesPerDraw[GfxShaderTypeMax];
    size_t maxImagesPerDraw[GfxShaderTypeMax];
    size_t maxSSBOsPerDraw[GfxShaderTypeMax];
    size_t maxUBOsPerData[GfxShaderTypeMax];

    UInt3 maxComputeWorkGroups;
    UInt3 maxComputeWorkGroupSize;

    size_t maxSSBOSize;
    size_t maxUBOSize;
    UInt2 max2DTextureSize[GfxTextureFormatMax];
    UInt3 max3DTextureSize(GfxTextureFormatMax);

    float maxMaxAnisotropy;
};

class GfxContext
{
    public:
        GfxCaps *getCaps() const;

        GfxSampler getSampler() const;
        void setSampler(const GfxSampler& sampler) const;
};
```
