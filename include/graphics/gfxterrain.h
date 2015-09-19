#ifndef GFXTERRAIN_H
#define GFXTERRAIN_H

#include "graphics/gfxtexture.h"

class GfxMesh;

class GfxTerrain
{
    public:
        GfxTerrain(float chunkSize,
                   size_t sizeInCunks,
                   GfxTexture *heightmap,
                   GfxTexture *texture);
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

        inline GfxTexture *getTexture() const
        {
            return texture;
        }

        inline void setTexture(GfxTexture *texture_)
        {
            texture->release();
            texture = texture_;
        }

        float textureScale;
    private:
        void recreate();
        void updateAABB();

        float chunkSize;
        size_t sizeInChunks;
        GfxTexture *heightmap;
        float scale;

        GfxMesh *mesh;
        GfxTexture *texture;
};

#endif // GFXTERRAIN_H
