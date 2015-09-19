```enum class PositionMode
{
    PixelBottomLeft,
    PixelTopRight
    PrecentBottomLeft,
    PrecentTopRight
    RelPrecentBottomLeft,
    RelPrecentTopRight
};

struct Position
{
    PositionMode mode;
    float value;
    String relativeTo; //Can be empty
};

class Widget
{
    NO_COPY(Widget)
    
    public:
        Position left;
        Position right;
        Position top;
        Position bottom;

        ScriptInstance *addScript(Script *script, const char *name) NO_BIND
        {
            if (script != nullptr)
            {
                removeScript();
            }
            
            script = script->createInstance(name, this);

            return script;
        }

        void removeScript() NO_BIND
        {
            DELETE(script);
            script = nullptr;
        }

        inline ScriptInstance *getScript() NO_BIND
        {
            return script;
        }

        void calculateRect(HashMap<String, Widget> widgets)
        {
            resLeft = calculatePositionResult(left, widgets, true);
            resRight = calculatePositionResult(right, widgets, true);
            resTop = calculatePositionResult(top, widgets, true);
            resBottom = calculatePositionResult(bottom, widgets, true);
        }
    private:
        float resLeft;
        float resRight;
        float resTop;
        float resBottom;

        float calculatePositionResult(Position pos, HashMap<String, Widget> widgets, bool x)
        {
            float relBottomLeft = 0;
            float relTopRight = x ? screenWidth : screenHeight;
            float screenSize = relTopRight;
            float relSize = screenSize;

            if (pos.relativeTo.getLength() != 0)
            {
                Widget *rel = widgets.get(pos.relativeTo);

                calculateWidget(rel, widgets);

                relBottomLeft = x ? rel.left : rel.bottom;
                relTopRight = x ? rel.right : rel.top;
                relSize = relTopRight - relBottomLeft;
            }

            switch (pos.mode)
            {
            case PositionMode::PixelBottomLeft:
            {
                return pos.value + relBottomLeft;
            }
            case PositionMode::PixelTopRight:
            {
                return pos.value - relTopRight;
            }
            case PositionMode::PrecentBottomLeft:
            {
                return pos.value * screenSize + relBottomLeft;
            }
            case PositionMode::PrecentTopRight:
            {
                return pos.value * screenSize - relTopRight;
            }
            case PositionMode::RelPrecentBottomLeft:
            {
                return pos.value * relSize + relBottomLeft;
            }
            case PositionMode::RelPrecentTopRight:
            {
                return pos.value * relSize - relTopRight;
            }
            }
        }
};

class GUI
{
    public:
    
    private:
        HashMap<String, Widget *> widgets;
};```
