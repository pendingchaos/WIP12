#include "graphics/gfxmesh.h"

#include "graphics/gfxapi.h"
#include "file.h"
#include "globals.h"
#include "containers/list.h"

static const size_t indexTypeSizes[] = {1, 2, 4};

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

    size_t indicesSize = numIndices * indexTypeSizes[(int)indexType];

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

    for (auto attrib : attribs)
    {
        if (attrib.type == type)
        {
            glBindBuffer(GL_ARRAY_BUFFER, 0);
            glVertexAttribPointer((int)attrib.type, 1, GL_BYTE, GL_FALSE, 0, (const GLvoid *)0);
            glDisableVertexAttribArray((int)attrib.type);
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

    bones.clear();
    animations.clear();
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

        for (auto attrib : attribs)
        {
            file.writeUInt8((int)attrib.type);
            file.writeUInt8((int)attrib.dataType);
            file.writeUInt32LE(attrib.data.getSize());
            file.write(attrib.data);
        }

        file.writeUInt8((int)indexType);
        file.write(numIndices * indexTypeSizes[(int)indexType], indices);

        file.writeUInt32LE(bones.getCount());

        for (auto bone : bones)
        {
            file.writeInt16LE(bone.parent);
            file.writeUInt32LE(bone.children.getCount());

            const Matrix4x4& boneMatrix = bone.boneMatrix;

            file.writeFloat32(boneMatrix[0][0]);
            file.writeFloat32(boneMatrix[0][1]);
            file.writeFloat32(boneMatrix[0][2]);
            file.writeFloat32(boneMatrix[0][3]);
            file.writeFloat32(boneMatrix[1][0]);
            file.writeFloat32(boneMatrix[1][1]);
            file.writeFloat32(boneMatrix[1][2]);
            file.writeFloat32(boneMatrix[1][3]);
            file.writeFloat32(boneMatrix[2][0]);
            file.writeFloat32(boneMatrix[2][1]);
            file.writeFloat32(boneMatrix[2][2]);
            file.writeFloat32(boneMatrix[2][3]);
            file.writeFloat32(boneMatrix[3][0]);
            file.writeFloat32(boneMatrix[3][1]);
            file.writeFloat32(boneMatrix[3][2]);
            file.writeFloat32(boneMatrix[3][3]);

            file.write(bone.children.getCount(), bone.children.getData());
        }

        file.writeUInt32LE(animations.getCount());

        for (auto kv : animations)
        {
            const String& name = kv.first;

            file.writeUInt32LE(name.getLength());
            file.write(name.getLength(), name.getData());

            const GfxAnimation& anim = kv.second;

            file.writeUInt32LE(anim.fps);
            file.writeUInt32LE(anim.frames.getCount());

            for (auto frame : anim.frames)
            {
                for (auto transform : frame.boneTransforms)
                {
                    file.writeFloat32(transform.orientation.x);
                    file.writeFloat32(transform.orientation.y);
                    file.writeFloat32(transform.orientation.z);
                    file.writeFloat32(transform.orientation.w);
                    file.writeFloat32(transform.scale.x);
                    file.writeFloat32(transform.scale.y);
                    file.writeFloat32(transform.scale.z);
                    file.writeFloat32(transform.position.x);
                    file.writeFloat32(transform.position.y);
                    file.writeFloat32(transform.position.z);
                }
            }
        }
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
    try
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

            ResizableData data = file.read(count * indexTypeSizes[(int)indexType_]);

            addIndices(count, indexType_, data.getData());
        } else
        {
            file.readUInt8();
        }

        uint32_t numBones = file.readUInt32LE();

        for (size_t i = 0; i < numBones; ++i)
        {
            GfxBone bone;

            bone.boneMatrix[0][0] = file.readFloat32();
            bone.boneMatrix[0][1] = file.readFloat32();
            bone.boneMatrix[0][2] = file.readFloat32();
            bone.boneMatrix[0][3] = file.readFloat32();
            bone.boneMatrix[1][0] = file.readFloat32();
            bone.boneMatrix[1][1] = file.readFloat32();
            bone.boneMatrix[1][2] = file.readFloat32();
            bone.boneMatrix[1][3] = file.readFloat32();
            bone.boneMatrix[2][0] = file.readFloat32();
            bone.boneMatrix[2][1] = file.readFloat32();
            bone.boneMatrix[2][2] = file.readFloat32();
            bone.boneMatrix[2][3] = file.readFloat32();
            bone.boneMatrix[3][0] = file.readFloat32();
            bone.boneMatrix[3][1] = file.readFloat32();
            bone.boneMatrix[3][2] = file.readFloat32();
            bone.boneMatrix[3][3] = file.readFloat32();

            uint32_t numChildren = file.readUInt32LE();
            bone.children = List<uint8_t>(numChildren);

            file.read(numChildren, bone.children.getData());

            bone.parent = -1;

            bones.append(bone);
        }

        for (size_t i = 0; i < numBones; ++i)
        {
            const List<uint8_t>& children = bones[i].children;

            for (size_t j = 0; j < children.getCount(); ++j)
            {
                bones[children[j]].parent = i;
            }
        }

        uint32_t numAnimations = file.readUInt32LE();

        for (size_t i = 0; i < numAnimations; ++i)
        {
            String name((size_t)file.readUInt32LE());
            file.read(name.getLength(), name.getData());

            GfxAnimation animation;
            animation.fps = file.readUInt32LE();
            animation.frames = List<GfxAnimationFrame>(file.readUInt32LE());

            for (size_t j = 0; j < animation.frames.getCount(); ++j)
            {
                GfxAnimationFrame frame;

                for (size_t k = 0; k < bones.getCount(); ++k)
                {
                    Transform transform;

                    transform.orientation.x = file.readFloat32();
                    transform.orientation.y = file.readFloat32();
                    transform.orientation.z = file.readFloat32();
                    transform.orientation.w = file.readFloat32();
                    transform.scale.x = file.readFloat32();
                    transform.scale.y = file.readFloat32();
                    transform.scale.z = file.readFloat32();
                    transform.position.x = file.readFloat32();
                    transform.position.y = file.readFloat32();
                    transform.position.z = file.readFloat32();

                    frame.boneTransforms.append(transform);
                }

                animation.frames[j] = frame;
            }

            animations.set(name, animation);
        }
    } catch (const FileException& e)
    {
        THROW(ResourceIOException,
              "mesh",
              getFilename(),
              e.getString());
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

    for (auto attrib : attribs)
    {
        mesh->setAttribute(attrib);
    }

    return (Resource *)mesh;
}

