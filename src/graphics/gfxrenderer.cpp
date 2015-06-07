#include "graphics/gfxrenderer.h"

#include "math/matrix3x3.h"
#include "graphics/gfxapi.h"
#include "graphics/camera.h"
#include "graphics/gfxframebuffer.h"
#include "graphics/gfxdebugdrawer.h"
#include "scene/scene.h"
#include "scene/entity.h"
#include "globals.h"

#include <cmath>

GfxRenderer::GfxRenderer(ResPtr<Scene> scene_) : debugDraw(false),
                                                 scene(scene_)
{
    skyboxVertex = resMgr->getResourceByFilename<GfxShader>("resources/shaders/skyboxVertex.bin");
    skyboxFragment = resMgr->getResourceByFilename<GfxShader>("resources/shaders/skyboxFragment.bin");
    skyboxMesh = resMgr->getResourceByFilename<GfxMesh>("resources/meshes/cube.bin");

    lightBuffer = gfxApi->createBuffer();
}

GfxRenderer::~GfxRenderer()
{
    DELETE(GfxBuffer, lightBuffer);
}

void GfxRenderer::beginRenderMesh(const Camera& camera,
                                  const Matrix4x4& worldMatrix,
                                  ResPtr<GfxMesh> mesh,
                                  GfxShaderCombination *comb)
{
    Matrix4x4 projectionMatrix = camera.getProjectionMatrix();
    Matrix4x4 viewMatrix = camera.getViewMatrix();
    Matrix3x3 normalMatrix = Matrix3x3(worldMatrix.inverse().transpose());

    GfxCompiledShader *vertexShader = comb->getCompiledVertexShader();
    GfxCompiledShader *tessControlShader = comb->getCompiledTessControlShader();
    GfxCompiledShader *tessEvalShader = comb->getCompiledTessEvalShader();
    GfxCompiledShader *geometryShader = comb->getCompiledGeometryShader();
    GfxCompiledShader *fragmentShader = comb->getCompiledFragmentShader();

    gfxApi->begin(vertexShader,
                  tessControlShader,
                  tessEvalShader,
                  geometryShader,
                  fragmentShader,
                  mesh);

    gfxApi->uniform(vertexShader, "projectionMatrix", projectionMatrix);

    gfxApi->uniform(vertexShader, "viewMatrix", viewMatrix);

    gfxApi->uniform(vertexShader, "worldMatrix", worldMatrix);

    gfxApi->uniform(vertexShader, "normalMatrix", normalMatrix);

    gfxApi->uniform(vertexShader, "cameraPosition", camera.getPosition());
}

void GfxRenderer::endRenderMesh(ResPtr<GfxMesh> mesh)
{
    if (mesh->indexed)
    {
        gfxApi->endIndexed(mesh->primitive,
                           mesh->indexData.type,
                           mesh->indexData.numIndices,
                           mesh->indexData.offset,
                           mesh->indexData.buffer,
                           mesh->winding);
    } else
    {
        gfxApi->end(mesh->primitive, mesh->numVertices, mesh->winding);
    }
}

void GfxRenderer::resize(const UInt2& size)
{
    width = size.x;
    height = size.y;

    if (camera.getType() == Camera::Perspective)
    {
        camera.setWidth(width);
        camera.setHeight(height);
    }
}

void GfxRenderer::render()
{
    gfxApi->clearDepth();

    if (skybox == nullptr)
    {
        gfxApi->clearColor(0, Float4(1.0f));
    }

    gfxApi->setViewport(0, 0, width, height);

    fillLightBuffer(scene);

    renderEntities();

    renderSkybox();

    if (debugDraw)
    {
        debugDrawer->render(camera);
    }
}

