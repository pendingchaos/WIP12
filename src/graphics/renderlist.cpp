#include "graphics/renderlist.h"

#include "globals.h"
#include "graphics/gfxapi.h"
#include "graphics/gfxmesh.h"
#include "graphics/gfxmaterial.h"
#include "graphics/gfxtexture.h"
#include "graphics/light.h"
#include "jobsystem.h"
#include "misc_macros.h"

RenderList::RenderList() : matrixTexture(nullptr)
{
    shadowVertexShader = resMgr->load<GfxShader>("resources/shaders/shadowmap.vs.bin");
    shadowGeometryShader = resMgr->load<GfxShader>("resources/shaders/pointShadowmap.gs.bin");
    shadowFragmentShader = resMgr->load<GfxShader>("resources/shaders/shadowmap.fs.bin");
    shadowPointFragmentShader = resMgr->load<GfxShader>("resources/shaders/pointShadowmap.fs.bin");

    shadowVertex = shadowVertexShader->getCompiled();
    shadowVertexAnim = shadowVertexShader->getCompiled(HashMapBuilder<Str, Str>().add("SKELETAL_ANIMATION", "1"));
    shadowGeometry = shadowGeometryShader->getCompiled();
    shadowFragment = shadowFragmentShader->getCompiled();
    shadowPointFragment = shadowPointFragmentShader->getCompiled();
}

