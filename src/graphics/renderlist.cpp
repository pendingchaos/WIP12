#include "graphics/renderlist.h"

#include "globals.h"
#include "graphics/gfxapi.h"
#include "graphics/gfxmesh.h"
#include "graphics/gfxmaterial.h"
#include "graphics/gfxtexture.h"
#include "graphics/light.h"
#include "jobsystem.h"
#include "misc_macros.h"

#include <algorithm>
#include <SDL2/SDL_assert.h>

RenderList::RenderList() : needsSorting(false), matrixTexture(nullptr)
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

    for (auto drawCall : drawCalls)
    {
        drawCall.material->release();
        drawCall.mesh->release();
    }
}

void RenderList::addDrawCall(const DrawCall& drawCall)
{
    Item item;
    item.key = ((size_t)drawCall.material%4294967296)<<32 |
               ((size_t)drawCall.mesh%4294967296);
    item.drawCallIndex = drawCalls.getCount();

    drawCall.material->copyRef<GfxMaterial>();
    drawCall.mesh->copyRef<GfxMesh>();

    items.append(item);
    drawCalls.append(drawCall);

    needsSorting = true;
}

void RenderList::addRenderList(const RenderList *list)
{
    size_t start = drawCalls.getCount();

    items.append(list->items);
    drawCalls.append(list->drawCalls);

    for (size_t i = start; i < items.getCount(); ++i)
    {
        items[i].drawCallIndex += start;
    }

    needsSorting = true;
}

#define DRAW do\
{\
    fillMatrixTexture(worldMatrices, normalMatrices);\
    gfxApi->addTextureBinding(gfxApi->getVertexShader(), "matrixTexture", matrixTexture);\
    gfxApi->draw(worldMatrices.getCount());\
    ++drawCount;\
    worldMatrices.clear();\
    normalMatrices.clear();\
} while (0)
#define BEGIN_MAT(material, animState) do\
{\
    gfxApi->pushState();\
    (material)->setupRender((animState), camera);\
} while (0)
#define END_MAT do\
{\
    gfxApi->end();\
    gfxApi->popState();\
} while (0)
size_t RenderList::execute(const Camera& camera)
{
    if (needsSorting)
    {
        std::sort(items.getData(), items.getData()+items.getCount());
    }

    size_t drawCount = 0;

    List<Matrix4x4> worldMatrices;
    List<Matrix4x4> normalMatrices;
    GfxMesh *mesh = nullptr;
    GfxMaterial *material = nullptr;
    for (auto& item : items)
    {
        DrawCall& drawCall = drawCalls[item.drawCallIndex];

        if (((drawCall.mesh != mesh) or
             (drawCall.material != material)) and
            (mesh != nullptr) and
            (material != nullptr))
        {
            DRAW;
        }

        if (drawCall.mesh != mesh)
        {
            mesh = drawCall.mesh;
            gfxApi->setMesh(mesh);
        }

        if (drawCall.material != material)
        {
            if (material != nullptr)
            {
                END_MAT;
            }

            material = drawCall.material;
            BEGIN_MAT(material, drawCall.animState);
        }

        worldMatrices.append(drawCall.worldMatrix);
        normalMatrices.append(drawCall.normalMatrix);

        if (drawCall.animState != nullptr)
        {
            DRAW;
            mesh = nullptr;
            material = nullptr;
        }
    }

    if (worldMatrices.getCount() != 0)
    {
        DRAW;
        END_MAT;
    }

    return drawCount;
}
#undef DRAW

