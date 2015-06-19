#include "graphics/gfxrenderer.h"

#include "math/matrix3x3.h"
#include "graphics/gfxapi.h"
#include "graphics/camera.h"
#include "graphics/gfxframebuffer.h"
#include "graphics/gfxdebugdrawer.h"
#include "graphics/gfxbuffer.h"
#include "graphics/gputimer.h"
#include "scene/scene.h"
#include "scene/entity.h"
#include "globals.h"
#include "logging.h"

#include <cmath>

float gauss(float x, float sigma)
{
    return (1.0 / (sigma*std::sqrt(2.0*3.141529))) *
           std::exp(-(x*x) / (2.0*sigma*sigma));
}

GfxRenderer::GfxRenderer(Scene *scene_) : debugDraw(false),
                                          vignetteRadius(1.5f),
                                          vignetteSoftness(1.0f),
                                          vignetteIntensity(0.0f),
                                          bloomThreshold(1.0f),
                                          bloomRadius(0.025f),
                                          bloomQuality(0.9f),
                                          bloomEnabled(true),
                                          ssaoRadius(0.1f),
                                          stats({0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}),
                                          width(0),
                                          height(0),
                                          scene(scene_),
                                          //averageLuminance(0.0f),
                                          numLights(0)
{
    skyboxVertex = resMgr->getResource<GfxShader>("resources/shaders/skyboxVertex.bin");
    skyboxFragment = resMgr->getResource<GfxShader>("resources/shaders/skyboxFragment.bin");
    skyboxMesh = resMgr->getResource<GfxMesh>("resources/meshes/cube.bin");
    gammaCorrectionFragment = resMgr->getResource<GfxShader>("resources/shaders/toSRGBFragment.bin");
    vignetteFragment = resMgr->getResource<GfxShader>("resources/shaders/vignetteFragment.bin");
    fxaaFragment = resMgr->getResource<GfxShader>("resources/shaders/fxaaFragment.bin");
    lightingDirectional = resMgr->getResource<GfxShader>("resources/shaders/lightingDirectional.bin");
    lightingPoint = resMgr->getResource<GfxShader>("resources/shaders/lightingPoint.bin");
    lightingSpot = resMgr->getResource<GfxShader>("resources/shaders/lightingSpot.bin");
    ssaoFragment = resMgr->getResource<GfxShader>("resources/shaders/ssaoFragment.bin");
    ssaoBlurXFragment = resMgr->getResource<GfxShader>("resources/shaders/ssaoBlurXFragment.bin");
    ssaoBlurYFragment = resMgr->getResource<GfxShader>("resources/shaders/ssaoBlurYFragment.bin");
    bloomBlurXFragment = resMgr->getResource<GfxShader>("resources/shaders/bloomBlurXFragment.bin");
    bloomBlurYFragment = resMgr->getResource<GfxShader>("resources/shaders/bloomBlurYFragment.bin");
    lumCalcFragment = resMgr->getResource<GfxShader>("resources/shaders/lumCalcFragment.bin");
    tonemapFragment = resMgr->getResource<GfxShader>("resources/shaders/tonemapFragment.bin");
    postEffectVertex = resMgr->getResource<GfxShader>("resources/shaders/postEffectVertex.bin");
    shadowmapVertex = resMgr->getResource<GfxShader>("resources/shaders/shadowmapVertex.bin");
    shadowmapFragment = resMgr->getResource<GfxShader>("resources/shaders/shadowmapFragment.bin");
    overlayVertex = resMgr->getResource<GfxShader>("resources/shaders/overlayVertex.bin");
    overlayFragment = resMgr->getResource<GfxShader>("resources/shaders/overlayFragment.bin");

    compiledGammaCorrectionFragment = gammaCorrectionFragment->getCompiled();
    compiledVignetteFragment = vignetteFragment->getCompiled();
    compiledFXAAFragment = fxaaFragment->getCompiled();
    compiledLightingDirectional = lightingDirectional->getCompiled();
    compiledLightingPoint = lightingPoint->getCompiled();
    compiledLightingSpot = lightingSpot->getCompiled();
    compiledLightingSpotShadow = lightingSpot->getCompiled(HashMapBuilder<String, String>().add("SHADOW_MAP", "1"));
    compiledSSAOFragment = ssaoFragment->getCompiled();
    compiledSSAOBlurXFragment = ssaoBlurXFragment->getCompiled();
    compiledSSAOBlurYFragment = ssaoBlurYFragment->getCompiled();
    compiledBloomBlurXFragment = bloomBlurXFragment->getCompiled();
    compiledBloomBlurYFragment = bloomBlurYFragment->getCompiled();
    compiledLumCalcFragment = lumCalcFragment->getCompiled();
    compiledTonemapFragment = tonemapFragment->getCompiled();
    compiledPostEffectVertex = postEffectVertex->getCompiled();
    compiledShadowmapVertex = shadowmapVertex->getCompiled();
    compiledShadowmapFragment = shadowmapFragment->getCompiled();
    compiledOverlayVertex = overlayVertex->getCompiled();
    compiledOverlayFragment = overlayFragment->getCompiled();

    lightBuffer = gfxApi->createBuffer();

    static const float positionData[] = {-1.0f,  1.0f,
                                         -1.0f, -1.0f,
                                          1.0f, -1.0f,
                                         -1.0f,  1.0f,
                                          1.0f, -1.0f,
                                          1.0f,  1.0f};

    GfxBuffer *positionBuffer = gfxApi->createBuffer();
    positionBuffer->allocData(sizeof(positionData), positionData, GfxBuffer::Static);

    quadMesh = NEW(GfxMesh);
    quadMesh->buffers.append(positionBuffer);
    quadMesh->primitive = GfxTriangles;
    quadMesh->numVertices = 6;

    GfxMesh::VertexAttribute positionAttribute;
    positionAttribute.buffer = positionBuffer;
    positionAttribute.numComponents = 2;
    positionAttribute.type = GfxFloat;
    positionAttribute.stride = 8;
    positionAttribute.offset = 0;

    quadMesh->setVertexAttrib(GfxPosition, positionAttribute);

    readColorTexture = NEW(GfxTexture);
    writeColorTexture = NEW(GfxTexture);
    depthTexture = NEW(GfxTexture);
    materialTexture = NEW(GfxTexture);
    normalTexture = NEW(GfxTexture);
    ssaoTexture = NEW(GfxTexture);
    ssaoBlurXTexture = NEW(GfxTexture);
    bloomBlurXTexture = NEW(GfxTexture);
    //luminanceTexture = NEW(GfxTexture);
    ssaoRandomTexture = NEW(GfxTexture);

    readColorTexture->setWrapMode(GfxTexture::Stretch);
    writeColorTexture->setWrapMode(GfxTexture::Stretch);
    depthTexture->setWrapMode(GfxTexture::Stretch);
    materialTexture->setWrapMode(GfxTexture::Stretch);
    normalTexture->setWrapMode(GfxTexture::Stretch);
    ssaoTexture->setWrapMode(GfxTexture::Stretch);
    ssaoBlurXTexture->setWrapMode(GfxTexture::Stretch);
    bloomBlurXTexture->setWrapMode(GfxTexture::Stretch);
    //luminanceTexture->setWrapMode(GfxTexture::Stretch);

    resize(640);

    ssaoRandomTexture->startCreation(GfxTexture::Texture2D,
                                     false,
                                     4,
                                     4,
                                     1,
                                     0,
                                     GfxTexture::Other,
                                     GfxTexture::RedGreenF32_F16);

    static const float randomVecs[] = {-0.99f, -0.15f,
                                       -0.5f, 0.87f,
                                       0.97f, -0.24f,
                                       0.65f, 0.76f,
                                       -0.81f, 0.59f,
                                       0.9f, -0.44f,
                                       -1.0f, 0.07f,
                                       0.79f, 0.61f,
                                       0.20f, -0.98f,
                                       0.93f, -0.36f,
                                       0.99f, -0.15f,
                                       -0.74f, -0.67f,
                                       0.87f, 0.49f,
                                       0.71f, -0.7f,
                                       -0.66f, -0.75f,
                                       -1.0f, 0.07f};

    ssaoRandomTexture->allocMipmap(0, 1, randomVecs);

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

    bloomblurXFramebuffer = gfxApi->createFramebuffer();
    bloomblurXFramebuffer->addColorAttachment(0, bloomBlurXTexture);

    /*luminanceFramebuffer = gfxApi->createFramebuffer();
    luminanceFramebuffer->addColorAttachment(0, luminanceTexture);*/

    gBufferTimer = gfxApi->createTimer();
    ssaoTimer = gfxApi->createTimer();
    ssaoBlurXTimer = gfxApi->createTimer();
    ssaoBlurYTimer = gfxApi->createTimer();
    deferredShadingTimer = gfxApi->createTimer();
    forwardTimer = gfxApi->createTimer();
    gammaCorrectionTimer = gfxApi->createTimer();
    fxaaTimer = gfxApi->createTimer();
    vignetteTimer = gfxApi->createTimer();
    bloomXTimer = gfxApi->createTimer();
    bloomYTimer = gfxApi->createTimer();
    //luminanceCalcTimer = gfxApi->createTimer();
    tonemappingTimer = gfxApi->createTimer();
    shadowmapTimer = gfxApi->createTimer();
    overlayTimer = gfxApi->createTimer();
}

