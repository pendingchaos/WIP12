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
                                     const GfxVertexAttribute& attribute);
        virtual void disableVertexAttrib(GfxVertexAttribPurpose purpose);
        virtual bool isVertexAttribEnabled(GfxVertexAttribPurpose purpose) const;
        virtual GfxVertexAttribute getVertexAttrib(GfxVertexAttribPurpose purpose) const;

        inline GLuint getGLVAO() const
        {
            return vao;
        }
    private:
        GLuint vao;
        GfxVertexAttribute attributes[GFX_VERTEX_ATTRIB_PURPOSE_COUNT];
};

#endif // GFXGLMESHIMPL_H
