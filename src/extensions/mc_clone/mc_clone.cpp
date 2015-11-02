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

#include <algorithm>
#include <cfloat>

MCChunk::MCChunk(size_t width_,
                 size_t height_,
                 size_t depth_,
                 uint8_t numTypes_,
                 float blockSize_) : width(width_),
                                     height(height_),
                                     depth(depth_),
                                     numTypes(numTypes_),
                                     blockSize(blockSize_),
                                     body(nullptr)
{
    cubes = (uint8_t *)ALLOCATE(width*height*depth);

    for (size_t i = 0; i < numTypes; ++i)
    {
        meshes[i] = NEW(GfxMesh);
    }

    for (size_t i = numTypes; i < 255; ++i)
    {
        meshes[i] = nullptr;
    }

    for (size_t i = 0; i < 255; ++i)
    {
        materials[i] = nullptr;
    }

    for (size_t z = 0; z < depth; ++z)
    {
        for (size_t y = 0; y < height; ++y)
        {
            for (size_t x = 0; x < width; ++x)
            {
                setCube(x, y, z, 0);
            }
        }
    }

    cubeShape = NEW(PhysicsShape);
    cubeShape->setBox(blockSize);

    compoundShape = NEW(PhysicsShape);
}

MCChunk::~MCChunk()
{
    compoundShape->release();
    cubeShape->release();

    body->getWorld()->destroyRigidBody(body);

    for (size_t i = 0; i < numTypes; ++i)
    {
        meshes[i]->release();
    }

    for (size_t i = 0; i < numTypes; ++i)
    {
        if (materials[i] != nullptr)
        {
            materials[i]->release();
        }
    }

    DEALLOCATE(cubes);
}

void MCChunk::updateMeshes()
{
    List<Position3D> positions[numTypes];
    List<Direction3D> normals[numTypes];
    List<Float2> uvs[numTypes];

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

    #define QUAD(pos0, uv0, pos1, uv1, pos2, uv2, pos3, uv3, norm)\
    do {\
        positions[type-1].append(pos1+pos); uvs[type-1].append(uv1); normals[type-1].append(norm);\
        positions[type-1].append(pos2+pos); uvs[type-1].append(uv2); normals[type-1].append(norm);\
        positions[type-1].append(pos3+pos); uvs[type-1].append(uv3); normals[type-1].append(norm);\
        \
        positions[type-1].append(pos3+pos); uvs[type-1].append(uv3); normals[type-1].append(norm);\
        positions[type-1].append(pos0+pos); uvs[type-1].append(uv0); normals[type-1].append(norm);\
        positions[type-1].append(pos1+pos); uvs[type-1].append(uv1); normals[type-1].append(norm);\
    } while (0)
    for (int z = 0; z < (int)depth; ++z)
    {
        for (int y = 0; y < (int)height; ++y)
        {
            for (int x = 0; x < (int)width; ++x)
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

                Float3 pos = Float3(x, y, z) * blockSize * 2.0f;

                aabb[type-1].extend(pos-blockSize);
                aabb[type-1].extend(pos+blockSize);

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

    for (size_t i = 0; i < numTypes; ++i)
    {
        if (aabb[i].min > aabb[i].max)
        {
            meshes[i]->aabb = AABB();
        } else
        {
            meshes[i]->aabb = aabb[i];
        }

        meshes[i]->numVertices = positions[i].getCount();
        meshes[i]->numIndices = 0;
        meshes[i]->primitive = GfxPrimitive::GfxTriangles;

        GfxMeshAttrib pos;
        pos.type = GfxMeshAttribType::Position;
        pos.dataType = GfxMeshAttribDataType::F32_3;
        pos.data = ResizableData(positions[i].getCount()*12, positions[i].getData());
        meshes[i]->setAttribute(pos);

        GfxMeshAttrib uv;
        uv.type = GfxMeshAttribType::TexCoord;
        uv.dataType = GfxMeshAttribDataType::F32_2;
        uv.data = ResizableData(uvs[i].getCount()*8, uvs[i].getData());
        meshes[i]->setAttribute(uv);

        GfxMeshAttrib norm;
        norm.type = GfxMeshAttribType::Normal;
        norm.dataType = GfxMeshAttribDataType::F32_3;
        norm.data = ResizableData(normals[i].getCount()*12, normals[i].getData());
        meshes[i]->setAttribute(norm);
    }
}

void MCChunk::updateRigidBodies(PhysicsWorld *world)
{
    if (body != nullptr)
    {
        body->getWorld()->destroyRigidBody(body);
    }

    List<PhysicsCompoundShape::Child> children;

    for (int z = 0; z < (int)depth; ++z)
    {
        for (int y = 0; y < (int)height; ++y)
        {
            for (int x = 0; x < (int)width; ++x)
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

    body = world->createRigidBody(info, compoundShape);
}

uint8_t MCChunk::getCube(int x, int y, int z)
{
    if (x < 0 or x > (int)width)
    {
        return 0;
    }

    if (y < 0 or y > (int)height)
    {
        return 0;
    }

    if (z < 0 or z > (int)depth)
    {
        return 0;
    }

    return _getCube(x, y, z);
}

void MCChunk::setCube(size_t x, size_t y, size_t z, uint8_t type)
{
    if (x > width)
    {
        return;
    }

    if (y > height)
    {
        return;
    }

    if (z > depth)
    {
        return;
    }

    if (type > numTypes)
    {
        return;
    }

    cubes[z*width*height + y*width + x] = type;
}

void MCChunk::setMaterial(uint8_t type, GfxMaterial *material)
{
    if (type-1 < (int)numTypes)
    {
        materials[type-1] = material;
    }
}

void MCChunk::render(GfxRenderer *renderer, const Matrix4x4& worldMatrix)
{
    for (size_t i = 0; i < numTypes; ++i)
    {
        if (materials[i] == nullptr)
        {
            continue;
        }

        GfxObject obj(materials[i], meshes[i]);
        obj.worldMatrix = worldMatrix;
        obj.normalMatrix = worldMatrix.inverse().transpose();

        renderer->addObject(obj);
    }
}

uint8_t MCChunk::_getCube(int x, int y, int z)
{
    return cubes[z*width*height + y*width + x];
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
