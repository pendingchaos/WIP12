#include "imgui.h"

#include "graphics/gfxmesh.h"
#include "graphics/gfxshader.h"
#include "graphics/gfxapi.h"
#include "graphics/font.h"
#include "resource/resourcemanager.h"
#include "platform.h"
#include "globals.h"

bool intersects(int left, int right, int bottom, int top, Int2 pos)
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

    vertexShader = resMgr->load<GfxShader>("resources/shaders/gui.vs.bin");
    fragmentShader = resMgr->load<GfxShader>("resources/shaders/gui.fs.bin");

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

    containerLeft = std::min(containerLeft, left);
    containerRight = std::max(containerRight, right);
    containerTop = std::max(containerTop, top);
    containerBottom = std::min(containerBottom, bottom);

    Command command;
    command.type = Command::Rectangle;
    command.rect.left = left + scrollX;
    command.rect.right = right + scrollX;
    command.rect.bottom = bottom + scrollY;
    command.rect.top = top + scrollY;
    command.rect.brightness = brightness;
    command.rect.gradientStart = gradientStart;
    command.rect.gradientSize = gradientSize;
    command.rect.gradientPower = gradientPower;
    command.rect.colorR = color.x;
    command.rect.colorG = color.y;
    command.rect.colorB = color.z;
    command.rect.topLeftCornerRoundness = cornerRoundness.x;
    command.rect.topRightCornerRoundness = cornerRoundness.y;
    command.rect.bottomLeftCornerRoundness = cornerRoundness.z;
    command.rect.bottomRightCornerRoundness = cornerRoundness.w;

    commands.append(command);
}

void ImGui::beginContainer(int left, int right, int bottom, int top, Container *container)
{
    if (left > right or bottom > top)
    {
        Command command;
        command.type = Command::PushScissor;
        command.scissor.left = 0;
        command.scissor.right = 0;
        command.scissor.bottom = 0;
        command.scissor.top = 0;

        commands.append(command);
        return;
    }

    rectangle(left, right+10, bottom-10, top, 0.44f, 1.0f, 0.0f, 1.0f, Float3(1.0f), Float4(0.0f));

    Command command;
    command.type = Command::PushScissor;
    command.scissor.left = left;
    command.scissor.right = right;
    command.scissor.bottom = bottom;
    command.scissor.top = top;

    commands.append(command);

    scrollX = container->scrollX;
    scrollY = container->scrollY;

    containerLeft = left;
    containerRight = right;
    containerTop = top;
    containerBottom = bottom;

    container->left = left;
    container->right = right;
    container->bottom = bottom;
    container->top = top;
}

void ImGui::endContainer(Container *container)
{
    scrollX = 0;
    scrollY = 0;

    Command command;
    command.type = Command::PopScissor;

    commands.append(command);

    int extraContainerWidth = (containerRight - containerLeft);
    int extraContainerHeight = (containerTop - containerBottom);
    int containerWidth = container->right - container->left;
    int containerheight = container->top - container->bottom;

    container->horizonal.barSize = std::min(float(containerWidth) / extraContainerWidth, 1.0f);
    container->vertical.barSize = std::min(float(containerheight) / extraContainerHeight, 1.0f);

    horizontalScrollBar(container->left,
                        container->right,
                        container->bottom-10,
                        container->bottom,
                        true,
                        false,
                        &container->horizonal);

    verticalScrollBar(container->right,
                      container->right+10,
                      container->bottom,
                      container->top,
                      true,
                      false,
                      &container->vertical);

    container->scrollX = container->horizonal.getValue() * -std::max(extraContainerWidth - containerWidth, 0);
    container->scrollY = (1.0f - container->vertical.getValue()) * std::max(extraContainerHeight - containerheight, 0);
}

