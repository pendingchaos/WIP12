#include "imgui.h"

#include "graphics/gfxmesh.h"
#include "graphics/gfxshader.h"
#include "graphics/gfxapi.h"
#include "graphics/font.h"
#include "resource/resourcemanager.h"
#include "platform.h"
#include "globals.h"

ImGui::ImGui()
{
    mesh = NEW(GfxMesh);

    ResizableData data(48);
    float *fdata = (float *)data.getData();
    fdata[0] = 0.0f;
    fdata[1] = 0.0f;

    fdata[2] = 1.0f;
    fdata[3] = 0.0f;

    fdata[4] = 0.0f;
    fdata[5] = 1.0f;

    fdata[6] = 1.0f;
    fdata[7] = 0.0f;

    fdata[8] = 1.0f;
    fdata[9] = 1.0f;

    fdata[10] = 0.0f;
    fdata[11] = 1.0f;

    GfxMeshAttrib attrib;
    attrib.type = GfxMeshAttribType::Position;
    attrib.dataType = GfxMeshAttribDataType::F32_2;
    attrib.data = data;
    mesh->setAttribute(attrib);

    mesh->numVertices = 6;

    vertexShader = resMgr->load<GfxShader>("resources/shaders/guiVertex.bin");
    fragmentShader = resMgr->load<GfxShader>("resources/shaders/guiFragment.bin");

    compiledVertex = vertexShader->getCompiled();
    compiledFragment = fragmentShader->getCompiled();

    font = resMgr->load<Font>("/usr/share/fonts/gnu-free/FreeSans.ttf");
}

ImGui::~ImGui()
{
    font->release();
    fragmentShader->release();
    vertexShader->release();
    mesh->release();
}

bool ImGui::button(const char *text, int left, int right, int bottom, int top)
{
    if (left > right or bottom > top)
    {
        return false;
    }

    bool pressed = false;

    Int2 mousePos = platform->getMousePosition();
    mousePos.y = platform->getWindowHeight() - mousePos.y;
    bool highlighted = mousePos.x > left and mousePos.x < right and mousePos.y > bottom and mousePos.y < top;

    float brightness = highlighted ? 0.95f : 1.0f;

    if (platform->isLeftMouseButtonPressed() and highlighted)
    {
        brightness = 0.8f;
        pressed = true;
    }

    gfxApi->pushState();

    gfxApi->setBlendingEnabled(true);
    gfxApi->setBlendFactors(GfxSrcAlpha, GfxSrcAlpha, GfxOneMinusSrcAlpha, GfxOneMinusSrcAlpha);
    gfxApi->setDepthFunction(GfxAlways);

    gfxApi->begin(compiledVertex, nullptr, nullptr, nullptr, compiledFragment, mesh);

    float w = gfxApi->getViewportWidth();
    float h = gfxApi->getViewportHeight();
    float fleft = left / w * 2.0f - 1.0f;
    float fright = right / w * 2.0f - 1.0f;
    float ftop = top / h * 2.0f - 1.0f;
    float fbottom = bottom / h * 2.0f - 1.0f;

    gfxApi->uniform(compiledVertex, "offset", Float2(fleft, fbottom));
    gfxApi->uniform(compiledVertex, "size", Float2(fright-fleft, ftop-fbottom));
    gfxApi->uniform(compiledFragment, "topRight", Float2(right, top));
    gfxApi->uniform(compiledFragment, "bottomLeft", Float2(left, bottom));
    gfxApi->uniform(compiledFragment, "brightness", brightness);

    gfxApi->end();

    gfxApi->popState();

    size_t textHeight = 30;
    size_t textWidth = font->predictWidth(textHeight, text);

    float textHeightGL = textHeight / float(platform->getWindowHeight()) / 2.0f;
    float textWidthGL = textWidth / float(platform->getWindowWidth()) / 2.0f;

    Float2 textPosition(fleft + (fright-fleft-textWidthGL)/2.0f,
                        fbottom + (ftop-fbottom-textHeightGL)/2.0f);

    font->render(textHeight, textPosition, text, nullptr, Float3(0.0f));

    return pressed;
}
