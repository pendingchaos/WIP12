#include "graphics/gfxrenderer.h"

#include "math/matrix3x3.h"
#include "graphics/gfxapi.h"
#include "graphics/camera.h"
#include "graphics/gfxframebuffer.h"
#include "graphics/gfxdebugdrawer.h"
#include "graphics/gfxbuffer.h"
#include "graphics/gputimer.h"
#include "graphics/gfxterrain.h"
#include "scene/scene.h"
#include "scene/entity.h"
#include "globals.h"
#include "logging.h"
#include "platform.h"

#include <cmath>

static GfxShaderCombination *createPostShader(const char *filename)
{
    GfxShader *vertex = resMgr->load<GfxShader>("resources/shaders/postEffect.vs.bin");
    GfxShader *fragment = resMgr->load<GfxShader>(filename);

    auto result = NEW(GfxShaderCombination, vertex, fragment);

    vertex->release();
    fragment->release();

    return result;
}

GfxRenderer::GfxRenderer(Scene *scene_) : debugDraw(false),
                                          bloomThreshold(1.0f),
                                          bloom1Radius(0.1f),
                                          bloom2Radius(0.05f),
                                          bloom3Radius(0.025f),
                                          bloom4Radius(0.0125f),
                                          bloom1Strength(1.0f),
                                          bloom2Strength(1.0f),
                                          bloom3Strength(1.0f),
                                          bloom4Strength(1.0f),
                                          bloomEnabled(true),
                                          ssaoRadius(0.1f),
                                          skybox(nullptr),
                                          stats({0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0}),
                                          width(0),
                                          height(0),
                                          scene(scene_),
                                          //averageLuminance(0.0f),
                                          numLights(0),
                                          terrain(nullptr)
{
    skyboxShaders = NEW(GfxShaderCombination,
                        resMgr->load<GfxShader>("resources/shaders/skybox.vs.bin"),
                        resMgr->load<GfxShader>("resources/shaders/skybox.fs.bin"));
    skyboxShaders->getShader(GfxShaderType::Vertex)->release();
    skyboxShaders->getShader(GfxShaderType::Fragment)->release();
    skyboxMesh = resMgr->load<GfxMesh>("resources/meshes/cube.bin");

    lightingDirectional = createPostShader("resources/shaders/lightingDirectional.fs.bin");
    lightingDirectionalShadow = createPostShader("resources/shaders/lightingDirectional.fs.bin");
    lightingDirectionalShadow->setDefine(GfxShaderType::Fragment, "SHADOW_MAP", "1");

    lightingPoint = createPostShader("resources/shaders/lightingPoint.fs.bin");
    lightingPointShadow = createPostShader("resources/shaders/lightingPoint.fs.bin");
    lightingPointShadow->setDefine(GfxShaderType::Fragment, "SHADOW_MAP", "1");

    lightingSpot = createPostShader("resources/shaders/lightingSpot.fs.bin");
    lightingSpotShadow = createPostShader("resources/shaders/lightingSpot.fs.bin");
    lightingSpotShadow->setDefine(GfxShaderType::Fragment, "SHADOW_MAP", "1");

    fxaa = createPostShader("resources/shaders/fxaa.fs.bin");
    ssao = createPostShader("resources/shaders/ssao.fs.bin");
    ssaoBlurX = createPostShader("resources/shaders/ssaoBlurX.fs.bin");
    ssaoBlurY = createPostShader("resources/shaders/ssaoBlurY.fs.bin");
    bloomBlurX = createPostShader("resources/shaders/bloomBlurX.fs.bin");
    bloomBlurY = createPostShader("resources/shaders/bloomBlurY.fs.bin");
    tonemap = createPostShader("resources/shaders/tonemap.fs.bin");
    applyBloom = createPostShader("resources/shaders/applyBloom.fs.bin");
    bloomDownsample = createPostShader("resources/shaders/bloomDownsample.fs.bin");
    gammaCorrection = createPostShader("resources/shaders/gammaCorrection.fs.bin");

    terrainVertex = resMgr->load<GfxShader>("resources/shaders/terrain.vs.bin");
    terrainTessControl = resMgr->load<GfxShader>("resources/shaders/terrain.tcs.bin");
    terrainTessEval = resMgr->load<GfxShader>("resources/shaders/terrain.tes.bin");
    terrainFragment = resMgr->load<GfxShader>("resources/shaders/terrain.fs.bin");

    shadowmapVertex = resMgr->load<GfxShader>("resources/shaders/shadowmap.vs.bin");
    pointShadowmapGeometry = resMgr->load<GfxShader>("resources/shaders/pointShadowmap.gs.bin");
    shadowmapFragment = resMgr->load<GfxShader>("resources/shaders/shadowmap.fs.bin");
    pointShadowmapFragment = resMgr->load<GfxShader>("resources/shaders/pointShadowmap.fs.bin");

    overlayShaders = NEW(GfxShaderCombination,
                         resMgr->load<GfxShader>("resources/shaders/overlay.vs.bin"),
                         resMgr->load<GfxShader>("resources/shaders/overlay.fs.bin"));
    overlayShaders->getShader(GfxShaderType::Vertex)->release();
    overlayShaders->getShader(GfxShaderType::Fragment)->release();

    colorModifierFragment = NEW(GfxShader);
    updateColorModifierShader();

    colorModify = NEW(GfxShaderCombination,
                      resMgr->load<GfxShader>("resources/shaders/postEffect.vs.bin"),
                      colorModifierFragment);
    colorModify->getShader(GfxShaderType::Vertex)->release();

    compiledShadowmapVertex = shadowmapVertex->getCompiled();
    compiledShadowmapVertexAnimated = shadowmapVertex->getCompiled(HashMapBuilder<Str, Str>().add("SKELETAL_ANIMATION", "1"));
    compiledTerrainVertex = terrainVertex->getCompiled();
    compiledTerrainTessControl = terrainTessControl->getCompiled();
    compiledTerrainTessEval = terrainTessEval->getCompiled();
    compiledTerrainFragment = terrainFragment->getCompiled();

    compiledPointShadowmapGeometry = pointShadowmapGeometry->getCompiled();

    compiledShadowmapFragment = shadowmapFragment->getCompiled();
    compiledPointShadowmapFragment = pointShadowmapFragment->getCompiled();

    shadowmapMaterial = NEW(GfxMaterial);
    shadowmapMaterial->setScript(resMgr->load<Script>("resources/scripts/materials/shadow.rkt"));

    lightBuffer = gfxApi->createBuffer();
    lightBuffer->allocData(16384, nullptr, GfxBufferUsage::Dynamic);

    static const float positionData[] = {-1.0f,  1.0f,
                                         -1.0f, -1.0f,
                                          1.0f, -1.0f,
                                         -1.0f,  1.0f,
                                          1.0f, -1.0f,
                                          1.0f,  1.0f};

    quadMesh = NEW(GfxMesh);

    quadMesh->primitive = GfxTriangles;
    quadMesh->numVertices = 6;

    GfxMeshAttrib attrib;
    attrib.type = GfxMeshAttribType::Position;
    attrib.dataType = GfxMeshAttribDataType::F32_2;
    attrib.data = ResizableData(sizeof(positionData), positionData);

    quadMesh->setAttribute(attrib);

    readColorTexture = NEW(GfxTexture);
    writeColorTexture = NEW(GfxTexture);
    depthTexture = NEW(GfxTexture);
    materialTexture = NEW(GfxTexture);
    normalTexture = NEW(GfxTexture);
    ssaoTexture = NEW(GfxTexture);
    ssaoBlurXTexture = NEW(GfxTexture);
    bloomBlurXTexture = NEW(GfxTexture);
    ssaoRandomTexture = NEW(GfxTexture);
    bloom1Texture = NEW(GfxTexture);
    bloom2Texture = NEW(GfxTexture);
    bloom3Texture = NEW(GfxTexture);
    bloom4Texture = NEW(GfxTexture);
    bloomDownsampleTexture = NEW(GfxTexture);
    geomNormalTexture = NEW(GfxTexture);

    readColorTexture->setWrapMode(GfxWrapMode::Stretch);
    writeColorTexture->setWrapMode(GfxWrapMode::Stretch);
    depthTexture->setWrapMode(GfxWrapMode::Stretch);
    materialTexture->setWrapMode(GfxWrapMode::Stretch);
    normalTexture->setWrapMode(GfxWrapMode::Stretch);
    ssaoTexture->setWrapMode(GfxWrapMode::Stretch);
    ssaoBlurXTexture->setWrapMode(GfxWrapMode::Stretch);
    bloomBlurXTexture->setWrapMode(GfxWrapMode::Stretch);
    bloom1Texture->setWrapMode(GfxWrapMode::Stretch);
    bloom2Texture->setWrapMode(GfxWrapMode::Stretch);
    bloom3Texture->setWrapMode(GfxWrapMode::Stretch);
    bloom4Texture->setWrapMode(GfxWrapMode::Stretch);
    bloomDownsampleTexture->setWrapMode(GfxWrapMode::Stretch);
    geomNormalTexture->setWrapMode(GfxWrapMode::Stretch);

    resize(640);

    ssaoRandomTexture->startCreation(GfxTextureType::Texture2D,
                                     4,
                                     4,
                                     1,
                                     GfxTexFormat::RGBF32_F16);

    const int NUM_DIRECTIONS = 4;

    float random[48];

    for (size_t i = 0; i < 16; ++i)
    {
        float angle = 2.0f * M_PI * (std::rand() / (float)RAND_MAX) / NUM_DIRECTIONS;

        random[i*3] = std::cos(angle);
        random[i*3+1] = std::sin(angle);
        random[i*3+2] = std::rand() / (float)RAND_MAX;
    }

    ssaoRandomTexture->allocMipmap(0, 1, random);

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
    gBufferFramebuffer->addColorAttachment(3, geomNormalTexture);
    gBufferFramebuffer->setDepthAttachment(depthTexture);

    ssaoFramebuffer = gfxApi->createFramebuffer();
    ssaoFramebuffer->addColorAttachment(0, ssaoTexture);

    ssaoBlurXFramebuffer = gfxApi->createFramebuffer();
    ssaoBlurXFramebuffer->addColorAttachment(0, ssaoBlurXTexture);

    bloomblurXFramebuffer = gfxApi->createFramebuffer();
    bloomblurXFramebuffer->addColorAttachment(0, bloomBlurXTexture);

    bloom1Framebuffer = gfxApi->createFramebuffer();
    bloom1Framebuffer->addColorAttachment(0, bloom1Texture);

    bloom2Framebuffer = gfxApi->createFramebuffer();
    bloom2Framebuffer->addColorAttachment(0, bloom2Texture);

    bloom3Framebuffer = gfxApi->createFramebuffer();
    bloom3Framebuffer->addColorAttachment(0, bloom3Texture);

    bloom4Framebuffer = gfxApi->createFramebuffer();
    bloom4Framebuffer->addColorAttachment(0, bloom4Texture);

    bloomDownsampleFramebuffer = gfxApi->createFramebuffer();
    bloomDownsampleFramebuffer->addColorAttachment(0, bloomDownsampleTexture);

    gBufferTimer = gfxApi->createTimer();
    ssaoTimer = gfxApi->createTimer();
    ssaoBlurXTimer = gfxApi->createTimer();
    ssaoBlurYTimer = gfxApi->createTimer();
    deferredShadingTimer = gfxApi->createTimer();
    forwardTimer = gfxApi->createTimer();
    gammaCorrectionTimer = gfxApi->createTimer();
    fxaaTimer = gfxApi->createTimer();
    colorModifierTimer = gfxApi->createTimer();
    bloomTimer = gfxApi->createTimer();
    shadowmapTimer = gfxApi->createTimer();
    overlayTimer = gfxApi->createTimer();
    debugDrawTimer = gfxApi->createTimer();

    forwardList = NEW(RenderList);
    deferredList = NEW(RenderList);
    shadowmapList = NEW(RenderList);

    /*addTerrain(2.0f,
               32,
               resMgr->load<GfxTexture>("resources/textures/terrain.bin"))->setScale(10.0f);

    GfxTerrainLayer layer(resMgr->load<GfxMaterial>("resources/materials/grass.bin"),
                          resMgr->load<GfxTexture>("resources/textures/terrainWeight.bin"));
    layer.uvScale = 64.0f;
    terrain->layers.append(layer);

    GfxTerrainLayer layer2(resMgr->load<GfxMaterial>("resources/materials/rock.bin"),
                          resMgr->load<GfxTexture>("resources/textures/terrainWeight2.bin"));
    layer2.uvScale = 64.0f;
    terrain->layers.append(layer2);*/
}

