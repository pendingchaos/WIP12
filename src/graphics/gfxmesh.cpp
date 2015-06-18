#include "graphics/gfxmesh.h"

#include "graphics/gfxapi.h"
#include "file.h"
#include "globals.h"
#include "containers/list.h"
#include "containers/pair.h"

GfxMesh::GfxMesh(const String& filename) : Resource(filename,
                                                    GfxMeshType),
                                           primitive(GfxTriangles),
                                           numVertices(0),
                                           cullMode(GfxCullNone),
                                           winding(GfxCCW),
                                           indexed(false),
                                           impl(gfxApi->createMeshImpl()) {}

GfxMesh::GfxMesh() : Resource(GfxMeshType),
                     primitive(GfxTriangles),
                     numVertices(0),
                     cullMode(GfxCullNone),
                     winding(GfxCCW),
                     indexed(false),
                     impl(gfxApi->createMeshImpl()) {}

GfxMesh::~GfxMesh()
{
    DELETE(GfxMeshImpl, impl);

    for (size_t i = 0; i < buffers.getCount(); ++i)
    {
        DELETE(GfxBuffer, buffers[i]);
    }
}

void GfxMesh::init(GfxPrimitive primitive_,
                   size_t numVertices_,
                   GfxCullMode cullMode_,
                   GfxWinding winding_)
{
    primitive = primitive_;
    numVertices = numVertices_;
    cullMode = cullMode_;
    winding = winding_;
    indexed = false;

    for (GLuint i = 0; i < GFX_VERTEX_ATTRIB_PURPOSE_COUNT; ++i)
    {
        impl->disableVertexAttrib((GfxVertexAttribPurpose)i);
    }
}

void GfxMesh::removeContent()
{
    numVertices = 0;
    cullMode = GfxCullNone;
    winding = GfxCCW;
    indexed = false;

    for (GLuint i = 0; i < GFX_VERTEX_ATTRIB_PURPOSE_COUNT; ++i)
    {
        impl->disableVertexAttrib((GfxVertexAttribPurpose)i);
    }

    for (size_t i = 0; i < buffers.getCount(); ++i)
    {
        DELETE(GfxBuffer, buffers[i]);
    }

    buffers.clear();
}

void GfxMesh::save()
{
    try
    {
        File file(filename.getData(), "wb");

        file.write(6, "mesh\x01\x00");

        file.writeUInt32LE(indexed ? indexData.numIndices : numVertices);
        file.writeUInt8(primitive);
        file.writeUInt8(winding);
        file.writeUInt8(cullMode);
        file.writeUInt8(indexed ? 1 : 0);

        file.writeFloat32(aabb.min.x);
        file.writeFloat32(aabb.min.y);
        file.writeFloat32(aabb.min.z);
        file.writeFloat32(aabb.max.x);
        file.writeFloat32(aabb.max.y);
        file.writeFloat32(aabb.max.z);

        if (indexed)
        {
            file.writeUInt8(indexData.type);
            file.writeUInt32LE(indexData.offset);
        }

        List<Pair<GfxVertexAttribPurpose, VertexAttribute>> attributes;

        for (size_t i = 0; i < GFX_VERTEX_ATTRIB_PURPOSE_COUNT; ++i)
        {
            GfxVertexAttribPurpose purpose = (GfxVertexAttribPurpose)i;

            if (isVertexAttribEnabled(purpose))
            {
                attributes.append(Pair<GfxVertexAttribPurpose, VertexAttribute>(purpose, getVertexAttrib(purpose)));
            }
        }

        file.writeUInt8(attributes.getCount());

        List<Pair<size_t, GfxBuffer *>> uniqueBuffers;
        size_t size = 0;

        for (size_t i = 0; i < attributes.getCount(); ++i)
        {
            GfxBuffer *buffer = attributes[i].value2.buffer;

            bool unique = true;

            for (size_t j = 0; j < uniqueBuffers.getCount(); ++j)
            {
                if (uniqueBuffers[j].value2 == buffer)
                {
                    unique = false;
                    break;
                }
            }

            if (unique)
            {
                uniqueBuffers.append(Pair<size_t, GfxBuffer *>(size, buffer));

                size += buffer->getSize();
            }
        }

        for (size_t i = 0; i < attributes.getCount(); ++i)
        {
            const VertexAttribute& attribute = attributes[i].value2;

            size_t bufferOffset = 0;

            for (size_t j = 0; j < uniqueBuffers.getCount(); ++j)
            {
                if (uniqueBuffers[j].value2 == attribute.buffer)
                {
                    bufferOffset = uniqueBuffers[j].value1;
                    break;
                }
            }

            file.writeUInt32LE(attribute.stride);
            file.writeUInt32LE(attribute.offset + bufferOffset);
            file.writeUInt8((uint8_t)attributes[i].value1);
            file.writeUInt8(attribute.numComponents);
            file.writeUInt8((uint8_t)attribute.type);
        }

        file.writeUInt32LE(size);

        for (size_t i = 0; i < uniqueBuffers.getCount(); ++i)
        {
            GfxBuffer *buffer = uniqueBuffers[i].value2;
            size_t bufSize = buffer->getSize();

            void *data = ALLOCATE(bufSize);

            buffer->getData(0, bufSize, data);

            file.write(buffer->getSize(), data);

            DEALLOCATE(data);
        }
    } catch (FileException& e)
    {
        THROW(ResourceIOException,
              "mesh",
              filename,
              e.getString());
    }
}

