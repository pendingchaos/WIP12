#include "graphics/renderlist.h"

#include "globals.h"
#include "graphics/gfxapi.h"
#include "graphics/gfxmesh.h"
#include "graphics/gfxmaterial.h"
#include "graphics/gfxtexture.h"
#include "jobsystem.h"

RenderList::RenderList()
{
    matrixTexture = NEW(GfxTexture);
}

RenderList::~RenderList()
{
    matrixTexture->release();

    for (auto batch : batches)
    {
        batch.material->release();
        batch.mesh->release();
    }
}

void RenderList::addDrawCall(const DrawCall& drawCall)
{
    //Currently skinned draw calls can not be batched.
    if (drawCall.animState != nullptr)
    {
        Batch batch;
        batch.material = drawCall.material->copyRef<GfxMaterial>();
        batch.mesh = drawCall.mesh->copyRef<GfxMesh>();
        batch.worldMatrices.append(drawCall.worldMatrix);
        batch.normalMatrices.append(drawCall.normalMatrix);
        batch.animState = drawCall.animState;

        batches.append(batch);

        return;
    }

    for (size_t k = 0; k < batches.getCount(); ++k)
    {
        if (batches[k].material == drawCall.material and batches[k].mesh == drawCall.mesh)
        {
            batches[k].worldMatrices.append(drawCall.worldMatrix);
            batches[k].normalMatrices.append(drawCall.normalMatrix);
            return;
        }
    }

    Batch batch;
    batch.material = drawCall.material->copyRef<GfxMaterial>();
    batch.mesh = drawCall.mesh->copyRef<GfxMesh>();
    batch.worldMatrices.append(drawCall.worldMatrix);
    batch.normalMatrices.append(drawCall.normalMatrix);
    batch.animState = nullptr;

    batches.append(batch);
}

void RenderList::execute(const Camera& camera)
{
    for (auto batch : batches)
    {
        fillMatrixTexture(batch.worldMatrices, batch.normalMatrices);

        GfxMaterial *material = batch.material;
        GfxMesh *mesh = batch.mesh;

        gfxApi->pushState();

        material->setupRender(mesh, batch.animState, camera);

        gfxApi->addTextureBinding(gfxApi->getVertexShader(), "matrixTexture", matrixTexture);

        gfxApi->setCullMode(mesh->cullMode);

        gfxApi->draw(batch.worldMatrices.getCount());
        gfxApi->end();

        gfxApi->popState();
    }
}

void RenderList::execute(Light *light, size_t pass)
{
    for (auto batch : batches)
    {
        fillMatrixTexture(batch.worldMatrices, batch.normalMatrices);

        GfxMaterial *material = batch.material;
        GfxMesh *mesh = batch.mesh;

        gfxApi->pushState();

        material->setupShadowRender(mesh, batch.animState, light, pass);

        gfxApi->addTextureBinding(gfxApi->getVertexShader(), "matrixTexture", matrixTexture);

        gfxApi->setCullMode(mesh->cullMode);

        gfxApi->draw(batch.worldMatrices.getCount());
        gfxApi->end();

        gfxApi->popState();
    }
}

void RenderList::clear()
{
    for (auto batch : batches)
    {
        batch.material->release();
        batch.mesh->release();
    }

    batches.clear();
}

struct Data
{
    Matrix4x4 *matrixData;
    const Matrix4x4 *worldMatrices;
    const Matrix4x4 *normalMatrices;
};

static void job(size_t index, size_t worker, void *userdata)
{
    Data data = *(Data *)userdata;
    data.matrixData[index*2] = data.worldMatrices[index];
    data.matrixData[index*2+1] = data.normalMatrices[index];
}

void RenderList::fillMatrixTexture(const List<Matrix4x4>& worldMatrices, const List<Matrix4x4>& normalMatrices)
{
    size_t maxSize = gfxApi->getMaxTextureSize();
    size_t numTexels = worldMatrices.getCount() * 8;
    size_t width = numTexels > maxSize ? maxSize : numTexels;
    size_t height = (numTexels+maxSize-1) / maxSize;
    Matrix4x4 *matrixData = (Matrix4x4 *)ALLOCATE(width*height*16);

    //Only up to ~1.5 speed up in extreme cases. Huge slowdown is less extreme cases.
    //~8 speed up when the job sleeps for 10 microseconds.
    #if 1
    const Matrix4x4 *worldMatrices_ = worldMatrices.getData();
    const Matrix4x4 *normalMatrices_ = normalMatrices.getData();
    for (size_t i = 0; i < worldMatrices.getCount(); ++i)
    {
        matrixData[i*2] = worldMatrices_[i];
        matrixData[i*2+1] = normalMatrices_[i];
    }
    #else
    Data data;
    data.matrixData = matrixData;
    data.worldMatrices = worldMatrices.getData();
    data.normalMatrices = normalMatrices.getData();
    runJobsSync(job, worldMatrices.getCount(), &data, sizeof(Data));
    #endif

    matrixTexture->startCreation(GfxTextureType::Texture2D,
                                 width,
                                 height,
                                 1,
                                 GfxTexFormat::RGBAF32);

    matrixTexture->allocMipmap(0, 1, matrixData);

    DEALLOCATE(matrixData);
}
