#include "extensions/mc_clone/mc_clone.h"

#include "logging.h"
#include "memory.h"
#include "graphics/gfxmesh.h"
#include "graphics/gfxmodel.h"
#include "graphics/gfxrenderer.h"
#include "math/matrix4x4.h"
#include "physics/rigidbody.h"
#include "physics/physicsshape.h"
#include "physics/physicsworld.h"
#include "containers/resizabledata.h"

#include <algorithm>
#include <cfloat>
#include <SDL2/SDL_timer.h>

MCChunk::MCChunk(MCWorld *world_) : world(world_), body(nullptr)
{
    UInt3 chunkSize = world->getChunkSize();

    cubes = (uint8_t *)ALLOCATE(chunkSize.x*chunkSize.y*chunkSize.z);

    for (size_t i = 0; i < world->getNumTypes(); ++i)
    {
        meshes[i] = NEW(GfxMesh);
    }

    for (size_t i = world->getNumTypes(); i < 255; ++i)
    {
        meshes[i] = nullptr;
    }

    for (size_t z = 0; z < chunkSize.z; ++z)
    {
        for (size_t y = 0; y < chunkSize.y; ++y)
        {
            for (size_t x = 0; x < chunkSize.x; ++x)
            {
                setCube((int)x, (int)y, (int)z, 0);
            }
        }
    }

    compoundShape = NEW(PhysicsShape);
}

MCChunk::~MCChunk()
{
    compoundShape->release();

    if (body != nullptr)
    {
        body->getWorld()->destroyRigidBody(body);
    }

    for (size_t i = 0; i < world->getNumTypes(); ++i)
    {
        meshes[i]->release();
    }

    DEALLOCATE(cubes);
}

