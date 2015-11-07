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
class GfxCompiledShader;
class GfxShader;

struct DrawCall
{
    DrawCall(GfxMesh *mesh_, GfxMaterial *mat) : mesh(mesh_),
                                                 material(mat),
                                                 worldMatrix(Matrix4x4::NoInit),
                                                 normalMatrix(Matrix4x4::NoInit),
                                                 animState(nullptr) {}

    GfxMesh *mesh;
    GfxMaterial *material;
    Matrix4x4 worldMatrix;
    Matrix4x4 normalMatrix;
    GfxAnimationState *animState;
} BIND;

class RenderList
{
    NO_COPY(RenderList);

    public:
        RenderList();
        ~RenderList();

        void addDrawCall(const DrawCall& drawCall);
        void addRenderList(const RenderList *list);
        size_t execute(const Camera& camera);
        size_t execute(Light *light, size_t pass);
        void clear();
    private:
        struct Batch
        {
            GfxMesh *mesh;
            GfxMaterial *material;
            List<Matrix4x4> worldMatrices;
            List<Matrix4x4> normalMatrices;
            GfxAnimationState *animState;
        };

        List<Batch> batches;
        GfxTexture *matrixTexture;

        GfxShader *shadowVertexShader;
        GfxShader *shadowGeometryShader;
        GfxShader *shadowFragmentShader;
        GfxShader *shadowPointFragmentShader;

        GfxCompiledShader *shadowVertex;
        GfxCompiledShader *shadowVertexAnim;
        GfxCompiledShader *shadowGeometry;
        GfxCompiledShader *shadowFragment;
        GfxCompiledShader *shadowPointFragment;

        void fillMatrixTexture(const List<Matrix4x4>& matrices, const List<Matrix4x4>& normalMatrices);
} BIND NOT_COPYABLE;

#endif // RENDERQUEUE_H