GfxRenderer::~GfxRenderer()
{
    DELETE(GPUTimer, gBufferTimer);
    DELETE(GPUTimer, ssaoTimer);
    DELETE(GPUTimer, ssaoBlurXTimer);
    DELETE(GPUTimer, ssaoBlurYTimer);
    DELETE(GPUTimer, deferredShadingTimer);
    DELETE(GPUTimer, forwardTimer);
    DELETE(GPUTimer, gammaCorrectionTimer);
    DELETE(GPUTimer, fxaaTimer);
    DELETE(GPUTimer, vignetteTimer);
    DELETE(GPUTimer, bloomXTimer);
    DELETE(GPUTimer, bloomYTimer);
    //DELETE(GPUTimer, luminanceCalcTimer);
    DELETE(GPUTimer, tonemappingTimer);
    DELETE(GPUTimer, shadowmapTimer);
    DELETE(GPUTimer, overlayTimer);

    DELETE(GfxFramebuffer, readFramebuffer);
    DELETE(GfxFramebuffer, writeFramebuffer);
    DELETE(GfxFramebuffer, gBufferFramebuffer);
    DELETE(GfxFramebuffer, ssaoFramebuffer);
    DELETE(GfxFramebuffer, ssaoBlurXFramebuffer);
    DELETE(GfxFramebuffer, bloomblurXFramebuffer);
    //DELETE(GfxFramebuffer, luminanceFramebuffer);

    DELETE(GfxBuffer, lightBuffer);
}

