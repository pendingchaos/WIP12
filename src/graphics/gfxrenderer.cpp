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
    GfxShader *vertex = resMgr->load<GfxShader>("resources/shaders/postEffectVertex.bin");
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
                        resMgr->load<GfxShader>("resources/shaders/skyboxVertex.bin"),
                        resMgr->load<GfxShader>("resources/shaders/skyboxFragment.bin"));
    skyboxShaders->getShader(GfxShaderType::Vertex)->release();
    skyboxShaders->getShader(GfxShaderType::Fragment)->release();
    skyboxMesh = resMgr->load<GfxMesh>("resources/meshes/cube.bin");

    lightingDirectional = createPostShader("resources/shaders/lightingDirectional.bin");
    lightingDirectionalShadow = createPostShader("resources/shaders/lightingDirectional.bin");
    lightingDirectionalShadow->setDefine(GfxShaderType::Fragment, "SHADOW_MAP", "1");

    lightingPoint = createPostShader("resources/shaders/lightingPoint.bin");
    lightingPointShadow = createPostShader("resources/shaders/lightingPoint.bin");
    lightingPointShadow->setDefine(GfxShaderType::Fragment, "SHADOW_MAP", "1");

    lightingSpot = createPostShader("resources/shaders/lightingSpot.bin");
    lightingSpotShadow = createPostShader("resources/shaders/lightingSpot.bin");
    lightingSpotShadow->setDefine(GfxShaderType::Fragment, "SHADOW_MAP", "1");

    fxaa = createPostShader("resources/shaders/fxaaFragment.bin");
    ssao = createPostShader("resources/shaders/ssaoFragment.bin");
    ssaoBlurX = createPostShader("resources/shaders/ssaoBlurXFragment.bin");
    ssaoBlurY = createPostShader("resources/shaders/ssaoBlurYFragment.bin");
    bloomBlurX = createPostShader("resources/shaders/bloomBlurXFragment.bin");
    bloomBlurY = createPostShader("resources/shaders/bloomBlurYFragment.bin");
    lumCalc = createPostShader("resources/shaders/lumCalcFragment.bin");
    tonemap = createPostShader("resources/shaders/tonemapFragment.bin");
    applyBloom = createPostShader("resources/shaders/applyBloomFragment.bin");
    bloomDownsample = createPostShader("resources/shaders/bloomDownsampleFragment.bin");
    gammaCorrection = createPostShader("resources/shaders/gammaCorrectionFragment.bin");

    terrainVertex = resMgr->load<GfxShader>("resources/shaders/terrainVertex.bin");
    terrainTessControl = resMgr->load<GfxShader>("resources/shaders/terrainTessControl.bin");
    terrainTessEval = resMgr->load<GfxShader>("resources/shaders/terrainTessEval.bin");
    terrainFragment = resMgr->load<GfxShader>("resources/shaders/terrainFragment.bin");

    if (gfxApi->tesselationSupported())
    {
        shadowmapTessControl = resMgr->load<GfxShader>("resources/shaders/shadowmapControl.bin");
        shadowmapTessEval = resMgr->load<GfxShader>("resources/shaders/shadowmapEval.bin");
    }

    shadowmapVertex = resMgr->load<GfxShader>("resources/shaders/shadowmapVertex.bin");
    pointShadowmapGeometry = resMgr->load<GfxShader>("resources/shaders/pointShadowmapGeometry.bin");
    shadowmapFragment = resMgr->load<GfxShader>("resources/shaders/shadowmapFragment.bin");
    pointShadowmapFragment = resMgr->load<GfxShader>("resources/shaders/pointShadowmapFragment.bin");

    overlayShaders = NEW(GfxShaderCombination,
                         resMgr->load<GfxShader>("resources/shaders/overlayVertex.bin"),
                         resMgr->load<GfxShader>("resources/shaders/overlayFragment.bin"));
    overlayShaders->getShader(GfxShaderType::Vertex)->release();
    overlayShaders->getShader(GfxShaderType::Fragment)->release();

    colorModifierFragment = NEW(GfxShader);
    updateColorModifierShader();

    colorModify = NEW(GfxShaderCombination,
                      resMgr->load<GfxShader>("resources/shaders/postEffectVertex.bin"),
                      colorModifierFragment);
    colorModify->getShader(GfxShaderType::Vertex)->release();

    compiledShadowmapVertex = shadowmapVertex->getCompiled();
    compiledShadowmapVertexAnimated = shadowmapVertex->getCompiled(HashMapBuilder<String, String>().add("SKELETAL_ANIMATION", "1"));
    compiledTerrainVertex = terrainVertex->getCompiled();
    compiledTerrainTessControl = terrainTessControl->getCompiled();
    compiledTerrainTessEval = terrainTessEval->getCompiled();
    compiledTerrainFragment = terrainFragment->getCompiled();

    compiledShadowmapVertexTesselation = shadowmapVertex->getCompiled(HashMapBuilder<String, String>().add("TESSELATION", "1"));
    compiledShadowmapVertexTesselationAnimated = shadowmapVertex->getCompiled(HashMapBuilder<String, String>().add("TESSELATION", "1").add("SKELETAL_ANIMATION", "1"));

    compiledPointShadowmapGeometry = pointShadowmapGeometry->getCompiled();

    compiledShadowmapTessControl = shadowmapTessControl->getCompiled();
    compiledShadowmapTessEval = shadowmapTessEval->getCompiled();

    compiledShadowmapFragment = shadowmapFragment->getCompiled();
    compiledPointShadowmapFragment = pointShadowmapFragment->getCompiled();

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
    //luminanceTexture = NEW(GfxTexture);
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
    //luminanceTexture->setWrapMode(GfxWrapMode::Stretch);

    resize(640);

    ssaoRandomTexture->startCreation(GfxTextureType::Texture2D,
                                     false,
                                     4,
                                     4,
                                     1,
                                     0,
                                     GfxTexPurpose::Other,
                                     GfxTexFormat::RGBF32_F16);

    const int NUM_DIRECTIONS = 8;

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

    /*luminanceFramebuffer = gfxApi->createFramebuffer();
    luminanceFramebuffer->addColorAttachment(0, luminanceTexture);*/

    gBufferTimer = gfxApi->createTimer();
    ssaoTimer = gfxApi->createTimer();
    ssaoBlurXTimer = gfxApi->createTimer();
    ssaoBlurYTimer = gfxApi->createTimer();
    ssaoUpsampleTimer = gfxApi->createTimer();
    deferredShadingTimer = gfxApi->createTimer();
    forwardTimer = gfxApi->createTimer();
    gammaCorrectionTimer = gfxApi->createTimer();
    fxaaTimer = gfxApi->createTimer();
    colorModifierTimer = gfxApi->createTimer();
    bloomTimer = gfxApi->createTimer();
    //luminanceCalcTimer = gfxApi->createTimer();
    shadowmapTimer = gfxApi->createTimer();
    overlayTimer = gfxApi->createTimer();
    debugDrawTimer = gfxApi->createTimer();

    //matrixTexture = NEW(GfxTexture);
    instanceBuffer = gfxApi->createBuffer();
    instanceBuffer->allocData(16384, NULL, GfxBufferUsage::Dynamic);

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
    //matrixTexture->release();
    DELETE(instanceBuffer);

    for (auto light : lights)
    {
        DELETE(light);
    }

    if (skybox != nullptr)
    {
        skybox->release();
    }

    DELETE(gBufferTimer);
    DELETE(ssaoTimer);
    DELETE(ssaoUpsampleTimer);
    DELETE(ssaoBlurXTimer);
    DELETE(ssaoBlurYTimer);
    DELETE(deferredShadingTimer);
    DELETE(forwardTimer);
    DELETE(gammaCorrectionTimer);
    DELETE(fxaaTimer);
    DELETE(colorModifierTimer);
    DELETE(bloomTimer);
    //DELETE(luminanceCalcTimer);
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
    //DELETE(luminanceFramebuffer);

    DELETE(lightBuffer);

    geomNormalTexture->release();
    bloomDownsampleTexture->release();
    bloom4Texture->release();
    bloom3Texture->release();
    bloom2Texture->release();
    bloom1Texture->release();
    ssaoRandomTexture->release();
    //luminanceTexture->release();
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
    DELETE(lumCalc);
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

    if (gfxApi->tesselationSupported())
    {
        shadowmapTessEval->release();
        shadowmapTessControl->release();
    }

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

    ssaoUpsampleTimer->swap();
    if (ssaoUpsampleTimer->resultAvailable())
    {
        stats.ssaoUpsampleTiming = ssaoUpsampleTimer->getResult() / (float)ssaoUpsampleTimer->getResultResolution();
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

    /*luminanceCalcTimer->swap();
    if (luminanceCalcTimer->resultAvailable())
    {
        stats.lumCalcTiming = luminanceCalcTimer->getResult() / (float)luminanceCalcTimer->getResultResolution();
    }*/

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
    String source = (STR(
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

vec3 reinhard(vec3 color)
{
    return color / (color + 1.0);
}
vec3 reinhardBrightnessOnly(vec3 color)
{
    vec3 xyY = RGBToxyY(color);
    xyY.z /= xyY.z + 1.0;
    return xyYToRGB(xyY);
}
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
        case ColorModifier::ReinhardTonemapping:
        {
            if (modifier.reinhardTonemap.brightnessOnly)
            {
                source.append("result_color = reinhardBrightnessOnly(result_color);");
            } else
            {
                source.append("result_color = reinhard(result_color);");
            }
            break;
        }
        case ColorModifier::Vignette:
        {
            source.append(String::format("result_color = vignette(result_color, %f, %f, %f);",
                                         modifier.vignette.radius,
                                         modifier.vignette.softness,
                                         modifier.vignette.intensity));
            break;
        }
        case ColorModifier::HueShift:
        {
            source.append(String::format("result_color = hueShift(result_color, %f);",
                                         modifier.hueShift.hue));
            break;
        }
        case ColorModifier::SaturationShift:
        {
            source.append(String::format("result_color = saturationShift(result_color, %f);",
                                         modifier.saturationShift.saturation));
            break;
        }
        case ColorModifier::BrightnessShift:
        {
            source.append(String::format("result_color = brightnessShift(result_color, %f);",
                                         modifier.brightnessShift.brightness));
            break;
        }
        case ColorModifier::Contrast:
        {
            source.append(String::format("result_color = contrast(result_color, %f);",
                                         modifier.contrast.contrast));
            break;
        }
        case ColorModifier::Multiply:
        {
            source.append(String::format("result_color = multiply(result_color, vec3(%f, %f, %f));",
                                         modifier.multiply.red,
                                         modifier.multiply.green,
                                         modifier.multiply.blue));
            break;
        }
        case ColorModifier::HueReplace:
        {
            source.append(String::format("result_color = hueReplace(result_color, %f);",
                                         modifier.hueReplace.hue));
            break;
        }
        case ColorModifier::SaturationReplace:
        {
            source.append(String::format("result_color = saturationReplace(result_color, %f);",
                                         modifier.saturationReplace.saturation));
            break;
        }
        case ColorModifier::BrightnessReplace:
        {
            source.append(String::format("result_color = brightnessReplace(result_color, %f);",
                                         modifier.brightnessReplace.brightness));
            break;
        }
        }
    }

    source.append("}");

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
                                        false,
                                        width,
                                        height,
                                        1,
                                        0,
                                        GfxTexPurpose::Other,
                                        GfxTexFormat::RGBF32_F16);
        readColorTexture->allocMipmap(0, 1, nullptr);

        writeColorTexture->startCreation(GfxTextureType::Texture2D,
                                         false,
                                         width,
                                         height,
                                         1,
                                         0,
                                         GfxTexPurpose::Other,
                                         GfxTexFormat::RGBF32_F16);
        writeColorTexture->allocMipmap(0, 1, nullptr);

        depthTexture->startCreation(GfxTextureType::Texture2D,
                                    false,
                                    width,
                                    height,
                                    1,
                                    0,
                                    GfxTexPurpose::Other,
                                    GfxTexFormat::DepthF32_F24);
        depthTexture->allocMipmap(0, 1, nullptr);

        materialTexture->startCreation(GfxTextureType::Texture2D,
                                       false,
                                       width,
                                       height,
                                       1,
                                       0,
                                       GfxTexPurpose::Other,
                                       GfxTexFormat::RedGreenU8);
        materialTexture->allocMipmap(0, 1, nullptr);

        normalTexture->startCreation(GfxTextureType::Texture2D,
                                     false,
                                     width,
                                     height,
                                     1,
                                     0,
                                     GfxTexPurpose::Other,
                                     GfxTexFormat::RGBI16);
        normalTexture->allocMipmap(0, 1, nullptr);

        ssaoTexture->startCreation(GfxTextureType::Texture2D,
                                   false,
                                   width,
                                   height,
                                   1,
                                   0,
                                   GfxTexPurpose::Other,
                                   GfxTexFormat::RGBAF32_F16);
        ssaoTexture->allocMipmap(0, 1, nullptr);

        ssaoBlurXTexture->startCreation(GfxTextureType::Texture2D,
                                        false,
                                        width,
                                        height,
                                        1,
                                        0,
                                        GfxTexPurpose::Other,
                                        GfxTexFormat::RGBAF32_F16);
        ssaoBlurXTexture->allocMipmap(0, 1, nullptr);

        bloomBlurXTexture->startCreation(GfxTextureType::Texture2D,
                                         false,
                                         width/4,
                                         height/4,
                                         1,
                                         0,
                                         GfxTexPurpose::Other,
                                         GfxTexFormat::RGBF32_F16);
        bloomBlurXTexture->allocMipmap(0, 1, nullptr);

        bloom1Texture->startCreation(GfxTextureType::Texture2D,
                                     false,
                                     width/4,
                                     height/4,
                                     1,
                                     0,
                                     GfxTexPurpose::Other,
                                     GfxTexFormat::RGBF32_F16);
        bloom1Texture->allocMipmap(0, 1, nullptr);

        bloom2Texture->startCreation(GfxTextureType::Texture2D,
                                     false,
                                     width/4,
                                     height/4,
                                     1,
                                     0,
                                     GfxTexPurpose::Other,
                                     GfxTexFormat::RGBF32_F16);
        bloom2Texture->allocMipmap(0, 1, nullptr);

        bloom3Texture->startCreation(GfxTextureType::Texture2D,
                                     false,
                                     width/4,
                                     height/4,
                                     1,
                                     0,
                                     GfxTexPurpose::Other,
                                     GfxTexFormat::RGBF32_F16);
        bloom3Texture->allocMipmap(0, 1, nullptr);

        bloom4Texture->startCreation(GfxTextureType::Texture2D,
                                     false,
                                     width/4,
                                     height/4,
                                     1,
                                     0,
                                     GfxTexPurpose::Other,
                                     GfxTexFormat::RGBF32_F16);
        bloom4Texture->allocMipmap(0, 1, nullptr);

        bloomDownsampleTexture->startCreation(GfxTextureType::Texture2D,
                                              false,
                                              width/4,
                                              height/4,
                                              1,
                                              0,
                                              GfxTexPurpose::Other,
                                              GfxTexFormat::RGBF32_F16);
        bloomDownsampleTexture->allocMipmap(0, 1, nullptr);

        /*luminanceTexture->startCreation(GfxTextureType::Texture2D,
                                        false,
                                        width,
                                        height,
                                        0,
                                        GfxTexPurpose::Other,
                                        GfxTexFormat::RedF32_F16);
        luminanceTexture->allocMipmap(0, 1, nullptr);*/

        geomNormalTexture->startCreation(GfxTextureType::Texture2D,
                                         false,
                                         width,
                                         height,
                                         1,
                                         0,
                                         GfxTexPurpose::Other,
                                         GfxTexFormat::RGBI16);
        geomNormalTexture->allocMipmap(0, 1, nullptr);
    }
}

