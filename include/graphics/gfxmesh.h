#ifndef GFXMESH_H
#define GFXMESH_H

#include "containers/hashmap.h"
#include "containers/string.h"
#include "graphics/gfxbuffer.h"
#include "graphics/gfxshader.h"
#include "graphics/gfxmaterial.h"
#include "graphics/gfxdefs.h"
#include "resource/resource.h"
#include "graphics/GL/glfl.h"
#include "math/aabb.h"
#include "misc_macros.h"
#include "scripting/bindings.h"
#include "scene/transform.h"

#include <stddef.h>
#include <stdint.h>

enum class GfxMeshIndexDataType
{
    U8,
    U16,
    U32
} BIND ENUM_CLASS;
static const unsigned int GfxMeshIndexDataTypeMax = 3;

enum class GfxMeshAttribType
{
    Position = 0,
    Normal = 1,
    Tangent = 2,
    Color = 3,
    TexCoord = 4,
    BoneIndex = 5,
    BoneWeight = 6
} BIND ENUM_CLASS;
static const unsigned int GfxMeshAttribTypeMax = 5;

enum class GfxMeshAttribDataType
{
    F16_1 = 0,
    F16_2 = 1,
    F16_3 = 2,
    F16_4 = 3,
    F32_1 = 4,
    F32_2 = 5,
    F32_3 = 6,
    F32_4 = 7,
    U8_1 = 8,
    U8_2 = 9,
    U8_3 = 10,
    U8_4 = 11,
    S8_1 = 12,
    S8_2 = 13,
    S8_3 = 14,
    S8_4 = 15,
    U16_1 = 16,
    U16_2 = 17,
    U16_3 = 18,
    U16_4 = 19,
    S16_1 = 20,
    S16_2 = 21,
    S16_3 = 22,
    S16_4 = 23,
    U32_1 = 24,
    U32_2 = 25,
    U32_3 = 26,
    U32_4 = 27,
    S32_1 = 28,
    S32_2 = 29,
    S32_3 = 30,
    S32_4 = 31,
    U8_1Norm = 32,
    U8_2Norm = 33,
    U8_3Norm = 34,
    U8_4Norm = 35,
    S8_1Norm = 36,
    S8_2Norm = 37,
    S8_3Norm = 38,
    S8_4Norm = 39,
    U16_1Norm = 40,
    U16_2Norm = 41,
    U16_3Norm = 42,
    U16_4Norm = 43,
    S16_1Norm = 44,
    S16_2Norm = 45,
    S16_3Norm = 46,
    S16_4Norm = 47,
    U32_1Norm = 48,
    U32_2Norm = 49,
    U32_3Norm = 50,
    U32_4Norm = 51,
    S32_1Norm = 52,
    S32_2Norm = 53,
    S32_3Norm = 54,
    S32_4Norm = 55
} BIND ENUM_CLASS;
static const unsigned int GfxMeshAttribDataTypeMax = 56;

struct GfxMeshAttrib
{
    GfxMeshAttribType type;
    GfxMeshAttribDataType dataType;
    ResizableData data;
} BIND;

struct GfxAnimationFrame
{
    List<Transform> boneTransforms; //index 0 is for GfxMesh::bones[0], index 1 is for GfxMesh::bones[1]...
};

struct GfxAnimation
{
    size_t fps;
    List<GfxAnimationFrame> frames;
};

struct GfxBone
{
    int16_t parent; //Index for GfxMesh::bones. -1 if the bone has no parent.
    Matrix4x4 boneMatrix;
    List<uint8_t> children; //Indices for GfxMesh::bones
};

class GfxMesh : public Resource
{
    public:
        static const ResType resource_type = ResType::GfxMeshType;

        GfxMesh(const Str& filename);
        GfxMesh();
        virtual ~GfxMesh();

        void addIndices(size_t numIndices,
                        GfxMeshIndexDataType indexType,
                        const void *indices) NO_BIND;

        inline void addIndices(size_t numIndices,
                               GfxMeshIndexDataType indexType,
                               const ResizableData& data)
        {
            static const size_t indexTypeSizes[] = {1, 2, 4};

            if ((indexTypeSizes[(int)indexType] * numIndices) > data.getSize())
            {
                THROW(BoundsException);
            }

            addIndices(numIndices, indexType, data.getData());
        }

        void removeIndices();

        void setAttribute(const GfxMeshAttrib& attrib);
        void removeAttribute(GfxMeshAttribType type);

        inline bool getIndexed() const
        {
            return indexed;
        }

        GfxMeshIndexDataType getIndexType() const
        {
            return indexType;
        }

        const void *getIndices() NO_BIND
        {
            return indices;
        }

        inline const List<GfxMeshAttrib>& getAttribs() const NO_BIND
        {
            return attribs;
        }

        inline size_t getAttribCount() const
        {
            return attribs.getCount();
        }

        inline GfxMeshAttrib getAttrib(size_t index) const
        {
            return attribs[index];
        }

        inline GLuint getGLVAO() const
        {
            return vao;
        }

        inline GLuint getGLIndexBuffer() const
        {
            return indexBuffer;
        }

        AABB aabb;
        size_t numVertices;
        size_t numIndices;
        GfxPrimitive primitive;
        GfxCullMode cullMode;
        GfxWinding winding;
        NO_BIND List<GfxBone> bones;
        NO_BIND HashMap<Str, GfxAnimation> animations;

        virtual void removeContent();

        virtual void save();
    private:
        bool indexed;

        List<GfxMeshAttrib> attribs;
        List<GLuint> buffers;
        GLuint indexBuffer;
        GLuint vao;

        GfxMeshIndexDataType indexType;
        void *indices;
    protected:
        virtual void _load();
        virtual Resource *_copy() const;
} DESTROY(obj->release()) BIND;

class GfxAnimationState
{
    NO_COPY(GfxAnimationState)

    public:
        GfxAnimationState(GfxMesh *mesh_,
                          const Str& animName_);
        ~GfxAnimationState();

        void updateMatrices();

        float timeOffset;

        inline const Str getAnimName() const
        {
            return animName;
        }

        inline GfxMesh *getMesh() const
        {
            return mesh;
        }

        inline GfxBuffer *getMatrixBuffer() const
        {
            return matrixBuffer;
        }

        inline GfxBuffer *getNormalMatrixBuffer() const
        {
            return normalMatrixBuffer;
        }
    private:
        const Str animName;
        GfxMesh *mesh;
        GfxBuffer *matrixBuffer;
        GfxBuffer *normalMatrixBuffer;
} BIND NOT_COPYABLE;

#endif // GFXMESH_H
