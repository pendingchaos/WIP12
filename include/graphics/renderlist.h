#ifndef RENDERQUEUE_H
#define RENDERQUEUE_H

#include "math/matrix4x4.h"
#include "containers/list.h"

class Camera;
class GfxMesh;
class GfxMaterial;
class GfxTexture;
class GfxAnimationState;
class Light;

struct DrawCall
{
    GfxMesh *mesh;
    GfxMaterial *material;
    Matrix4x4 worldMatrix;
    GfxAnimationState *animState;
};

class RenderList
{
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
};

#endif // RENDERQUEUE_H