void GfxRenderer::render()
{
    stats.numDrawCalls = 0;

    GfxTexture *oldReadTex = readColorTexture;
    GfxTexture *oldWriteTex = writeColorTexture;
    GfxFramebuffer *oldReadFb = readFramebuffer;
    GfxFramebuffer *oldWriteFb = writeFramebuffer;

    uint64_t start = platform->getTime();

    batches.clear();
    batchEntities(scene->getEntities());

    stats.batchingTiming = float(platform->getTime() - start) / platform->getTimerFrequency();

    //TODO: Add a timing for this.
    for (auto batch : batches)
    {
        if (batch.animState != nullptr)
        {
            batch.animState->updateMatrices();
        }
    }

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

    gfxApi->clearColor(0, Float4(0.0f));
    gfxApi->clearColor(1, Float4(0.0f));
    gfxApi->clearColor(2, Float4(0.5f, 0.5f, 0.5f, 0.0f));

    renderBatches(false);

    renderTerrain();

    swapFramebuffers();

    gfxApi->setWriteDepth(false);
    gfxApi->setDepthFunction(GfxAlways);

    gBufferTimer->end();
    stats.gbufferCPUTiming = float(platform->getTime() - start) / platform->getTimerFrequency();

    //Generate normals
    /*gfxApi->setCurrentFramebuffer(geomNormalFramebuffer);

    gfxApi->begin(compiledPostEffectVertex,
                  nullptr,
                  nullptr,
                  nullptr,
                  compiledGenerateNormalsFragment,
                  quadMesh);

    gfxApi->addTextureBinding(compiledGenerateNormalsFragment, "depthTexture", depthTexture);
    gfxApi->uniform(compiledGenerateNormalsFragment, "viewProjectionMatrix", camera.getProjectionMatrix() * camera.getViewMatrix());

    gfxApi->end(quadMesh->primitive,
                quadMesh->numVertices,
                quadMesh->winding);*/

    //SSAO
    ssaoTimer->begin();

    gfxApi->setCurrentFramebuffer(ssaoFramebuffer);

    gfxApi->begin(ssao, quadMesh);

    GfxCompiledShader *ssaoFragment = ssao->getCompiled(GfxShaderType::Fragment);

    gfxApi->addTextureBinding(ssaoFragment, "depthTexture", depthTexture);
    gfxApi->addTextureBinding(ssaoFragment, "normalTexture", normalTexture);
    gfxApi->addTextureBinding(ssaoFragment, "randomTexture", ssaoRandomTexture);
    gfxApi->uniform(ssaoFragment, "normalMatrix", Matrix3x3(camera.getViewMatrix().inverse().transpose()));
    gfxApi->uniform(ssaoFragment, "inverseProjectionMatrix", camera.getProjectionMatrix().inverse());
    gfxApi->uniform(ssaoFragment, "radius", 1.0f);
    gfxApi->uniform(ssaoFragment, "exponent", 1.5f);
    gfxApi->uniform(ssaoFragment, "multiplier", 4.0f);
    gfxApi->uniform(ssaoFragment, "cosAngleBias", 0.0833f);

    gfxApi->end();

    ssaoTimer->end();

    //SSAO Blur X
    ssaoBlurXTimer->begin();

    gfxApi->setCurrentFramebuffer(ssaoBlurXFramebuffer);

    gfxApi->begin(ssaoBlurX, quadMesh);

    GfxCompiledShader *ssaoBlurXFragment = ssaoBlurX->getCompiled(GfxShaderType::Fragment);
    gfxApi->addTextureBinding(ssaoBlurXFragment, "aoTexture", ssaoTexture);

    gfxApi->end();
    ++stats.numDrawCalls;

    ssaoBlurXTimer->end();

    //SSAO Blur Y
    ssaoBlurYTimer->begin();

    gfxApi->setCurrentFramebuffer(ssaoFramebuffer);

    gfxApi->begin(ssaoBlurY, quadMesh);

    GfxCompiledShader *ssaoBlurYFragment = ssaoBlurY->getCompiled(GfxShaderType::Fragment);
    gfxApi->addTextureBinding(ssaoBlurYFragment, "aoTexture", ssaoBlurXTexture);

    gfxApi->end();
    ++stats.numDrawCalls;

    ssaoBlurYTimer->end();

    /*//SSAO Upsample
    ssaoUpsampleTimer->begin();

    gfxApi->setCurrentFramebuffer(ssaoFinalFramebuffer);
    gfxApi->setViewport(0, 0, width, height);

    gfxApi->begin(ssaoUpsample, quadMesh);

    GfxCompiledShader *ssaoUpsampleFragment = ssaoUpsample->getCompiled(GfxShaderType::Fragment);
    gfxApi->addTextureBinding(ssaoUpsampleFragment, "aoTexture", ssaoTexture);

    gfxApi->end();
    ++stats.numDrawCalls;

    ssaoUpsampleTimer->end();*/

    //Lighting using the G buffer
    deferredShadingTimer->begin();

    gfxApi->setCurrentFramebuffer(writeFramebuffer);
    gfxApi->clearColor(0, Float4(0.0f));

    Matrix4x4 viewProjection = (camera.getProjectionMatrix() * camera.getViewMatrix());

    gfxApi->setBlendingEnabled(true);
    gfxApi->setBlendFactors(GfxOne, GfxOne, GfxOne, GfxOne);
    gfxApi->setBlendMode(GfxAdd, GfxAdd);

    for (auto light : lights)
    {
        GfxShaderCombination *shaders;

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
        gfxApi->uniform(fragment, "viewProjection", viewProjection);
        gfxApi->uniform(fragment, "lightColor", light->color * light->power);
        gfxApi->uniform(fragment, "lightAmbientStrength", light->ambientStrength);
        gfxApi->uniform(fragment, "cameraPosition", camera.getPosition());

        if (light->getShadowmap() != nullptr)
        {
            GfxTexture *shadowmap = light->getShadowmap();
            gfxApi->addTextureBinding(fragment, "depthmap", shadowmap);
            gfxApi->addTextureBinding(fragment, "shadowmap", shadowmap, TextureSampler::createShadowmap());

            gfxApi->uniform(fragment, "shadowmapViewMatrix", light->getViewMatrix());
            gfxApi->uniform(fragment, "shadowmapProjectionMatrix", light->getProjectionMatrix());
            gfxApi->uniform(fragment, "shadowMinBias", light->shadowMinBias);
            gfxApi->uniform(fragment, "shadowBiasScale", light->shadowBiasScale);
            gfxApi->uniform(fragment, "shadowFixedBias", light->shadowFixedBias);
            gfxApi->uniform(fragment, "shadowRadius", light->shadowRadius);
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
                gfxApi->uniform(fragment, "lightFar", light->shadowmapFar);
            }
            break;
        }
        }

        gfxApi->end();
        ++stats.numDrawCalls;
    }

    deferredShadingTimer->end();

    gfxApi->setBlendingEnabled(false);

    //Forward
    start = platform->getTime();
    forwardTimer->begin();

    gfxApi->setWriteDepth(true);
    gfxApi->setDepthFunction(GfxLessEqual);

    fillLightBuffer(scene);

    renderBatches(true);

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

    //Luminance calculation.
    /*luminanceCalcTimer->begin();

    gfxApi->setCurrentFramebuffer(luminanceFramebuffer);

    gfxApi->begin(compiledPostEffectVertex,
                  nullptr,
                  nullptr,
                  nullptr,
                  compiledLumCalcFragment,
                  quadMesh);

    gfxApi->addTextureBinding(compiledLumCalcFragment, "colorTexture", writeColorTexture);

    gfxApi->end();
    ++stats.numDrawCalls;

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

    DELETE_ARRAY(lums);

    averageLuminance /= lumWidth * lumHeight;

    averageLuminance = std::max(std::exp(averageLuminance), 0.001f);

    luminanceCalcTimer->end();*/

    bloomTimer->begin();

    if (bloomEnabled)
    {
        //Downsample
        gfxApi->setCurrentFramebuffer(bloomDownsampleFramebuffer);
        gfxApi->setViewport(0, 0, width/4, height/4);

        gfxApi->begin(bloomDownsample, quadMesh);

        GfxCompiledShader *bloomDownsampleFragment = bloomDownsample->getCompiled(GfxShaderType::Fragment);

        gfxApi->addTextureBinding(bloomDownsampleFragment, "colorTexture", readColorTexture);
        gfxApi->uniform(bloomDownsampleFragment, "threshold", bloomThreshold);

        gfxApi->end();
        ++stats.numDrawCalls;

        GfxCompiledShader *bloomBlurXFragment = bloomBlurX->getCompiled(GfxShaderType::Fragment);
        GfxCompiledShader *bloomBlurYFragment = bloomBlurY->getCompiled(GfxShaderType::Fragment);

        #define BLOOM(framebuffer) {\
        int32_t radius = bloomRadiusPixels / 4;\
        float bloomSigma = radius / 3.0f;\
        \
        gfxApi->setCurrentFramebuffer(bloomblurXFramebuffer);\
\
        gfxApi->begin(bloomBlurX, quadMesh);\
\
        gfxApi->addTextureBinding(bloomBlurXFragment, "bloomTexture", bloomDownsampleTexture);\
        gfxApi->uniform(bloomBlurXFragment, "radius", (int32_t)radius);\
        gfxApi->uniform(bloomBlurXFragment, "sigma", bloomSigma);\
\
        gfxApi->end();\
        ++stats.numDrawCalls;\
\
        gfxApi->setCurrentFramebuffer(framebuffer);\
\
        gfxApi->begin(bloomBlurY, quadMesh);\
\
        gfxApi->addTextureBinding(bloomBlurYFragment, "bloomTexture", bloomBlurXTexture);\
        gfxApi->uniform(bloomBlurYFragment, "radius", (int32_t)radius);\
        gfxApi->uniform(bloomBlurYFragment, "sigma", bloomSigma);\
\
        gfxApi->end();\
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

        //Apply bloom
        gfxApi->setCurrentFramebuffer(writeFramebuffer);
        gfxApi->setViewport(0, 0, width, height);

        gfxApi->begin(applyBloom, quadMesh);

        GfxCompiledShader *applyBloomFragment = applyBloom->getCompiled(GfxShaderType::Fragment);

        gfxApi->addTextureBinding(applyBloomFragment, "colorTexture", readColorTexture);
        gfxApi->addTextureBinding(applyBloomFragment, "bloom1Texture", bloom1Texture);
        gfxApi->addTextureBinding(applyBloomFragment, "bloom2Texture", bloom2Texture);
        gfxApi->addTextureBinding(applyBloomFragment, "bloom3Texture", bloom3Texture);
        gfxApi->addTextureBinding(applyBloomFragment, "bloom4Texture", bloom4Texture);
        gfxApi->uniform(applyBloomFragment, "bloom1Strength", bloom1Strength);
        gfxApi->uniform(applyBloomFragment, "bloom2Strength", bloom2Strength);
        gfxApi->uniform(applyBloomFragment, "bloom3Strength", bloom3Strength);
        gfxApi->uniform(applyBloomFragment, "bloom4Strength", bloom4Strength);

        gfxApi->end();
        ++stats.numDrawCalls;

        swapFramebuffers();
    }

    bloomTimer->end();

    //Color modifiers.
    colorModifierTimer->begin();

    gfxApi->setCurrentFramebuffer(writeFramebuffer);

    gfxApi->begin(colorModify, quadMesh);

    GfxCompiledShader *colorModifyFragment = colorModify->getCompiled(GfxShaderType::Fragment);

    gfxApi->addTextureBinding(colorModifyFragment, "colorTexture", readColorTexture);

    gfxApi->end();
    ++stats.numDrawCalls;

    colorModifierTimer->end();

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
    gammaCorrectionTimer->begin();

    gfxApi->setCurrentFramebuffer(writeFramebuffer);

    gfxApi->begin(gammaCorrection, quadMesh);

    gfxApi->addTextureBinding(gammaCorrection->getCompiled(GfxShaderType::Fragment), "colorTexture", readColorTexture);

    gfxApi->end();
    ++stats.numDrawCalls;

    swapFramebuffers();

    gammaCorrectionTimer->end();

    //FXAA
    fxaaTimer->begin();

    gfxApi->setCurrentFramebuffer(nullptr);

    gfxApi->begin(fxaa, quadMesh);

    gfxApi->addTextureBinding(fxaa->getCompiled(GfxShaderType::Fragment), "colorTexture", readColorTexture);

    gfxApi->end();
    ++stats.numDrawCalls;

    fxaaTimer->end();

    readColorTexture = oldReadTex;
    writeColorTexture = oldWriteTex;
    readFramebuffer = oldReadFb;
    writeFramebuffer = oldWriteFb;

    updateStats();
}

