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
    pointShadowmapGeometry = resMgr->getResource<GfxShader>("resources/shaders/pointShadowmapGeometry.bin");

    if (gfxApi->tesselationSupported())
    {
        shadowmapTessControl = resMgr->getResource<GfxShader>("resources/shaders/shadowmapControl.bin");
        shadowmapTessEval = resMgr->getResource<GfxShader>("resources/shaders/shadowmapEval.bin");
    }

    shadowmapFragment = resMgr->getResource<GfxShader>("resources/shaders/shadowmapFragment.bin");
    pointShadowmapFragment = resMgr->getResource<GfxShader>("resources/shaders/pointShadowmapFragment.bin");
    overlayVertex = resMgr->getResource<GfxShader>("resources/shaders/overlayVertex.bin");
    overlayFragment = resMgr->getResource<GfxShader>("resources/shaders/overlayFragment.bin");
    colorModifierFragment = NEW(GfxShader);
    gammaCorrectionFragment = resMgr->getResource<GfxShader>("resources/shaders/gammaCorrectionFragment.bin");

    compiledFXAAFragment = fxaaFragment->getCompiled();
    compiledLightingDirectional = lightingDirectional->getCompiled();
    compiledLightingDirectionalShadow = lightingDirectional->getCompiled(HashMapBuilder<String, String>().add("SHADOW_MAP", "1"));
    compiledLightingPoint = lightingPoint->getCompiled();
    compiledLightingPointShadow = lightingPoint->getCompiled(HashMapBuilder<String, String>().add("SHADOW_MAP", "1"));
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

    if (gfxApi->tesselationSupported())
    {
        compiledShadowmapVertexTesselation = shadowmapVertex->getCompiled(HashMapBuilder<String, String>().add("TESSELATION", "1"));
    }

    compiledPointShadowmapGeometry = pointShadowmapGeometry->getCompiled();

    if (gfxApi->tesselationSupported())
    {
        compiledShadowmapTessControl = shadowmapTessControl->getCompiled();
        compiledShadowmapTessEval = shadowmapTessEval->getCompiled();
    }

    compiledShadowmapFragment = shadowmapFragment->getCompiled();
    compiledPointShadowmapFragment = pointShadowmapFragment->getCompiled();
    compiledOverlayVertex = overlayVertex->getCompiled();
    compiledOverlayFragment = overlayFragment->getCompiled();
    compiledGammaCorrectionFragment = gammaCorrectionFragment->getCompiled();

    updateColorModifierShader();

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
    colorModifierTimer = gfxApi->createTimer();
    bloomXTimer = gfxApi->createTimer();
    bloomYTimer = gfxApi->createTimer();
    //luminanceCalcTimer = gfxApi->createTimer();
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
    DELETE(GPUTimer, colorModifierTimer);
    DELETE(GPUTimer, bloomXTimer);
    DELETE(GPUTimer, bloomYTimer);
    //DELETE(GPUTimer, luminanceCalcTimer);
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

    if (colorModifierTimer->resultAvailable())
    {
        stats.colorModifierTiming = colorModifierTimer->getResult() / (float)colorModifierTimer->getResultResolution();
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

    if (shadowmapTimer->resultAvailable())
    {
        stats.shadowmapTiming = shadowmapTimer->getResult() / (float)shadowmapTimer->getResultResolution();
    }

    if (overlayTimer->resultAvailable())
    {
        stats.overlayTiming = overlayTimer->getResult() / (float)overlayTimer->getResultResolution();
    }
}

