#include "imgui.h"

#include "graphics/gfxmesh.h"
#include "graphics/gfxshader.h"
#include "graphics/gfxapi.h"
#include "graphics/font.h"
#include "resource/resourcemanager.h"
#include "platform.h"
#include "globals.h"

inline bool intersects(int left, int right, int bottom, int top, Int2 pos)
{
    return pos.x > left and pos.x < right and pos.y > bottom and pos.y < top;
}

ImGui::ImGui() : textSize(30),
                 scrollSpeed(1.0f),
                 scrollX(0),
                 scrollY(0)
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

void ImGui::rectangle(int left,
                      int right,
                      int bottom,
                      int top,
                      float brightness,
                      float gradientStart,
                      float gradientSize,
                      float gradientPower,
                      Float3 color,
                      Float4 cornerRoundness)
{
    if (left > right or bottom > top)
    {
        return;
    }

    left += scrollX;
    right += scrollX;

    top += scrollY;
    bottom += scrollY;

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
    gfxApi->uniform(compiledVertex, "gradientStart", gradientStart);
    gfxApi->uniform(compiledVertex, "gradientSize", gradientSize);
    gfxApi->uniform(compiledVertex, "gradientPower", gradientPower);
    gfxApi->uniform(compiledVertex, "color", color);
    gfxApi->uniform(compiledFragment, "topRight", Float2(right, top));
    gfxApi->uniform(compiledFragment, "bottomLeft", Float2(left, bottom));
    gfxApi->uniform(compiledFragment, "brightness", brightness);
    gfxApi->uniform(compiledFragment, "topLeftCornerRoundness", cornerRoundness.x);
    gfxApi->uniform(compiledFragment, "topRightCornerRoundness", cornerRoundness.y);
    gfxApi->uniform(compiledFragment, "bottomLeftCornerRoundness", cornerRoundness.z);
    gfxApi->uniform(compiledFragment, "bottomRightCornerRoundness", cornerRoundness.w);

    gfxApi->end();

    gfxApi->popState();
}

void ImGui::beginContainer(int left, int right, int bottom, int top, int *scrollX_, int *scrollY_)
{
    if (left > right or bottom > top)
    {
        gfxApi->pushState();
        return;
    }

    rectangle(left, right, bottom, top, 0.44f, 1.0f, 0.0f, 1.0f, Float3(1.0f), Float4(0.0f));

    gfxApi->pushState();
    gfxApi->setScissor(left, bottom, right-left, top-bottom);

    if (scrollX_ != nullptr)
    {
        scrollX = *scrollX_;
    }

    if (scrollY_ != nullptr)
    {
        scrollY = *scrollY_;
    }
}

void ImGui::endContainer()
{
    gfxApi->popState();

    scrollX = 0;
    scrollY = 0;
}

void ImGui::verticalScrollBar(int left,
                              int right,
                              int bottom,
                              int top,
                              bool leftSideRounded,
                              bool rightSideRounded,
                              ScrollBar *state)
{
    if (left > right or bottom > top)
    {
        return;
    }

    Float4 cornerRoundness = (leftSideRounded ? Float4(5.0f, 0.0f, 5.0f, 0.0f) : Float4()) +
                             (rightSideRounded ? Float4(0.0f, 5.0f, 0.0f, 5.0f) : Float4());

    rectangle(left,
              right,
              bottom,
              top,
              0.25f,
              1.0f,
              0.0f,
              1.0f,
              Float3(1.0f),
              cornerRoundness);

    int size = top - bottom;

    Int2 mousePos = platform->getMousePosition();
    mousePos.y = platform->getWindowHeight() - mousePos.y;
    bool intersection = intersects(left, right, bottom, top, mousePos);

    float brightness = intersection ? 0.95f : 1.0f;

    switch (state->state)
    {
    case ScrollBarState::Idle:
    {
        if (platform->isLeftMouseButtonPressed() and intersection)
        {
            int barBottom = bottom + state->center*size - state->barSize*size/2.0f;
            int barTop = barBottom + state->barSize*size;

            if (mousePos.y > barBottom and mousePos.y < barTop)
            {
                state->state = ScrollBarState::Dragged;
            } else
            {
                state->state = ScrollBarState::Placed;
            }
        }
        break;
    }
    case ScrollBarState::Dragged:
    {
        int movement = state->lastMousePos.y - platform->getMousePosition().y;
        state->center += float(movement) / size;
        brightness = 0.8f;

        if (not platform->isLeftMouseButtonPressed())
        {
            state->state = ScrollBarState::Idle;
        }
        break;
    }
    case ScrollBarState::Placed:
    {
        state->center = float(mousePos.y - bottom) / size;
        brightness = 0.8f;

        if (not platform->isLeftMouseButtonPressed())
        {
            state->state = ScrollBarState::Idle;
        }
        break;
    }
    }

    if (intersection)
    {
        state->center += platform->getMouseWheel().y * scrollSpeed * platform->getFrametime();
    }

    state->center = std::min(std::max(state->center, state->barSize/2.0f), 1.0f-state->barSize/2.0f);

    int barBottom = bottom + state->center*size - state->barSize*size/2.0f;
    int barTop = barBottom + state->barSize*size;

    rectangle(left,
              right,
              barBottom,
              barTop,
              brightness,
              0.85f,
              0.15f,
              2.2f,
              Float3(1.0f),
              cornerRoundness);

    state->lastMousePos = platform->getMousePosition();
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
    bool highlighted = intersects(left, right, bottom, top, mousePos);

    float brightness = highlighted ? 0.95f : 1.0f;

    if (platform->isLeftMouseButtonPressed() and highlighted)
    {
        brightness = 0.8f;
        pressed = true;
    }

    rectangle(left, right, bottom, top, brightness);

    size_t textWidth = font->predictWidth(textSize, text);

    float textHeightGL = textSize / float(platform->getWindowHeight()) / 2.0f;
    float textWidthGL = textWidth / float(platform->getWindowWidth()) / 2.0f;

    left += scrollX;
    right += scrollX;

    top += scrollY;
    bottom += scrollY;

    float w = gfxApi->getViewportWidth();
    float h = gfxApi->getViewportHeight();
    float fleft = left / w * 2.0f - 1.0f;
    float fright = right / w * 2.0f - 1.0f;
    float ftop = top / h * 2.0f - 1.0f;
    float fbottom = bottom / h * 2.0f - 1.0f;

    Float2 textPosition(fleft + (fright-fleft-textWidthGL)/2.0f,
                        fbottom + (ftop-fbottom-textHeightGL)/2.0f);

    font->render(textSize, textPosition, text, nullptr, buttonTextColor);

    return pressed;
}

