#include "graphics/gfxterrain.h"

#include "graphics/gfxmesh.h"
#include "graphics/gfxmaterial.h"
#include "graphics/gfxtexture.h"

GfxTerrainLayer::GfxTerrainLayer(GfxMaterial *material_,
                                 GfxTexture *weight_) : uvScale(1.0f),
                                                        material(material_),
                                                        weight(weight_) {}

GfxTerrainLayer::GfxTerrainLayer(const GfxTerrainLayer& other)
 : uvScale(other.uvScale),
   material(other.material->copyRef<GfxMaterial>()),
   weight(other.weight->copyRef<GfxTexture>()) {}

GfxTerrainLayer::~GfxTerrainLayer()
{
    weight->release();
    material->release();
}

GfxTerrainLayer& GfxTerrainLayer::operator = (const GfxTerrainLayer& other)
{
    weight->release();
    material->release();

    uvScale = other.uvScale;
    material = other.material->copyRef<GfxMaterial>();
    weight = other.weight->copyRef<GfxTexture>();

    return *this;
}

void GfxTerrainLayer::setMaterial(GfxMaterial *material_)
{
    material->release();
    material = material_;
}

void GfxTerrainLayer::setWeight(GfxTexture *weight_)
{
    weight->release();
    weight = weight_;
}

GfxTerrain::GfxTerrain(float chunkSize_,
                       size_t sizeInChunks_,
                       GfxTexture *heightmap_) : chunkSize(chunkSize_),
                                                 sizeInChunks(sizeInChunks_),
                                                 heightmap(heightmap_),
                                                 scale(1.0f)
{
    mesh = NEW(GfxMesh);

    recreate();
}

GfxTerrain::~GfxTerrain()
{
    mesh->release();
    heightmap->release();
}

void GfxTerrain::recreate()
{
    ResizableData data(48);

    float *v0 = (float *)data.getData();
    float *v1 = v0 + 3;
    float *v2 = v1 + 3;
    float *v3 = v2 + 3;

    v0[0] = 0.0f;
    v0[1] = 0.0f;
    v0[2] = 0.0f;

    v1[0] = chunkSize;
    v1[1] = 0.0f;
    v1[2] = 0.0f;

    v2[0] = chunkSize;
    v2[1] = 0.0f;
    v2[2] = chunkSize;

    v3[0] = 0.0f;
    v3[1] = 0.0f;
    v3[2] = chunkSize;
/*
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

        }
    }*/

    GfxMeshAttrib attrib;
    attrib.type = GfxMeshAttribType::Position;
    attrib.dataType = GfxMeshAttribDataType::F32_3;
    attrib.data = data;
    mesh->setAttribute(attrib);

    mesh->numVertices = 4;

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