void GfxMesh::setVertexAttrib(GfxVertexAttribPurpose purpose, const VertexAttribute& attribute)
{
    impl->setVertexAttrib(purpose, attribute);
}

void GfxMesh::disableVertexAttrib(GfxVertexAttribPurpose purpose)
{
    impl->disableVertexAttrib(purpose);
}

bool GfxMesh::isVertexAttribEnabled(GfxVertexAttribPurpose purpose) const
{
    return impl->isVertexAttribEnabled(purpose);
}

GfxMesh::VertexAttribute GfxMesh::getVertexAttrib(GfxVertexAttribPurpose purpose) const
{
    return impl->getVertexAttrib(purpose);
}

void GfxMesh::_load()
{
    removeContent();

    File file(filename.getData(), "rb");

    char magic[4];

    file.read(4, magic);

    if (magic[0] != 'm' or
        magic[1] != 'e' or
        magic[2] != 's' or
        magic[3] != 'h')
    {
            THROW(ResourceIOException, "mesh", filename, "Invalid magic.");
    }

    uint8_t majorVer = file.readUInt8();
    uint8_t minorVer = file.readUInt8();

    if (majorVer != 1 or minorVer != 0)
    {
            THROW(ResourceIOException, "mesh", filename, "Unsupported version.");
    }

    uint32_t count = file.readUInt32LE();
    primitive = (GfxPrimitive)file.readUInt8();
    winding = (GfxWinding)file.readUInt8();
    cullMode = (GfxCullMode)file.readUInt8();
    indexed = file.readUInt8() != 0;

    aabb.min.x = file.readFloat32();
    aabb.min.y = file.readFloat32();
    aabb.min.z = file.readFloat32();
    aabb.max.x = file.readFloat32();
    aabb.max.y = file.readFloat32();
    aabb.max.z = file.readFloat32();

    numVertices = indexed ? 0 : count;

    GfxVertexAttribType indexType = GfxUnsignedInteger;
    uint32_t indicesOffset = 0;

    if (indexed)
    {
        indexType = (GfxVertexAttribType)file.readUInt8();
        indicesOffset = file.readUInt32LE();
    }

    uint8_t numVertexAttribs = file.readUInt8();

    GfxBuffer *buffer = gfxApi->createBuffer();

    buffers.append(buffer);

    if (indexed)
    {
        indexData.type = indexType;
        indexData.numIndices = count;
        indexData.offset = indicesOffset;
        indexData.buffer = buffer;
    }

    for (size_t i = 0; i < numVertexAttribs; ++i)
    {
        uint32_t stride = file.readUInt32LE();
        uint32_t offset = file.readUInt32LE();
        GfxVertexAttribPurpose purpose = (GfxVertexAttribPurpose)file.readUInt8();
        uint8_t numComponents = file.readUInt8();
        GfxVertexAttribType type = (GfxVertexAttribType)file.readUInt8();

        GfxMesh::VertexAttribute attribute;

        attribute.buffer = buffer;
        attribute.numComponents = numComponents;
        attribute.offset = offset;
        attribute.stride = stride;
        attribute.type = type;

        setVertexAttrib(purpose, attribute);
    }

    size_t size = file.readUInt32LE();

    void *data = ALLOCATE(size);

    file.read(size, data);

    buffer->allocData(size, data, GfxBuffer::Static);

    DEALLOCATE(data);
}
