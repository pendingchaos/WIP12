#ifndef GFXGLMESHIMPL_H
#define GFXGLMESHIMPL_H

#include "graphics/gfxmesh.h"

class GfxGLMeshImpl : public GfxMeshImpl
{
    NO_COPY_INHERITED(GfxGLMeshImpl, GfxMeshImpl)

    public:
        GfxGLMeshImpl(GfxMesh *mesh);
        virtual ~GfxGLMeshImpl();

        virtual void setVertexAttrib(GfxVertexAttribPurpose purpose,
                                     const GfxMesh::VertexAttribute& attribute);
        virtual void disableVertexAttrib(GfxVertexAttribPurpose purpose);
        virtual bool isVertexAttribEnabled(GfxVertexAttribPurpose purpose) const;
        virtual GfxMesh::VertexAttribute getVertexAttrib(GfxVertexAttribPurpose purpose) const;

        inline GLuint getGLVAO() const
        {
            return vao;
        }
    private:
        GLuint vao;
        GfxMesh::VertexAttribute attributes[GFX_VERTEX_ATTRIB_PURPOSE_COUNT];
};

#endif // GFXGLMESHIMPL_H