void GfxRenderer::updateStats()
{
    if (gBufferTimer->resultAvailable())
    {
        stats.gBufferTiming = gBufferTimer->getResult() / (float)gBufferTimer->getResultResolution();
    }

    if (ssaoTimer->resultAvailable())
    {
        stats.ssaoTiming = ssaoTimer->getResult() / (float)ssaoTimer->getResultResolution();
    }

    if (ssaoBlurXTimer->resultAvailable())
    {
        stats.ssaoBlurXTiming = ssaoBlurXTimer->getResult() / (float)ssaoBlurXTimer->getResultResolution();
    }

    if (ssaoBlurYTimer->resultAvailable())
    {
        stats.ssaoBlurYTiming = ssaoBlurYTimer->getResult() / (float)ssaoBlurYTimer->getResultResolution();
    }

    if (deferredShadingTimer->resultAvailable())
    {
        stats.deferredShadingTiming = deferredShadingTimer->getResult() / (float)deferredShadingTimer->getResultResolution();
    }

    if (forwardTimer->resultAvailable())
    {
        stats.forwardTiming = forwardTimer->getResult() / (float)forwardTimer->getResultResolution();
    }

    if (gammaCorrectionTimer->resultAvailable())
    {
        stats.gammaCorrectionTiming = gammaCorrectionTimer->getResult() / (float)gammaCorrectionTimer->getResultResolution();
    }

    if (fxaaTimer->resultAvailable())
    {
        stats.fxaaTiming = fxaaTimer->getResult() / (float)fxaaTimer->getResultResolution();
    }

    if (vignetteTimer->resultAvailable())
    {
        stats.vignetteTiming = vignetteTimer->getResult() / (float)vignetteTimer->getResultResolution();
    }

    if (bloomXTimer->resultAvailable())
    {
        stats.bloomXTiming = bloomXTimer->getResult() / (float)bloomXTimer->getResultResolution();
    }

    if (bloomYTimer->resultAvailable())
    {
        stats.bloomYTiming = bloomYTimer->getResult() / (float)bloomYTimer->getResultResolution();
    }

    /*if (luminanceCalcTimer->resultAvailable())
    {
        stats.lumCalcTiming = luminanceCalcTimer->getResult() / (float)luminanceCalcTimer->getResultResolution();
    }*/

    if (tonemappingTimer->resultAvailable())
    {
        stats.tonemappingTiming = tonemappingTimer->getResult() / (float)tonemappingTimer->getResultResolution();
    }

    if (shadowmapTimer->resultAvailable())
    {
        stats.shadowmapTiming = shadowmapTimer->getResult() / (float)shadowmapTimer->getResultResolution();
    }

    if (overlayTimer->resultAvailable())
    {
        stats.overlayTiming = overlayTimer->getResult() / (float)overlayTimer->getResultResolution();
    }
}