void MCChunk::updateMeshes()
{
    UInt3 chunkSize = world->getChunkSize();
    size_t numTypes = world->getNumTypes();
    float blockSize = world->getBlockSize();

    ResizableData positions[numTypes];
    ResizableData normals[numTypes];
    ResizableData uvs[numTypes];

    const Float2 t00(0.0f, 0.0f);
    const Float2 t10(1.0f, 0.0f);
    const Float2 t11(1.0f, 1.0f);
    const Float2 t01(0.0f, 1.0f);

    AABB aabb[numTypes];

    for (size_t i = 0; i < numTypes; ++i)
    {
        aabb[i].min = Float3(FLT_MAX);
        aabb[i].max = Float3(FLT_MIN);
    }

    #define VERT(pos, uv, norm)\
    do {\
        Float3 pos_ = (pos);\
        posData.setFloat32(posOffset, pos_.x); posOffset += 4;\
        posData.setFloat32(posOffset, pos_.y); posOffset += 4;\
        posData.setFloat32(posOffset, pos_.z); posOffset += 4;\
        uvData.setUInt8(uvOffset, uv.x*255); ++uvOffset;\
        uvData.setUInt8(uvOffset, uv.y*255); ++uvOffset;\
        normData.setInt8(normOffset, norm.x*127); ++normOffset;\
        normData.setInt8(normOffset, norm.y*127); ++normOffset;\
        normData.setInt8(normOffset, norm.z*127); ++normOffset;\
    } while (0)

    #define QUAD(pos0, uv0, pos1, uv1, pos2, uv2, pos3, uv3, norm)\
    do {\
        VERT(pos1+pos, uv1, norm);\
        VERT(pos2+pos, uv2, norm);\
        VERT(pos3+pos, uv3, norm);\
        \
        VERT(pos3+pos, uv3, norm);\
        VERT(pos0+pos, uv0, norm);\
        VERT(pos1+pos, uv1, norm);\
    } while (0)
    for (int z = 0; z < (int)chunkSize.z; ++z)
    {
        for (int y = 0; y < (int)chunkSize.y; ++y)
        {
            for (int x = 0; x < (int)chunkSize.x; ++x)
            {
                uint8_t type = _getCube(x, y, z);

                if (type == 0)
                {
                    continue;
                }

                bool posx = getCube(x+1, y, z) == 0;
                bool posy = getCube(x, y+1, z) == 0;
                bool posz = getCube(x, y, z+1) == 0;
                bool negx = getCube(x-1, y, z) == 0;
                bool negy = getCube(x, y-1, z) == 0;
                bool negz = getCube(x, y, z-1) == 0;

                if (not (posx or posy or posz or negx or negy or negz))
                {
                    continue;
                }

                Float3 pos = Float3(x, y, z) * blockSize * 2.0f;

                aabb[type-1].extend(pos-blockSize);
                aabb[type-1].extend(pos+blockSize);

                size_t numQuads = (posx ? 1 : 0) +
                                  (posy ? 1 : 0) +
                                  (posz ? 1 : 0) +
                                  (negx ? 1 : 0) +
                                  (negy ? 1 : 0) +
                                  (negz ? 1 : 0);

                ResizableData& posData = positions[type-1];
                ResizableData& uvData = uvs[type-1];
                ResizableData& normData = normals[type-1];

                size_t posOffset = posData.getSize();
                posData.resize(posOffset+numQuads*72);

                size_t uvOffset = uvData.getSize();
                uvData.resize(uvOffset+numQuads*12);

                size_t normOffset = normData.getSize();
                normData.resize(normOffset+numQuads*18);

                if (posz)
                {
                    QUAD(Float3(-blockSize, -blockSize, blockSize), t00,
                         Float3(blockSize, -blockSize, blockSize), t10,
                         Float3(blockSize, blockSize, blockSize), t11,
                         Float3(-blockSize, blockSize, blockSize), t01,
                         Float3(0.0, 0.0, 1.0));
                }

                if (negz)
                {
                    QUAD(Float3(-blockSize, -blockSize, -blockSize), t10,
                         Float3(-blockSize, blockSize, -blockSize), t11,
                         Float3(blockSize, blockSize, -blockSize), t01,
                         Float3(blockSize, -blockSize, -blockSize), t00,
                         Float3(0.0, 0.0, -1.0));
                }

                if (posy)
                {
                    QUAD(Float3(-blockSize, blockSize, -blockSize), t01,
                         Float3(-blockSize, blockSize, blockSize), t00,
                         Float3(blockSize, blockSize, blockSize), t10,
                         Float3(blockSize, blockSize, -blockSize), t11,
                         Float3(0.0, 1.0, 0.0));
                }

                if (negy)
                {
                    QUAD(Float3(-blockSize, -blockSize, -blockSize), t11,
                         Float3(blockSize, -blockSize, -blockSize), t01,
                         Float3(blockSize, -blockSize, blockSize), t00,
                         Float3(-blockSize, -blockSize, blockSize), t10,
                         Float3(0.0, -1.0, 0.0));
                }

                if (posx)
                {
                    QUAD(Float3(blockSize, -blockSize, -blockSize), t10,
                         Float3(blockSize, blockSize, -blockSize), t11,
                         Float3(blockSize, blockSize, blockSize), t01,
                         Float3(blockSize, -blockSize, blockSize), t00,
                         Float3(1.0, 0.0, 0.0));
                }

                if (negx)
                {
                    QUAD(Float3(-blockSize, -blockSize, -blockSize), t00,
                         Float3(-blockSize, -blockSize, blockSize), t10,
                         Float3(-blockSize, blockSize, blockSize), t11,
                         Float3(-blockSize, blockSize, -blockSize), t01,
                         Float3(-1.0, 0.0, 0.0));
                }
            }
        }
    }
    #undef QUAD
    #undef VERT

    for (size_t i = 0; i < numTypes; ++i)
    {
        if (aabb[i].min > aabb[i].max)
        {
            meshes[i]->aabb = AABB();
        } else
        {
            meshes[i]->aabb = aabb[i];
        }

        meshes[i]->numVertices = positions[i].getSize()/12;
        meshes[i]->numIndices = 0;
        meshes[i]->primitive = GfxPrimitive::GfxTriangles;

        GfxMeshAttrib pos;
        pos.type = GfxMeshAttribType::Position;
        pos.dataType = GfxMeshAttribDataType::F32_3;
        pos.data = positions[i];
        meshes[i]->setAttribute(pos);

        GfxMeshAttrib uv;
        uv.type = GfxMeshAttribType::TexCoord;
        uv.dataType = GfxMeshAttribDataType::U8_2Norm;
        uv.data = uvs[i];
        meshes[i]->setAttribute(uv);

        GfxMeshAttrib norm;
        norm.type = GfxMeshAttribType::Normal;
        norm.dataType = GfxMeshAttribDataType::S8_3Norm;
        norm.data = normals[i];
        meshes[i]->setAttribute(norm);
    }
}