GfxRenderer::~GfxRenderer()
{
    for (auto light : lights)
    {
        DELETE(light);
    }

    if (skybox != nullptr)
    {
        skybox->release();
    }

    DELETE(shadowmapList);
    DELETE(deferredList);
    DELETE(forwardList);

    DELETE(gBufferTimer);
    DELETE(ssaoTimer);
    DELETE(ssaoBlurXTimer);
    DELETE(ssaoBlurYTimer);
    DELETE(deferredShadingTimer);
    DELETE(forwardTimer);
    DELETE(gammaCorrectionTimer);
    DELETE(fxaaTimer);
    DELETE(colorModifierTimer);
    DELETE(bloomTimer);
    DELETE(shadowmapTimer);
    DELETE(overlayTimer);
    DELETE(debugDrawTimer);

    DELETE(readFramebuffer);
    DELETE(writeFramebuffer);
    DELETE(gBufferFramebuffer);
    DELETE(ssaoFramebuffer);
    DELETE(ssaoBlurXFramebuffer);
    DELETE(bloomblurXFramebuffer);
    DELETE(bloom1Framebuffer);
    DELETE(bloom2Framebuffer);
    DELETE(bloom3Framebuffer);
    DELETE(bloom4Framebuffer);
    DELETE(bloomDownsampleFramebuffer);

    shadowmapMaterial->release();

    DELETE(lightBuffer);

    geomNormalTexture->release();
    bloomDownsampleTexture->release();
    bloom4Texture->release();
    bloom3Texture->release();
    bloom2Texture->release();
    bloom1Texture->release();
    ssaoRandomTexture->release();
    bloomBlurXTexture->release();
    ssaoBlurXTexture->release();
    ssaoTexture->release();
    normalTexture->release();
    materialTexture->release();
    depthTexture->release();
    writeColorTexture->release();
    readColorTexture->release();

    quadMesh->release();

    DELETE(skyboxShaders);
    DELETE(fxaa);
    DELETE(lightingDirectional);
    DELETE(lightingDirectionalShadow);
    DELETE(lightingPoint);
    DELETE(lightingPointShadow);
    DELETE(lightingSpot);
    DELETE(lightingSpotShadow);
    DELETE(ssao);
    DELETE(ssaoBlurX);
    DELETE(ssaoBlurY);
    DELETE(bloomBlurX);
    DELETE(bloomBlurY);
    DELETE(tonemap);
    DELETE(bloomDownsample);
    DELETE(gammaCorrection);
    DELETE(applyBloom);
    DELETE(overlayShaders);
    DELETE(colorModify);

    terrainFragment->release();
    terrainTessControl->release();
    terrainTessEval->release();
    terrainVertex->release();
    colorModifierFragment->release();
    pointShadowmapFragment->release();
    shadowmapFragment->release();

    pointShadowmapGeometry->release();
    shadowmapVertex->release();
    skyboxMesh->release();
}

