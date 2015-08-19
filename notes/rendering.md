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
### Requirements
#### Required:
- OpenGL 3.3
- GL_ARB_tessellation_shader
- GL_ARB_texture_gather
- GL_KHR_debug or similar extension
#### Optional:
- GL_ARB_separate_shader_objects
- GL_ARB_get_program_binary
- GL_ARB_internalformat_query
- GL_ARB_multi_draw_indirect (still used if the below is not supported but not for GPU culling)
- GL_ARB_indirect_parameters (only used when the below is supported) (for GPU culling)
- GL_ARB_compute_shader with GL_ARB_shader_storage_buffer_object (for particle effects and GPU culling if the above is supported)
- GL_ARB_buffer_storage (used when the above is not supported for persistent buffers)
### API
```c++
namespace gfx
{
enum class ShaderType
{
    Vertex,
    Geometry,
    Fragment,
    TessControl,
    TessEval,
    Compute,
    Max
};

enum class DepthFunc
{
    Never,
    Less,
    Equal,
    LessEqual,
    Greater,
    NotEqual,
    GreaterEqual,
    Always,
    Max
};

enum class BlendMode
{
    Add,
    Subtract,
    ReverseSubtract,
    Max
};

enum class BlendFactor
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
    OneMinusConstantAlpha,
    Max
};

enum class MeshAttribDataType
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
    S32_4Norm,
    Max
};

enum class MeshAttribType
{
    Position,
    Normal,
    Tangent,
    Color,
    TexCoord,
    Max
};

enum class TextureFormat
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
    DepthF32,
    Max
};

enum class TextureFilter
{
    Nearest,
    Linear,
    Max
};

enum class TextureMipmapMode
{
    None,
    Nearest,
    Linear,
    Max
};

enum class TextureWrapMode
{
    Clamp,
    Repeat,
    Mirror,
    Max
};

class Texture2D
{
    public:
        struct Sampler
        {
            TextureFilter magFilter;
            TextureFilter minFilter;
            TextureMipmapMode mipmapMode;
            TextureWrapMode XWrapMode;
            TextureWrapMode YWrapMode;
            float maxAnisotropy;
        };
        
        void init(TextureFormat format, UInt2 size);
        void setData(size_t mipmap, const void *data);
        void getData(size_t mipmap, void *data);
        
        TextureFormat getFormat();
        UInt2 getSize();
        Sampler getSampler();
        void setSampler(const Sampler& sampler);
};

class Texture3D
{
    public:
        struct Sampler
        {
            TextureFilter magFilter;
            TextureFilter minFilter;
            TextureMipmapMode mipmapMode;
            TextureWrapMode XWrapMode;
            TextureWrapMode YWrapMode;
            float maxAnisotropy;
        };
        
        void init(TextureFormat format, UInt3 size);
        void setData(size_t mipmap, const void *data);
        void getData(size_t mipmap, void *data);
        
        TextureFormat getFormat();
        UInt3 getSize();
        Sampler getSampler();
        void setSampler(const Sampler& sampler);
};

class TextureCube
{
    public:
        enum class Face
        {
            PositiveX,
            NegativeX,
            PositiveY,
            NegativeY,
            PositiveZ,
            NegativeZ
        };
        
        struct Sampler
        {
            TextureFilter magFilter;
            TextureFilter minFilter;
            TextureMipmapMode mipmapMode;
            TextureWrapMode XWrapMode;
            TextureWrapMode YWrapMode;
            float maxAnisotropy;
        };
        
        void init(TextureFormat format, UInt2 size);
        void setData(Face face, size_t mipmap, const void *data);
        void getData(Face face, size_t mipmap, void *data);
        
        TextureFormat getFormat();
        UInt2 getSize();
        Sampler getSampler();
        void setSampler(const Sampler& sampler);
};

class Buffer
{
    public:
        void init(size_t size, const void *data);
        void setData(size_t offset, size_t amount, const void *data);
        void getData(size_t offset, size_t amount, void *data) const;

        inline size_t getSize() {...}
};

class Mesh
{
    public:
        struct Attrib
        {
            MeshAttribDataType type;
            void *data;
        };
        
        void init(size_t numIndices,
                  IndexType indexType,
                  size_t numAttribs,
                  const Attrib attribMax[MeshAttribType::Max]
                  CullMode cullMode,
                  Winding winding,
                  void *indices);

        inline AABB getAABB() const {...}
};

class Shader
{
    public:
        void setSource(size_t maxInstances, ShaderType type, const String& source);
        
        inline ShaderType getType() {...}
        inline size_t getMaxInstances() {...}
        
        CompiledShader *getCompiled(const HashMap<String, String>& defines);
};

class CompiledShader
{
    public:
        inline Shader *getShader() const {...}
        inline HashMap<String, String> getDefines() const {...}
};

class ShaderCombination
{
    public:
        ShaderCombination(const CompiledShader *shaders[ShaderType::Max]);
        
        inline CompiledShader *getShader(ShaderType type) {...}
};

class PipelineState
{
    public:
        void setBlendingEnabled(bool enabled);
        bool isBlendingEnabled() const;

        void setBlendConstantColor(const uint8_t constantColor[4]);
        const uint8_t *getBlendConstantColor() const;

        void setBlendFactors(BlendFactor srcFactorRGB,
                             BlendFactor srcFactorAlpha,
                             BlendFactor dstFactorRGB,
                             BlendFactor dstFactorAlpha);
        BlendFactor getBlendSrcFactorRGB() const;
        BlendFactor getBlendSrcFactorAlpha() const;
        BlendFactor getBlendDstFactorRGB() const;
        BlendFactor getBlendDstFactorAlpha() const;

        void setBlendMode(BlendMode blendRGB, BlendMode blendAlpha);
        BlendMode getBlendModeRGB() const;
        BlendMode getBlendModeAlpha() const;

        void setWriteDepth(bool depth);
        bool getWriteDepth() const;

        void setDepthFunction(DepthFunc depthFunc);
        DepthFunc getDepthFunction() const;
};

class PerInstanceData
{
    public:
        size_t stride;
        ResizableData data;
};

//This can not be modified when it is used in a draw call.
class ShaderParams
{
    public:
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
        
        void setTexture2D(const String& name, const Texture2D *texture);
        void setTexture3D(const String& name, const Texture3D *texture);
        void setTextureCube(const String& name, const TextureCube *texture);
        void setUBO(const String& name, const Buffer *buffer);
        void setSSBO(const String& name, const Buffer *buffer);
        
        void setImage2D(const String& name, const Texture2D *texture, bool read, bool write);
        void setImage3D(const String& name, const Texture3D *texture, bool read, bool write);
        void setImageCube(const String& name, const TextureCube *texture, bool read, bool write);
        
        void remove(const String& name);
};

class DrawCalls
{
    public:
        void clear();
        void addSetOrderedDraws(bool ordered);
        void addDraw(const PipelineState *state,
                     const ShaderCombination *shaders,
                     const Mesh *mesh,
                     List<const ShaderParams *> params[ShaderType::Max],
                     PerInstanceData instanceData[ShaderType::Max]);
        void addComputeDispatch(Shader *computeShader, UInt3 dimensions);
};

class RenderPass
{
    public:
        void clearDrawCalls();
        void addDrawCalls(const DrawCalls *drawCalls);
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
    
    size_t maxTexturesPerDraw[ShaderType::Max];
    size_t maxImagesPerDraw[ShaderType::Max];
    size_t maxSSBOsPerDraw[ShaderType::Max];
    size_t maxUBOsPerData[ShaderType::Max];
    
    UInt3 maxComputeWorkGroups;
    UInt3 maxComputeWorkGroupSize;
    
    size_t maxSSBOSize;
    size_t maxUBOSize;
    UInt2 max2DTextureSize[TextureFormat::Max];
    UInt3 max3DTextureSize(TextureFormat::Max);
    
    float maxMaxAnisotropy;
};

class Context
{
    public:
        Caps *getCaps() const;
        
        RenderPass *createRenderPass(Texture2D *depth,
                                     const List<Texture2D *>& color) const;
        
        CommandBuffer *createCommandBuffer() const;
        
        Texture2D *createTexture2D() const;
        Texture3D *createTexture3D() const;
        TextureCube *createTextureCube() const;
        Buffer *createBuffer() const;
        Mesh *createMesh() const;
        Shader *createShader() const;
        ShaderCombination *createShaderCombination() const;
        PipelineState *createPipelineState() const;
        ShaderParams *createShaderParams() const;
};
}
```