void MCChunk::updateRigidBodies(const Matrix4x4& transform)
{
    if (body != nullptr)
    {
        body->getWorld()->destroyRigidBody(body);
    }

    List<PhysicsCompoundShape::Child> children;

    UInt3 chunkSize = world->getChunkSize();
    float blockSize = world->getBlockSize();
    PhysicsShape *cubeShape = world->getCubeShape();

    for (int z = 0; z < (int)chunkSize.z; ++z)
    {
        for (int y = 0; y < (int)chunkSize.y; ++y)
        {
            for (int x = 0; x < (int)chunkSize.x; ++x)
            {
                uint8_t type = _getCube(x, y, z);

                if (type == 0)
                {
                    continue;
                }

                bool posx = getCube(x+1, y, z) == 0;
                bool posy = getCube(x, y+1, z) == 0;
                bool posz = getCube(x, y, z+1) == 0;
                bool negx = getCube(x-1, y, z) == 0;
                bool negy = getCube(x, y-1, z) == 0;
                bool negz = getCube(x, y, z-1) == 0;

                if (not (posx or posy or posz or negx or negy or negz))
                {
                    continue;
                }

                Float3 pos = Float3(x, y, z) * blockSize * 2.0f;

                PhysicsCompoundShape::Child child(cubeShape);
                child.position = pos;

                children.append(child);
            }
        }
    }

    compoundShape->setCompound(children.getCount(), children.getData());

    RigidBodyConstructionInfo info;
    info.type = RigidBodyType::Static;

    body = world->getPhysicsWorld()->createRigidBody(info, compoundShape);
    body->setTransform(transform);
}

uint8_t MCChunk::getCube(int x, int y, int z)
{
    UInt3 chunkSize = world->getChunkSize();

    if (x < 0 or x >= (int)chunkSize.x)
    {
        return 0;
    }

    if (y < 0 or y >= (int)chunkSize.y)
    {
        return 0;
    }

    if (z < 0 or z >= (int)chunkSize.z)
    {
        return 0;
    }

    return cubes[z*chunkSize.x*chunkSize.y + y*chunkSize.x + x];
}

void MCChunk::setCube(int x, int y, int z, uint8_t type)
{
    UInt3 chunkSize = world->getChunkSize();

    if (x < 0 or x >= (int)chunkSize.x)
    {
        return;
    }

    if (y < 0 or y >= (int)chunkSize.y)
    {
        return;
    }

    if (z < 0 or z >= (int)chunkSize.z)
    {
        return;
    }

    if (type > world->getNumTypes())
    {
        return;
    }

    cubes[z*chunkSize.x*chunkSize.y + y*chunkSize.x + x] = type;
}

void MCChunk::render(GfxRenderer *renderer, const Matrix4x4& worldMatrix)
{
    for (size_t i = 0; i < world->getNumTypes(); ++i)
    {
        if (world->getMaterial(i) == nullptr)
        {
            continue;
        }

        GfxObject obj(world->getMaterial(i), meshes[i]);
        obj.worldMatrix = worldMatrix;
        obj.normalMatrix = worldMatrix.inverse().transpose();

        renderer->addObject(obj);
    }
}

