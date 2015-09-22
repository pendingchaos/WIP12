#include "imgui.h"

#include "graphics/gfxmesh.h"
#include "graphics/gfxshader.h"
#include "graphics/gfxapi.h"
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
}

ImGui::~ImGui()
{
    fragmentShader->release();
    vertexShader->release();
    mesh->release();
}

bool ImGui::button(const char *text, float left, float right, float bottom, float top)
{
    if (left > right or bottom > top)
    {
        return false;
    }

    bool pressed = false;
    float brightness = 1.0f;

    Float2 mousePos = platform->getMousePosition();

    mousePos = mousePos / Float2(platform->getWindowWidth(), platform->getWindowHeight());
    mousePos = mousePos * 2.0f - 1.0f;

    if (mousePos.x > left and mousePos.x < right and mousePos.y > bottom and mousePos.y < top)
    {
        brightness = 0.9f;
    }

    if (platform->isLeftMouseButtonPressed())
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

    gfxApi->uniform(compiledVertex, "offset", Float2(left, bottom));
    gfxApi->uniform(compiledVertex, "size", Float2(right-left, top-bottom));
    gfxApi->uniform(compiledFragment, "topRight", Float2((right + 1.0f) / 2.0f * w,
                                                         (top + 1.0f) / 2.0f * h));
    gfxApi->uniform(compiledFragment, "bottomLeft", Float2((left + 1.0f) / 2.0f * w,
                                                           (bottom + 1.0f) / 2.0f * h));
    gfxApi->uniform(compiledFragment, "brightness", brightness);

    gfxApi->end();

    gfxApi->popState();

    return pressed;
}
