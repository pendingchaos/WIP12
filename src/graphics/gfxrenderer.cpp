#include "graphics/gfxrenderer.h"

#include "math/matrix3x3.h"
#include "graphics/gfxapi.h"
#include "graphics/camera.h"
#include "graphics/gfxframebuffer.h"
#include "graphics/gfxdebugdrawer.h"
#include "graphics/gfxbuffer.h"
#include "scene/scene.h"
#include "scene/entity.h"
#include "globals.h"

#include <cmath>

GfxRenderer::GfxRenderer(Scene *scene_) : debugDraw(false),
                                          vignetteRadius(1.5f),
                                          vignetteSoftness(1.0f),
                                          vignetteIntensity(1.0f),
                                          width(0),
                                          height(0),
                                          scene(scene_)
{
    skyboxVertex = resMgr->getResourceByFilename<GfxShader>("resources/shaders/skyboxVertex.bin");
    skyboxFragment = resMgr->getResourceByFilename<GfxShader>("resources/shaders/skyboxFragment.bin");
    skyboxMesh = resMgr->getResourceByFilename<GfxMesh>("resources/meshes/cube.bin");
    gammaCorrectionFragment = resMgr->getResourceByFilename<GfxShader>("resources/shaders/toSRGBFragment.bin");
    vignetteFragment = resMgr->getResourceByFilename<GfxShader>("resources/shaders/vignetteFragment.bin");
    fxaaFragment = resMgr->getResourceByFilename<GfxShader>("resources/shaders/fxaaFragment.bin");
    lightingDirectional = resMgr->getResourceByFilename<GfxShader>("resources/shaders/lightingDirectional.bin");
    lightingPoint = resMgr->getResourceByFilename<GfxShader>("resources/shaders/lightingPoint.bin");
    lightingSpot = resMgr->getResourceByFilename<GfxShader>("resources/shaders/lightingSpot.bin");
    ssaoFragment = resMgr->getResourceByFilename<GfxShader>("resources/shaders/ssaoFragment.bin");
    ssaoBlurXFragment = resMgr->getResourceByFilename<GfxShader>("resources/shaders/ssaoBlurXFragment.bin");
    ssaoBlurYFragment = resMgr->getResourceByFilename<GfxShader>("resources/shaders/ssaoBlurYFragment.bin");
    postEffectVertex = resMgr->getResourceByFilename<GfxShader>("resources/shaders/postEffectVertex.bin");

    compiledGammaCorrectionFragment = gammaCorrectionFragment->getCompiled();
    compiledVignetteFragment = vignetteFragment->getCompiled();
    compiledFXAAFragment = fxaaFragment->getCompiled();
    compiledLightingDirectional = lightingDirectional->getCompiled();
    compiledLightingPoint = lightingPoint->getCompiled();
    compiledLightingSpot = lightingSpot->getCompiled();
    compiledSSAOFragment = ssaoFragment->getCompiled();
    compiledSSAOBlurXFragment = ssaoBlurXFragment->getCompiled();
    compiledSSAOBlurYFragment = ssaoBlurYFragment->getCompiled();
    compiledPostEffectVertex = postEffectVertex->getCompiled();

    lightBuffer = gfxApi->createBuffer();

    static const float positionData[] = {-1.0f,  1.0f,
                                         -1.0f, -1.0f,
                                          1.0f, -1.0f,
                                         -1.0f,  1.0f,
                                          1.0f, -1.0f,
                                          1.0f,  1.0f};

    GfxBuffer *positionBuffer = gfxApi->createBuffer();
    positionBuffer->allocData(sizeof(positionData), positionData, GfxBuffer::Static);

    fullScreenQuadMesh = NEW(GfxMesh, "");
    fullScreenQuadMesh->buffers.append(positionBuffer);
    fullScreenQuadMesh->primitive = GfxTriangles;
    fullScreenQuadMesh->numVertices = 6;

    GfxMesh::VertexAttribute positionAttribute;
    positionAttribute.buffer = positionBuffer;
    positionAttribute.numComponents = 2;
    positionAttribute.type = GfxFloat;
    positionAttribute.stride = 8;
    positionAttribute.offset = 0;

    fullScreenQuadMesh->setVertexAttrib(GfxPosition, positionAttribute);

    readColorTexture = NEW(GfxTexture, "");
    writeColorTexture = NEW(GfxTexture, "");
    depthTexture = NEW(GfxTexture, "");
    materialTexture = NEW(GfxTexture, "");
    normalTexture = NEW(GfxTexture, "");
    ssaoTexture = NEW(GfxTexture, "");
    ssaoBlurXTexture = NEW(GfxTexture, "");

    resize(640);

    readFramebuffer = gfxApi->createFramebuffer();
    readFramebuffer->addColorAttachment(0, readColorTexture);
    readFramebuffer->setDepthAttachment(depthTexture);

    writeFramebuffer = gfxApi->createFramebuffer();
    writeFramebuffer->addColorAttachment(0, writeColorTexture);
    writeFramebuffer->setDepthAttachment(depthTexture);

    gBufferFramebuffer = gfxApi->createFramebuffer();
    gBufferFramebuffer->addColorAttachment(0, writeColorTexture);
    gBufferFramebuffer->addColorAttachment(1, materialTexture);
    gBufferFramebuffer->addColorAttachment(2, normalTexture);
    gBufferFramebuffer->setDepthAttachment(depthTexture);

    ssaoFramebuffer = gfxApi->createFramebuffer();
    ssaoFramebuffer->addColorAttachment(0, ssaoTexture);

    ssaoBlurXFramebuffer = gfxApi->createFramebuffer();
    ssaoBlurXFramebuffer->addColorAttachment(0, ssaoBlurXTexture);
}