GfxAnimationState::GfxAnimationState(GfxMesh *mesh_,
                                     const String& animName_) : animName(animName_.copy()),
                                                                timeOffset(0.0f),
                                                                mesh(mesh_->copyRef<GfxMesh>())
{
    matrixBuffer = gfxApi->createBuffer();
    normalMatrixBuffer = gfxApi->createBuffer();

    matrixBuffer->allocData(16384, GfxBufferUsage::Dynamic);
    normalMatrixBuffer->allocData(16384, GfxBufferUsage::Dynamic);
}

GfxAnimationState::~GfxAnimationState()
{
    DELETE(matrixBuffer);
    DELETE(normalMatrixBuffer);

    mesh->release();
}

void getMatrix(size_t index, const GfxMesh *mesh, const GfxAnimationFrame& frame, List<Matrix4x4>& matrices, const Matrix4x4& parentMatrix)
{
    const GfxBone& bone = mesh->bones[index];

    Matrix4x4 matrix = parentMatrix * frame.boneTransforms[index].createMatrix();
    matrices[index] = matrix * mesh->bones[index].boneMatrix;

    for (auto child : bone.children)
    {
        getMatrix(child, mesh, frame, matrices, matrix);
    }
}

void GfxAnimationState::updateMatrices()
{
    //TODO: Error handling when this fails.
    const GfxAnimation& anim = mesh->animations.get(animName);

    List<Matrix4x4> matrices(mesh->bones.getCount());
    List<Matrix4x4> normalMatrices(mesh->bones.getCount());

    if (anim.frames.getCount() == 0)
    {
        for (size_t i = 0; i < matrices.getCount(); ++i)
        {
            matrices[i] = matrices[i].transpose();
            normalMatrices[i] = Matrix4x4().transpose();
        }
    } else
    {
        size_t frameIndex = size_t(std::floor(timeOffset * anim.fps)) % anim.frames.getCount();
        size_t nextFrameIndex = (frameIndex+1) % anim.frames.getCount();
        float mix = timeOffset*anim.fps - std::floor(timeOffset*anim.fps);

        const GfxAnimationFrame& frame = anim.frames[frameIndex];
        const GfxAnimationFrame& nextFrame = anim.frames[nextFrameIndex];

        List<Matrix4x4> nextMatrices(mesh->bones.getCount());
        List<Matrix4x4> nextNormalMatrices(mesh->bones.getCount());

        for (size_t i = 0; i < frame.boneTransforms.getCount(); ++i)
        {
            if (mesh->bones[i].parent != -1)
            {
                continue;
            }

            getMatrix(i, mesh, frame, matrices, Matrix4x4());
        }

        for (size_t i = 0; i < nextFrame.boneTransforms.getCount(); ++i)
        {
            if (mesh->bones[i].parent != -1)
            {
                continue;
            }

            getMatrix(i, mesh, nextFrame, nextMatrices, Matrix4x4());
        }

        for (size_t i = 0; i < matrices.getCount(); ++i)
        {
            Matrix4x4 worldMatrix = matrices[i];
            Matrix4x4 nextWorldMatrix = nextMatrices[i];

            #define MIX(idx) worldMatrix idx = worldMatrix idx*(1.0f-mix) + nextWorldMatrix idx*mix;
            MIX([0][0])
            MIX([1][0])
            MIX([2][0])
            MIX([3][0])
            MIX([0][1])
            MIX([1][1])
            MIX([2][1])
            MIX([3][1])
            MIX([0][2])
            MIX([1][2])
            MIX([2][2])
            MIX([3][2])
            MIX([0][3])
            MIX([1][3])
            MIX([2][3])
            MIX([3][3])
            #undef MIX

            //The normal matrix does not need to be transposed because if it were it would have to be transposed again to work with the OpenGL implementation.
            normalMatrices[i] = worldMatrix.inverse();
            matrices[i] = worldMatrix.transpose();
        }
    }

    matrixBuffer->setData(0, matrices.getCount()*64, matrices.getData());
    normalMatrixBuffer->setData(0, normalMatrices.getCount()*64, normalMatrices.getData());
}