RenderList::~RenderList()
{
    shadowPointFragmentShader->release();
    shadowFragmentShader->release();
    shadowGeometryShader->release();
    shadowVertexShader->release();

    if (matrixTexture != nullptr)
    {
        matrixTexture->release();
    }

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

    for (size_t i = 0; i < batches.getCount(); ++i)
    {
        if (batches[i].material == drawCall.material and batches[i].mesh == drawCall.mesh)
        {
            batches[i].worldMatrices.append(drawCall.worldMatrix);
            batches[i].normalMatrices.append(drawCall.normalMatrix);
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

void RenderList::addRenderList(const RenderList *list)
{
    for (auto& batch : list->batches)
    {
        batch.material->copyRef<GfxMaterial>();
        batch.mesh->copyRef<GfxMesh>();
    }

    batches.append(list->batches);
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

        //TODO: This does not increment the draw call count.
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

        GfxMesh *mesh = batch.mesh;

        gfxApi->pushState();

        GfxCompiledShader *vertex = batch.animState != nullptr ? shadowVertexAnim : shadowVertex;
        GfxCompiledShader *geometry = nullptr;
        GfxCompiledShader *fragment = light->type == GfxLightType::Point ? shadowPointFragment : shadowFragment;
        if (light->type == GfxLightType::Point)
        {
            if (light->point.singlePassShadowMap)
            {
                geometry = shadowGeometry;
            }
        }

        gfxApi->begin(vertex,
                      nullptr,
                      nullptr,
                      geometry,
                      fragment);
        gfxApi->setMesh(batch.mesh);

        switch (light->type)
        {
        case GfxLightType::Point:
        {
            Position3D pos = light->point.position;

            Matrix4x4 matrices[] = {Matrix4x4::lookAtDir(pos, Float3(1.0f, 0.0f, 0.0f), Float3(0.0f, -1.0f, 0.0f)),
                                    Matrix4x4::lookAtDir(pos, Float3(-1.0f, 0.0f, 0.0f), Float3(0.0f, -1.0f, 0.0f)),
                                    Matrix4x4::lookAtDir(pos, Float3(0.0f, 1.0f, 0.0f), Float3(0.0f, 0.0f, 1.0f)),
                                    Matrix4x4::lookAtDir(pos, Float3(0.0f, -1.0f, 0.0f), Float3(0.0f, 0.0f, -1.0f)),
                                    Matrix4x4::lookAtDir(pos, Float3(0.0f, 0.0f, 1.0f), Float3(0.0f, -1.0f, 0.0f)),
                                    Matrix4x4::lookAtDir(pos, Float3(0.0f, 0.0f, -1.0f), Float3(0.0f, -1.0f, 0.0f))};

            if (light->point.singlePassShadowMap)
            {
                gfxApi->uniform(geometry, "matrix0", light->getProjectionMatrix() * matrices[0]);
                gfxApi->uniform(geometry, "matrix1", light->getProjectionMatrix() * matrices[1]);
                gfxApi->uniform(geometry, "matrix2", light->getProjectionMatrix() * matrices[2]);
                gfxApi->uniform(geometry, "matrix3", light->getProjectionMatrix() * matrices[3]);
                gfxApi->uniform(geometry, "matrix4", light->getProjectionMatrix() * matrices[4]);
                gfxApi->uniform(geometry, "matrix5", light->getProjectionMatrix() * matrices[5]);

                gfxApi->uniform(vertex, "projectionMatrix", Matrix4x4());
                gfxApi->uniform(vertex, "viewMatrix", Matrix4x4());
            } else
            {
                gfxApi->uniform(vertex, "projectionMatrix", light->getProjectionMatrix());
                gfxApi->uniform(vertex, "viewMatrix", matrices[pass]);
            }

            gfxApi->uniform(fragment, "lightPos", pos);
            gfxApi->uniform(fragment, "lightFar", light->getPointLightInfluence());
            break;
        }
        case GfxLightType::Directional:
        {
            gfxApi->uniform(vertex, "projectionMatrix", light->getCascadeProjectionMatrix(pass));
            gfxApi->uniform(vertex, "viewMatrix", light->getCascadeViewMatrix(pass));
            break;
        }
        case GfxLightType::Spot:
        {
            gfxApi->uniform(vertex, "projectionMatrix", light->getProjectionMatrix());
            gfxApi->uniform(vertex, "viewMatrix", light->getViewMatrix());
            break;
        }
        }

        gfxApi->uniform(fragment, "biasScale", light->shadowAutoBiasScale);

        if (batch.animState != nullptr)
        {
            gfxApi->addUBOBinding(fragment, "bonePositionData", batch.animState->getMatrixBuffer());
        }

        gfxApi->addTextureBinding(gfxApi->getVertexShader(), "matrixTexture", matrixTexture);

        gfxApi->setCullMode(mesh->cullMode);

        //TODO: This does not increment the draw call count.
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

#define NUM_PER_JOB 32

static void job(size_t index, size_t worker, void *userdata)
{
    index *= NUM_PER_JOB;
    Data data = *(Data *)userdata;
    #define OP(i) data.matrixData[index*2+i*2] = data.worldMatrices[index+i];\
    data.matrixData[index*2+i*2+1] = data.worldMatrices[index+i];
    FOR_N(OP, NUM_PER_JOB); index+=NUM_PER_JOB;
    #undef OP
}

void RenderList::fillMatrixTexture(const List<Matrix4x4>& worldMatrices, const List<Matrix4x4>& normalMatrices)
{
    size_t maxSize = gfxApi->getMaxTextureSize();
    size_t numTexels = worldMatrices.getCount() * 8;
    size_t width = numTexels > maxSize ? maxSize : numTexels;
    size_t height = (numTexels+maxSize-1) / maxSize;

    Matrix4x4 *matrixData = (Matrix4x4 *)ALLOCATE(width*height*16);

    if (worldMatrices.getCount() <= NUM_PER_JOB*8)
    {
        const Matrix4x4 *worldMatrices_ = worldMatrices.getData();
        const Matrix4x4 *normalMatrices_ = normalMatrices.getData();
        for (size_t i = 0; i < worldMatrices.getCount(); ++i)
        {
            matrixData[i*2] = worldMatrices_[i];
            matrixData[i*2+1] = normalMatrices_[i];
        }
    } else
    {
        Data data;
        data.matrixData = matrixData;
        data.worldMatrices = worldMatrices.getData();
        data.normalMatrices = normalMatrices.getData();
        runJobsSync(job, worldMatrices.getCount()/NUM_PER_JOB, &data, sizeof(Data));
        for (size_t i = worldMatrices.getCount()/NUM_PER_JOB*NUM_PER_JOB; i < worldMatrices.getCount(); ++i)
        {
            matrixData[i*2] = worldMatrices[i];
            matrixData[i*2+1] = normalMatrices[i];
        }
    }

    if (matrixTexture == nullptr)
    {
        matrixTexture = NEW(GfxTexture);
    }

    if (width != matrixTexture->getBaseWidth() or height != matrixTexture->getBaseHeight())
    {
        matrixTexture->startCreation(GfxTextureType::Texture2D,
                                     width,
                                     height,
                                     1,
                                     GfxTexFormat::RGBAF32);
    }

    matrixTexture->allocMipmap(0, 1, matrixData);

    DEALLOCATE(matrixData);
}