GfxRenderer::~GfxRenderer()
{
    DELETE(GfxFramebuffer, readFramebuffer);
    DELETE(GfxFramebuffer, writeFramebuffer);
    DELETE(GfxFramebuffer, gBufferFramebuffer);
    DELETE(GfxFramebuffer, ssaoFramebuffer);
    DELETE(GfxFramebuffer, ssaoBlurXFramebuffer);

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
    if (size.x != width or size.y != width)
    {
        width = size.x;
        height = size.y;

        if (camera.getType() == Camera::Perspective)
        {
            camera.setWidth(width);
            camera.setHeight(height);
        }

        readColorTexture->startCreation(GfxTexture::Texture2D,
                                        false,
                                        width,
                                        height,
                                        0,
                                        GfxTexture::Other,
                                        GfxTexture::RGBF32_F16);
        readColorTexture->allocMipmap(0, 1, NULL);

        writeColorTexture->startCreation(GfxTexture::Texture2D,
                                         false,
                                         width,
                                         height,
                                         0,
                                         GfxTexture::Other,
                                         GfxTexture::RGBF32_F16);
        writeColorTexture->allocMipmap(0, 1, NULL);

        depthTexture->startCreation(GfxTexture::Texture2D,
                                    false,
                                    width,
                                    height,
                                    0,
                                    GfxTexture::Other,
                                    GfxTexture::DepthF32_F24);
        depthTexture->allocMipmap(0, 1, NULL);

        materialTexture->startCreation(GfxTexture::Texture2D,
                                       false,
                                       width,
                                       height,
                                       0,
                                       GfxTexture::Other,
                                       GfxTexture::RedGreenU8);
        materialTexture->allocMipmap(0, 1, NULL);

        normalTexture->startCreation(GfxTexture::Texture2D,
                                     false,
                                     width,
                                     height,
                                     0,
                                     GfxTexture::Other,
                                     GfxTexture::RGBF32_F16);
        normalTexture->allocMipmap(0, 1, NULL);

        ssaoTexture->startCreation(GfxTexture::Texture2D,
                                   false,
                                   width,
                                   height,
                                   0,
                                   GfxTexture::Other,
                                   GfxTexture::LuminanceU8);
        ssaoTexture->allocMipmap(0, 1, NULL);

        ssaoBlurXTexture->startCreation(GfxTexture::Texture2D,
                                        false,
                                        width,
                                        height,
                                        0,
                                        GfxTexture::Other,
                                        GfxTexture::LuminanceU8);
        ssaoBlurXTexture->allocMipmap(0, 1, NULL);
    }
}

