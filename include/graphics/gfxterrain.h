#ifndef GFXTERRAIN_H
#define GFXTERRAIN_H

#include "graphics/gfxtexture.h"

class GfxMesh;
class GfxMaterial;
class GfxTexture;

class GfxTerrainLayer
{
    public:
        GfxTerrainLayer(GfxMaterial *material, GfxTexture *weight);
        GfxTerrainLayer(const GfxTerrainLayer& other);
        ~GfxTerrainLayer();

        GfxTerrainLayer& operator = (const GfxTerrainLayer& other);

        GfxMaterial *getMaterial() const
        {
            return material;
        }

        void setMaterial(GfxMaterial *material_);

        GfxTexture *getWeight() const
        {
            return weight;
        }

        void setWeight(GfxTexture *weight_);

        float uvScale;
    private:
        GfxMaterial *material;
        GfxTexture *weight;
} NO_BIND;

class GfxTerrain
{
    public:
        GfxTerrain(float chunkSize,
                   size_t sizeInCunks,
                   GfxTexture *heightmap);
        ~GfxTerrain();

        float getChunkSize() const
        {
            return chunkSize;
        }

        size_t getSizeInChunks() const
        {
            return sizeInChunks;
        }

        GfxTexture *getHeightmap() const
        {
            return heightmap;
        }

        void setChunkSize(float chunkSize_)
        {
            chunkSize = chunkSize_;
            recreate();
        }

        void setSizeInChunks(size_t sizeInChunks_)
        {
            sizeInChunks = sizeInChunks_;
            recreate();
        }

        void setHeightmap(GfxTexture *heightmap) const NO_BIND
        {
            heightmap = heightmap;
        }

        GfxMesh *getMesh() const
        {
            return mesh;
        }

        float getScale() const
        {
            return scale;
        }

        void setScale(float scale_)
        {
            scale = scale_;
            updateAABB();
        }

        List<GfxTerrainLayer> layers;
    private:
        void recreate();
        void updateAABB();

        float chunkSize;
        size_t sizeInChunks;
        GfxTexture *heightmap;
        float scale;

        GfxMesh *mesh;
} NO_BIND;

#endif // GFXTERRAIN_H