size_t ImGui::label(const char *text,
                    int leftOrRight,
                    int bottomOrTop,
                    bool isLeft,
                    bool isBottom)
{
    size_t textWidth = font->predictWidth(textSize, text);

    int left = isLeft ? leftOrRight : (leftOrRight - textWidth);
    int bottom = isBottom ? bottomOrTop : (bottomOrTop - textSize/2);

    float w = gfxApi->getViewportWidth();
    float h = gfxApi->getViewportHeight();
    float fleft = left / w * 2.0f - 1.0f;
    float fbottom = bottom / h * 2.0f - 1.0f;

    font->render(textSize, Float2(fleft, fbottom), text, nullptr, labelColor);

    return textWidth;
}

GuiPlacer::GuiPlacer(ImGui *gui_,
                     int top_,
                     int left_,
                     size_t padding_) : gui(gui_),
                                        top(top_-padding_),
                                        xOrigin(XOrigin::Left),
                                        leftOrRight(left_+padding_),
                                        padding(padding_),
                                        yAdvance(0),
                                        currentLeftOrRight(leftOrRight),
                                        currentTop(top) {}

bool GuiPlacer::button(const char *text, size_t width, size_t height)
{
    bool result;

    switch (xOrigin)
    {
    case XOrigin::Left:
    {
        result = gui->button(text, currentLeftOrRight, currentLeftOrRight+width, currentTop-height, currentTop);
        currentLeftOrRight += width + padding;
        break;
    }
    case XOrigin::Right:
    {
        result = gui->button(text, currentLeftOrRight-width, currentLeftOrRight, currentTop-height, currentTop);
        currentLeftOrRight -= width + padding;
        break;
    }
    }

    yAdvance = std::max(height + padding, yAdvance);

    return result;
}

void GuiPlacer::label(const char *text)
{
    switch (xOrigin)
    {
    case XOrigin::Left:
    {
        currentLeftOrRight += gui->label(text, currentLeftOrRight, currentTop, true, false) + padding;
        break;
    }
    case XOrigin::Right:
    {
        currentLeftOrRight -= gui->label(text, currentLeftOrRight, currentTop, false, false) + padding;
        break;
    }
    }

    yAdvance = std::max(gui->textSize + padding, yAdvance);
}

GuiPlacer GuiPlacer::placer(size_t width, size_t padding_)
{
    switch (xOrigin)
    {
    case XOrigin::Left:
    {
        return GuiPlacer(gui, currentTop+padding_, currentLeftOrRight, padding_);
    }
    case XOrigin::Right:
    {
        return GuiPlacer(gui, currentTop+padding_, currentLeftOrRight - width, padding_);
    }
    }

    return GuiPlacer(gui, 0, 0, 10);
}

void GuiPlacer::advanceY()
{
    currentTop -= yAdvance;
    yAdvance = 0;
    currentLeftOrRight = leftOrRight;
}

void GuiPlacer::advanceY(const GuiPlacer& other)
{
    currentTop -= other.top - other.currentTop;
    yAdvance = 0;
    currentLeftOrRight = leftOrRight;
}

void GuiPlacer::resetY()
{
    currentTop = top;
    yAdvance = 0;
}

void GuiPlacer::setXOrigin(XOrigin origin, int value)
{
    xOrigin = origin;

    switch (origin)
    {
    case XOrigin::Left:
    {
        leftOrRight = value + padding;
        break;
    }
    case XOrigin::Right:
    {
        leftOrRight = value - padding;
        break;
    }
    }

    currentLeftOrRight = leftOrRight;
}