void GfxRenderer::render()
{
    ResPtr<GfxTexture> oldReadTex = readColorTexture;
    ResPtr<GfxTexture> oldWriteTex = writeColorTexture;
    GfxFramebuffer *oldReadFb = readFramebuffer;
    GfxFramebuffer *oldWriteFb = writeFramebuffer;

    gfxApi->setViewport(0, 0, width, height);

    //G buffer
    gfxApi->setCurrentFramebuffer(gBufferFramebuffer);
    gfxApi->setWriteDepth(true);
    gfxApi->setDepthFunction(GfxLess);

    gfxApi->clearDepth();

    gfxApi->clearColor(0, Float4(0.0f));
    gfxApi->clearColor(1, Float4(0.0f));
    gfxApi->clearColor(2, Float4(0.5f, 0.5f, 0.5f, 0.0f));

    renderEntities(GfxModel::GBuffer);

    swapFramebuffers();

    gfxApi->setWriteDepth(false);
    gfxApi->setDepthFunction(GfxAlways);

    //SSAO
    //This should not mess up readColorTexture.
    gfxApi->setCurrentFramebuffer(ssaoFramebuffer);

    gfxApi->begin(compiledPostEffectVertex,
                  NULL,
                  NULL,
                  NULL,
                  compiledSSAOFragment,
                  fullScreenQuadMesh);

    gfxApi->addTextureBinding(compiledSSAOFragment, "depthTexture", depthTexture);
    gfxApi->addTextureBinding(compiledSSAOFragment, "normalTexture", normalTexture);
    gfxApi->uniform(compiledSSAOFragment, "cameraNear", camera.getNear());
    gfxApi->uniform(compiledSSAOFragment, "cameraFar", camera.getFar());
    gfxApi->uniform(compiledSSAOFragment, "normalMatrix", Matrix3x3(camera.getViewMatrix().inverse().transpose()));

    gfxApi->end(fullScreenQuadMesh->primitive,
                fullScreenQuadMesh->numVertices,
                fullScreenQuadMesh->winding);

    //SSAO Blur X
    gfxApi->setCurrentFramebuffer(ssaoBlurXFramebuffer);

    gfxApi->begin(compiledPostEffectVertex,
                  NULL,
                  NULL,
                  NULL,
                  compiledSSAOBlurXFragment,
                  fullScreenQuadMesh);

    gfxApi->addTextureBinding(compiledSSAOBlurXFragment, "aoTexture", ssaoTexture);

    gfxApi->end(fullScreenQuadMesh->primitive,
                fullScreenQuadMesh->numVertices,
                fullScreenQuadMesh->winding);

    //SSAO Blur Y
    gfxApi->setCurrentFramebuffer(ssaoFramebuffer);

    gfxApi->begin(compiledPostEffectVertex,
                  NULL,
                  NULL,
                  NULL,
                  compiledSSAOBlurYFragment,
                  fullScreenQuadMesh);

    gfxApi->addTextureBinding(compiledSSAOBlurYFragment, "aoTexture", ssaoBlurXTexture);

    gfxApi->end(fullScreenQuadMesh->primitive,
                fullScreenQuadMesh->numVertices,
                fullScreenQuadMesh->winding);

    //Lighting using the G buffer
    gfxApi->setCurrentFramebuffer(writeFramebuffer);
    gfxApi->clearColor(0, Float4(0.0f));

    Matrix4x4 viewProjection = (camera.getProjectionMatrix() * camera.getViewMatrix());

    gfxApi->setBlendingEnabled(true);
    gfxApi->setBlendFactors(GfxOne, GfxOne, GfxOne, GfxOne);
    gfxApi->setBlendMode(GfxAdd, GfxAdd);

    for (size_t i = 0; i < lights.getCount(); ++i)
    {
        const Light& light = lights[i];

        GfxCompiledShader *fragmentShader;

        switch (light.type)
        {
        case Light::Directional:
        {
            fragmentShader = compiledLightingDirectional;
            break;
        }
        case Light::Point:
        {
            fragmentShader = compiledLightingPoint;
            break;
        }
        case Light::Spot:
        {
            fragmentShader = compiledLightingSpot;
            break;
        }
        }

        gfxApi->begin(compiledPostEffectVertex,
                      NULL,
                      NULL,
                      NULL,
                      fragmentShader,
                      fullScreenQuadMesh);

        gfxApi->addTextureBinding(fragmentShader, "albedoTexture", readColorTexture);
        gfxApi->addTextureBinding(fragmentShader, "materialTexture", materialTexture);
        gfxApi->addTextureBinding(fragmentShader, "normalTexture", normalTexture);
        gfxApi->addTextureBinding(fragmentShader, "depthTexture", depthTexture);
        gfxApi->addTextureBinding(fragmentShader, "aoTexture", ssaoTexture);
        gfxApi->uniform(fragmentShader, "viewProjection", viewProjection);
        gfxApi->uniform(fragmentShader, "lightColor", light.color * light.power);
        gfxApi->uniform(fragmentShader, "cameraPosition", camera.getPosition());

        switch (light.type)
        {
        case Light::Directional:
        {
            gfxApi->uniform(fragmentShader, "lightNegDir", -light.direction.direction.normalize());
            break;
        }
        case Light::Spot:
        {
            gfxApi->uniform(fragmentShader, "lightNegDir", -light.spot.direction.normalize());
            gfxApi->uniform(fragmentShader, "lightPos", light.spot.position);
            gfxApi->uniform(fragmentShader, "lightCosInnerCutoff", (float)std::cos(RADIANS(light.spot.innerCutoff)));
            gfxApi->uniform(fragmentShader, "lightCosOuterCutoff", (float)std::cos(RADIANS(light.spot.outerCutoff)));
            gfxApi->uniform(fragmentShader, "lightRadius", light.spot.radius);
            break;
        }
        case Light::Point:
        {
            gfxApi->uniform(fragmentShader, "lightPos", light.point.position);
            gfxApi->uniform(fragmentShader, "lightRadius", light.point.radius);
            break;
        }
        }

        gfxApi->end(fullScreenQuadMesh->primitive,
                    fullScreenQuadMesh->numVertices,
                    fullScreenQuadMesh->winding);
    }

    //Forward
    gfxApi->setBlendingEnabled(false);
    gfxApi->setWriteDepth(true);
    gfxApi->setDepthFunction(GfxLessEqual);

    fillLightBuffer(scene);

    renderEntities(GfxModel::Forward);

    renderSkybox();

    if (debugDraw)
    {
        debugDrawer->render(camera);
    }

    swapFramebuffers();

    gfxApi->setWriteDepth(false);
    gfxApi->setDepthFunction(GfxAlways);

    //Vignette
    gfxApi->setCurrentFramebuffer(writeFramebuffer);

    gfxApi->begin(compiledPostEffectVertex,
                  NULL,
                  NULL,
                  NULL,
                  compiledVignetteFragment,
                  fullScreenQuadMesh);

    gfxApi->uniform(compiledVignetteFragment, "vignetteRadius", vignetteRadius);
    gfxApi->uniform(compiledVignetteFragment, "vignetteSoftness", vignetteSoftness);
    gfxApi->uniform(compiledVignetteFragment, "vignetteIntensity", vignetteIntensity);
    gfxApi->addTextureBinding(compiledVignetteFragment, "colorTexture", readColorTexture);

    gfxApi->end(fullScreenQuadMesh->primitive,
                fullScreenQuadMesh->numVertices,
                fullScreenQuadMesh->winding);

    swapFramebuffers();

    //FXAA
    gfxApi->setCurrentFramebuffer(writeFramebuffer);

    gfxApi->begin(compiledPostEffectVertex,
                  NULL,
                  NULL,
                  NULL,
                  compiledFXAAFragment,
                  fullScreenQuadMesh);

    gfxApi->addTextureBinding(compiledFXAAFragment, "colorTexture", readColorTexture);

    gfxApi->end(fullScreenQuadMesh->primitive,
                fullScreenQuadMesh->numVertices,
                fullScreenQuadMesh->winding);

    swapFramebuffers();

    //Gamma correction
    gfxApi->setCurrentFramebuffer(NULL);

    gfxApi->begin(compiledPostEffectVertex,
                  NULL,
                  NULL,
                  NULL,
                  compiledGammaCorrectionFragment,
                  fullScreenQuadMesh);

    gfxApi->addTextureBinding(compiledGammaCorrectionFragment, "colorTexture", readColorTexture);

    gfxApi->end(fullScreenQuadMesh->primitive,
                fullScreenQuadMesh->numVertices,
                fullScreenQuadMesh->winding);

    readColorTexture = oldReadTex;
    writeColorTexture = oldWriteTex;
    readFramebuffer = oldReadFb;
    writeFramebuffer = oldWriteFb;
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

void GfxRenderer::renderEntities(GfxModel::ContextType contextType)
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
                renderModel(contextType, camera, transform, comp->model);
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

void GfxRenderer::swapFramebuffers()
{
    std::swap(writeFramebuffer, readFramebuffer);
    std::swap(writeColorTexture, readColorTexture);
}
