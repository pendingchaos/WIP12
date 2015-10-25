#include "graphics/renderlist.h"

#include "globals.h"
#include "graphics/gfxapi.h"
#include "graphics/gfxmesh.h"
#include "graphics/gfxmaterial.h"
#include "graphics/gfxtexture.h"

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
        batch.animState = drawCall.animState;

        batches.append(batch);

        return;
    }

    for (size_t k = 0; k < batches.getCount(); ++k)
    {
        if (batches[k].material == drawCall.material and batches[k].mesh == drawCall.mesh)
        {
            batches[k].worldMatrices.append(drawCall.worldMatrix);
            return;
        }
    }

    Batch batch;
    batch.material = drawCall.material->copyRef<GfxMaterial>();
    batch.mesh = drawCall.mesh->copyRef<GfxMesh>();
    batch.worldMatrices.append(drawCall.worldMatrix);
    batch.animState = nullptr;

    batches.append(batch);
}

void RenderList::execute(const Camera& camera)
{
    for (auto batch : batches)
    {
        fillMatrixTexture(batch.worldMatrices);

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
        fillMatrixTexture(batch.worldMatrices);

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

void RenderList::fillMatrixTexture(const List<Matrix4x4>& worldMatrices)
{
    size_t maxSize = gfxApi->getMaxTextureSize();
    size_t numTexels = worldMatrices.getCount() * 8;
    size_t width = numTexels > maxSize ? maxSize : numTexels;
    size_t height = (numTexels+maxSize-1) / maxSize;
    uint8_t *matrixData = (uint8_t *)ALLOCATE(width*height*16);

    for (size_t j = 0; j < worldMatrices.getCount(); ++j)
    {
        Matrix4x4 worldMatrix = worldMatrices[j];
        Matrix4x4 normalMatrix = Matrix3x3(worldMatrix.inverse().transpose());
        worldMatrix = worldMatrix.transpose();
        normalMatrix = normalMatrix.transpose();

        std::memcpy(matrixData+j*128, (void *)&worldMatrix, 64);
        std::memcpy(matrixData+j*128+64, (void *)&normalMatrix, 64);
    }

    matrixTexture->startCreation(GfxTextureType::Texture2D,
                                 width,
                                 height,
                                 1,
                                 GfxTexFormat::RGBAF32);

    matrixTexture->allocMipmap(0, 1, matrixData);

    DEALLOCATE(matrixData);
}