void GfxRenderer::updateColorModifierShader()
{
    //uniform.glsl
    String source = "#extension GL_ARB_separate_shader_objects : enable\n"
"\n"
"#ifdef GL_ARB_separate_shader_objects\n"
"#define DECLUNIFORM(type, name) uniform type _##name##_uniform;\n"
"#define U(name) _##name##_uniform\n"
"#else\n"
"#ifdef __VERTEX__\n"
"#define DECLUNIFORM(type, name) uniform type _##name##_vertex;\n"
"#define U(name) _##name##_vertex\n"
"#elif defined(__TESS_CONTROL__)\n"
"#define DECLUNIFORM(type, name) uniform type _##name##_tessControl;\n"
"#define U(name) _##name##_tessControl\n"
"#elif defined(__TESS_EVAL__)\n"
"#define DECLUNIFORM(type, name) uniform type _##name##_tessEval;\n"
"#define U(name) _##name##_tessEval\n"
"#elif defined(__GEOMETRY__)\n"
"#define DECLUNIFORM(type, name) uniform type _##name##_geometry;\n"
"#define U(name) _##name##_geometry\n"
"#elif defined(__FRAGMENT__)\n"
"#define DECLUNIFORM(type, name) uniform type _##name##_fragment;\n"
"#define U(name) _##name##_fragment\n"
"#elif defined(__COMPUTE__)\n"
"#define DECLUNIFORM(type, name) uniform type _##name##_compute;\n"
"#define U(name) _##name##_compute\n"
"#endif\n"
"#endif\n";

    source.append(STR(
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

DECLUNIFORM(sampler2D, colorTexture)

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

vec3 contrast(vec3 color, float contrast)
{
    return (color - 0.5) * contrast + 0.5;
}

vec3 multiply(vec3 color, vec3 by)
{
    return color * by;
}

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
    result_color = texture(U(colorTexture), frag_uv).rgb;
));

    for (size_t i = 0; i < colorModifiers.getCount(); ++i)
    {
        const ColorModifier& modifier = colorModifiers[i];

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

    colorModifierFragment->setSource(GfxShader::Fragment, source);

    compiledColorModifier = colorModifierFragment->getCompiled();
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
    gfxApi->setCullMode(mesh->cullMode);

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
        readColorTexture->allocMipmap(0, 1, nullptr);

        writeColorTexture->startCreation(GfxTexture::Texture2D,
                                         false,
                                         width,
                                         height,
                                         1,
                                         0,
                                         GfxTexture::Other,
                                         GfxTexture::RGBF32_F16);
        writeColorTexture->allocMipmap(0, 1, nullptr);

        depthTexture->startCreation(GfxTexture::Texture2D,
                                    false,
                                    width,
                                    height,
                                    1,
                                    0,
                                    GfxTexture::Other,
                                    GfxTexture::DepthF32_F24);
        depthTexture->allocMipmap(0, 1, nullptr);

        materialTexture->startCreation(GfxTexture::Texture2D,
                                       false,
                                       width,
                                       height,
                                       1,
                                       0,
                                       GfxTexture::Other,
                                       GfxTexture::RedGreenU8);
        materialTexture->allocMipmap(0, 1, nullptr);

        normalTexture->startCreation(GfxTexture::Texture2D,
                                     false,
                                     width,
                                     height,
                                     1,
                                     0,
                                     GfxTexture::Other,
                                     GfxTexture::RGBF32_F16);
        normalTexture->allocMipmap(0, 1, nullptr);

        ssaoTexture->startCreation(GfxTexture::Texture2D,
                                   false,
                                   width,
                                   height,
                                   1,
                                   0,
                                   GfxTexture::Other,
                                   GfxTexture::LuminanceU8);
        ssaoTexture->allocMipmap(0, 1, nullptr);

        ssaoBlurXTexture->startCreation(GfxTexture::Texture2D,
                                        false,
                                        width,
                                        height,
                                        1,
                                        0,
                                        GfxTexture::Other,
                                        GfxTexture::LuminanceU8);
        ssaoBlurXTexture->allocMipmap(0, 1, nullptr);

        bloomBlurXTexture->startCreation(GfxTexture::Texture2D,
                                         false,
                                         width,
                                         height,
                                         1,
                                         0,
                                         GfxTexture::Other,
                                         GfxTexture::RGBF32_F16);
        bloomBlurXTexture->allocMipmap(0, 1, nullptr);

        /*luminanceTexture->startCreation(GfxTexture::Texture2D,
                                        false,
                                        width,
                                        height,
                                        0,
                                        GfxTexture::Other,
                                        GfxTexture::RedF32_F16);
        luminanceTexture->allocMipmap(0, 1, nullptr);*/
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

        light->updateMatrices(this);

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
                  nullptr,
                  nullptr,
                  nullptr,
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
                  nullptr,
                  nullptr,
                  nullptr,
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
                  nullptr,
                  nullptr,
                  nullptr,
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
            if (light->getShadowmap() != nullptr)
            {
                fragmentShader = compiledLightingDirectionalShadow;
            } else
            {
                fragmentShader = compiledLightingDirectional;
            }
            break;
        }
        case Light::Point:
        {
            if (light->getShadowmap() != nullptr)
            {
                fragmentShader = compiledLightingPointShadow;
            } else
            {
                fragmentShader = compiledLightingPoint;
            }
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
                      nullptr,
                      nullptr,
                      nullptr,
                      fragmentShader,
                      quadMesh);

        gfxApi->addTextureBinding(fragmentShader, "albedoTexture", readColorTexture);
        gfxApi->addTextureBinding(fragmentShader, "materialTexture", materialTexture);
        gfxApi->addTextureBinding(fragmentShader, "normalTexture", normalTexture);
        gfxApi->addTextureBinding(fragmentShader, "depthTexture", depthTexture);
        gfxApi->addTextureBinding(fragmentShader, "aoTexture", ssaoTexture);
        gfxApi->uniform(fragmentShader, "viewProjection", viewProjection);
        gfxApi->uniform(fragmentShader, "lightColor", light->color * light->power);
        gfxApi->uniform(fragmentShader, "lightAmbientStrength", light->ambientStrength);
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

            if (light->getShadowmap() != nullptr)
            {
                gfxApi->uniform(fragmentShader, "lightFar", light->shadowmapFar);
            }
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
                  nullptr,
                  nullptr,
                  nullptr,
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
                      nullptr,
                      nullptr,
                      nullptr,
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
                      nullptr,
                      nullptr,
                      nullptr,
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

    //Color modifiers.
    colorModifierTimer->begin();

    gfxApi->setCurrentFramebuffer(writeFramebuffer);

    gfxApi->begin(compiledPostEffectVertex,
                  nullptr,
                  nullptr,
                  nullptr,
                  compiledColorModifier,
                  quadMesh);

    gfxApi->addTextureBinding(compiledColorModifier, "colorTexture", readColorTexture);

    gfxApi->end(quadMesh->primitive,
                quadMesh->numVertices,
                quadMesh->winding);

    colorModifierTimer->end();

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
                              nullptr,
                              nullptr,
                              nullptr,
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

    gfxApi->setCurrentFramebuffer(writeFramebuffer);

    gfxApi->begin(compiledPostEffectVertex,
                  nullptr,
                  nullptr,
                  nullptr,
                  compiledGammaCorrectionFragment,
                  quadMesh);

    gfxApi->addTextureBinding(compiledGammaCorrectionFragment, "colorTexture", readColorTexture);

    gfxApi->end(quadMesh->primitive,
                quadMesh->numVertices,
                quadMesh->winding);

    swapFramebuffers();

    gammaCorrectionTimer->end();

    //FXAA
    fxaaTimer->begin();

    gfxApi->setCurrentFramebuffer(nullptr);

    gfxApi->begin(compiledPostEffectVertex,
                  nullptr,
                  nullptr,
                  nullptr,
                  compiledFXAAFragment,
                  quadMesh);

    gfxApi->addTextureBinding(compiledFXAAFragment, "colorTexture", readColorTexture);

    gfxApi->end(quadMesh->primitive,
                quadMesh->numVertices,
                quadMesh->winding);

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

    for (size_t i = 0; i < entities.getCount(); ++i)
    {
        const Entity *entity = entities[i];

        Matrix4x4 transform = entity->transform.createMatrix();

        if (entity->hasRenderComponent())
        {
            const RenderComponent *comp = entity->getRenderComponent();

            if (comp->type == RenderComponent::Model)
            {
                ResPtr<GfxModel> model = comp->model;

                for (size_t i = 0; i < model->subModels.getCount(); ++i)
                {
                    const GfxModel::SubModel& subModel = model->subModels[i];

                    for (size_t j = 0; j < subModel.getCount(); ++j)
                    {
                        const GfxModel::LOD& lod = subModel[j];

                        aabb.extend(lod.mesh->aabb.transform(transform * lod.worldMatrix));
                    }
                }
            }
        }
    }

    return aabb;
}

