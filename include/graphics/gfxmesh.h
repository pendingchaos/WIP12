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

#include <stddef.h>
#include <stdint.h>

class GfxGLApi;
class GfxMeshImpl;

struct GfxVertexAttribute
{
    uint8_t numComponents;
    GfxVertexAttribType type;
    uint32_t stride;
    uint32_t offset;
} BIND;

struct GfxIndexData
{
    GfxVertexAttribType type;
    size_t numIndices;
    size_t offset;
} BIND;

class GfxMesh : public Resource
{
    public:
        static const ResType resource_type = ResType::GfxMeshType;

        GfxMesh(const String& filename);
        GfxMesh();
        virtual ~GfxMesh();

        void init(GfxPrimitive primitive_,
                  size_t numVertices_,
                  GfxCullMode cullMode,
                  GfxWinding winding);

        void setVertexAttrib(GfxVertexAttribPurpose purpose,
                             const GfxVertexAttribute& attribute);
        void disableVertexAttrib(GfxVertexAttribPurpose purpose);
        bool isVertexAttribEnabled(GfxVertexAttribPurpose purpose) const;
        GfxVertexAttribute getVertexAttrib(GfxVertexAttribPurpose purpose) const;

        virtual void removeContent();

        virtual void save();

        inline GfxMeshImpl *getImpl() const NO_BIND
        {
            return impl;
        }

        GfxPrimitive primitive;
        size_t numVertices;
        GfxCullMode cullMode;
        GfxWinding winding;

        bool indexed;
        GfxIndexData indexData;

        AABB aabb;

        inline GfxBuffer *getBuffer() const
        {
            return buffer;
        }
    private:
        GfxBuffer *buffer;
        GfxMeshImpl *impl;
    protected:
        virtual void _load();
        virtual Resource *_copy() const;

    NO_COPY_INHERITED(GfxMesh, Resource)
} DESTROY(obj->release()) BIND;

class GfxMeshImpl
{
    friend class GfxMesh;

    protected:
        GfxMeshImpl(GfxMesh *mesh_) : mesh(mesh_) {}
        virtual ~GfxMeshImpl() {}

        virtual void setVertexAttrib(GfxVertexAttribPurpose purpose,
                                     const GfxVertexAttribute& attribute)=0;
        virtual void disableVertexAttrib(GfxVertexAttribPurpose purpose)=0;
        virtual bool isVertexAttribEnabled(GfxVertexAttribPurpose purpose) const=0;
        virtual GfxVertexAttribute getVertexAttrib(GfxVertexAttribPurpose purpose) const=0;

        GfxMesh *mesh;

    NO_COPY(GfxMeshImpl)
};

#endif // GFXMESH_H