float scrollBarLogic(int left,
                     int right,
                     int bottom,
                     int top,
                     ScrollBar *state,
                     bool vertical,
                     float scrollSpeed)
{
    int size = vertical ? top-bottom : right-left;

    Int2 mousePos = platform->getMousePosition();
    mousePos.y = platform->getWindowHeight() - mousePos.y;
    bool intersection = intersects(left, right, bottom, top, mousePos);

    float brightness = intersection ? 0.95f : 1.0f;

    switch (state->state)
    {
    case ScrollBarState::Idle:
    {
        bool pressed = platform->isLeftMouseButtonPressed() and intersection;

        if (pressed and vertical)
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
        } else if (pressed and intersection)
        {
            int barLeft = left + state->center*size - state->barSize*size/2.0f;
            int barRight = barLeft + state->barSize*size;

            if (mousePos.x > barLeft and mousePos.x < barRight)
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
        int movement;

        if (vertical)
        {
            movement = mousePos.y - state->lastMousePos.y;
        } else
        {
            movement = mousePos.x - state->lastMousePos.x;
        }

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
        state->center = float(vertical ? (mousePos.y-bottom) : (mousePos.x-left)) / size;
        brightness = 0.8f;

        if (not platform->isLeftMouseButtonPressed())
        {
            state->state = ScrollBarState::Idle;
        }
        break;
    }
    }

    if (intersection and vertical)
    {
        state->center += platform->getMouseWheel().y * scrollSpeed * platform->getFrametime();
    } else if (intersection)
    {
        state->center += platform->getMouseWheel().x * scrollSpeed * platform->getFrametime();
    }

    state->center = std::max(state->center, state->barSize/2.0f);
    state->center = std::min(state->center, 1.0f-state->barSize/2.0f);

    state->lastMousePos = mousePos;

    return brightness;
}

#pragma GCC push_options
#pragma GCC optimize "-O0"
static bool invalid(int left, int right, int bottom, int top)
{
    return left > right or bottom > top;
}
#pragma GCC pop_options

void ImGui::verticalScrollBar(int left,
                              int right,
                              int bottom,
                              int top,
                              bool leftRounded,
                              bool rightRounded,
                              ScrollBar *state)
{
    if (invalid(left, right, bottom, top))
    {
        return;
    }

    Float4 cornerRoundness = (leftRounded ? Float4(5.0f, 0.0f, 5.0f, 0.0f) : Float4()) +
                             (rightRounded ? Float4(0.0f, 5.0f, 0.0f, 5.0f) : Float4());

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

    float brightness = scrollBarLogic(left+scrollX, right+scrollX, bottom+scrollY, top+scrollY, state, true, scrollSpeed);

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
}

void ImGui::horizontalScrollBar(int left,
                                int right,
                                int bottom,
                                int top,
                                bool topRounded,
                                bool bottomRounded,
                                ScrollBar *state)
{
    if (invalid(left, right, bottom, top))
    {
        return;
    }

    Float4 cornerRoundness = (topRounded ? Float4(5.0f, 5.0f, 0.0f, 0.0f) : Float4()) +
                             (bottomRounded ? Float4(0.0f, 0.0f, 5.0f, 5.0f) : Float4());

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

    int size = right - left;

    float brightness = scrollBarLogic(left+scrollX, right+scrollX, bottom+scrollY, top+scrollY, state, false, scrollSpeed);

    int barLeft = left + state->center*size - state->barSize*size/2.0f;
    int barRight = barLeft + state->barSize*size;

    rectangle(barLeft,
              barRight,
              bottom,
              top,
              brightness,
              0.85f,
              0.15f,
              2.2f,
              Float3(1.0f),
              cornerRoundness);
}

bool ImGui::button(const char *text, int left, int right, int bottom, int top)
{
    if (invalid(left, right, bottom, top))
    {
        return false;
    }

    left += scrollX;
    right += scrollX;

    top += scrollY;
    bottom += scrollY;

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

    rectangle(left-scrollX, right-scrollX, bottom-scrollY, top-scrollY, brightness);

    //For some reason doing this in integers won't work.
    size_t textWidth = font->predictWidth(textSize, text);

    float textHeightGL = textSize / float(platform->getWindowHeight()) / 2.0f;
    float textWidthGL = textWidth / float(platform->getWindowWidth()) / 2.0f;

    float w = gfxApi->getViewportWidth();
    float h = gfxApi->getViewportHeight();
    float fleft = left / w * 2.0f - 1.0f;
    float fright = right / w * 2.0f - 1.0f;
    float ftop = top / h * 2.0f - 1.0f;
    float fbottom = bottom / h * 2.0f - 1.0f;

    Float2 textPosition(fleft + (fright-fleft-textWidthGL)/2.0f,
                        fbottom + (ftop-fbottom-textHeightGL)/2.0f);

    Command command;
    command.type = Command::Text;
    command.text.size = textSize;
    command.text.left = (textPosition.x + 1.0f) / 2.0f * platform->getWindowWidth();
    command.text.bottom = (textPosition.y + 1.0f) / 2.0f * platform->getWindowHeight();
    command.text.colorR = buttonTextColor.x;
    command.text.colorG = buttonTextColor.y;
    command.text.colorB = buttonTextColor.z;
    command.textStr = text;

    commands.append(command);

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

    containerLeft = std::min(containerLeft, left);
    containerRight = std::max(containerRight, left + int(textWidth));
    containerTop = std::max(containerTop, bottom + int(textSize));
    containerBottom = std::min(containerBottom, bottom);

    Command command;
    command.type = Command::Text;
    command.text.size = textSize;
    command.text.left = left + scrollX;
    command.text.bottom = bottom + scrollY;
    command.text.colorR = labelColor.x;
    command.text.colorG = labelColor.y;
    command.text.colorB = labelColor.z;
    command.textStr = text;

    commands.append(command);

    return textWidth;
}