void GfxRenderer::beginRenderMesh(const Camera& camera,
                                  const Matrix4x4& worldMatrix,
                                  ResPtr<GfxMesh> mesh,
                                  GfxShaderCombination *comb)
{
    gfxApi->pushState();

    gfxApi->setCullMode(mesh->cullMode);

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

    gfxApi->popState();
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
                                        1,
                                        0,
                                        GfxTexture::Other,
                                        GfxTexture::RGBF32_F16);
        readColorTexture->allocMipmap(0, 1, NULL);

        writeColorTexture->startCreation(GfxTexture::Texture2D,
                                         false,
                                         width,
                                         height,
                                         1,
                                         0,
                                         GfxTexture::Other,
                                         GfxTexture::RGBF32_F16);
        writeColorTexture->allocMipmap(0, 1, NULL);

        depthTexture->startCreation(GfxTexture::Texture2D,
                                    false,
                                    width,
                                    height,
                                    1,
                                    0,
                                    GfxTexture::Other,
                                    GfxTexture::DepthF32_F24);
        depthTexture->allocMipmap(0, 1, NULL);

        materialTexture->startCreation(GfxTexture::Texture2D,
                                       false,
                                       width,
                                       height,
                                       1,
                                       0,
                                       GfxTexture::Other,
                                       GfxTexture::RedGreenU8);
        materialTexture->allocMipmap(0, 1, NULL);

        normalTexture->startCreation(GfxTexture::Texture2D,
                                     false,
                                     width,
                                     height,
                                     1,
                                     0,
                                     GfxTexture::Other,
                                     GfxTexture::RGBF32_F16);
        normalTexture->allocMipmap(0, 1, NULL);

        ssaoTexture->startCreation(GfxTexture::Texture2D,
                                   false,
                                   width,
                                   height,
                                   1,
                                   0,
                                   GfxTexture::Other,
                                   GfxTexture::LuminanceU8);
        ssaoTexture->allocMipmap(0, 1, NULL);

        ssaoBlurXTexture->startCreation(GfxTexture::Texture2D,
                                        false,
                                        width,
                                        height,
                                        1,
                                        0,
                                        GfxTexture::Other,
                                        GfxTexture::LuminanceU8);
        ssaoBlurXTexture->allocMipmap(0, 1, NULL);

        bloomBlurXTexture->startCreation(GfxTexture::Texture2D,
                                         false,
                                         width,
                                         height,
                                         1,
                                         0,
                                         GfxTexture::Other,
                                         GfxTexture::RGBF32_F16);
        bloomBlurXTexture->allocMipmap(0, 1, NULL);

        /*luminanceTexture->startCreation(GfxTexture::Texture2D,
                                        false,
                                        width,
                                        height,
                                        0,
                                        GfxTexture::Other,
                                        GfxTexture::RedF32_F16);
        luminanceTexture->allocMipmap(0, 1, NULL);*/
    }
}

