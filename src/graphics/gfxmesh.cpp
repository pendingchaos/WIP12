#include "graphics/gfxmesh.h"

#include "graphics/gfxapi.h"
#include "file.h"
#include "globals.h"
#include "containers/list.h"

GfxMesh::GfxMesh(const String& filename) : Resource(filename,
                                                    ResType::GfxMeshType),
                                           numVertices(0),
                                           numIndices(0),
                                           primitive(GfxTriangles),
                                           cullMode(GfxCullNone),
                                           winding(GfxCCW),
                                           indexed(false),
                                           indexBuffer(0),
                                           indexType(GfxMeshIndexDataType::U8),
                                           indices(nullptr)
{
    glGenVertexArrays(1, &vao);
}

GfxMesh::GfxMesh() : Resource(ResType::GfxMeshType),
                     numVertices(0),
                     numIndices(0),
                     primitive(GfxTriangles),
                     cullMode(GfxCullNone),
                     winding(GfxCCW),
                     indexed(false),
                     indexBuffer(0),
                     indexType(GfxMeshIndexDataType::U8),
                     indices(nullptr)
{
    glGenVertexArrays(1, &vao);
}

GfxMesh::~GfxMesh()
{
    glDeleteVertexArrays(1, &vao);

    if (indexBuffer != 0)
    {
        glDeleteBuffers(1, &indexBuffer);
    }

    glDeleteBuffers(buffers.getCount(), buffers.getData());

    DEALLOCATE(indices);
}

void GfxMesh::addIndices(size_t numIndices_, GfxMeshIndexDataType indexType_, const void *indices_)
{
    if (indexed)
    {
        glDeleteBuffers(1, &indexBuffer);
        DEALLOCATE(indices);
    }

    indexed = true;
    numIndices = numIndices_;
    indexType = indexType_;

    size_t indicesSize = numIndices * ((int)indexType+1);

    indices = ALLOCATE(indicesSize);

    std::memcpy(indices, indices_, indicesSize);

    GLint lastBuffer;
    glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &lastBuffer);

    glGenBuffers(1, &indexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, indexBuffer);

    glBufferData(GL_ARRAY_BUFFER, indicesSize, indices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, lastBuffer);
}

void GfxMesh::removeIndices()
{
    if (indexed)
    {
        glDeleteBuffers(1, &indexBuffer);
        indexBuffer = 0;
    }

    DEALLOCATE(indices);
    indices = nullptr;

    indexed = false;
    numIndices = 0;
    indexType = GfxMeshIndexDataType::U8;
}

void GfxMesh::setAttribute(const GfxMeshAttrib& attrib)
{
    GLint lastBuffer;
    glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &lastBuffer);

    GLuint buffer;

    GfxMeshAttrib newAttrib;

    for (size_t i = 0; i < attribs.getCount(); ++i)
    {
        if (attribs[i].type == attrib.type)
        {
            attribs[i].data = attrib.data.copy();
            attribs[i].dataType = attrib.dataType;

            buffer = buffers[i];
            glBindBuffer(GL_ARRAY_BUFFER, buffer);

            glBufferData(GL_ARRAY_BUFFER,
                         attrib.data.getSize(),
                         attrib.data.getData(),
                         GL_STATIC_DRAW);

            goto vaoStuff;
        }
    }

    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);

    glBufferData(GL_ARRAY_BUFFER,
                 attrib.data.getSize(),
                 attrib.data.getData(),
                 GL_STATIC_DRAW);

    newAttrib.type = attrib.type;
    newAttrib.dataType = attrib.dataType;
    newAttrib.data = attrib.data.copy();

    attribs.append(newAttrib);
    buffers.append(buffer);

    vaoStuff:

    GLenum dataTypeTypes[] = {GL_HALF_FLOAT, GL_HALF_FLOAT, GL_HALF_FLOAT, GL_HALF_FLOAT,
                              GL_FLOAT, GL_FLOAT, GL_FLOAT, GL_FLOAT,
                              GL_UNSIGNED_BYTE, GL_UNSIGNED_BYTE, GL_UNSIGNED_BYTE, GL_UNSIGNED_BYTE,
                              GL_BYTE, GL_BYTE, GL_BYTE, GL_BYTE,
                              GL_UNSIGNED_SHORT, GL_UNSIGNED_SHORT, GL_UNSIGNED_SHORT, GL_UNSIGNED_SHORT,
                              GL_SHORT, GL_SHORT, GL_SHORT, GL_SHORT,
                              GL_UNSIGNED_INT, GL_UNSIGNED_INT, GL_UNSIGNED_INT, GL_UNSIGNED_INT,
                              GL_INT, GL_INT, GL_INT, GL_INT,
                              GL_UNSIGNED_BYTE, GL_UNSIGNED_BYTE, GL_UNSIGNED_BYTE, GL_UNSIGNED_BYTE,
                              GL_BYTE, GL_BYTE, GL_BYTE, GL_BYTE,
                              GL_UNSIGNED_SHORT, GL_UNSIGNED_SHORT, GL_UNSIGNED_SHORT, GL_UNSIGNED_SHORT,
                              GL_SHORT, GL_SHORT, GL_SHORT, GL_SHORT,
                              GL_UNSIGNED_INT, GL_UNSIGNED_INT, GL_UNSIGNED_INT, GL_UNSIGNED_INT,
                              GL_INT, GL_INT, GL_INT, GL_INT};

    bool dataTypeNormalized[] = {false, false, false, false,
                                 false, false, false, false,
                                 false, false, false, false,
                                 false, false, false, false,
                                 false, false, false, false,
                                 false, false, false, false,
                                 false, false, false, false,
                                 false, false, false, false,
                                 true, true, true, true,
                                 true, true, true, true,
                                 true, true, true, true,
                                 true, true, true, true,
                                 true, true, true, true,
                                 true, true, true, true};

    GLint lastVAO;
    glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &lastVAO);
    glBindVertexArray(vao);

    glVertexAttribPointer((int)attrib.type,
                          (int)attrib.dataType % 4 + 1,
                          dataTypeTypes[(int)attrib.dataType],
                          dataTypeNormalized[(int)attrib.dataType],
                          0,
                          (const GLvoid *)0);
    glEnableVertexAttribArray((int)attrib.type);

    glBindVertexArray(lastVAO);
    glBindBuffer(GL_ARRAY_BUFFER, lastBuffer);
}

