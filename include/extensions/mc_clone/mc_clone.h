#ifndef MC_CLONE_H
#define MC_CLONE_H

#include "scripting/bindings.h"
#include "containers/list.h"
#include "math/t3.h"
#include "misc_macros.h"

#include <stddef.h>
#include <stdint.h>

class GfxMesh;
class GfxMaterial;
class GfxModel;
class GfxRenderer;
class Matrix4x4;
class PhysicsWorld;
class RigidBody;
class PhysicsShape;
class MCWorld;

class MCChunk
{
    NO_COPY(MCChunk);

    public:
        MCChunk(MCWorld *world);
        ~MCChunk();

        void updateMeshes();
        void updateRigidBodies(const Matrix4x4& transform);

        GfxMesh *getMesh(uint8_t type)
        {
            if (type == 0)
            {
                return nullptr;
            }

            return meshes[type+1];
        }

        uint8_t getCube(int x, int y, int z);
        void setCube(int x, int y, int z, uint8_t type);

        void render(GfxRenderer *renderer, const Matrix4x4& worldMatrix);

        size_t generateSphere(size_t radius, uint8_t type);
    private:
        uint8_t _getCube(int x, int y, int z);

        MCWorld *world;
        GfxMesh *meshes[255];
        uint8_t *cubes;
        RigidBody *body;
        PhysicsShape *compoundShape;
} BIND NOT_COPYABLE;

class MCWorld
{
    public:
        MCWorld(const UInt3& chunkSize,
                uint8_t numTypes,
                float blockSize,
                PhysicsWorld *world);
        ~MCWorld();

        void setMaterial(uint8_t type, GfxMaterial *material);

        void render(GfxRenderer *renderer);

        void update();

        void setCube(int x, int y, int z, uint8_t type);
        uint8_t getCube(int x, int y, int z);

        //TODO: Get rid of this. It is a workaround for scripting limitations.
        uint8_t getCube(float x, float y, float z)
        {
            return getCube((int)x, (int)y, (int)z);
        }

        void setCube(float x, float y, float z, uint8_t type)
        {
            setCube((int)x, (int)y, (int)z, type);
        }

        UInt3 getChunkSize() const
        {
            return chunkSize;
        }

        uint8_t getNumTypes() const
        {
            return numTypes;
        }

        float getBlockSize() const
        {
            return blockSize;
        }

        PhysicsWorld *getPhysicsWorld() const
        {
            return physicsWorld;
        }

        PhysicsShape *getCubeShape() const NO_BIND
        {
            return cubeShape;
        }

        GfxMaterial *getMaterial(uint8_t type) const NO_BIND
        {
            return materials[type];
        }
    private:
        struct Chunk
        {
            Int3 pos;
            MCChunk *chunk;
            bool dirty;
        };

        GfxMaterial *materials[255];
        PhysicsShape *cubeShape;

        UInt3 chunkSize;
        uint8_t numTypes;
        float blockSize;
        PhysicsWorld *physicsWorld;

        List<Chunk> chunks;
} BIND NOT_COPYABLE;

#endif // MC_CLONE_H