void GfxRenderer::updateStats()
{
    gBufferTimer->swap();
    if (gBufferTimer->resultAvailable())
    {
        stats.gBufferTiming = gBufferTimer->getResult() / (float)gBufferTimer->getResultResolution();
    }

    ssaoTimer->swap();
    if (ssaoTimer->resultAvailable())
    {
        stats.ssaoTiming = ssaoTimer->getResult() / (float)ssaoTimer->getResultResolution();
    }

    ssaoBlurXTimer->swap();
    if (ssaoBlurXTimer->resultAvailable())
    {
        stats.ssaoBlurXTiming = ssaoBlurXTimer->getResult() / (float)ssaoBlurXTimer->getResultResolution();
    }

    ssaoBlurYTimer->swap();
    if (ssaoBlurYTimer->resultAvailable())
    {
        stats.ssaoBlurYTiming = ssaoBlurYTimer->getResult() / (float)ssaoBlurYTimer->getResultResolution();
    }

    deferredShadingTimer->swap();
    if (deferredShadingTimer->resultAvailable())
    {
        stats.deferredShadingTiming = deferredShadingTimer->getResult() / (float)deferredShadingTimer->getResultResolution();
    }

    forwardTimer->swap();
    if (forwardTimer->resultAvailable())
    {
        stats.forwardTiming = forwardTimer->getResult() / (float)forwardTimer->getResultResolution();
    }

    gammaCorrectionTimer->swap();
    if (gammaCorrectionTimer->resultAvailable())
    {
        stats.gammaCorrectionTiming = gammaCorrectionTimer->getResult() / (float)gammaCorrectionTimer->getResultResolution();
    }

    fxaaTimer->swap();
    if (fxaaTimer->resultAvailable())
    {
        stats.fxaaTiming = fxaaTimer->getResult() / (float)fxaaTimer->getResultResolution();
    }

    colorModifierTimer->swap();
    if (colorModifierTimer->resultAvailable())
    {
        stats.colorModifierTiming = colorModifierTimer->getResult() / (float)colorModifierTimer->getResultResolution();
    }

    bloomTimer->swap();
    if (bloomTimer->resultAvailable())
    {
        stats.bloomTiming = bloomTimer->getResult() / (float)bloomTimer->getResultResolution();
    }

    shadowmapTimer->swap();
    if (shadowmapTimer->resultAvailable())
    {
        stats.shadowmapTiming = shadowmapTimer->getResult() / (float)shadowmapTimer->getResultResolution();
    }

    overlayTimer->swap();
    if (overlayTimer->resultAvailable())
    {
        stats.overlayTiming = overlayTimer->getResult() / (float)overlayTimer->getResultResolution();
    }

    debugDrawTimer->swap();
    if (debugDrawTimer->resultAvailable())
    {
        stats.debugDrawTiming = debugDrawTimer->getResult() / (float)debugDrawTimer->getResultResolution();
    }
}

