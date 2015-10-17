#ifndef PLATFORM_H
#define PLATFORM_H

#include "math/t2.h"
#include "containers/string.h"
#include "error.h"
#include "scripting/bindings.h"
#include "misc_macros.h"

#include <stddef.h>
#include <stdint.h>
#include <SDL2/SDL.h>

class PlatformException : public Exception
{
    public:
        PlatformException(const char *file_,
                          size_t line_,
                          const char *function_,
                          const Str& problem_) : Exception(file_, line_, function_),
                                                    problem(problem_) {}

        virtual const char *getString() const
        {
            return problem.getData();
        }
    private:
        Str problem;
};

enum class Key
{
    Space = ' ',
    Apostrophe = '\'',
    Comma = ',',
    Minus = '-',
    Period = '.',
    Slash = '/',
    _0 = '0',
    _1 = '1',
    _2 = '2',
    _3 = '3',
    _4 = '4',
    _5 = '5',
    _6 = '6',
    _7 = '7',
    _8 = '8',
    _9 = '9',
    Semicolon = ';',
    Equal = '=',
    A = 'a',
    B = 'b',
    C = 'c',
    D = 'd',
    E = 'e',
    F = 'f',
    G = 'g',
    H = 'h',
    I = 'i',
    J = 'j',
    K = 'k',
    L = 'l',
    M = 'm',
    N = 'n',
    O = 'o',
    P = 'p',
    Q = 'q',
    R = 'r',
    S = 's',
    T = 't',
    U = 'u',
    V = 'v',
    W = 'w',
    X = 'x',
    Y = 'y',
    Z = 'z',
    LeftBracket = '[',
    RightBracket = ']',
    Backslash = '\\',
    Escape = 256,
    Enter,
    Tab,
    Backspace,
    Insert,
    Delete,
    Right,
    Left,
    Down,
    Up,
    PageUp,
    PageDown,
    Home,
    End,
    CapsLock,
    ScrollLock,
    NumLock,
    PrintScreen,
    Pause,
    F1,
    F2,
    F3,
    F4,
    F5,
    F6,
    F7,
    F8,
    F9,
    LeftShift,
    LeftControl,
    LeftAlt,
    LeftSuper,
    RightShift,
    RightControl,
    RightAlt,
    RightSuper,
    Menu,
    Unknown
} BIND ENUM_CLASS;

enum class MouseButton
{
    Left,
    Middle,
    Right,
    Unknown
} BIND ENUM_CLASS;

enum class EventType
{
    Quit,
    WindowResize,
    KeyDown,
    KeyUp,
    MouseMotion,
    MouseButtonDown,
    MouseButtonUp,
    MouseWheel,
    Unknown
} BIND ENUM_CLASS;

struct Event
{
    EventType type;

    union
    {
        struct
        {
            unsigned int width;
            unsigned int height;
        } resize;
        struct
        {
            Key key;
        } key;
        struct
        {
            unsigned int x;
            unsigned int y;
            int relativeX;
            int relativeY;
        } mouseMotion;
        struct
        {
            MouseButton button;
            bool doubleClicked;
        } mouseButton;
        struct
        {
            int relativeX;
            int relativeY;
        } mouseWheel;
    } NO_BIND;

    inline unsigned int getWidth() const
    {
        return type == EventType::WindowResize ? resize.width : 0;
    }

    inline unsigned int getHeight() const
    {
        return type == EventType::WindowResize ? resize.height : 0;
    }

    inline Key getKey() const
    {
        return (type == EventType::KeyDown or type == EventType::KeyUp) ? key.key : Key::Unknown;
    }

    inline unsigned int getX() const
    {
        return type == EventType::MouseMotion ? mouseMotion.x : 0;
    }

    inline unsigned int getY() const
    {
        return type == EventType::MouseMotion ? mouseMotion.y : 0;
    }

    inline int getRelX() const
    {
        if (type == EventType::MouseMotion)
        {
            return mouseMotion.relativeX;
        } else if (type == EventType::MouseWheel)
        {
            return mouseWheel.relativeX;
        } else
        {
            return 0;
        }
    }

    inline int getRelY() const
    {
        if (type == EventType::MouseMotion)
        {
            return mouseMotion.relativeX;
        } else if (type == EventType::MouseWheel)
        {
            return mouseWheel.relativeX;
        } else
        {
            return 0;
        }
    }

    inline MouseButton getButton() const
    {
        return (type == EventType::MouseButtonDown or type == EventType::MouseButtonUp) ? mouseButton.button : MouseButton::Unknown;
    }

    inline bool getDoubleClicked() const
    {
        return (type == EventType::MouseButtonDown or type == EventType::MouseButtonUp) ? mouseButton.doubleClicked : false;
    }
} BIND;

class Platform
{
    NO_COPY(Platform);

    public:
        Platform();
        virtual ~Platform();

        void initWindow(uint32_t width,
                        uint32_t height);
        void destroyWindow();

        //Virtual to get around bug in script_binding_generator.py.
        virtual void run(void (*updateFunction)(Platform *platform)) NO_BIND;
        bool pollEvent(Event& event) NO_BIND;
        bool eventsLeft() const;

        Event popEvent()
        {
            Event event;
            pollEvent(event);
            return event;
        }

        uint64_t getTime() const;
        uint64_t getTimerFrequency() const;

        size_t getWindowWidth() const;
        size_t getWindowHeight() const;

        Int2 getMousePosition() const;
        void setMousePosition(Int2 position);
        bool isLeftMouseButtonPressed() const;
        bool isRightMouseButtonPressed() const;
        bool isMiddleMouseButtonPressed() const;

        Int2 getMouseWheel() const;

        bool isCursorVisible() const;
        void setCursorVisible(bool visible) const;

        bool isKeyPressed(Key key) const;

        bool getFullscreen() const;
        void setFullscreen(bool fullscreen);

        inline float getFrametime() const
        {
            return frametime;
        }

        inline float getGPUFrametime() const
        {
            return gpuFrametime;
        }

        inline float getCPUFrametime() const
        {
            return cpuFrametime;
        }

        bool running;
    private:
        SDL_Window *window;
        SDL_GLContext context;
        float frametime;
        float gpuFrametime;
        float cpuFrametime;
        bool fullscreen;
        Int2 mouseWheel;
} BIND NOT_COPYABLE;

#endif // PLATFORM_H