AABB GfxRenderer::computeSceneAABB() const
{
    AABB aabb;

    const List<Entity *>& entities = scene->getEntities();

    _computeSceneAABB(entities, aabb);

    if (terrain != nullptr)
    {
        aabb.extend(terrain->getMesh()->aabb);
    }

    return aabb;
}

AABB GfxRenderer::computeShadowCasterAABB() const
{
    AABB aabb;

    const List<Entity *>& entities = scene->getEntities();

    _computeShadowCasterAABB(entities, aabb);

    if (terrain != nullptr)
    {
        aabb.extend(terrain->getMesh()->aabb);
    }

    return aabb;
}

void GfxRenderer::_computeSceneAABB(const List<Entity *>& entities, AABB& aabb) const
{
    for (auto entity : entities)
    {
        Matrix4x4 transform = entity->getFinalTransform();

        if (entity->hasRenderComponent())
        {
            const RenderComponent *comp = entity->getRenderComponent();

            if (comp->mode == RenderMode::Model)
            {
                GfxModel *model = comp->model;

                for (auto subModel : model->subModels)
                {
                    for (auto lod : subModel)
                    {
                        AABB aabb2 = lod.mesh->aabb.transform(transform * lod.worldMatrix);

                        if (lod.material->getDisplacementMap() != nullptr)
                        {
                            aabb2.grow(lod.material->displacementStrength);
                        }

                        aabb.extend(aabb2);
                    }
                }
            }
        }

        _computeSceneAABB(entity->getEntities(), aabb);
    }
}