uint8_t MCChunk::_getCube(int x, int y, int z)
{
    UInt3 chunkSize = world->getChunkSize();
    return cubes[z*chunkSize.x*chunkSize.y + y*chunkSize.x + x];
}

MCWorld::MCWorld(const UInt3& chunkSize_,
                 uint8_t numTypes_,
                 float blockSize_,
                 PhysicsWorld *physicsWorld_) : chunkSize(chunkSize_),
                                                numTypes(numTypes_),
                                                blockSize(blockSize_),
                                                physicsWorld(physicsWorld_)
{
    for (size_t i = 0; i < 255; ++i)
    {
        materials[i] = nullptr;
    }

    cubeShape = NEW(PhysicsShape);
    cubeShape->setBox(blockSize);
}

MCWorld::~MCWorld()
{
    for (auto& chunk : chunks)
    {
        DELETE(chunk.chunk);
    }

    cubeShape->release();

    for (size_t i = 0; i < numTypes; ++i)
    {
        if (materials[i] != nullptr)
        {
            materials[i]->release();
        }
    }
}

void MCWorld::setMaterial(uint8_t type, GfxMaterial *material)
{
    if (type-1 < (int)numTypes)
    {
        materials[type-1] = material;
    }
}

void MCWorld::render(GfxRenderer *renderer)
{
    for (auto& chunk : chunks)
    {
        Position3D pos(chunk.pos.x, chunk.pos.y, chunk.pos.z);
        pos *= chunkSize;
        pos *= blockSize * 2.0;

        chunk.chunk->render(renderer, Matrix4x4::translate(pos));
    }
}

void MCWorld::update()
{
    for (auto& chunk : chunks)
    {
        if (chunk.dirty)
        {
            Position3D pos(chunk.pos.x, chunk.pos.y, chunk.pos.z);
            pos *= chunkSize;
            pos *= blockSize*2.0;

            chunk.chunk->updateMeshes();
            chunk.chunk->updateRigidBodies(Matrix4x4::translate(pos));

            chunk.dirty = false;
        }
    }
}

int pymod(int a, int b) //Thanks glamhoth
{
    return ((a % b) + b) % b;
}

int div2(int a, int b)
{
    return std::floor(float(a) / float(b));
}

void MCWorld::setCube(int x, int y, int z, uint8_t type)
{
    Int3 chunkPos = Int3(div2(x, chunkSize.x),
                         div2(y, chunkSize.y),
                         div2(z, chunkSize.z));
    Int3 relPos = Int3(pymod(x, chunkSize.x),
                       pymod(y, chunkSize.y),
                       pymod(z, chunkSize.z));

    for (auto& chunk : chunks)
    {
        if (chunkPos == chunk.pos)
        {
            chunk.chunk->setCube(relPos.x, relPos.y, relPos.z, type);
            chunk.dirty = true;
            return;
        }
    }

    Chunk chunk;
    chunk.pos.x = chunkPos.x;
    chunk.pos.y = chunkPos.y;
    chunk.pos.z = chunkPos.z;

    chunk.chunk = NEW(MCChunk, this);
    chunk.chunk->setCube(relPos.x, relPos.y, relPos.z, type);
    chunk.dirty = true;

    chunks.append(chunk);
}

uint8_t MCWorld::getCube(int x, int y, int z)
{
    Int3 chunkPos = Int3(div2(x, chunkSize.x),
                         div2(y, chunkSize.y),
                         div2(z, chunkSize.z));
    Int3 relPos = Int3(pymod(x, chunkSize.x),
                       pymod(y, chunkSize.y),
                       pymod(z, chunkSize.z));

    for (auto& chunk : chunks)
    {
        if (chunk.pos == chunkPos)
        {
            return chunk.chunk->getCube(relPos.x, relPos.y, relPos.z);
        }
    }

    return 0;
}

void *init_mc_clone()
{
    logInfo("Initialized MCClone extension\n");
    return nullptr;
}

void deinit_mc_clone(void *ext)
{
    logInfo("Deinitialized MCClone extension\n");
}