void GfxRenderer::fillLightBuffer(ResPtr<Scene> scene)
{
    numLights = lights.getCount();

    float *lightData = NEW_ARRAY(float, numLights * 16);

    for (size_t i = 0; i < numLights; ++i)
    {
        const Light& light = lights[i];

        lightData[i*16  ] = light.color.x * light.power;
        lightData[i*16+1] = light.color.y * light.power;
        lightData[i*16+2] = light.color.z * light.power;

        switch (light.type)
        {
        case Light::Directional:
        {
            Vector3D dir = -light.direction.direction.normalize();

            lightData[i*16+3] = dir.x;
            lightData[i*16+4] = dir.y;
            lightData[i*16+5] = dir.z;
            lightData[i*16+11] = 0.0;
            break;
        }
        case Light::Spot:
        {
            Vector3D dir = -light.spot.direction.normalize();

            lightData[i*16+3] = light.spot.position.x;
            lightData[i*16+4] = light.spot.position.y;
            lightData[i*16+5] = light.spot.position.z;
            lightData[i*16+6] = dir.x;
            lightData[i*16+7] = dir.y;
            lightData[i*16+8] = dir.z;
            lightData[i*16+9] = std::cos(RADIANS(light.spot.innerCutoff));
            lightData[i*16+10] = std::cos(RADIANS(light.spot.outerCutoff));
            lightData[i*16+11] = 1.0;
            lightData[i*16+12] = light.spot.radius;
            break;
        }
        case Light::Point:
        {
            lightData[i*16+3] = light.point.position.x;
            lightData[i*16+4] = light.point.position.y;
            lightData[i*16+5] = light.point.position.z;
            lightData[i*16+11] = 2.0;
            lightData[i*16+12] = light.point.radius;
            break;
        }
        }
    }

    lightBuffer->allocData(numLights*64, lightData, GfxBuffer::Dynamic);

    DELETE_ARRAY(float, lightData);
}

void GfxRenderer::renderEntities()
{
    const List<Entity *>& entities = scene->getEntities();

    for (size_t i = 0; i < entities.getCount(); ++i)
    {
        const Entity *entity = entities[i];

        Matrix4x4 transform = entity->transform.createMatrix();

        for (size_t i = 0; i < entity->getScripts().getCount(); ++i)
        {
            entity->getScripts()[i]->render();
        }

        if (entity->hasRenderComponent())
        {
            const RenderComponent *comp = entity->getRenderComponent();

            switch (comp->type)
            {
            case RenderComponent::Nothing:
            {
                break;
            }
            case RenderComponent::Model:
            {
                renderModel(GfxModel::Forward, camera, transform, comp->model);
                break;
            }
            }
        }
    }
}

void GfxRenderer::renderSkybox()
{
    if (skybox != nullptr)
    {
        gfxApi->pushState();

        GfxCompiledShader *compiledVS = skyboxVertex->getCompiled();
        GfxCompiledShader *compiledFS = skyboxFragment->getCompiled();

        gfxApi->begin(compiledVS,
                      nullptr,
                      nullptr,
                      nullptr,
                      compiledFS,
                      skyboxMesh);

        gfxApi->setDepthFunction(GfxLessEqual);

        gfxApi->uniform(compiledVS, "projectionMatrix", camera.getProjectionMatrix());

        gfxApi->uniform(compiledVS, "viewMatrix", Matrix4x4(Matrix3x3(camera.getViewMatrix())));

        gfxApi->addTextureBinding(compiledFS, "enviroment", skybox);

        if (skyboxMesh->indexed)
        {
            gfxApi->endIndexed(skyboxMesh->primitive,
                               skyboxMesh->indexData.type,
                               skyboxMesh->indexData.numIndices,
                               skyboxMesh->indexData.offset,
                               skyboxMesh->indexData.buffer,
                               skyboxMesh->winding);
        } else
        {
            gfxApi->end(skyboxMesh->primitive,
                        skyboxMesh->numVertices,
                        skyboxMesh->winding);
        }

        gfxApi->popState();
    }
}

void GfxRenderer::renderModel(GfxModel::ContextType contextType,
                              const Camera& camera,
                              const Matrix4x4& worldMatrix,
                              const ResPtr<GfxModel> model)
{
    int contextIndex = model->contexts.findEntry(contextType);

    if (contextIndex == -1)
    {
        return;
    }

    const GfxModel::Context& context = model->contexts.getValue(contextIndex);

    Position3D position = Position3D(worldMatrix[0][3],
                                     worldMatrix[1][3],
                                     worldMatrix[2][3]);

    float distance = position.distance(camera.getPosition());

    for (size_t i = 0; i < context.getCount(); ++i)
    {
        GfxModel::SubModel subModel = context[i];

        for (size_t j = 0; j < subModel.getCount(); ++j)
        {
            const GfxModel::LOD& lod = subModel[j];

            if (lod.minDistance < distance and distance < lod.maxDistance)
            {
                lod.material->render(this, lod.mesh, worldMatrix * lod.worldMatrix);
                break;
            }
        }
    }
}