void GfxRenderer::render()
{
    ResPtr<GfxTexture> oldReadTex = readColorTexture;
    ResPtr<GfxTexture> oldWriteTex = writeColorTexture;
    GfxFramebuffer *oldReadFb = readFramebuffer;
    GfxFramebuffer *oldWriteFb = writeFramebuffer;

    //Shadowmaps
    shadowmapTimer->begin();

    for (size_t i = 0; i < lights.getCount(); ++i)
    {
        Light *light = lights[i];

        if (light->getShadowmap() == nullptr)
        {
            continue;
        }

        renderShadowmap(light);
    }

    shadowmapTimer->end();

    //G buffer
    gfxApi->setViewport(0, 0, width, height);
    gfxApi->setWriteDepth(true);
    gfxApi->setDepthFunction(GfxLess);

    gBufferTimer->begin();

    gfxApi->setCurrentFramebuffer(gBufferFramebuffer);

    gfxApi->clearDepth();

    gfxApi->clearColor(0, Float4(0.0f));
    gfxApi->clearColor(1, Float4(0.0f));
    gfxApi->clearColor(2, Float4(0.5f, 0.5f, 0.5f, 0.0f));

    renderEntities(false);

    swapFramebuffers();

    gfxApi->setWriteDepth(false);
    gfxApi->setDepthFunction(GfxAlways);

    gBufferTimer->end();

    //SSAO
    //This should not mess up readColorTexture.
    ssaoTimer->begin();

    gfxApi->setCurrentFramebuffer(ssaoFramebuffer);

    gfxApi->begin(compiledPostEffectVertex,
                  NULL,
                  NULL,
                  NULL,
                  compiledSSAOFragment,
                  quadMesh);

    gfxApi->addTextureBinding(compiledSSAOFragment, "depthTexture", depthTexture);
    gfxApi->addTextureBinding(compiledSSAOFragment, "normalTexture", normalTexture);
    gfxApi->uniform(compiledSSAOFragment, "cameraNear", camera.getNear());
    gfxApi->uniform(compiledSSAOFragment, "cameraFar", camera.getFar());
    gfxApi->uniform(compiledSSAOFragment, "normalMatrix", Matrix3x3(camera.getViewMatrix().inverse().transpose()));
    gfxApi->uniform(compiledSSAOFragment, "radius", ssaoRadius);
    gfxApi->addTextureBinding(compiledSSAOFragment, "randomTex", ssaoRandomTexture);

    gfxApi->end(quadMesh->primitive,
                quadMesh->numVertices,
                quadMesh->winding);

    ssaoTimer->end();

    //SSAO Blur X
    ssaoBlurXTimer->begin();

    gfxApi->setCurrentFramebuffer(ssaoBlurXFramebuffer);

    gfxApi->begin(compiledPostEffectVertex,
                  NULL,
                  NULL,
                  NULL,
                  compiledSSAOBlurXFragment,
                  quadMesh);

    gfxApi->addTextureBinding(compiledSSAOBlurXFragment, "aoTexture", ssaoTexture);

    gfxApi->end(quadMesh->primitive,
                quadMesh->numVertices,
                quadMesh->winding);

    ssaoBlurXTimer->end();

    //SSAO Blur Y
    ssaoBlurYTimer->begin();

    gfxApi->setCurrentFramebuffer(ssaoFramebuffer);

    gfxApi->begin(compiledPostEffectVertex,
                  NULL,
                  NULL,
                  NULL,
                  compiledSSAOBlurYFragment,
                  quadMesh);

    gfxApi->addTextureBinding(compiledSSAOBlurYFragment, "aoTexture", ssaoBlurXTexture);

    gfxApi->end(quadMesh->primitive,
                quadMesh->numVertices,
                quadMesh->winding);

    ssaoBlurYTimer->end();

    //Lighting using the G buffer
    deferredShadingTimer->begin();

    gfxApi->setCurrentFramebuffer(writeFramebuffer);
    gfxApi->clearColor(0, Float4(0.0f));

    Matrix4x4 viewProjection = (camera.getProjectionMatrix() * camera.getViewMatrix());

    gfxApi->setBlendingEnabled(true);
    gfxApi->setBlendFactors(GfxOne, GfxOne, GfxOne, GfxOne);
    gfxApi->setBlendMode(GfxAdd, GfxAdd);

    for (size_t i = 0; i < lights.getCount(); ++i)
    {
        Light *light = lights[i];

        GfxCompiledShader *fragmentShader;

        switch (light->type)
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
            if (light->getShadowmap() != nullptr)
            {
                fragmentShader = compiledLightingSpotShadow;
            } else
            {
                fragmentShader = compiledLightingSpot;
            }
            break;
        }
        }

        gfxApi->begin(compiledPostEffectVertex,
                      NULL,
                      NULL,
                      NULL,
                      fragmentShader,
                      quadMesh);

        gfxApi->addTextureBinding(fragmentShader, "albedoTexture", readColorTexture);
        gfxApi->addTextureBinding(fragmentShader, "materialTexture", materialTexture);
        gfxApi->addTextureBinding(fragmentShader, "normalTexture", normalTexture);
        gfxApi->addTextureBinding(fragmentShader, "depthTexture", depthTexture);
        gfxApi->addTextureBinding(fragmentShader, "aoTexture", ssaoTexture);
        gfxApi->uniform(fragmentShader, "viewProjection", viewProjection);
        gfxApi->uniform(fragmentShader, "lightColor", light->color * light->power);
        gfxApi->uniform(fragmentShader, "cameraPosition", camera.getPosition());

        if (light->getShadowmap() != nullptr)
        {
            gfxApi->addTextureBinding(fragmentShader, "shadowmap", light->getShadowmap());
            gfxApi->uniform(fragmentShader, "shadowmapViewMatrix", light->getViewMatrix());
            gfxApi->uniform(fragmentShader, "shadowmapProjectionMatrix", light->getProjectionMatrix());
            gfxApi->uniform(fragmentShader, "shadowMinBias", light->shadowMinBias);
            gfxApi->uniform(fragmentShader, "shadowBiasScale", light->shadowBiasScale);
        }

        switch (light->type)
        {
        case Light::Directional:
        {
            gfxApi->uniform(fragmentShader, "lightNegDir", -light->direction.direction.normalize());
            break;
        }
        case Light::Spot:
        {
            gfxApi->uniform(fragmentShader, "lightNegDir", -light->spot.direction.normalize());
            gfxApi->uniform(fragmentShader, "lightPos", light->spot.position);
            gfxApi->uniform(fragmentShader, "lightCosInnerCutoff", (float)std::cos(RADIANS(light->spot.innerCutoff)));
            gfxApi->uniform(fragmentShader, "lightCosOuterCutoff", (float)std::cos(RADIANS(light->spot.outerCutoff)));
            gfxApi->uniform(fragmentShader, "lightRadius", light->spot.radius);
            break;
        }
        case Light::Point:
        {
            gfxApi->uniform(fragmentShader, "lightPos", light->point.position);
            gfxApi->uniform(fragmentShader, "lightRadius", light->point.radius);
            break;
        }
        }

        gfxApi->end(quadMesh->primitive,
                    quadMesh->numVertices,
                    quadMesh->winding);
    }

    deferredShadingTimer->end();

    gfxApi->setBlendingEnabled(false);

    //Forward
    forwardTimer->begin();

    gfxApi->setWriteDepth(true);
    gfxApi->setDepthFunction(GfxLessEqual);

    fillLightBuffer(scene);

    renderEntities(true);

    renderSkybox();

    if (debugDraw)
    {
        debugDrawer->render(camera);
    }

    gfxApi->setWriteDepth(false);
    gfxApi->setDepthFunction(GfxAlways);

    forwardTimer->end();

    swapFramebuffers();

    //Luminance calculation.
    /*luminanceCalcTimer->begin();

    gfxApi->setCurrentFramebuffer(luminanceFramebuffer);

    gfxApi->begin(compiledPostEffectVertex,
                  NULL,
                  NULL,
                  NULL,
                  compiledLumCalcFragment,
                  quadMesh);

    gfxApi->addTextureBinding(compiledLumCalcFragment, "colorTexture", writeColorTexture);

    gfxApi->end(quadMesh->primitive,
                quadMesh->numVertices,
                quadMesh->winding);

    luminanceTexture->generateMipmaps();

    size_t lumMipmapLevel = 0;
    size_t lumWidth = TEX_COMPUTE_MIPMAP_SIZE(width, lumMipmapLevel);
    size_t lumHeight = TEX_COMPUTE_MIPMAP_SIZE(height, lumMipmapLevel);

    while (lumWidth != 1 and lumHeight != 1)
    {
        lumWidth /= 2;
        lumHeight /= 2;
        ++lumMipmapLevel;
    }

    float *lums = NEW_ARRAY(float, lumWidth*lumHeight);

    luminanceTexture->getMipmap(lumMipmapLevel, 1, lums);

    averageLuminance = 0.0f;

    for (size_t x = 0; x < lumWidth; ++x)
    {
        for(size_t y = 0; y < lumHeight; ++y)
        {
            averageLuminance += lums[y*lumWidth+x];
        }
    }

    DELETE_ARRAY(float, lums);

    averageLuminance /= lumWidth * lumHeight;

    averageLuminance = std::max(std::exp(averageLuminance), 0.001f);

    luminanceCalcTimer->end();*/

    if (bloomEnabled)
    {
        //Bloom X
        bloomXTimer->begin();

        uint32_t bloomRadiusPixels = uint32_t(std::min(width, height)*bloomRadius);
        float bloomDivisor = 0.0;
        float bloomSigma = bloomRadiusPixels / 3.0f;
        float bloomStep = bloomRadiusPixels / (bloomQuality * bloomRadiusPixels);

        for (float i = -(float)bloomRadiusPixels; i < (float)bloomRadiusPixels+1; i += bloomStep)
        {
            bloomDivisor += gauss(i, bloomSigma);
        }

        gfxApi->setCurrentFramebuffer(bloomblurXFramebuffer);

        gfxApi->begin(compiledPostEffectVertex,
                      NULL,
                      NULL,
                      NULL,
                      compiledBloomBlurXFragment,
                      quadMesh);

        gfxApi->addTextureBinding(compiledBloomBlurXFragment, "colorTexture", readColorTexture);
        gfxApi->uniform(compiledBloomBlurXFragment, "threshold", bloomThreshold);
        gfxApi->uniform(compiledBloomBlurXFragment, "radius", (int32_t)bloomRadiusPixels);
        gfxApi->uniform(compiledBloomBlurXFragment, "divisor", bloomDivisor);
        gfxApi->uniform(compiledBloomBlurXFragment, "sigma", bloomSigma);
        gfxApi->uniform(compiledBloomBlurXFragment, "step", bloomStep);

        gfxApi->end(quadMesh->primitive,
                    quadMesh->numVertices,
                    quadMesh->winding);

        bloomXTimer->end();

        //Bloom Y
        bloomYTimer->begin();

        gfxApi->setCurrentFramebuffer(writeFramebuffer);

        gfxApi->begin(compiledPostEffectVertex,
                      NULL,
                      NULL,
                      NULL,
                      compiledBloomBlurYFragment,
                      quadMesh);

        gfxApi->addTextureBinding(compiledBloomBlurYFragment, "colorTexture", readColorTexture);
        gfxApi->addTextureBinding(compiledBloomBlurYFragment, "bloomTexture", bloomBlurXTexture);
        gfxApi->uniform(compiledBloomBlurYFragment, "radius", (int32_t)bloomRadiusPixels);
        gfxApi->uniform(compiledBloomBlurYFragment, "divisor", bloomDivisor);
        gfxApi->uniform(compiledBloomBlurYFragment, "sigma", bloomSigma);
        gfxApi->uniform(compiledBloomBlurYFragment, "step", bloomStep);

        gfxApi->end(quadMesh->primitive,
                    quadMesh->numVertices,
                    quadMesh->winding);

        swapFramebuffers();

        bloomYTimer->end();
    }

    //Tonemapping
    tonemappingTimer->begin();

    gfxApi->setCurrentFramebuffer(writeFramebuffer);

    gfxApi->begin(compiledPostEffectVertex,
                  NULL,
                  NULL,
                  NULL,
                  compiledTonemapFragment,
                  quadMesh);

    gfxApi->addTextureBinding(compiledTonemapFragment, "colorTexture", readColorTexture);

    gfxApi->end(quadMesh->primitive,
                quadMesh->numVertices,
                quadMesh->winding);

    tonemappingTimer->end();

    swapFramebuffers();

    //Vignette
    vignetteTimer->begin();

    gfxApi->setCurrentFramebuffer(writeFramebuffer);

    gfxApi->begin(compiledPostEffectVertex,
                  NULL,
                  NULL,
                  NULL,
                  compiledVignetteFragment,
                  quadMesh);

    gfxApi->uniform(compiledVignetteFragment, "vignetteRadius", vignetteRadius);
    gfxApi->uniform(compiledVignetteFragment, "vignetteSoftness", vignetteSoftness);
    gfxApi->uniform(compiledVignetteFragment, "vignetteIntensity", vignetteIntensity);
    gfxApi->addTextureBinding(compiledVignetteFragment, "colorTexture", readColorTexture);

    gfxApi->end(quadMesh->primitive,
                quadMesh->numVertices,
                quadMesh->winding);

    swapFramebuffers();

    vignetteTimer->end();

    //FXAA
    fxaaTimer->begin();

    gfxApi->setCurrentFramebuffer(writeFramebuffer);

    gfxApi->begin(compiledPostEffectVertex,
                  NULL,
                  NULL,
                  NULL,
                  compiledFXAAFragment,
                  quadMesh);

    gfxApi->addTextureBinding(compiledFXAAFragment, "colorTexture", readColorTexture);

    gfxApi->end(quadMesh->primitive,
                quadMesh->numVertices,
                quadMesh->winding);

    fxaaTimer->end();

    //Overlays
    overlayTimer->begin();

    const List<Entity *>& entities = scene->getEntities();

    for (size_t i = 0; i < entities.getCount(); ++i)
    {
        const Entity *entity = entities[i];

        Matrix4x4 transform = entity->transform.createMatrix();

        if (entity->hasRenderComponent())
        {
            const RenderComponent *comp = entity->getRenderComponent();

            switch (comp->type)
            {
            case RenderComponent::Overlay:
            {
                gfxApi->begin(compiledOverlayVertex,
                              NULL,
                              NULL,
                              NULL,
                              compiledOverlayFragment,
                              quadMesh);

                gfxApi->uniform(compiledOverlayVertex, "transform", transform);
                gfxApi->uniform(compiledOverlayFragment, "color", comp->overlayData.color);
                gfxApi->addTextureBinding(compiledOverlayFragment, "colorTexture", comp->overlayTexture);

                gfxApi->end(quadMesh->primitive,
                            quadMesh->numVertices,
                            quadMesh->winding);
                break;
            }
            default:
            {
                break;
            }
            }
        }
    }

    swapFramebuffers();

    overlayTimer->end();

    //Gamma correction
    gammaCorrectionTimer->begin();

    gfxApi->setCurrentFramebuffer(NULL);

    gfxApi->begin(compiledPostEffectVertex,
                  NULL,
                  NULL,
                  NULL,
                  compiledGammaCorrectionFragment,
                  quadMesh);

    gfxApi->addTextureBinding(compiledGammaCorrectionFragment, "colorTexture", readColorTexture);

    gfxApi->end(quadMesh->primitive,
                quadMesh->numVertices,
                quadMesh->winding);

    gammaCorrectionTimer->end();

    readColorTexture = oldReadTex;
    writeColorTexture = oldWriteTex;
    readFramebuffer = oldReadFb;
    writeFramebuffer = oldWriteFb;

    updateStats();
}