void GfxRenderer::updateColorModifierShader()
{
    Str source = (STR(
//Begin color.glsl\n
vec3 RGBToxyY(vec3 rgb)
{
	const mat3 RGB2XYZ = mat3(0.4124, 0.3576, 0.1805,
							  0.2126, 0.7152, 0.0722,
							  0.0193, 0.1192, 0.9505);
	vec3 XYZ = RGB2XYZ * rgb;

	// XYZ to xyY\n
	return vec3(XYZ.x / (XYZ.x + XYZ.y + XYZ.z),
				XYZ.y / (XYZ.x + XYZ.y + XYZ.z),
				XYZ.y);
}

vec3 xyYToRGB(vec3 xyY)
{
	// xyY to XYZ\n
	vec3 XYZ = vec3((xyY.z / xyY.y) * xyY.x,
					xyY.z,
					(xyY.z / xyY.y) * (1.0 - xyY.x - xyY.y));

	const mat3 XYZ2RGB = mat3(3.2406, -1.5372, -0.4986,
                              -0.9689, 1.8758, 0.0415,
                              0.0557, -0.2040, 1.0570);

	return XYZ2RGB * XYZ;
}

//From http://lolengine.net/blog/2013/07/27/rgb-to-hsv-in-glsl\n
vec3 rgb2hsv(vec3 c)
{
    vec4 K = vec4(0.0, -1.0 / 3.0, 2.0 / 3.0, -1.0);
    //vec4 p = mix(vec4(c.bg, K.wz), vec4(c.gb, K.xy), step(c.b, c.g));\n
    //vec4 q = mix(vec4(p.xyw, c.r), vec4(c.r, p.yzx), step(p.x, c.r));\n
    vec4 p = c.g < c.b ? vec4(c.bg, K.wz) : vec4(c.gb, K.xy);
    vec4 q = c.r < p.x ? vec4(p.xyw, c.r) : vec4(c.r, p.yzx);

    float d = q.x - min(q.w, q.y);
    float e = 1.0e-10;
    return vec3(abs(q.z + (q.w - q.y) / (6.0 * d + e)), d / (q.x + e), q.x);
}

vec3 hsv2rgb(vec3 c)
{
    vec4 K = vec4(1.0, 2.0 / 3.0, 1.0 / 3.0, 3.0);
    vec3 p = abs(fract(c.xxx + K.xyz) * 6.0 - K.www);
    return c.z * mix(K.xxx, clamp(p - K.xxx, 0.0, 1.0), c.y);
}
//End color.glsl\n

layout (location = 0) out vec3 result_color;

in vec2 frag_uv;

uniform sampler2D colorTexture;

vec3 vignette(vec3 color, float radius, float softness, float intensity)
{
    float vignette = distance(vec2(0.5), frag_uv);
    vignette = smoothstep(radius/2.0, (radius-softness)/2.0, vignette);
    return color * mix(1.0, vignette, intensity);
}
vec3 hueShift(vec3 color, float hue)
{
    vec3 hsv = rgb2hsv(color);
    hsv.x += hue;
    return hsv2rgb(hsv);
}
vec3 saturationShift(vec3 color, float saturation)
{
    vec3 hsv = rgb2hsv(color);
    hsv.y += saturation;
    return hsv2rgb(hsv);
}
vec3 brightnessShift(vec3 color, float brightness)
{
    vec3 xyY = RGBToxyY(color);
    xyY.z += brightness;
    return xyYToRGB(xyY);
}
vec3 contrast(vec3 color, float contrast){return (color - 0.5) * contrast + 0.5;}
vec3 multiply(vec3 color, vec3 by){return color * by;}
vec3 hueReplace(vec3 color, float hue)
{
    vec3 hsv = rgb2hsv(color);
    hsv.x = hue;
    return hsv2rgb(hsv);
}
vec3 saturationReplace(vec3 color, float saturation)
{
    vec3 hsv = rgb2hsv(color);
    hsv.y = saturation;
    return hsv2rgb(hsv);
}
vec3 brightnessReplace(vec3 color, float brightness)
{
    vec3 xyY = RGBToxyY(color);
    xyY.z = brightness;
    return xyYToRGB(xyY);
}
void main()
{
    result_color = texture(colorTexture, frag_uv).rgb;
));

    for (auto modifier : colorModifiers)
    {
        switch (modifier.type)
        {
        case ColorModifier::Vignette:
        {
            source = source + Str::format("result_color = vignette(result_color, %f, %f, %f);",
                                          modifier.vignette.radius,
                                          modifier.vignette.softness,
                                          modifier.vignette.intensity);
            break;
        }
        case ColorModifier::HueShift:
        {
            source = source + Str::format("result_color = hueShift(result_color, %f);",
                                          modifier.hueShift.hue);
            break;
        }
        case ColorModifier::SaturationShift:
        {
            source = source + Str::format("result_color = saturationShift(result_color, %f);",
                                          modifier.saturationShift.saturation);
            break;
        }
        case ColorModifier::BrightnessShift:
        {
            source = source + Str::format("result_color = brightnessShift(result_color, %f);",
                                          modifier.brightnessShift.brightness);
            break;
        }
        case ColorModifier::Contrast:
        {
            source = source + Str::format("result_color = contrast(result_color, %f);",
                                          modifier.contrast.contrast);
            break;
        }
        case ColorModifier::Multiply:
        {
            source = source + Str::format("result_color = multiply(result_color, vec3(%f, %f, %f));",
                                          modifier.multiply.red,
                                          modifier.multiply.green,
                                          modifier.multiply.blue);
            break;
        }
        case ColorModifier::HueReplace:
        {
            source = source + Str::format("result_color = hueReplace(result_color, %f);",
                                          modifier.hueReplace.hue);
            break;
        }
        case ColorModifier::SaturationReplace:
        {
            source = source + Str::format("result_color = saturationReplace(result_color, %f);",
                                          modifier.saturationReplace.saturation);
            break;
        }
        case ColorModifier::BrightnessReplace:
        {
            source = source + Str::format("result_color = brightnessReplace(result_color, %f);",
                                          modifier.brightnessReplace.brightness);
            break;
        }
        }
    }

    source = source + "}";

    colorModifierFragment->compile(GfxShaderType::Fragment, source);

    compiledColorModifier = colorModifierFragment->getCompiled();
}

GfxTerrain *GfxRenderer::addTerrain(float chunkSize,
                                    size_t sizeInChunks,
                                    GfxTexture *heightmap)
{
    DELETE(terrain);
    terrain = NEW(GfxTerrain, chunkSize, sizeInChunks, heightmap);

    return terrain;
}

void GfxRenderer::removeTerrain()
{
    DELETE(terrain);
    terrain = nullptr;
}

void GfxRenderer::resize(const UInt2& size)
{
    if (size.x != width or size.y != width)
    {
        width = size.x;
        height = size.y;

        if (camera.getType() == CameraType::Perspective)
        {
            camera.setWidth(width);
            camera.setHeight(height);
        }

        readColorTexture->startCreation(GfxTextureType::Texture2D,
                                        width,
                                        height,
                                        1,
                                        GfxTexFormat::RGBF32_F16);
        readColorTexture->allocMipmap(0, 1, nullptr);

        writeColorTexture->startCreation(GfxTextureType::Texture2D,
                                         width,
                                         height,
                                         1,
                                         GfxTexFormat::RGBF32_F16);
        writeColorTexture->allocMipmap(0, 1, nullptr);

        depthTexture->startCreation(GfxTextureType::Texture2D,
                                    width,
                                    height,
                                    1,
                                    GfxTexFormat::DepthF32_F24);
        depthTexture->allocMipmap(0, 1, nullptr);

        materialTexture->startCreation(GfxTextureType::Texture2D,
                                       width,
                                       height,
                                       1,
                                       GfxTexFormat::RedGreenU8);
        materialTexture->allocMipmap(0, 1, nullptr);

        normalTexture->startCreation(GfxTextureType::Texture2D,
                                     width,
                                     height,
                                     1,
                                     GfxTexFormat::RGBI16);
        normalTexture->allocMipmap(0, 1, nullptr);

        ssaoTexture->startCreation(GfxTextureType::Texture2D,
                                   width,
                                   height,
                                   1,
                                   GfxTexFormat::RGBAF32_F16);
        ssaoTexture->allocMipmap(0, 1, nullptr);

        ssaoBlurXTexture->startCreation(GfxTextureType::Texture2D,
                                        width,
                                        height,
                                        1,
                                        GfxTexFormat::RGBAF32_F16);
        ssaoBlurXTexture->allocMipmap(0, 1, nullptr);

        bloomBlurXTexture->startCreation(GfxTextureType::Texture2D,
                                         width/4,
                                         height/4,
                                         1,
                                         GfxTexFormat::RGBF32_F16);
        bloomBlurXTexture->allocMipmap(0, 1, nullptr);

        bloom1Texture->startCreation(GfxTextureType::Texture2D,
                                     width/4,
                                     height/4,
                                     1,
                                     GfxTexFormat::RGBF32_F16);
        bloom1Texture->allocMipmap(0, 1, nullptr);

        bloom2Texture->startCreation(GfxTextureType::Texture2D,
                                     width/4,
                                     height/4,
                                     1,
                                     GfxTexFormat::RGBF32_F16);
        bloom2Texture->allocMipmap(0, 1, nullptr);

        bloom3Texture->startCreation(GfxTextureType::Texture2D,
                                     width/4,
                                     height/4,
                                     1,
                                     GfxTexFormat::RGBF32_F16);
        bloom3Texture->allocMipmap(0, 1, nullptr);

        bloom4Texture->startCreation(GfxTextureType::Texture2D,
                                     width/4,
                                     height/4,
                                     1,
                                     GfxTexFormat::RGBF32_F16);
        bloom4Texture->allocMipmap(0, 1, nullptr);

        bloomDownsampleTexture->startCreation(GfxTextureType::Texture2D,
                                              width/4,
                                              height/4,
                                              1,
                                              GfxTexFormat::RGBF32_F16);
        bloomDownsampleTexture->allocMipmap(0, 1, nullptr);

        geomNormalTexture->startCreation(GfxTextureType::Texture2D,
                                         width,
                                         height,
                                         1,
                                         GfxTexFormat::RGBI16);
        geomNormalTexture->allocMipmap(0, 1, nullptr);
    }
}

class PostEffect
{
    public:
        PostEffect() : fb(nullptr), shaders(nullptr), gpuTimer(nullptr), quad(nullptr) {}

        inline PostEffect& setFramebuffer(GfxFramebuffer *fb_)
        {
            fb = fb_;
            return *this;
        }

        inline PostEffect& setShaders(GfxShaderCombination *shaders_)
        {
            shaders = shaders_;
            return *this;
        }

        inline PostEffect& setGpuTimer(GPUTimer *timer)
        {
            gpuTimer = timer;
            return *this;
        }

        inline PostEffect& setQuad(GfxMesh *quad_)
        {
            quad = quad_;
            return *this;
        }

        PostEffect& begin()
        {
            start = platform->getTime();

            if (gpuTimer != nullptr)
            {
                gpuTimer->begin();
            }

            gfxApi->setCurrentFramebuffer(fb);
            gfxApi->begin(shaders, quad);
            return *this;
        }

        uint64_t end()
        {
            gfxApi->draw();
            gfxApi->end();

            if (gpuTimer != nullptr)
            {
                gpuTimer->end();
            }

            return float(platform->getTime() - start) / platform->getTimerFrequency();
        }

        template <typename T>
        PostEffect& uniform(const char *name, const T& v)
        {
            gfxApi->uniform(shaders->getCompiled(GfxShaderType::Fragment), name, v);
            return *this;
        }

        PostEffect& texture(const char *name, GfxTexture *tex)
        {
            gfxApi->addTextureBinding(shaders->getCompiled(GfxShaderType::Fragment), name, tex, TextureSampler(tex));
            return *this;
        }
    private:
        GfxFramebuffer *fb;
        GfxShaderCombination *shaders;
        GPUTimer *gpuTimer;
        GfxMesh *quad;
        uint64_t start;
};

void GfxRenderer::render()
{
    stats.numDrawCalls = 0;

    GfxTexture *oldReadTex = readColorTexture;
    GfxTexture *oldWriteTex = writeColorTexture;
    GfxFramebuffer *oldReadFb = readFramebuffer;
    GfxFramebuffer *oldWriteFb = writeFramebuffer;

    uint64_t start = platform->getTime();

    //TODO: Move these out of the batching timer.
    for (auto& obj : objects)
    {
        obj.mesh->release();
        obj.material->release();
    }
    objects.clear();

    fillObjects(scene->getEntities());

    computeSceneAABB();
    computeShadowCasterAABB();

    fillRenderLists(scene->getEntities());

    stats.batchingCPUTiming = float(platform->getTime() - start) / platform->getTimerFrequency();

    //TODO: Get rid of this
    start = platform->getTime();
    stats.animationCPUTiming = float(platform->getTime() - start) / platform->getTimerFrequency();

    //Shadowmaps
    start = platform->getTime();
    shadowmapTimer->begin();

    for (auto light : lights)
    {
        light->updateMatrices(this);

        if (light->getShadowmap() == nullptr)
        {
            continue;
        }

        renderShadowmap(light);
    }

    shadowmapTimer->end();
    stats.shadowmapCPUTiming = float(platform->getTime() - start) / platform->getTimerFrequency();

    //G buffer
    gfxApi->setViewport(0, 0, width, height);
    gfxApi->setWriteDepth(true);
    gfxApi->setDepthFunction(GfxLess);

    start = platform->getTime();
    gBufferTimer->begin();

    gfxApi->setCurrentFramebuffer(gBufferFramebuffer);

    gfxApi->clearDepth();

    deferredList->execute(camera);
    deferredList->clear();

    swapFramebuffers();

    gfxApi->setWriteDepth(false);
    gfxApi->setDepthFunction(GfxAlways);

    gBufferTimer->end();
    stats.gbufferCPUTiming = float(platform->getTime() - start) / platform->getTimerFrequency();

    //SSAO
    stats.miscPostEffectsCPUTiming =
    PostEffect().setFramebuffer(ssaoFramebuffer)
                .setShaders(ssao)
                .setGpuTimer(ssaoTimer)
                .setQuad(quadMesh)
                .begin()
                .texture("depthTexture", depthTexture)
                .texture("normalTexture", normalTexture)
                .texture("randomTexture", ssaoRandomTexture)
                .uniform("normalMatrix", Matrix3x3(camera.getViewMatrix().inverse().transpose()))
                .uniform("inverseProjectionMatrix", camera.getProjectionMatrix().inverse())
                .uniform("radius", 1.0f)
                .uniform("exponent", 1.5f)
                .uniform("multiplier", 4.0f)
                .uniform("cosAngleBias", 0.0833f)
                .end();
    ++stats.numDrawCalls;

    //SSAO Blur X
    stats.miscPostEffectsCPUTiming +=
    PostEffect().setFramebuffer(ssaoBlurXFramebuffer)
                .setShaders(ssaoBlurX)
                .setGpuTimer(ssaoBlurXTimer)
                .setQuad(quadMesh)
                .begin()
                .texture("aoTexture", ssaoTexture)
                .end();
    ++stats.numDrawCalls;

    //SSAO Blur Y
    stats.miscPostEffectsCPUTiming +=
    PostEffect().setFramebuffer(ssaoFramebuffer)
                .setShaders(ssaoBlurY)
                .setGpuTimer(ssaoBlurYTimer)
                .setQuad(quadMesh)
                .begin()
                .texture("aoTexture", ssaoBlurXTexture)
                .end();
    ++stats.numDrawCalls;

    //Lighting using the G buffer
    deferredShadingTimer->begin();
    start = platform->getTime();

    gfxApi->setCurrentFramebuffer(writeFramebuffer);
    gfxApi->clearColor(0, Float4(0.0f));

    gfxApi->setBlendingEnabled(true);
    gfxApi->setBlendFactors(GfxOne, GfxOne, GfxOne, GfxOne);
    gfxApi->setBlendMode(GfxAdd, GfxAdd);

    for (auto light : lights)
    {
        gfxApi->pushState();

        GfxShaderCombination *shaders = (GfxShaderCombination *)42;

        switch (light->type)
        {
        case GfxLightType::Directional:
        {
            if (light->getShadowmap() != nullptr)
            {
                shaders = lightingDirectionalShadow;
            } else
            {
                shaders = lightingDirectional;
            }
            break;
        }
        case GfxLightType::Point:
        {
            if (light->getShadowmap() != nullptr)
            {
                shaders = lightingPointShadow;
            } else
            {
                shaders = lightingPoint;
            }

            float influence = light->getPointLightInfluence(0.003921f);

            //Enable when Frustum is fixed.
            //if (not camera.getFrustum().sphereIntersection(light->point.position, influence))
            //{
            //    gfxApi->popState();
            //    continue;
            //}

            AABB aabb(light->point.position - influence,
                      light->point.position + influence);

            debugDrawer->addBox(aabb, Float4(0.0f, 1.0f, 0.0f, 1.0f));

            aabb = aabb.transform(camera.getProjectionMatrix() *
                                  camera.getViewMatrix());

            float hw = width / 2.0f;
            float hh = height / 2.0f;

            aabb.min.x = std::max(aabb.min.x, -1.0f) * hw + hw;
            aabb.min.y = std::max(aabb.min.y, -1.0f) * hh + hh;
            aabb.max.x = std::min(aabb.max.x,  1.0f) * hw + hw;
            aabb.max.y = std::min(aabb.max.y,  1.0f) * hh + hh;

            gfxApi->setScissorEnabled(true);
            gfxApi->setScissor(aabb.min.x,
                               aabb.min.y,
                               aabb.max.x-aabb.min.x,
                               aabb.max.y-aabb.min.y);
            break;
        }
        case GfxLightType::Spot:
        {
            if (light->getShadowmap() != nullptr)
            {
                shaders = lightingSpotShadow;
            } else
            {
                shaders = lightingSpot;
            }
            break;
        }
        }

        gfxApi->begin(shaders, quadMesh);

        GfxCompiledShader *fragment = shaders->getCompiled(GfxShaderType::Fragment);

        gfxApi->addTextureBinding(fragment, "albedoTexture", readColorTexture);
        gfxApi->addTextureBinding(fragment, "materialTexture", materialTexture);
        gfxApi->addTextureBinding(fragment, "normalTexture", normalTexture);
        gfxApi->addTextureBinding(fragment, "geomNormalTexture", geomNormalTexture);
        gfxApi->addTextureBinding(fragment, "depthTexture", depthTexture);
        gfxApi->addTextureBinding(fragment, "aoTexture", ssaoTexture);
        gfxApi->uniform(fragment, "viewProjection", camera.getProjectionMatrix() * camera.getViewMatrix());
        gfxApi->uniform(fragment, "lightColor", light->color * light->power);
        gfxApi->uniform(fragment, "lightAmbientStrength", light->ambientStrength);
        gfxApi->uniform(fragment, "cameraPosition", camera.getPosition());

        if (light->getShadowmap() != nullptr)
        {
            gfxApi->uniform(fragment, "shadowMinBias", light->shadowMinBias);
            gfxApi->uniform(fragment, "shadowBiasScale", light->shadowBiasScale);
            gfxApi->uniform(fragment, "shadowFixedBias", light->shadowFixedBias);

            if (light->type == GfxLightType::Directional)
            {
                GfxTexture *shadowmap = light->getShadowmap();

                gfxApi->uniform(fragment, "shadowRadius", light->shadowRadius);
                gfxApi->addTextureBinding(fragment, "depthmap", shadowmap);
                gfxApi->addTextureBinding(fragment, "shadowmap", shadowmap, TextureSampler::createShadowmap());

                Matrix4x4 view[4];
                view[0] = light->getCascadeViewMatrix(0);
                view[1] = light->getCascadeViewMatrix(1);
                view[2] = light->getCascadeViewMatrix(2);
                view[3] = light->getCascadeViewMatrix(3);

                Matrix4x4 proj[4];
                proj[0] = light->getCascadeProjectionMatrix(0);
                proj[1] = light->getCascadeProjectionMatrix(1);
                proj[2] = light->getCascadeProjectionMatrix(2);
                proj[3] = light->getCascadeProjectionMatrix(3);

                //TODO: Why doesn't gfxApi->uniform(fragment, "<name>", 4, <stuff>) work?
                gfxApi->uniform(fragment, "shadowmapViewMatrices[0]", view[0]);
                gfxApi->uniform(fragment, "shadowmapViewMatrices[1]", view[1]);
                gfxApi->uniform(fragment, "shadowmapViewMatrices[2]", view[2]);
                gfxApi->uniform(fragment, "shadowmapViewMatrices[3]", view[3]);
                gfxApi->uniform(fragment, "shadowmapProjectionMatrices[0]", proj[0]);
                gfxApi->uniform(fragment, "shadowmapProjectionMatrices[1]", proj[1]);
                gfxApi->uniform(fragment, "shadowmapProjectionMatrices[2]", proj[2]);
                gfxApi->uniform(fragment, "shadowmapProjectionMatrices[3]", proj[3]);
            } else
            {
                GfxTexture *shadowmap = light->getShadowmap();

                gfxApi->addTextureBinding(fragment, "shadowmap", shadowmap, TextureSampler::createShadowmap());
                gfxApi->uniform(fragment, "shadowmapViewMatrix", light->getViewMatrix());
                gfxApi->uniform(fragment, "shadowmapProjectionMatrix", light->getProjectionMatrix());
            }
        }

        switch (light->type)
        {
        case GfxLightType::Directional:
        {
            gfxApi->uniform(fragment, "lightNegDir", -light->direction.direction.normalize());
            gfxApi->uniform(fragment, "time", float(platform->getTime()) / float(platform->getTimerFrequency()));
            break;
        }
        case GfxLightType::Spot:
        {
            gfxApi->uniform(fragment, "lightNegDir", -light->spot.direction.normalize());
            gfxApi->uniform(fragment, "lightPos", light->spot.position);
            gfxApi->uniform(fragment, "lightCosInnerCutoff", (float)std::cos(RADIANS(light->spot.innerCutoff)));
            gfxApi->uniform(fragment, "lightCosOuterCutoff", (float)std::cos(RADIANS(light->spot.outerCutoff)));
            gfxApi->uniform(fragment, "lightRadius", light->spot.radius);
            break;
        }
        case GfxLightType::Point:
        {
            gfxApi->uniform(fragment, "lightPos", light->point.position);
            gfxApi->uniform(fragment, "lightRadius", light->point.radius);

            if (light->getShadowmap() != nullptr)
            {
                gfxApi->uniform(fragment, "lightFar", light->getPointLightInfluence());
            }
            break;
        }
        }

        gfxApi->draw();
        gfxApi->end();
        ++stats.numDrawCalls;

        gfxApi->popState();
    }

    stats.deferredShadingCPUTiming = float(platform->getTime() - start) / platform->getTimerFrequency();
    deferredShadingTimer->end();

    gfxApi->setBlendingEnabled(false);

    //Forward
    start = platform->getTime();
    forwardTimer->begin();

    gfxApi->setWriteDepth(true);
    gfxApi->setDepthFunction(GfxLessEqual);

    fillLightBuffer(scene);

    forwardList->execute(camera);
    forwardList->clear();

    renderSkybox();

    forwardTimer->end();

    debugDrawTimer->begin();

    if (debugDraw)
    {
        debugDrawer->render(camera);
    }

    debugDrawTimer->end();
    stats.forwardCPUTiming = float(platform->getTime() - start) / platform->getTimerFrequency();

    gfxApi->setWriteDepth(false);
    gfxApi->setDepthFunction(GfxAlways);

    swapFramebuffers();

    bloomTimer->begin();
    start = platform->getTime();

    if (bloomEnabled)
    {
        //Downsample
        gfxApi->setViewport(0, 0, width/4, height/4);
        PostEffect().setFramebuffer(bloomDownsampleFramebuffer)
                .setShaders(bloomDownsample)
                .setQuad(quadMesh)
                .begin()
                .texture("colorTexture", readColorTexture)
                .uniform("threshold", bloomThreshold)
                .end();
        ++stats.numDrawCalls;

        #define BLOOM(framebuffer) {\
        int32_t radius = bloomRadiusPixels / 4;\
        float bloomSigma = radius / 3.0f;\
        \
        PostEffect().setFramebuffer(bloomblurXFramebuffer)\
                    .setShaders(bloomBlurX)\
                    .setQuad(quadMesh)\
                    .begin()\
                    .texture("bloomTexture", bloomDownsampleTexture)\
                    .uniform("radius", (int32_t)radius)\
                    .uniform("sigma", bloomSigma)\
                    .end();\
        ++stats.numDrawCalls;\
\
        PostEffect().setFramebuffer(framebuffer)\
                    .setShaders(bloomBlurY)\
                    .setQuad(quadMesh)\
                    .begin()\
                    .texture("bloomTexture", bloomBlurXTexture)\
                    .uniform("radius", (int32_t)radius)\
                    .uniform("sigma", bloomSigma)\
                    .end();\
        ++stats.numDrawCalls;\
        }

        uint32_t bloomRadiusPixels = uint32_t(height*bloom1Radius);
        bloomRadiusPixels = std::max(bloomRadiusPixels, 1u);
        BLOOM(bloom1Framebuffer);

        bloomRadiusPixels = uint32_t(std::min(width, height)*bloom2Radius);
        bloomRadiusPixels = std::max(bloomRadiusPixels, 1u);
        BLOOM(bloom2Framebuffer);

        bloomRadiusPixels = uint32_t(std::min(width, height)*bloom3Radius);
        bloomRadiusPixels = std::max(bloomRadiusPixels, 1u);
        BLOOM(bloom3Framebuffer);

        bloomRadiusPixels = uint32_t(std::min(width, height)*bloom4Radius);
        bloomRadiusPixels = std::max(bloomRadiusPixels, 1u);
        BLOOM(bloom4Framebuffer);

        #undef BLOOM

        gfxApi->setViewport(0, 0, width, height);
    }

    stats.miscPostEffectsCPUTiming += float(platform->getTime() - start) / platform->getTimerFrequency();
    bloomTimer->end();

    //Tonemapping.
    stats.miscPostEffectsCPUTiming +=
    PostEffect().setFramebuffer(writeFramebuffer)
                .setShaders(tonemap)
                //.setGpuTimer(tonemapTimer) //TODO
                .setQuad(quadMesh)
                .begin()
                .texture("colorTexture", readColorTexture)
                .end();
    ++stats.numDrawCalls;

    swapFramebuffers();

    //Color modifiers.
    stats.miscPostEffectsCPUTiming +=
    PostEffect().setFramebuffer(writeFramebuffer)
                .setShaders(colorModify)
                .setGpuTimer(colorModifierTimer)
                .setQuad(quadMesh)
                .begin()
                .texture("colorTexture", readColorTexture)
                .end();
    ++stats.numDrawCalls;

    swapFramebuffers();

    if (bloomEnabled)
    {
        //Apply bloom
        PostEffect().setFramebuffer(writeFramebuffer)
                    .setShaders(applyBloom)
                    .setQuad(quadMesh)
                    .begin()
                    .texture("colorTexture", readColorTexture)
                    .texture("bloom1Texture", bloom1Texture)
                    .texture("bloom2Texture", bloom2Texture)
                    .texture("bloom3Texture", bloom3Texture)
                    .texture("bloom4Texture", bloom4Texture)
                    .uniform("bloom1Strength", bloom1Strength)
                    .uniform("bloom2Strength", bloom2Strength)
                    .uniform("bloom3Strength", bloom3Strength)
                    .uniform("bloom4Strength", bloom4Strength)
                    .end();
        ++stats.numDrawCalls;
    }

    //Overlays
    start = platform->getTime();
    overlayTimer->begin();

    const List<Entity *>& entities = scene->getEntities();

    for (auto entity : entities)
    {
        Matrix4x4 transform = entity->getFinalTransform();

        if (entity->hasRenderComponent())
        {
            const RenderComponent *comp = entity->getRenderComponent();

            switch (comp->mode)
            {
            case RenderMode::Overlay:
            {
                gfxApi->begin(overlayShaders, quadMesh);

                gfxApi->uniform(overlayShaders->getCompiled(GfxShaderType::Vertex), "transform", transform);
                gfxApi->uniform(overlayShaders->getCompiled(GfxShaderType::Fragment), "color", comp->overlayData.color);
                gfxApi->addTextureBinding(overlayShaders->getCompiled(GfxShaderType::Fragment), "colorTexture", comp->overlayTexture);

                gfxApi->draw();
                gfxApi->end();
                ++stats.numDrawCalls;
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
    stats.overlayCPUTiming = float(platform->getTime() - start) / platform->getTimerFrequency();

    //Gamma correction
    stats.miscPostEffectsCPUTiming +=
    PostEffect().setFramebuffer(writeFramebuffer)
                .setShaders(gammaCorrection)
                .setGpuTimer(gammaCorrectionTimer)
                .setQuad(quadMesh)
                .begin()
                .texture("colorTexture", readColorTexture)
                .end();
    ++stats.numDrawCalls;

    swapFramebuffers();

    //FXAA
    stats.miscPostEffectsCPUTiming +=
    PostEffect().setFramebuffer(nullptr)
                .setShaders(fxaa)
                .setGpuTimer(fxaaTimer)
                .setQuad(quadMesh)
                .begin()
                .texture("colorTexture", readColorTexture)
                .end();
    ++stats.numDrawCalls;

    swapFramebuffers();

    readColorTexture = oldReadTex;
    writeColorTexture = oldWriteTex;
    readFramebuffer = oldReadFb;
    writeFramebuffer = oldWriteFb;

    start = platform->getTime();
    updateStats();
    stats.updateStatsCPUTiming = float(platform->getTime() - start) / platform->getTimerFrequency();
}

void GfxRenderer::computeSceneAABB()
{
    AABB aabb;

    for (auto& obj : objects)
    {
        //TODO: This ignores displacement mapping
        aabb.extend(obj.mesh->aabb.transform(obj.worldMatrix));
    }

    if (terrain != nullptr)
    {
        aabb.extend(terrain->getMesh()->aabb);
    }

    sceneAABB = aabb;
}

void GfxRenderer::computeShadowCasterAABB()
{
    AABB aabb;

    for (auto& obj : objects)
    {
        //TODO: This ignores displacement mapping
        if (obj.shadowCaster)
        {
            aabb.extend(obj.mesh->aabb.transform(obj.worldMatrix));
        }
    }

    if (terrain != nullptr)
    {
        aabb.extend(terrain->getMesh()->aabb);
    }

    shadowCasterAABB = aabb;
}

void GfxRenderer::fillLightBuffer(Scene *scene)
{
    float *lightData = NEW_ARRAY(float, 4096);

    static const size_t pointOffset = 1792;
    static const size_t dirOffset = 3840;

    numPointLights = 0;
    numDirectionalLights = 0;
    numSpotLights = 0;

    for (auto light : lights)
    {
        switch (light->type)
        {
        case GfxLightType::Directional:
        {
            Vector3D dir = -light->direction.direction.normalize();

            lightData[dirOffset+numDirectionalLights*8+0] = light->color.x;
            lightData[dirOffset+numDirectionalLights*8+1] = light->color.y;
            lightData[dirOffset+numDirectionalLights*8+2] = light->color.z;
            lightData[dirOffset+numDirectionalLights*8+3] = light->ambientStrength;
            lightData[dirOffset+numDirectionalLights*8+4] = dir.x;
            lightData[dirOffset+numDirectionalLights*8+5] = dir.y;
            lightData[dirOffset+numDirectionalLights*8+6] = dir.z;

            ++numDirectionalLights;
            break;
        }
        case GfxLightType::Spot:
        {
            Vector3D dir = -light->spot.direction.normalize();

            lightData[numSpotLights*16+0] = dir.x;
            lightData[numSpotLights*16+1] = dir.y;
            lightData[numSpotLights*16+2] = dir.z;
            lightData[numSpotLights*16+4] = light->spot.position.x;
            lightData[numSpotLights*16+5] = light->spot.position.y;
            lightData[numSpotLights*16+6] = light->spot.position.z;
            lightData[numSpotLights*16+8] = light->color.x;
            lightData[numSpotLights*16+9] = light->color.y;
            lightData[numSpotLights*16+10] = light->color.z;
            lightData[numSpotLights*16+12] = std::cos(RADIANS(light->spot.innerCutoff));
            lightData[numSpotLights*16+13] = std::cos(RADIANS(light->spot.outerCutoff));
            lightData[numSpotLights*16+14] = light->spot.radius;
            lightData[numSpotLights*16+15] = light->ambientStrength;

            ++numSpotLights;
            break;
        }
        case GfxLightType::Point:
        {
            lightData[pointOffset+numPointLights*8+0] = light->point.position.x;
            lightData[pointOffset+numPointLights*8+1] = light->point.position.y;
            lightData[pointOffset+numPointLights*8+2] = light->point.position.z;
            lightData[pointOffset+numPointLights*8+3] = light->point.radius;
            lightData[pointOffset+numPointLights*8+4] = light->color.x;
            lightData[pointOffset+numPointLights*8+5] = light->color.x;
            lightData[pointOffset+numPointLights*8+6] = light->color.x;
            lightData[pointOffset+numPointLights*8+7] = light->ambientStrength;

            ++numPointLights;
            break;
        }
        }
    }

    lightBuffer->setData(0, 16384, lightData);

    DELETE_ARRAY(lightData);
}

void GfxRenderer::fillRenderLists(const List<Entity *>& entities)
{
    for (auto& obj : objects)
    {
        DrawCall drawCall(obj.mesh, obj.material);
        drawCall.animState = obj.animState;
        drawCall.worldMatrix = obj.worldMatrix;

        if (obj.shadowCaster)
        {
            DrawCall shadowDrawCall = drawCall;
            shadowDrawCall.material = shadowmapMaterial;

            shadowmapList->addDrawCall(shadowDrawCall);
        }

        if (obj.material->forward)
        {
            forwardList->addDrawCall(drawCall);
        } else
        {
            deferredList->addDrawCall(drawCall);
        }
    }
}

void GfxRenderer::renderSkybox()
{
    if (skybox != nullptr)
    {
        gfxApi->pushState();

        GfxCompiledShader *compiledVS = skyboxShaders->getCompiled(GfxShaderType::Vertex);
        GfxCompiledShader *compiledFS = skyboxShaders->getCompiled(GfxShaderType::Fragment);

        gfxApi->begin(skyboxShaders, skyboxMesh);

        gfxApi->setDepthFunction(GfxLessEqual);

        gfxApi->uniform(compiledVS, "projectionMatrix", camera.getProjectionMatrix());
        gfxApi->uniform(compiledVS, "viewMatrix", Matrix4x4(Matrix3x3(camera.getViewMatrix())));

        gfxApi->addTextureBinding(compiledFS, "enviroment", skybox);

        gfxApi->draw();
        gfxApi->end();
        ++stats.numDrawCalls;

        gfxApi->popState();
    }
}

void GfxRenderer::renderShadowmap(Light *light)
{
    gfxApi->pushState();
    gfxApi->resetState();

    gfxApi->setViewport(0, 0, light->getShadowmapResolution(), light->getShadowmapResolution());

    size_t numPasses = 1;

    if (light->type == GfxLightType::Point)
    {
        numPasses = light->point.singlePassShadowMap ? 1 : 6;
    } else if (light->type == GfxLightType::Directional)
    {
        numPasses = 4;
    }

    for (size_t i = 0; i < numPasses; ++i)
    {
        gfxApi->setCurrentFramebuffer(light->getFramebuffers()[i]);
        gfxApi->clearDepth();

        shadowmapList->execute(light, i);

        if (light->type != GfxLightType::Spot)
        {
            //TODO
            //renderTerrainToShadowmap(projectionMatrix, viewMatrix, light->shadowAutoBiasScale);
        }
    }

    shadowmapList->clear();

    gfxApi->popState();
}

void GfxRenderer::renderTerrain()
{
    if (terrain == nullptr)
    {
        return;
    }

    for (auto layer : terrain->layers)
    {
        GfxMaterial *material = layer.getMaterial();

        gfxApi->pushState();

        material->setupRender(terrain->getMesh(), nullptr, camera);

        //TODO
        //shaderComb->setDefine(GfxShaderType::Fragment, "TERRAIN", "1");
        //gfxApi->addTextureBinding(fragment, "weightMap", layer.getWeight());
        //gfxApi->setTessPatchSize(4);

        gfxApi->draw(terrain->getSizeInChunks() * terrain->getSizeInChunks());
        gfxApi->end();
        ++stats.numDrawCalls;

        //shaderComb->removeDefine(GfxShaderType::Fragment, "TERRAIN");

        gfxApi->setBlendingEnabled(true);
        gfxApi->setBlendFactors(GfxOne, GfxOne, GfxOne, GfxOne);
        gfxApi->setDepthFunction(GfxLessEqual);

        gfxApi->popState();
    }
}

void GfxRenderer::renderTerrainToShadowmap(const Matrix4x4& projectionMatrix,
                                           const Matrix4x4& viewMatrix,
                                           float autoBiasScale)
{
    if (terrain == nullptr)
    {
        return;
    }

    gfxApi->begin(compiledTerrainVertex,
                  compiledTerrainTessControl,
                  compiledTerrainTessEval,
                  nullptr,
                  compiledShadowmapFragment,
                  terrain->getMesh());

    gfxApi->uniform(compiledTerrainVertex, "sizeInChunks", (uint32_t)terrain->getSizeInChunks());
    gfxApi->uniform(compiledTerrainVertex, "chunkSize", terrain->getChunkSize());
    gfxApi->uniform(compiledTerrainTessControl, "cameraPosition", camera.getPosition());
    gfxApi->uniform(compiledTerrainTessEval, "viewMatrix", viewMatrix);
    gfxApi->uniform(compiledTerrainTessEval, "projectionMatrix", projectionMatrix);
    gfxApi->uniform(compiledTerrainTessEval, "size", terrain->getChunkSize() * terrain->getSizeInChunks());
    gfxApi->uniform(compiledTerrainTessEval, "scale", terrain->getScale());
    gfxApi->addTextureBinding(compiledTerrainTessEval,
                              "heightMap",
                              terrain->getHeightmap());
    gfxApi->uniform(compiledShadowmapFragment, "biasScale", autoBiasScale);

    gfxApi->setTessPatchSize(4);

    gfxApi->draw(terrain->getSizeInChunks() * terrain->getSizeInChunks());
    gfxApi->end();
    ++stats.numDrawCalls;
}

void GfxRenderer::swapFramebuffers()
{
    std::swap(writeFramebuffer, readFramebuffer);
    std::swap(writeColorTexture, readColorTexture);
}

void GfxRenderer::fillObjects(const List<Entity *>& entities)
{
    for (auto entity : entities)
    {
        Matrix4x4 transform = entity->getFinalTransform();

        if (entity->hasRenderComponent())
        {
            const RenderComponent *comp = entity->getRenderComponent();

            switch (comp->mode)
            {
            case RenderMode::Model:
            {
                GfxModel *model = comp->model;

                Position3D position = Position3D(transform[0][3],
                                                 transform[1][3],
                                                 transform[2][3]);

                float distance = position.distance(camera.getPosition());

                GfxMesh *animMesh = nullptr;
                GfxAnimationState *animState = nullptr;
                if (comp->getAnimationState() != nullptr)
                {
                    animState = comp->getAnimationState();
                    animMesh = animState->getMesh();
                }

                for (auto subModel : model->subModels)
                {
                    for (auto lod : subModel)
                    {
                        if (lod.minDistance < distance and
                            distance < lod.maxDistance)
                        {
                            GfxMaterial *material = lod.material;
                            GfxMesh *mesh = lod.mesh;

                            Object obj;
                            obj.shadowCaster = comp->getShadowCaster();
                            obj.material = material->copyRef<GfxMaterial>();
                            obj.mesh = mesh->copyRef<GfxMesh>();
                            obj.animState = (mesh == animMesh) ? animState : nullptr;
                            obj.worldMatrix = transform * lod.worldMatrix;
                            obj.normalMatrix = Matrix3x3(obj.worldMatrix.inverse().transpose());

                            objects.append(obj);
                        }
                    }
                }
                break;
            }
            default:
            {
                break;
            }
            }
        }

        fillObjects(entity->getEntities());;
    }
}