void GfxRenderer::_computeShadowCasterAABB(const List<Entity *>& entities, AABB& aabb) const
{
    for (auto entity : entities)
    {
        Matrix4x4 transform = entity->getFinalTransform();

        if (entity->hasRenderComponent())
        {
            const RenderComponent *comp = entity->getRenderComponent();

            if (comp->mode == RenderMode::Model and comp->modelData.shadowCaster)
            {
                GfxModel *model = comp->model;

                for (auto subModel : model->subModels)
                {
                    for (auto lod : subModel)
                    {
                        AABB aabb2 = lod.mesh->aabb.transform(transform * lod.worldMatrix);

                        if (lod.material->getDisplacementMap() != nullptr and lod.material->shadowTesselation)
                        {
                            aabb2.grow(lod.material->displacementStrength);
                        }

                        aabb.extend(aabb2);
                    }
                }
            }
        }

        _computeShadowCasterAABB(entity->getEntities(), aabb);
    }
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

void GfxRenderer::batchEntities(const List<Entity *>& entities)
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
                if (comp->getAnimationState() != nullptr)
                {
                    GfxAnimationState *state = comp->getAnimationState();

                    batchModel(transform, comp->model, state->getMesh(), state);
                } else
                {
                    batchModel(transform, comp->model, nullptr, nullptr);
                }
                break;
            }
            default:
            {
                break;
            }
            }
        }

        batchEntities(entity->getEntities());;
    }
}