#define DRAW(animState_) do\
{\
    GfxAnimationState *animState = animState_;\
    fillMatrixTexture(worldMatrices, normalMatrices);\
    gfxApi->pushState();\
    GfxCompiledShader *vertex = animState != nullptr ? shadowVertexAnim : shadowVertex;\
    GfxCompiledShader *geometry = nullptr;\
    GfxCompiledShader *fragment = light->type == GfxLightType::Point ? shadowPointFragment : shadowFragment;\
    if (light->type == GfxLightType::Point)\
    {\
        if (light->point.singlePassShadowMap)\
        {\
            geometry = shadowGeometry;\
        }\
    }\
    gfxApi->begin(vertex,\
                  nullptr,\
                  nullptr,\
                  geometry,\
                  fragment);\
    GfxCullMode oldCullMode = mesh->cullMode;\
    mesh->cullMode = GfxCullNone;\
    gfxApi->setMesh(mesh);\
    mesh->cullMode = oldCullMode;\
    switch (light->type)\
    {\
    case GfxLightType::Point:\
    {\
        Position3D pos = light->point.position;\
        Matrix4x4 matrices[] = {Matrix4x4::lookAtDir(pos, Float3(1.0f, 0.0f, 0.0f), Float3(0.0f, -1.0f, 0.0f)),\
                                Matrix4x4::lookAtDir(pos, Float3(-1.0f, 0.0f, 0.0f), Float3(0.0f, -1.0f, 0.0f)),\
                                Matrix4x4::lookAtDir(pos, Float3(0.0f, 1.0f, 0.0f), Float3(0.0f, 0.0f, 1.0f)),\
                                Matrix4x4::lookAtDir(pos, Float3(0.0f, -1.0f, 0.0f), Float3(0.0f, 0.0f, -1.0f)),\
                                Matrix4x4::lookAtDir(pos, Float3(0.0f, 0.0f, 1.0f), Float3(0.0f, -1.0f, 0.0f)),\
                                Matrix4x4::lookAtDir(pos, Float3(0.0f, 0.0f, -1.0f), Float3(0.0f, -1.0f, 0.0f))};\
        if (light->point.singlePassShadowMap)\
        {\
            gfxApi->uniform(geometry, "matrix0", light->getProjectionMatrix() * matrices[0]);\
            gfxApi->uniform(geometry, "matrix1", light->getProjectionMatrix() * matrices[1]);\
            gfxApi->uniform(geometry, "matrix2", light->getProjectionMatrix() * matrices[2]);\
            gfxApi->uniform(geometry, "matrix3", light->getProjectionMatrix() * matrices[3]);\
            gfxApi->uniform(geometry, "matrix4", light->getProjectionMatrix() * matrices[4]);\
            gfxApi->uniform(geometry, "matrix5", light->getProjectionMatrix() * matrices[5]);\
            gfxApi->uniform(vertex, "projectionMatrix", Matrix4x4());\
            gfxApi->uniform(vertex, "viewMatrix", Matrix4x4());\
        } else\
        {\
            gfxApi->uniform(vertex, "projectionMatrix", light->getProjectionMatrix());\
            gfxApi->uniform(vertex, "viewMatrix", matrices[pass]);\
        }\
        gfxApi->uniform(fragment, "lightPos", pos);\
        gfxApi->uniform(fragment, "lightFar", light->getPointLightInfluence());\
        break;\
    }\
    case GfxLightType::Directional:\
    {\
        gfxApi->uniform(vertex, "projectionMatrix", light->getCascadeProjectionMatrix(pass));\
        gfxApi->uniform(vertex, "viewMatrix", light->getCascadeViewMatrix(pass));\
        break;\
    }\
    case GfxLightType::Spot:\
    {\
        gfxApi->uniform(vertex, "projectionMatrix", light->getProjectionMatrix());\
        gfxApi->uniform(vertex, "viewMatrix", light->getViewMatrix());\
        break;\
    }\
    default:\
    {\
        SDL_assert(false);\
    }\
    }\
    gfxApi->uniform(fragment, "biasScale", light->shadowAutoBiasScale);\
    if (animState != nullptr)\
    {\
        gfxApi->addUBOBinding(fragment, "bonePositionData", animState->getMatrixBuffer());\
    }\
    gfxApi->addTextureBinding(gfxApi->getVertexShader(), "matrixTexture", matrixTexture);\
    gfxApi->draw(worldMatrices.getCount());\
    ++drawCount;\
    gfxApi->end();\
    gfxApi->popState();\
    worldMatrices.clear();\
    normalMatrices.clear();\
} while (0)
size_t RenderList::execute(Light *light, size_t pass)
{
    if (needsSorting)
    {
        std::sort(items.getData(), items.getData()+items.getCount());
    }

    size_t drawCount = 0;

    List<Matrix4x4> worldMatrices;
    List<Matrix4x4> normalMatrices;
    GfxMesh *mesh = nullptr;
    for (auto& item : items)
    {
        DrawCall& drawCall = drawCalls[item.drawCallIndex];

        if ((drawCall.mesh != mesh) and
            (mesh != nullptr))
        {
            DRAW(drawCall.animState);
        }

        if (drawCall.mesh != mesh)
        {
            gfxApi->setMesh(drawCall.mesh);
            mesh = drawCall.mesh;
        }

        worldMatrices.append(drawCall.worldMatrix);
        normalMatrices.append(drawCall.normalMatrix);

        if (drawCall.animState != nullptr)
        {
            DRAW(drawCall.animState);
            mesh = nullptr;
        }
    }

    if (worldMatrices.getCount() != 0)
    {
        DRAW(nullptr);
    }

    return drawCount;
}
#undef DRAW

void RenderList::clear()
{
    for (auto drawCall : drawCalls)
    {
        drawCall.material->release();
        drawCall.mesh->release();
    }

    items.clear();
    drawCalls.clear();
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
    UNUSED(worker);

    index *= NUM_PER_JOB;
    Data data = *(Data *)userdata;
    #define OP(i) data.matrixData[index*2+i*2] = data.worldMatrices[index+i];\
    data.matrixData[index*2+i*2+1] = data.worldMatrices[index+i];
    FOR_N(OP, NUM_PER_JOB);
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
