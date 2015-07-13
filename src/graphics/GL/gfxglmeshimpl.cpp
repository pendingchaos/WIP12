#include "graphics/GL/gfxglmeshimpl.h"

#include "graphics/GL/gfxglbuffer.h"

GfxGLMeshImpl::GfxGLMeshImpl(GfxMesh *mesh) : GfxMeshImpl(mesh)
{
    glGenVertexArrays(1, &vao);
}

GfxGLMeshImpl::~GfxGLMeshImpl()
{
    glDeleteVertexArrays(1, &vao);
}

void GfxGLMeshImpl::setVertexAttrib(GfxVertexAttribPurpose purpose,
                                  const GfxMesh::VertexAttribute& attribute)
{
    GLint lastVAO;
    glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &lastVAO);
    glBindVertexArray(vao);

    size_t soffset = static_cast<size_t>(attribute.offset);

    glBindBuffer(GL_ARRAY_BUFFER, dynamic_cast<GfxGLBuffer *>(mesh->getBuffer())->getGLBuffer());

    GLint location = (GLint)purpose;

    #define VERTEX_ATTRIB_POINTER(type, normalized)\
    glVertexAttribPointer(location,\
                          attribute.numComponents,\
                          type,\
                          normalized,\
                          attribute.stride,\
                          (const GLvoid *)soffset);

    switch (attribute.type)
    {
    case GfxByte:
    {
        VERTEX_ATTRIB_POINTER(GL_BYTE, false);
        break;
    }
    case GfxUnsignedByte:
    {
        VERTEX_ATTRIB_POINTER(GL_UNSIGNED_BYTE, false);
        break;
    }
    case GfxShort:
    {
        VERTEX_ATTRIB_POINTER(GL_SHORT, false);
        break;
    }
    case GfxUnsignedShort:
    {
        VERTEX_ATTRIB_POINTER(GL_UNSIGNED_SHORT, false);
        break;
    }
    case GfxInteger:
    {
        VERTEX_ATTRIB_POINTER(GL_INT, false);
        break;
    }
    case GfxUnsignedInteger:
    {
        VERTEX_ATTRIB_POINTER(GL_UNSIGNED_INT, false);
        break;
    }
    case GfxNormalizedByte:
    {
        VERTEX_ATTRIB_POINTER(GL_BYTE, true);
        break;
    }
    case GfxNormalizedUnsignedByte:
    {
        VERTEX_ATTRIB_POINTER(GL_UNSIGNED_BYTE, true);
        break;
    }
    case GfxNormalizedShort:
    {
        VERTEX_ATTRIB_POINTER(GL_SHORT, true);
        break;
    }
    case GfxNormalizedUnsignedShort:
    {
        VERTEX_ATTRIB_POINTER(GL_UNSIGNED_SHORT, true);
        break;
    }
    case GfxNormalizedInteger:
    {
        VERTEX_ATTRIB_POINTER(GL_INT, true);
        break;
    }
    case GfxNormalizedUnsignedInteger:
    {
        VERTEX_ATTRIB_POINTER(GL_UNSIGNED_INT, true);
        break;
    }
    case GfxHalfFloat:
    {
        VERTEX_ATTRIB_POINTER(GL_HALF_FLOAT, false);
        break;
    }
    case GfxFloat:
    {
        VERTEX_ATTRIB_POINTER(GL_FLOAT, false);
        break;
    }
    case GfxDouble:
    {
        VERTEX_ATTRIB_POINTER(GL_DOUBLE, false);
        break;
    }
    }

    #undef VERTEX_ATTRIB_POINTER

    glEnableVertexAttribArray(location);

    glBindVertexArray(lastVAO);

    attributes[location] = attribute;
}

void GfxGLMeshImpl::disableVertexAttrib(GfxVertexAttribPurpose purpose)
{
    GLint lastVAO;
    glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &lastVAO);
    glBindVertexArray(vao);

    glDisableVertexAttribArray((GLint)purpose);

    glBindVertexArray(lastVAO);
}

bool GfxGLMeshImpl::isVertexAttribEnabled(GfxVertexAttribPurpose purpose) const
{
    GLint lastVAO;
    glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &lastVAO);
    glBindVertexArray(vao);

    GLint enabled;
    glGetVertexAttribiv((GLint)purpose, GL_VERTEX_ATTRIB_ARRAY_ENABLED, &enabled);

    glBindVertexArray(lastVAO);

    return enabled;
}

GfxMesh::VertexAttribute GfxGLMeshImpl::getVertexAttrib(GfxVertexAttribPurpose purpose) const
{
    return attributes[(int)purpose];
}
