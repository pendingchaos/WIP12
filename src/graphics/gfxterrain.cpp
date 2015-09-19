#include "graphics/gfxterrain.h"

#include "graphics/gfxmesh.h"

GfxTerrain::GfxTerrain(float chunkSize_,
                       size_t sizeInChunks_,
                       GfxTexture *heightmap_,
                       GfxTexture *texture_) : textureScale(1.0f),
                                               chunkSize(chunkSize_),
                                               sizeInChunks(sizeInChunks_),
                                               heightmap(heightmap_),
                                               scale(1.0f),
                                               texture(texture_)
{
    mesh = NEW(GfxMesh);

    recreate();
}

GfxTerrain::~GfxTerrain()
{
    texture->release();
    mesh->release();
    heightmap->release();
}

void GfxTerrain::recreate()
{
    size_t numChunks = sizeInChunks * sizeInChunks;

    ResizableData data(48 * numChunks);

    float size = sizeInChunks * chunkSize;

    for (size_t x = 0; x < sizeInChunks; ++x)
    {
        for (size_t z = 0; z < sizeInChunks; ++z)
        {
            float *v0 = (float *)((uint8_t *)data.getData() + (x+z*sizeInChunks) * 48);
            float *v1 = v0 + 3;
            float *v2 = v1 + 3;
            float *v3 = v2 + 3;

            Position3D chunkPos(float(x*chunkSize) - size/2,
                                0.0f,
                                float(z*chunkSize) - size/2);

            v0[0] = chunkPos.x + 0.0f;
            v0[1] = chunkPos.y + 0.0f;
            v0[2] = chunkPos.z + 0.0f;

            v1[0] = chunkPos.x + chunkSize;
            v1[1] = chunkPos.y + 0.0f;
            v1[2] = chunkPos.z + 0.0f;

            v2[0] = chunkPos.x + chunkSize;
            v2[1] = chunkPos.y + 0.0f;
            v2[2] = chunkPos.z + chunkSize;

            v3[0] = chunkPos.x + 0.0f;
            v3[1] = chunkPos.y + 0.0f;
            v3[2] = chunkPos.z + chunkSize;
        }
    }

    GfxMeshAttrib attrib;
    attrib.type = GfxMeshAttribType::Position;
    attrib.dataType = GfxMeshAttribDataType::F32_3;
    attrib.data = data;
    mesh->setAttribute(attrib);

    mesh->numVertices = 4 * numChunks;

    updateAABB();
}

void GfxTerrain::updateAABB()
{
    mesh->aabb = AABB(Position3D(sizeInChunks/2.0f * -chunkSize,
                                 0.0f,
                                 sizeInChunks/2.0f * -chunkSize),
                      Position3D(sizeInChunks/2.0f * chunkSize,
                                 scale,
                                 sizeInChunks/2.0f * chunkSize));
}
