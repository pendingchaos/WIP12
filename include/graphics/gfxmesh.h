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
#include "misc_macros.h"

#include <stddef.h>
#include <stdint.h>

class GfxGLApi;
class GfxMeshImpl;

class GfxMesh : public Resource
{
    public:
        static const Resource::Type resource_type = GfxMeshType;

        GfxMesh(const String& filename);
        GfxMesh();
        virtual ~GfxMesh();

        void init(GfxPrimitive primitive_,
                  size_t numVertices_,
                  GfxCullMode cullMode,
                  GfxWinding winding);

        struct VertexAttribute
        {
            GfxBuffer *buffer;
            uint8_t numComponents;
            GfxVertexAttribType type;
            uint32_t stride;
            uint32_t offset;

            inline bool operator == (const VertexAttribute& other) const
            {
                return buffer == other.buffer and
                       numComponents == other.numComponents and
                       type == other.type and
                       stride == other.stride and
                       offset == other.offset;
            }
        };

        void setVertexAttrib(GfxVertexAttribPurpose purpose,
                             const GfxMesh::VertexAttribute& attribute);
        void disableVertexAttrib(GfxVertexAttribPurpose purpose);
        bool isVertexAttribEnabled(GfxVertexAttribPurpose purpose) const;
        GfxMesh::VertexAttribute getVertexAttrib(GfxVertexAttribPurpose purpose) const;

        virtual void removeContent();

        virtual void save();

        inline GfxMeshImpl *getImpl() const
        {
            return impl;
        }

        GfxPrimitive primitive;
        size_t numVertices;
        GfxCullMode cullMode;
        GfxWinding winding;

        bool indexed;
        struct
        {
            GfxVertexAttribType type;
            size_t numIndices;
            size_t offset;
            GfxBuffer *buffer;
        } indexData;

        List<GfxBuffer *> buffers;
    private:
        GfxMeshImpl *impl;
    protected:
        virtual void _load();

    NO_COPY_INHERITED(GfxMesh, Resource)
};

class GfxMeshImpl
{
    friend class GfxMesh;

    protected:
        GfxMeshImpl() {}
        virtual ~GfxMeshImpl() {}

        virtual void setVertexAttrib(GfxVertexAttribPurpose purpose,
                                     const GfxMesh::VertexAttribute& attribute)=0;
        virtual void disableVertexAttrib(GfxVertexAttribPurpose purpose)=0;
        virtual bool isVertexAttribEnabled(GfxVertexAttribPurpose purpose) const=0;
        virtual GfxMesh::VertexAttribute getVertexAttrib(GfxVertexAttribPurpose purpose) const=0;

    NO_COPY(GfxMeshImpl)
};

#endif // GFXMESH_H
