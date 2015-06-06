#ifndef PLATFORM_H
#define PLATFORM_H

#include "math/t2.h"
#include "containers/string.h"
#include "error.h"

#include <stddef.h>

class PlatformException : Exception
{
    public:
        PlatformException(const char *file_,
                          size_t line_,
                          const char *function_,
                          const String& problem_) : Exception(file_, line_, function_),
                                                    problem(problem_) {}

        virtual const char *getString() const
        {
            return problem.getData();
        }
    private:
        String problem;
};

class Platform
{
    public:
        enum Key
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
        };

        enum MouseButton
        {
            LeftMouseButton,
            MiddleMouseButton,
            RightMouseButton,
            UnknownMouseButton
        };

        struct Event
        {
            enum Type
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
            };

            Type type;

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
            };
        };

        Platform() : running(false) {}
        virtual ~Platform() {}

        virtual void initWindow(uint32_t width,
                                uint32_t height,
                                uint32_t MSAA)=0;
        virtual void destroyWindow()=0;

        virtual void run(void (*updateFunction)(Platform *platform))=0;
        virtual bool pollEvent(Event& event)=0;
        virtual bool eventsLeft() const=0;

        virtual uint64_t getTime() const=0;
        virtual uint64_t getTimerFrequency() const=0;
        virtual float getFrametime() const=0;

        virtual size_t getWindowWidth() const=0;
        virtual size_t getWindowHeight() const=0;

        virtual Int2 getMousePosition() const=0;
        virtual void setMousePosition(Int2 position)=0;
        virtual bool isLeftMouseButtonPressed() const=0;
        virtual bool isRightMouseButtonPressed() const=0;
        virtual bool isMiddleMouseButtonPressed() const=0;

        virtual bool isCursorVisible() const=0;
        virtual void setCursorVisible(bool visible) const=0;

        virtual bool isKeyPressed(Key key) const=0;

        virtual bool getFullscreen() const=0;
        virtual void setFullscreen(bool fullscreen)=0;

        bool running;
};

#endif // PLATFORM_H