void GfxRenderer::batchModel(const Matrix4x4& worldMatrix,
                             const GfxModel *model,
                             GfxMesh *animMesh,
                             GfxAnimationState *animState)
{
    Position3D position = Position3D(worldMatrix[0][3],
                                     worldMatrix[1][3],
                                     worldMatrix[2][3]);

    float distance = position.distance(camera.getPosition());

    for (auto subModel : model->subModels)
    {
        for (auto lod : subModel)
        {
            if (lod.minDistance < distance and
                distance < lod.maxDistance)
            {
                Matrix4x4 newWorldMatrix = worldMatrix * lod.worldMatrix;

                GfxMaterial *material = lod.material;
                GfxMesh *mesh = lod.mesh;

                if (mesh == animMesh)
                {
                    Batch batch;
                    batch.material = material;
                    batch.mesh = mesh;
                    batch.worldMatrices = List<Matrix4x4>();
                    batch.worldMatrices.append(newWorldMatrix);
                    batch.animState = animState;
                    batches.append(batch);
                    continue;
                }

                bool found = false;

                for (size_t k = 0; k < batches.getCount(); ++k)
                {
                    if (batches[k].material == material and batches[k].mesh == mesh)
                    {
                        batches[k].worldMatrices.append(newWorldMatrix);
                        found = true;
                        break;
                    }
                }

                if (not found)
                {
                    Batch batch;
                    batch.material = material;
                    batch.mesh = mesh;
                    batch.worldMatrices.append(newWorldMatrix);
                    batch.animState = nullptr;

                    batches.append(batch);
                }
                break;
            }
        }
    }
}

