#ifndef MC_CLONE_H
#define MC_CLONE_H

#include "scripting/bindings.h"
#include "containers/list.h"
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

class MCChunk
{
    NO_COPY(MCChunk);

    public:
        MCChunk(size_t width, size_t height, size_t depth, uint8_t numTypes, float blockSize);
        ~MCChunk();

        void updateMeshes();
        void updateRigidBodies(PhysicsWorld *world);

        GfxMesh *getMesh(uint8_t type)
        {
            if (type == 0)
            {
                return nullptr;
            }

            return meshes[type+1];
        }

        uint8_t getCube(int x, int y, int z);
        void setCube(size_t x, size_t y, size_t z, uint8_t type);

        void setMaterial(uint8_t type, GfxMaterial *material);

        void render(GfxRenderer *renderer, const Matrix4x4& worldMatrix);
    private:
        size_t width;
        size_t height;
        size_t depth;
        size_t numTypes;
        float blockSize;
        GfxMesh *meshes[255];
        GfxMaterial *materials[255];
        uint8_t *cubes;
        List<RigidBody *> bodies;
        PhysicsShape *shape;
} BIND NOT_COPYABLE;

#endif // MC_CLONE_H