void ImGui::render()
{
    for (auto command : commands)
    {
        switch (command.type)
        {
        case Command::Rectangle:
        {
            decltype(Command::rect) rect = command.rect;

            gfxApi->pushState();

            gfxApi->setBlendingEnabled(true);
            gfxApi->setBlendFactors(GfxSrcAlpha,
                                    GfxSrcAlpha,
                                    GfxOneMinusSrcAlpha,
                                    GfxOneMinusSrcAlpha);
            gfxApi->setDepthFunction(GfxAlways);

            gfxApi->begin(compiledVertex, nullptr, nullptr, nullptr, compiledFragment, mesh);

            float w = gfxApi->getViewportWidth();
            float h = gfxApi->getViewportHeight();
            float fleft = rect.left / w * 2.0f - 1.0f;
            float fright = rect.right / w * 2.0f - 1.0f;
            float ftop = rect.top / h * 2.0f - 1.0f;
            float fbottom = rect.bottom / h * 2.0f - 1.0f;

            gfxApi->uniform(compiledVertex, "offset", Float2(fleft, fbottom));
            gfxApi->uniform(compiledVertex, "size", Float2(fright-fleft, ftop-fbottom));
            gfxApi->uniform(compiledVertex, "gradientStart", rect.gradientStart);
            gfxApi->uniform(compiledVertex, "gradientSize", rect.gradientSize);
            gfxApi->uniform(compiledVertex, "gradientPower", rect.gradientPower);
            gfxApi->uniform(compiledVertex, "color", Float3(rect.colorR, rect.colorG, rect.colorB));
            gfxApi->uniform(compiledFragment, "topRight", Float2(rect.right, rect.top));
            gfxApi->uniform(compiledFragment, "bottomLeft", Float2(rect.left, rect.bottom));
            gfxApi->uniform(compiledFragment, "brightness", rect.brightness);
            gfxApi->uniform(compiledFragment, "topLeftCornerRoundness", rect.topLeftCornerRoundness);
            gfxApi->uniform(compiledFragment, "topRightCornerRoundness", rect.topRightCornerRoundness);
            gfxApi->uniform(compiledFragment, "bottomLeftCornerRoundness", rect.bottomLeftCornerRoundness);
            gfxApi->uniform(compiledFragment, "bottomRightCornerRoundness", rect.bottomRightCornerRoundness);

            gfxApi->draw();
            gfxApi->end();

            gfxApi->popState();
            break;
        }
        case Command::Text:
        {
            float w = gfxApi->getViewportWidth();
            float h = gfxApi->getViewportHeight();
            float fleft = command.text.left / w * 2.0f - 1.0f;
            float fbottom = command.text.bottom / h * 2.0f - 1.0f;

            font->render(command.text.size,
                         Float2(fleft, fbottom),
                         command.textStr.getData(),
                         nullptr,
                         Float3(command.text.colorR,
                                command.text.colorG,
                                command.text.colorB));
            break;
        }
        case Command::PushScissor:
        {
            gfxApi->pushState();

            gfxApi->setScissorEnabled(true);
            gfxApi->setScissor(command.scissor.left,
                               command.scissor.bottom,
                               command.scissor.right-command.scissor.left,
                               command.scissor.top-command.scissor.bottom);
            break;
        }
        case Command::PopScissor:
        {
            gfxApi->popState();
            break;
        }
        }
    }

    commands.clear();
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
    bool result = false;

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