void GfxRenderer::renderBatches(bool forward)
{
    Matrix4x4 projectionMatrix = camera.getProjectionMatrix();
    Matrix4x4 viewMatrix = camera.getViewMatrix();

    for (auto batch : batches)
    {
        if (batch.material->isForward() == forward)
        {
            List<Matrix4x4> worldMatrices = batch.worldMatrices;

            /*uint8_t *matrixData = (uint8_t *)ALLOCATE(worldMatrices.getCount()*128);

            for (size_t j = 0; j < worldMatrices.getCount(); ++j)
            {
                Matrix4x4 worldMatrix = worldMatrices[j];
                Matrix4x4 normalMatrix = Matrix3x3(worldMatrix.inverse().transpose());
                worldMatrix = worldMatrix.transpose();
                normalMatrix = normalMatrix.transpose();

                std::memcpy(matrixData+j*128, (void *)&worldMatrix, 64);
                std::memcpy(matrixData+j*128+64, (void *)&normalMatrix, 64);
            }

            matrixTexture->startCreation(GfxTexture::Texture2D,
                                         false,
                                         worldMatrices.getCount()*8,
                                         1,
                                         1,
                                         255,
                                         GfxTexture::Other,
                                         GfxTexture::RGBAF32);

            matrixTexture->allocMipmap(0, 1, matrixData);

            DEALLOCATE(matrixData);*/

            GfxMaterial *material = batch.material;
            GfxMesh *mesh = batch.mesh;
            GfxShaderCombination *shaderComb = material->getShaderComb();

            bool useTesselation = material->getDisplacementMap() != nullptr and
                                  gfxApi->tesselationSupported() and
                                  mesh->primitive == GfxTriangles;

            gfxApi->pushState();

            if (batch.animState != nullptr)
            {
                shaderComb->setDefine(GfxShaderType::Vertex, "SKELETAL_ANIMATION", "1");
            }

            GfxCompiledShader *vertex = shaderComb->getCompiled(GfxShaderType::Vertex);
            GfxCompiledShader *tessControl = shaderComb->getCompiled(GfxShaderType::TessControl);
            GfxCompiledShader *tessEval = shaderComb->getCompiled(GfxShaderType::TessEval);
            GfxCompiledShader *geometry = shaderComb->getCompiled(GfxShaderType::Geometry);
            GfxCompiledShader *fragment = shaderComb->getCompiled(GfxShaderType::Fragment);

            gfxApi->begin(vertex,
                          tessControl,
                          tessEval,
                          geometry,
                          fragment,
                          mesh);

            if (useTesselation)
            {
                gfxApi->uniform(vertex, "projectionViewMatrix", Matrix4x4());
            } else
            {
                gfxApi->uniform(vertex, "projectionViewMatrix", projectionMatrix * viewMatrix);
            }

            gfxApi->uniform(vertex, "cameraPosition", camera.getPosition());

            if (useTesselation)
            {
                gfxApi->uniform(tessControl, "minTessLevel", material->minTessLevel);
                gfxApi->uniform(tessControl, "maxTessLevel", material->maxTessLevel);
                gfxApi->uniform(tessControl, "tessMinDistance", material->tessMinDistance);
                gfxApi->uniform(tessControl, "tessMaxDistance", material->tessMaxDistance);
                gfxApi->uniform(tessControl, "cameraPosition", camera.getPosition());

                gfxApi->addTextureBinding(tessEval, "heightMap", material->getDisplacementMap());
                gfxApi->uniform(tessEval, "displacementMidlevel", material->displacementMidlevel);
                gfxApi->uniform(tessEval, "projectionViewMatrix", projectionMatrix * viewMatrix);
                gfxApi->uniform(tessEval, "strength", material->displacementStrength);
            }

            gfxApi->uniform(fragment, "smoothness", material->smoothness);
            gfxApi->uniform(fragment, "metalMask", material->metalMask);
            gfxApi->uniform(fragment, "albedo", material->albedo);

            if (material->isForward())
            {
                gfxApi->uniform(fragment, "numSpotLights", (uint32_t)numSpotLights);
                gfxApi->uniform(fragment, "numPointLights", (uint32_t)numPointLights);
                gfxApi->uniform(fragment, "numDirectionalLights", (uint32_t)numDirectionalLights);
                gfxApi->addUBOBinding(fragment, "lights_", lightBuffer);
            }

            if (material->getMaterialMap() != nullptr)
            {
                gfxApi->addTextureBinding(fragment, "materialMap", material->getMaterialMap());
            }

            if (material->getAlbedoMap() != nullptr)
            {
                gfxApi->addTextureBinding(fragment, "albedoMap", material->getAlbedoMap());
            }

            if (material->getNormalMap() != nullptr)
            {
                gfxApi->addTextureBinding(fragment, "normalMap", material->getNormalMap());
            }

            if (material->getParallaxHeightMap() != nullptr)
            {
                gfxApi->addTextureBinding(fragment, "heightMap", material->getParallaxHeightMap());

                gfxApi->uniform(fragment, "heightScale", material->parallaxStrength);
                gfxApi->uniform(fragment, "parallaxEdgeDiscard", material->parallaxEdgeDiscard ? 1 : 0);
            }

            if (material->getPOMHeightMap() != nullptr)
            {
                gfxApi->addTextureBinding(fragment, "heightMap", material->getPOMHeightMap());

                gfxApi->uniform(fragment, "heightScale", material->parallaxStrength);
                gfxApi->uniform(fragment, "parallaxEdgeDiscard", material->parallaxEdgeDiscard ? 1 : 0);
                gfxApi->uniform(fragment, "pomMinLayers", material->pomMinLayers);
                gfxApi->uniform(fragment, "pomMaxLayers", material->pomMaxLayers);
            }

            if (batch.animState != nullptr)
            {
                gfxApi->addUBOBinding(vertex, "bonePositionData", batch.animState->getMatrixBuffer());
                gfxApi->addUBOBinding(vertex, "boneNormalData", batch.animState->getNormalMatrixBuffer());
            }

            //gfxApi->addTextureBinding(vertex, "matrixTexture", matrixTexture);
            gfxApi->addUBOBinding(vertex, "instanceData", instanceBuffer);

            gfxApi->setCullMode(mesh->cullMode);

            if (useTesselation)
            {
                gfxApi->setTessPatchSize(3);
            }

            for (size_t j = 0; j < worldMatrices.getCount()/128; ++j)
            {
                float instanceData[4096];

                for (size_t k = 0; k < 128; ++k)
                {
                    Matrix4x4 worldMatrix = worldMatrices[j*128+k];
                    Matrix4x4 normalMatrix = worldMatrix.inverse();
                    worldMatrix = worldMatrix.transpose();

                    std::memcpy(instanceData+k*32, &worldMatrix, 64);
                    std::memcpy(instanceData+k*32+16, &normalMatrix, 64);
                }

                instanceBuffer->setData(0, 16384, instanceData);

                gfxApi->draw(128);
                ++stats.numDrawCalls;
            }

            size_t numDone = worldMatrices.getCount() / 128 * 128;
            size_t numLeft = worldMatrices.getCount() % 128;

            if (numLeft % 128 != 0)
            {
                float instanceData[numLeft*32];

                for (size_t k = 0; k < numLeft; ++k)
                {
                    Matrix4x4 worldMatrix = worldMatrices[numDone+k];
                    Matrix4x4 normalMatrix = worldMatrix.inverse();
                    worldMatrix = worldMatrix.transpose();

                    std::memcpy(instanceData+k*32, &worldMatrix, 64);
                    std::memcpy(instanceData+k*32+16, &normalMatrix, 64);
                }

                instanceBuffer->setData(0, numLeft*128, instanceData);

                gfxApi->draw(numLeft);
                ++stats.numDrawCalls;
            }

            gfxApi->end(0);

            if (batch.animState != nullptr)
            {
                shaderComb->removeDefine(GfxShaderType::Vertex, "SKELETAL_ANIMATION");
            }

            gfxApi->popState();
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

        gfxApi->end();
        ++stats.numDrawCalls;

        gfxApi->popState();
    }
}

void GfxRenderer::renderBatchesToShadowmap(const Matrix4x4& viewMatrix,
                                           const Matrix4x4& projectionMatrix,
                                           Light *light,
                                           size_t cubemapFace)
{
    for (auto batch : batches)
    {
        GfxMaterial *material = batch.material;
        GfxMesh *mesh = batch.mesh;

        GfxCompiledShader *vertexShader = batch.animState == nullptr ?
                                          compiledShadowmapVertex :
                                          compiledShadowmapVertexAnimated;
        GfxCompiledShader *geometryShader = nullptr;
        GfxCompiledShader *fragmentShader = compiledShadowmapFragment;
        GfxCompiledShader *tessControlShader = nullptr;
        GfxCompiledShader *tessEvalShader = nullptr;

        bool useTesselation = material->getDisplacementMap() != nullptr and
                              material->shadowTesselation and
                              gfxApi->tesselationSupported();

        if (useTesselation)
        {
            vertexShader = batch.animState == nullptr ?
                           compiledShadowmapVertexTesselation :
                           compiledShadowmapVertexTesselationAnimated;
            tessControlShader = compiledShadowmapTessControl;
            tessEvalShader = compiledShadowmapTessEval;
        }

        if (light->type == GfxLightType::Point)
        {
            fragmentShader = compiledPointShadowmapFragment;

            if (light->point.singlePassShadowMap)
            {
                geometryShader = compiledPointShadowmapGeometry;
            }
        }

        gfxApi->begin(vertexShader,
                      tessControlShader,
                      tessEvalShader,
                      geometryShader,
                      fragmentShader,
                      mesh);

        if (light->type == GfxLightType::Point)
        {
            Position3D pos = light->point.position;

            Matrix4x4 matrices[] = {Matrix4x4::lookAt(pos,
                                                      pos+Direction3D(1.0f, 0.0f, 0.0f),
                                                      Direction3D(0.0f, -1.0f, 0.0f)),
                                    Matrix4x4::lookAt(pos,
                                                      pos+Direction3D(-1.0f, 0.0f, 0.0f),
                                                      Direction3D(0.0f, -1.0f, 0.0f)),
                                    Matrix4x4::lookAt(pos,
                                                      pos+Direction3D(0.0f, 1.0f, 0.0f),
                                                      Direction3D(0.0f, 0.0f, 1.0f)),
                                    Matrix4x4::lookAt(pos,
                                                      pos+Direction3D(0.0f, -1.0f, 0.0f),
                                                      Direction3D(0.0f, 0.0f, -1.0f)),
                                    Matrix4x4::lookAt(pos,
                                                      pos+Direction3D(0.0f, 0.0f, 1.0f),
                                                      Direction3D(0.0f, -1.0f, 0.0f)),
                                    Matrix4x4::lookAt(pos,
                                                      pos+Direction3D(0.0f, 0.0f, -1.0f),
                                                      Direction3D(0.0f, -1.0f, 0.0f))};

            if (light->point.singlePassShadowMap)
            {
                gfxApi->uniform(geometryShader, "matrix0", projectionMatrix * matrices[0]);
                gfxApi->uniform(geometryShader, "matrix1", projectionMatrix * matrices[1]);
                gfxApi->uniform(geometryShader, "matrix2", projectionMatrix * matrices[2]);
                gfxApi->uniform(geometryShader, "matrix3", projectionMatrix * matrices[3]);
                gfxApi->uniform(geometryShader, "matrix4", projectionMatrix * matrices[4]);
                gfxApi->uniform(geometryShader, "matrix5", projectionMatrix * matrices[5]);
            }

            gfxApi->uniform(fragmentShader, "lightPos", light->point.position);
            gfxApi->uniform(fragmentShader, "lightFar", light->shadowmapFar);

            if (light->point.singlePassShadowMap)
            {
                if (not useTesselation)
                {
                    gfxApi->uniform(vertexShader, "projectionMatrix", Matrix4x4());
                    gfxApi->uniform(vertexShader, "viewMatrix", Matrix4x4());
                } else
                {
                    gfxApi->uniform(tessEvalShader, "projectionMatrix", Matrix4x4());
                    gfxApi->uniform(tessEvalShader, "viewMatrix", Matrix4x4());
                }
            } else
            {
                Matrix4x4 viewMatrix = matrices[cubemapFace];

                if (not useTesselation)
                {
                    gfxApi->uniform(vertexShader, "projectionMatrix", projectionMatrix);
                    gfxApi->uniform(vertexShader, "viewMatrix", viewMatrix);
                } else
                {
                    gfxApi->uniform(tessEvalShader, "projectionMatrix", projectionMatrix);
                    gfxApi->uniform(tessEvalShader, "viewMatrix", viewMatrix);
                }
            }
        } else
        {
            if (not useTesselation)
            {
                gfxApi->uniform(vertexShader, "projectionMatrix", projectionMatrix);
                gfxApi->uniform(vertexShader, "viewMatrix", viewMatrix);
            }
        }

        if (useTesselation)
        {
            if (light->type != GfxLightType::Point)
            {
                gfxApi->uniform(tessEvalShader, "projectionMatrix", projectionMatrix);
                gfxApi->uniform(tessEvalShader, "viewMatrix", viewMatrix);
            }

            gfxApi->uniform(tessControlShader, "minTessLevel", material->shadowMinTessLevel);
            gfxApi->uniform(tessControlShader, "maxTessLevel", material->shadowMaxTessLevel);
            gfxApi->uniform(tessControlShader, "tessMinDistance", material->tessMaxDistance);
            gfxApi->uniform(tessControlShader, "tessMaxDistance", material->tessMinDistance);
            gfxApi->addTextureBinding(tessEvalShader, "heightMap", material->getDisplacementMap());
            gfxApi->uniform(tessEvalShader, "strength", material->displacementStrength);
            gfxApi->uniform(tessEvalShader, "displacementMidlevel", material->displacementMidlevel);
            gfxApi->uniform(tessControlShader, "cameraPosition", camera.getPosition());
        }

        gfxApi->uniform(fragmentShader, "biasScale", light->shadowAutoBiasScale);

        gfxApi->setTessPatchSize(3);

        if (batch.animState != nullptr)
        {
            gfxApi->addUBOBinding(vertexShader, "bonePositionData", batch.animState->getMatrixBuffer());

            if (useTesselation)
            {
                gfxApi->addUBOBinding(vertexShader, "boneNormalData", batch.animState->getNormalMatrixBuffer());
            }
        }

        for (auto worldMatrix : batch.worldMatrices)
        {
            gfxApi->uniform(vertexShader, "worldMatrix", worldMatrix);

            if (useTesselation)
            {
                gfxApi->uniform(vertexShader, "normalMatrix", Matrix3x3(worldMatrix.inverse().transpose()));
            }

            gfxApi->draw();
            ++stats.numDrawCalls;
        }

        gfxApi->end(0);
    }
}

void GfxRenderer::renderShadowmap(Light *light)
{
    Matrix4x4 projectionMatrix = light->getProjectionMatrix();
    Matrix4x4 viewMatrix = light->getViewMatrix();

    gfxApi->pushState();
    gfxApi->resetState();

    gfxApi->setViewport(0, 0, light->getShadowmapResolution(), light->getShadowmapResolution());

    bool singlePass = light->type == GfxLightType::Point ? light->point.singlePassShadowMap : true;

    for (size_t i = 0; i < (singlePass ? 1 : 6); ++i)
    {
        if (singlePass)
        {
            gfxApi->setCurrentFramebuffer(light->getShadowmapFramebuffer());
        } else
        {
            gfxApi->setCurrentFramebuffer(light->getPointLightFramebuffers()[i]);
        }

        gfxApi->clearDepth();

        renderBatchesToShadowmap(viewMatrix, projectionMatrix, light, i);
    }

    if (light->type != GfxLightType::Point)
    {
        renderTerrainToShadowmap(projectionMatrix, viewMatrix, light->shadowAutoBiasScale);
    }

    gfxApi->popState();
}

void GfxRenderer::renderTerrain()
{
    if (terrain == nullptr)
    {
        return;
    }

    Matrix4x4 viewMatrix = camera.getViewMatrix();
    Matrix4x4 projectionMatrix = camera.getProjectionMatrix();

    gfxApi->pushState();

    for (auto layer : terrain->layers)
    {
        GfxMaterial *material = layer.getMaterial();
        GfxShaderCombination *shaderComb = material->getShaderComb();

        shaderComb->setDefine(GfxShaderType::Fragment, "TERRAIN", "1");

        GfxCompiledShader *fragment = shaderComb->getCompiled(GfxShaderType::Fragment);

        gfxApi->begin(compiledTerrainVertex,
                      compiledTerrainTessControl,
                      compiledTerrainTessEval,
                      nullptr,
                      fragment,
                      terrain->getMesh());

        gfxApi->uniform(compiledTerrainVertex, "sizeInChunks", (uint32_t)terrain->getSizeInChunks());
        gfxApi->uniform(compiledTerrainVertex, "chunkSize", terrain->getChunkSize());
        gfxApi->uniform(compiledTerrainTessControl, "cameraPosition", camera.getPosition());
        gfxApi->uniform(compiledTerrainTessEval, "viewMatrix", viewMatrix);
        gfxApi->uniform(compiledTerrainTessEval, "projectionMatrix", projectionMatrix);
        gfxApi->uniform(compiledTerrainTessEval, "size", terrain->getChunkSize() * terrain->getSizeInChunks());
        gfxApi->uniform(compiledTerrainTessEval, "scale", terrain->getScale());
        gfxApi->uniform(compiledTerrainTessEval, "cameraPosition", camera.getPosition());
        gfxApi->uniform(compiledTerrainTessEval, "uvScale", layer.uvScale);
        gfxApi->addTextureBinding(compiledTerrainTessEval,
                                  "heightMap",
                                  terrain->getHeightmap());

        gfxApi->uniform(fragment, "smoothness", material->smoothness);
        gfxApi->uniform(fragment, "metalMask", material->metalMask);
        gfxApi->uniform(fragment, "albedo", material->albedo);

        if (material->getMaterialMap() != nullptr)
        {
            gfxApi->addTextureBinding(fragment, "materialMap", material->getMaterialMap());
        }

        if (material->getAlbedoMap() != nullptr)
        {
            gfxApi->addTextureBinding(fragment, "albedoMap", material->getAlbedoMap());
        }

        if (material->getNormalMap() != nullptr)
        {
            gfxApi->addTextureBinding(fragment, "normalMap", material->getNormalMap());
        }

        if (material->getParallaxHeightMap() != nullptr)
        {
            gfxApi->addTextureBinding(fragment, "heightMap", material->getParallaxHeightMap());

            gfxApi->uniform(fragment, "heightScale", material->parallaxStrength);
            gfxApi->uniform(fragment, "parallaxEdgeDiscard", material->parallaxEdgeDiscard ? 1 : 0);
        }

        if (material->getPOMHeightMap() != nullptr)
        {
            gfxApi->addTextureBinding(fragment, "heightMap", material->getPOMHeightMap());

            gfxApi->uniform(fragment, "heightScale", material->parallaxStrength);
            gfxApi->uniform(fragment, "parallaxEdgeDiscard", material->parallaxEdgeDiscard ? 1 : 0);
            gfxApi->uniform(fragment, "pomMinLayers", material->pomMinLayers);
            gfxApi->uniform(fragment, "pomMaxLayers", material->pomMaxLayers);
        }

        gfxApi->addTextureBinding(fragment, "weightMap", layer.getWeight());

        gfxApi->setTessPatchSize(4);

        gfxApi->end(terrain->getSizeInChunks() * terrain->getSizeInChunks());
        ++stats.numDrawCalls;

        shaderComb->removeDefine(GfxShaderType::Fragment, "TERRAIN");

        gfxApi->setBlendingEnabled(true);
        gfxApi->setBlendFactors(GfxOne, GfxOne, GfxOne, GfxOne);
        gfxApi->setDepthFunction(GfxLessEqual);
    }

    gfxApi->popState();
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

    gfxApi->end(terrain->getSizeInChunks() * terrain->getSizeInChunks());
    ++stats.numDrawCalls;
}

void GfxRenderer::swapFramebuffers()
{
    std::swap(writeFramebuffer, readFramebuffer);
    std::swap(writeColorTexture, readColorTexture);
}
