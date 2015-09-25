#ifndef IMGUI_H
#define IMGUI_H

#include "scripting/bindings.h"
#include "math/t3.h"
#include "math/t4.h"
#include "containers/string.h"
#include "graphics/font.h"

#include <stddef.h>

class GfxMesh;
class GfxShader;
class GfxCompiledShader;

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

    inline float getValue() const
    {
        return barSize >= 1.0f ? 1.0f : (center - barSize/2.0f) / (1.0f - barSize);
    }

    inline void setValue(float value)
    {
        center = value * (1.0f - barSize*2.0f) + barSize;
    }
} BIND;

struct Container
{
    Container() : scrollX(0), scrollY(0) {}

    ScrollBar vertical;
    ScrollBar horizonal;

    NO_BIND size_t scrollX;
    NO_BIND size_t scrollY;
    NO_BIND int left;
    NO_BIND int right;
    NO_BIND int bottom;
    NO_BIND int top;
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
        void beginContainer(int left, int right, int bottom, int top, Container *container) NO_BIND;
        void endContainer(Container *container);
        void verticalScrollBar(int left,
                               int right,
                               int bottom,
                               int top,
                               bool leftRounded,
                               bool rightRounded,
                               ScrollBar *state);
        void horizontalScrollBar(int left,
                                 int right,
                                 int bottom,
                                 int top,
                                 bool topRounded,
                                 bool bottomRounded,
                                 ScrollBar *state);
        bool button(const char *text, int left, int right, int bottom, int top);
        size_t label(const char *text,
                     int leftOrRight,
                     int bottomOrTop,
                     bool left=true,
                     bool bottom=true);

        void render();
    private:
        struct Command
        {
            enum Type
            {
                Rectangle,
                Text,
                PushScissor,
                PopScissor
            };

            Type type;

            String textStr;
            union
            {
                struct
                {
                    size_t size;
                    int left;
                    int bottom;
                    float colorR;
                    float colorG;
                    float colorB;
                } text;
                struct
                {
                    int left;
                    int right;
                    int bottom;
                    int top;
                    float brightness;
                    float gradientStart;
                    float gradientSize;
                    float gradientPower;
                    float colorR;
                    float colorG;
                    float colorB;
                    float topLeftCornerRoundness;
                    float topRightCornerRoundness;
                    float bottomLeftCornerRoundness;
                    float bottomRightCornerRoundness;
                } rect;
                struct
                {
                    uint16_t left;
                    uint16_t right;
                    uint16_t bottom;
                    uint16_t top;
                } scissor;
            };
        };

        GfxMesh *mesh;
        GfxShader *vertexShader;
        GfxShader *fragmentShader;
        GfxCompiledShader *compiledVertex;
        GfxCompiledShader *compiledFragment;

        Font *font;

        int scrollX;
        int scrollY;
        int containerLeft;
        int containerRight;
        int containerTop;
        int containerBottom;

        List<Command> commands;
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