AABB GfxRenderer::computeShadowCasterAABB() const
{
    AABB aabb;

    const List<Entity *>& entities = scene->getEntities();

    for (size_t i = 0; i < entities.getCount(); ++i)
    {
        const Entity *entity = entities[i];

        Matrix4x4 transform = entity->transform.createMatrix();

        if (entity->hasRenderComponent())
        {
            const RenderComponent *comp = entity->getRenderComponent();

            if (comp->type == RenderComponent::Model and comp->modelData.shadowCaster)
            {
                ResPtr<GfxModel> model = comp->model;

                for (size_t i = 0; i < model->subModels.getCount(); ++i)
                {
                    const GfxModel::SubModel& subModel = model->subModels[i];

                    for (size_t j = 0; j < subModel.getCount(); ++j)
                    {
                        const GfxModel::LOD& lod = subModel[j];

                        aabb.extend(lod.mesh->aabb.transform(transform * lod.worldMatrix));
                    }
                }
            }
        }
    }

    return aabb;
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
        lightData[i*16+13] = light->ambientStrength;

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

    Matrix4x4 projectionMatrix = camera.getProjectionMatrix();
    Matrix4x4 viewMatrix = camera.getViewMatrix();
    Matrix3x3 normalMatrix = Matrix3x3(worldMatrix.inverse().transpose());

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
                gfxApi->setCullMode(lod.mesh->cullMode);

                ResPtr<GfxMaterial> material = lod.material;
                ResPtr<GfxMesh> mesh = lod.mesh;
                GfxShaderCombination *shaderComb = material->getShaderComb();

                bool useTesselation = material->getDisplacementMap() != nullptr and
                                      gfxApi->tesselationSupported() and
                                      mesh->primitive == GfxTriangles;

                gfxApi->pushState();

                GfxCompiledShader *vertex = shaderComb->getCompiledVertexShader();
                GfxCompiledShader *tessControl = shaderComb->getCompiledTessControlShader();
                GfxCompiledShader *tessEval = shaderComb->getCompiledTessEvalShader();
                GfxCompiledShader *geometry = shaderComb->getCompiledGeometryShader();
                GfxCompiledShader *fragment = shaderComb->getCompiledFragmentShader();

                gfxApi->begin(vertex,
                              tessControl,
                              tessEval,
                              geometry,
                              fragment,
                              mesh);

                if (useTesselation)
                {
                    gfxApi->uniform(vertex, "projectionMatrix", Matrix4x4());
                    gfxApi->uniform(vertex, "viewMatrix", Matrix4x4());
                } else
                {
                    gfxApi->uniform(vertex, "projectionMatrix", projectionMatrix);
                    gfxApi->uniform(vertex, "viewMatrix", viewMatrix);
                }

                gfxApi->uniform(vertex, "worldMatrix", worldMatrix);
                gfxApi->uniform(vertex, "normalMatrix", normalMatrix);
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
                    gfxApi->uniform(tessEval, "projectionMatrix", projectionMatrix);
                    gfxApi->uniform(tessEval, "viewMatrix", viewMatrix);
                    gfxApi->uniform(tessEval, "strength", material->displacementStrength);
                }

                gfxApi->uniform(fragment, "smoothness", material->smoothness);
                gfxApi->uniform(fragment, "metalMask", material->metalMask);
                gfxApi->uniform(fragment, "albedo", material->albedo);

                if (material->isForward())
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

                gfxApi->setCullMode(mesh->cullMode);

                GfxPrimitive primitive = useTesselation ?
                                         GfxPatches :
                                         mesh->primitive;

                if (useTesselation)
                {
                    gfxApi->setTessPatchSize(3);
                }

                if (mesh->indexed)
                {
                    gfxApi->endIndexed(primitive,
                                       mesh->indexData.type,
                                       mesh->indexData.numIndices,
                                       mesh->indexData.offset,
                                       mesh->indexData.buffer,
                                       mesh->winding);
                } else
                {
                    gfxApi->end(primitive, mesh->numVertices, mesh->winding);
                }

                gfxApi->popState();
                break;
            }
        }
    }
}

