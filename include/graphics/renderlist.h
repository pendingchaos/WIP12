#ifndef RENDERQUEUE_H
#define RENDERQUEUE_H

#include "math/matrix4x4.h"
#include "containers/list.h"
#include "misc_macros.h"
#include "scripting/bindings.h"

class Camera;
class GfxMesh;
class GfxMaterial;
class GfxTexture;
class GfxAnimationState;
class Light;

struct DrawCall
{
    DrawCall(GfxMesh *mesh_, GfxMaterial *mat) : mesh(mesh_),
                                                 material(mat),
                                                 animState(nullptr) {}

    GfxMesh *mesh;
    GfxMaterial *material;
    Matrix4x4 worldMatrix;
    GfxAnimationState *animState;
} BIND;

class RenderList
{
    NO_COPY(RenderList);

    public:
        RenderList();
        ~RenderList();

        void addDrawCall(const DrawCall& drawCall);
        void execute(const Camera& camera);
        void execute(Light *light, size_t pass);
        void clear();
    private:
        struct Batch
        {
            GfxMesh *mesh;
            GfxMaterial *material;
            List<Matrix4x4> worldMatrices;
            GfxAnimationState *animState;
        };

        List<Batch> batches;
        GfxTexture *matrixTexture;

        void fillMatrixTexture(const List<Matrix4x4>& matrices);
} BIND NOT_COPYABLE;

#endif // RENDERQUEUE_H