void GfxMesh::removeAttribute(GfxMeshAttribType type)
{
    GLint lastBuffer;
    glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &lastBuffer);

    GLint lastVAO;
    glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &lastVAO);
    glBindVertexArray(vao);

    for (size_t i = 0; i < attribs.getCount(); ++i)
    {
        if (attribs[i].type == type)
        {
            glBindBuffer(GL_ARRAY_BUFFER, 0);
            glVertexAttribPointer((int)attribs[i].type, 1, GL_BYTE, GL_FALSE, 0, (const GLvoid *)0);
            glDisableVertexAttribArray((int)attribs[i].type);
        }
    }

    glBindVertexArray(lastVAO);

    glBindBuffer(GL_ARRAY_BUFFER, lastBuffer);
}

void GfxMesh::removeContent()
{
    removeIndices();

    numVertices = 0;
    primitive = GfxTriangles;
    cullMode = GfxCullNone;
    winding = GfxCCW;

    glDeleteVertexArrays(1, &vao);
    glGenVertexArrays(1, &vao);

    glDeleteBuffers(buffers.getCount(), buffers.getData());
    buffers.clear();
}

void GfxMesh::save()
{
    try
    {
        File file(getFilename().getData(), "wb");

        file.write(6, "mesh\x00\x00");

        file.writeUInt32LE(indexed ? numIndices : numVertices);
        file.writeUInt8(indexed ? 1 : 0);
        file.writeUInt8((int)primitive);
        file.writeUInt8((int)cullMode);
        file.writeUInt8((int)winding);

        file.writeFloat32(aabb.min.x);
        file.writeFloat32(aabb.min.y);
        file.writeFloat32(aabb.min.z);
        file.writeFloat32(aabb.max.x);
        file.writeFloat32(aabb.max.y);
        file.writeFloat32(aabb.max.z);

        file.writeUInt32LE(attribs.getCount());

        for (size_t i = 0; i < attribs.getCount(); ++i)
        {
            file.writeUInt8((int)attribs[i].type);
            file.writeUInt8((int)attribs[i].dataType);
            file.writeUInt32LE(attribs[i].data.getSize());
            file.write(attribs[i].data);
        }

        file.writeUInt8((int)indexType);
        file.write(numIndices * ((int)indexType+1), indices);
    } catch (FileException& e)
    {
        THROW(ResourceIOException,
              "mesh",
              getFilename(),
              e.getString());
    }
}

void GfxMesh::_load()
{
    removeContent();

    File file(getFilename().getData(), "rb");

    char magic[4];

    file.read(4, magic);

    if (magic[0] != 'm' or
        magic[1] != 'e' or
        magic[2] != 's' or
        magic[3] != 'h')
    {
        THROW(ResourceIOException, "mesh", getFilename(), "Invalid magic.");
    }

    uint8_t majorVer = file.readUInt8();
    uint8_t minorVer = file.readUInt8();

    if (majorVer != 0 or minorVer != 0)
    {
        THROW(ResourceIOException, "mesh", getFilename(), "Unsupported version.");
    }

    size_t count = file.readUInt32LE();
    indexed = file.readUInt8() != 0;

    numVertices = indexed ? 0 : count;

    primitive = (GfxPrimitive)file.readUInt8();
    cullMode = (GfxCullMode)file.readUInt8();
    winding = (GfxWinding)file.readUInt8();

    aabb.min.x = file.readFloat32();
    aabb.min.y = file.readFloat32();
    aabb.min.z = file.readFloat32();
    aabb.max.x = file.readFloat32();
    aabb.max.y = file.readFloat32();
    aabb.max.z = file.readFloat32();

    size_t attribCount = file.readUInt32LE();

    for (size_t i = 0; i < attribCount; ++i)
    {
        GfxMeshAttrib attrib;
        attrib.type = (GfxMeshAttribType)file.readUInt8();
        attrib.dataType = (GfxMeshAttribDataType)file.readUInt8();

        attrib.data = file.read(file.readUInt32LE());

        setAttribute(attrib);
    }

    if (indexed)
    {
        GfxMeshIndexDataType indexType_ = (GfxMeshIndexDataType)file.readUInt8();

        ResizableData data = file.read(count * ((int)indexType_+1));

        addIndices(count, indexType_, data.getData());
    }
}

Resource *GfxMesh::_copy() const
{
    GfxMesh *mesh = NEW(GfxMesh);

    mesh->numVertices = numVertices;
    mesh->primitive = primitive;
    mesh->cullMode = cullMode;
    mesh->winding = winding;
    mesh->aabb = aabb;

    if (indexed)
    {
        mesh->addIndices(numIndices, indexType, indices);
    }

    for (size_t i = 0; i < attribs.getCount(); ++i)
    {
        mesh->setAttribute(attribs[i]);
    }

    return (Resource *)mesh;
}