void GfxRenderer::renderModelToShadowmap(const Matrix4x4& viewMatrix,
                                         const Matrix4x4& projectionMatrix,
                                         const Matrix4x4& worldMatrix,
                                         const ResPtr<GfxModel> model,
                                         Light *light,
                                         size_t cubemapFace)
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
                Matrix4x4 newWorldMatrix = worldMatrix * lod.worldMatrix;

                ResPtr<GfxMaterial> material = lod.material;
                ResPtr<GfxMesh> mesh = lod.mesh;

                GfxCompiledShader *vertexShader = compiledShadowmapVertex;
                GfxCompiledShader *geometryShader = nullptr;
                GfxCompiledShader *fragmentShader = compiledShadowmapFragment;
                GfxCompiledShader *tessControlShader = nullptr;
                GfxCompiledShader *tessEvalShader = nullptr;

                bool useTesselation = material->getDisplacementMap() != nullptr and
                                      material->shadowTesselation and
                                      gfxApi->tesselationSupported();

                if (useTesselation)
                {
                    vertexShader = compiledShadowmapVertexTesselation;
                    tessControlShader = compiledShadowmapTessControl;
                    tessEvalShader = compiledShadowmapTessEval;
                }

                if (light->type == Light::Point)
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

                if (light->type == Light::Point)
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
                    if (light->type != Light::Point)
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
                    gfxApi->uniform(vertexShader, "normalMatrix", Matrix3x3(newWorldMatrix.inverse().transpose()));
                }

                gfxApi->uniform(vertexShader, "worldMatrix", newWorldMatrix);

                gfxApi->uniform(fragmentShader, "biasScale", light->shadowAutoBiasScale);

                GfxPrimitive primitive = useTesselation ?
                                         GfxPatches :
                                         mesh->primitive;

                gfxApi->setTessPatchSize(3);

                if (mesh->indexed)
                {
                    gfxApi->endIndexed(primitive,
                                       mesh->indexData.type,
                                       mesh->indexData.numIndices,
                                       mesh->indexData.offset,
                                       mesh->indexData.buffer,
                                       mesh->winding);
                } else
                {
                    gfxApi->end(primitive, mesh->numVertices, mesh->winding);
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

    gfxApi->setViewport(0, 0, light->getShadowmapResolution(), light->getShadowmapResolution());

    const List<Entity *>& entities = scene->getEntities();

    bool singlePass = light->type == Light::Point ? light->point.singlePassShadowMap : true;

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

        for (size_t j = 0; j < entities.getCount(); ++j)
        {
            const Entity *entity = entities[j];

            Matrix4x4 transform = entity->transform.createMatrix();

            if (entity->hasRenderComponent())
            {
                const RenderComponent *comp = entity->getRenderComponent();

                switch (comp->type)
                {
                case RenderComponent::Model:
                {
                    renderModelToShadowmap(viewMatrix,
                                           projectionMatrix,
                                           transform,
                                           comp->model,
                                           light,
                                           i);
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

    gfxApi->popState();
}

void GfxRenderer::swapFramebuffers()
{
    std::swap(writeFramebuffer, readFramebuffer);
    std::swap(writeColorTexture, readColorTexture);
}
