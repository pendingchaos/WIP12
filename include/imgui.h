#ifndef IMGUI_H
#define IMGUI_H

#include "scripting/bindings.h"
#include "math/t3.h"
#include "math/t4.h"

#include <stddef.h>

class GfxMesh;
class GfxShader;
class GfxCompiledShader;
class Font;

enum class ScrollBarState
{
    Idle,
    Dragged,
    Placed
};

struct ScrollBar
{
    ScrollBar() : center(0.5f), barSize(0.5f), state(ScrollBarState::Idle) {}

    float center;
    float barSize;

    NO_BIND ScrollBarState state;
    NO_BIND Int2 lastMousePos;
} BIND;

class ImGui
{
    public:
        ImGui();
        ~ImGui();

        Float3 buttonTextColor;
        Float3 labelColor;
        size_t textSize;
        float scrollSpeed;

        void rectangle(int left,
                       int right,
                       int bottom,
                       int top,
                       float brightness=1.0f,
                       float gradientStart=0.85f,
                       float gradientSize=0.15f,
                       float gradientPower=2.2f,
                       Float3 color=Float3(1.0f),
                       Float4 cornerRoundness=Float4(5.0f)); //Topleft, topright, bottomleft, bottomright
        void beginContainer(int left, int right, int bottom, int top, int *scrollX, int *scrollY) NO_BIND;
        void endContainer();
        void verticalScrollBar(int left,
                               int right,
                               int bottom,
                               int top,
                               bool leftSideRounded,
                               bool rightSideRounded,
                               ScrollBar *state);
        bool button(const char *text, int left, int right, int bottom, int top);
        size_t label(const char *text,
                     int leftOrRight,
                     int bottomOrTop,
                     bool left=true,
                     bool bottom=true);
    private:
        GfxMesh *mesh;
        GfxShader *vertexShader;
        GfxShader *fragmentShader;
        GfxCompiledShader *compiledVertex;
        GfxCompiledShader *compiledFragment;

        Font *font;

        int scrollX;
        int scrollY;
} BIND;

enum class XOrigin
{
    Left,
    Right
} ENUM_CLASS BIND;

class GuiPlacer
{
    public:
        GuiPlacer(ImGui *gui, int top, int left, size_t padding);

        bool button(const char *text, size_t width, size_t height);
        void label(const char *text);
        GuiPlacer placer(size_t width, size_t padding);

        void advanceY();
        void advanceY(const GuiPlacer& other);
        void resetY();

        void setXOrigin(XOrigin origin, int value);

        inline XOrigin getXOriginMode()
        {
            return xOrigin;
        }

        inline int getXOrigin()
        {
            return leftOrRight;
        }

        inline size_t getPadding() const
        {
            return padding;
        }
    private:
        ImGui *gui;
        int top;

        XOrigin xOrigin;
        int leftOrRight;

        size_t padding;

        size_t yAdvance;
        int currentLeftOrRight;
        int currentTop;
} BIND;

#endif // IMGUI_H
