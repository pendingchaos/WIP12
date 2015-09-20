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

        inline GfxMaterial *getMaterial() const
        {
            return material;
        }

        void setMaterial(GfxMaterial *material_);

        inline GfxTexture *getWeight() const
        {
            return weight;
        }

        void setWeight(GfxTexture *weight_);

        float uvScale;
    private:
        GfxMaterial *material;
        GfxTexture *weight;
};

class GfxTerrain
{
    public:
        GfxTerrain(float chunkSize,
                   size_t sizeInCunks,
                   GfxTexture *heightmap);
        ~GfxTerrain();

        inline float getChunkSize() const
        {
            return chunkSize;
        }

        inline size_t getSizeInChunks() const
        {
            return sizeInChunks;
        }

        inline GfxTexture *getHeightmap() const
        {
            return heightmap;
        }

        inline void setChunkSize(float chunkSize_)
        {
            chunkSize = chunkSize_;
            recreate();
        }

        inline void setSizeInChunks(size_t sizeInChunks_)
        {
            sizeInChunks = sizeInChunks_;
            recreate();
        }

        inline void setHeightmap(GfxTexture *heightmap) const NO_BIND
        {
            heightmap = heightmap;
        }

        inline GfxMesh *getMesh() const
        {
            return mesh;
        }

        inline float getScale() const
        {
            return scale;
        }

        inline void setScale(float scale_)
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
};

#endif // GFXTERRAIN_H