void GfxRenderer::fillLightBuffer(ResPtr<Scene> scene)
{
    numLights = lights.getCount();

    float *lightData = NEW_ARRAY(float, numLights * 16);

    for (size_t i = 0; i < numLights; ++i)
    {
        const Light *light = lights[i];

        lightData[i*16  ] = light->color.x * light->power;
        lightData[i*16+1] = light->color.y * light->power;
        lightData[i*16+2] = light->color.z * light->power;

        switch (light->type)
        {
        case Light::Directional:
        {
            Vector3D dir = -light->direction.direction.normalize();

            lightData[i*16+3] = dir.x;
            lightData[i*16+4] = dir.y;
            lightData[i*16+5] = dir.z;
            lightData[i*16+11] = 0.0;
            break;
        }
        case Light::Spot:
        {
            Vector3D dir = -light->spot.direction.normalize();

            lightData[i*16+3] = light->spot.position.x;
            lightData[i*16+4] = light->spot.position.y;
            lightData[i*16+5] = light->spot.position.z;
            lightData[i*16+6] = dir.x;
            lightData[i*16+7] = dir.y;
            lightData[i*16+8] = dir.z;
            lightData[i*16+9] = std::cos(RADIANS(light->spot.innerCutoff));
            lightData[i*16+10] = std::cos(RADIANS(light->spot.outerCutoff));
            lightData[i*16+11] = 1.0;
            lightData[i*16+12] = light->spot.radius;
            break;
        }
        case Light::Point:
        {
            lightData[i*16+3] = light->point.position.x;
            lightData[i*16+4] = light->point.position.y;
            lightData[i*16+5] = light->point.position.z;
            lightData[i*16+11] = 2.0;
            lightData[i*16+12] = light->point.radius;
            break;
        }
        }
    }

    lightBuffer->allocData(numLights*64, lightData, GfxBuffer::Dynamic);

    DELETE_ARRAY(float, lightData);
}

void GfxRenderer::renderEntities(bool forward)
{
    const List<Entity *>& entities = scene->getEntities();

    for (size_t i = 0; i < entities.getCount(); ++i)
    {
        const Entity *entity = entities[i];

        Matrix4x4 transform = entity->transform.createMatrix();


        if (entity->hasRenderComponent())
        {
            const RenderComponent *comp = entity->getRenderComponent();

            switch (comp->type)
            {
            case RenderComponent::Model:
            {
                renderModel(forward, camera, transform, comp->model);
                break;
            }
            default:
            {
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

void GfxRenderer::renderModel(bool forward,
                              const Camera& camera,
                              const Matrix4x4& worldMatrix,
                              const ResPtr<GfxModel> model)
{
    Position3D position = Position3D(worldMatrix[0][3],
                                     worldMatrix[1][3],
                                     worldMatrix[2][3]);

    float distance = position.distance(camera.getPosition());

    for (size_t i = 0; i < model->subModels.getCount(); ++i)
    {
        GfxModel::SubModel subModel = model->subModels[i];

        for (size_t j = 0; j < subModel.getCount(); ++j)
        {
            const GfxModel::LOD& lod = subModel[j];

            if (lod.minDistance < distance and
                distance < lod.maxDistance and
                lod.material->isForward() == forward)
            {
                ResPtr<GfxMaterial> material = lod.material;
                GfxShaderCombination *shaderComb = material->getShaderComb();
                GfxCompiledShader *fragment = shaderComb->getCompiledFragmentShader();

                beginRenderMesh(camera, worldMatrix, lod.mesh, shaderComb);

                gfxApi->uniform(fragment, "smoothness", lod.material->smoothness);
                gfxApi->uniform(fragment, "metalMask", lod.material->metalMask);
                gfxApi->uniform(fragment, "albedo", lod.material->albedo);

                if (lod.material->isForward())
                {
                    gfxApi->uniform(fragment, "numLights", (uint32_t)lights.getCount());
                    gfxApi->addUBOBinding(fragment, "lights_", lightBuffer);
                }

                if (material->getSmoothnessMap() != nullptr)
                {
                    gfxApi->addTextureBinding(fragment, "smoothnessMap", material->getSmoothnessMap());
                }

                if (material->getMetalMaskMap() != nullptr)
                {
                    gfxApi->addTextureBinding(fragment, "metalMaskMap", material->getMetalMaskMap());
                }

                if (material->getAlbedoMap() != nullptr)
                {
                    gfxApi->addTextureBinding(fragment, "albedoMap", material->getAlbedoMap());
                }

                if (material->getNormalMap() != nullptr)
                {
                    gfxApi->addTextureBinding(fragment, "normalMap", material->getNormalMap());
                }

                endRenderMesh(lod.mesh);
                break;
            }
        }
    }
}

void GfxRenderer::renderModelToShadowmap(const Matrix4x4& viewMatrix,
                                         const Matrix4x4& projectionMatrix,
                                         const Matrix4x4& worldMatrix,
                                         const ResPtr<GfxModel> model)
{
    Position3D position = Position3D(worldMatrix[0][3],
                                     worldMatrix[1][3],
                                     worldMatrix[2][3]);

    float distance = position.distance(camera.getPosition());

    for (size_t i = 0; i < model->subModels.getCount(); ++i)
    {
        GfxModel::SubModel subModel = model->subModels[i];

        for (size_t j = 0; j < subModel.getCount(); ++j)
        {
            const GfxModel::LOD& lod = subModel[j];

            if (lod.minDistance < distance and distance < lod.maxDistance)
            {
                ResPtr<GfxMesh> mesh = lod.mesh;

                gfxApi->begin(compiledShadowmapVertex,
                              nullptr,
                              nullptr,
                              nullptr,
                              compiledShadowmapFragment,
                              mesh);

                gfxApi->uniform(compiledShadowmapVertex, "projectionMatrix", projectionMatrix);
                gfxApi->uniform(compiledShadowmapVertex, "viewMatrix", viewMatrix);
                gfxApi->uniform(compiledShadowmapVertex, "worldMatrix", worldMatrix * lod.worldMatrix);

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
        }
    }
}

void GfxRenderer::renderShadowmap(Light *light)
{
    Matrix4x4 projectionMatrix = light->getProjectionMatrix();
    Matrix4x4 viewMatrix = light->getViewMatrix();

    gfxApi->pushState();
    gfxApi->resetState();
    gfxApi->setCullMode(GfxCullBack);

    gfxApi->setViewport(0, 0, light->getShadowmapResolution(), light->getShadowmapResolution());
    gfxApi->setCurrentFramebuffer(light->getShadowmapFramebuffer());

    gfxApi->clearDepth();

    const List<Entity *>& entities = scene->getEntities();

    for (size_t i = 0; i < entities.getCount(); ++i)
    {
        const Entity *entity = entities[i];

        Matrix4x4 transform = entity->transform.createMatrix();

        if (entity->hasRenderComponent())
        {
            const RenderComponent *comp = entity->getRenderComponent();

            switch (comp->type)
            {
            case RenderComponent::Model:
            {
                renderModelToShadowmap(viewMatrix, projectionMatrix, transform, comp->model);
                break;
            }
            default:
            {
                break;
            }
            }
        }
    }

    gfxApi->popState();
}

void GfxRenderer::swapFramebuffers()
{
    std::swap(writeFramebuffer, readFramebuffer);
    std::swap(writeColorTexture, readColorTexture);
}
