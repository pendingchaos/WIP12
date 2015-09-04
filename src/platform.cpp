#include "platform.h"

#include "memory.h"
#include "error.h"
#include "graphics/gfxapi.h"
#include "graphics/gputimer.h"
#include "globals.h"

#include <cstdio>

struct toSDLScancodeStruct {
    Platform::Key key;
    SDL_Scancode scancode;
};

toSDLScancodeStruct toSDLScancodeTable[] = {
{Platform::Space, SDL_SCANCODE_SPACE},
{Platform::Apostrophe, SDL_SCANCODE_APOSTROPHE},
{Platform::Comma, SDL_SCANCODE_COMMA},
{Platform::Minus, SDL_SCANCODE_MINUS},
{Platform::Period, SDL_SCANCODE_PERIOD},
{Platform::Slash, SDL_SCANCODE_SLASH},
{Platform::_0, SDL_SCANCODE_0},
{Platform::_1, SDL_SCANCODE_1},
{Platform::_2, SDL_SCANCODE_2},
{Platform::_3, SDL_SCANCODE_3},
{Platform::_4, SDL_SCANCODE_4},
{Platform::_5, SDL_SCANCODE_5},
{Platform::_6, SDL_SCANCODE_6},
{Platform::_7, SDL_SCANCODE_7},
{Platform::_8, SDL_SCANCODE_8},
{Platform::_9, SDL_SCANCODE_9},
{Platform::Semicolon, SDL_SCANCODE_SEMICOLON},
{Platform::Equal, SDL_SCANCODE_EQUALS},
{Platform::A, SDL_SCANCODE_A},
{Platform::B, SDL_SCANCODE_B},
{Platform::C, SDL_SCANCODE_C},
{Platform::D, SDL_SCANCODE_D},
{Platform::E, SDL_SCANCODE_E},
{Platform::F, SDL_SCANCODE_F},
{Platform::G, SDL_SCANCODE_G},
{Platform::H, SDL_SCANCODE_H},
{Platform::I, SDL_SCANCODE_I},
{Platform::J, SDL_SCANCODE_J},
{Platform::K, SDL_SCANCODE_K},
{Platform::L, SDL_SCANCODE_L},
{Platform::M, SDL_SCANCODE_M},
{Platform::N, SDL_SCANCODE_N},
{Platform::O, SDL_SCANCODE_O},
{Platform::P, SDL_SCANCODE_P},
{Platform::Q, SDL_SCANCODE_Q},
{Platform::R, SDL_SCANCODE_R},
{Platform::S, SDL_SCANCODE_S},
{Platform::T, SDL_SCANCODE_T},
{Platform::U, SDL_SCANCODE_U},
{Platform::V, SDL_SCANCODE_V},
{Platform::W, SDL_SCANCODE_W},
{Platform::X, SDL_SCANCODE_X},
{Platform::Y, SDL_SCANCODE_Y},
{Platform::Z, SDL_SCANCODE_Z},
{Platform::LeftBracket, SDL_SCANCODE_LEFTBRACKET},
{Platform::RightBracket, SDL_SCANCODE_RIGHTBRACKET},
{Platform::Backslash, SDL_SCANCODE_BACKSLASH},
{Platform::Escape, SDL_SCANCODE_ESCAPE},
{Platform::Enter, SDL_SCANCODE_RETURN},
{Platform::Tab, SDL_SCANCODE_TAB},
{Platform::Backspace, SDL_SCANCODE_BACKSPACE},
{Platform::Insert, SDL_SCANCODE_INSERT},
{Platform::Delete, SDL_SCANCODE_DELETE},
{Platform::Right, SDL_SCANCODE_RIGHT},
{Platform::Left, SDL_SCANCODE_LEFT},
{Platform::Down, SDL_SCANCODE_DOWN},
{Platform::Up, SDL_SCANCODE_UP},
{Platform::PageUp, SDL_SCANCODE_PAGEUP},
{Platform::PageDown, SDL_SCANCODE_PAGEDOWN},
{Platform::Home, SDL_SCANCODE_HOME},
{Platform::End, SDL_SCANCODE_END},
{Platform::CapsLock, SDL_SCANCODE_CAPSLOCK},
{Platform::ScrollLock, SDL_SCANCODE_SCROLLLOCK},
{Platform::NumLock, SDL_SCANCODE_NUMLOCKCLEAR},
{Platform::PrintScreen, SDL_SCANCODE_PRINTSCREEN},
{Platform::Pause, SDL_SCANCODE_PAUSE},
{Platform::F1, SDL_SCANCODE_F1},
{Platform::F2, SDL_SCANCODE_F2},
{Platform::F3, SDL_SCANCODE_F3},
{Platform::F4, SDL_SCANCODE_F4},
{Platform::F5, SDL_SCANCODE_F5},
{Platform::F6, SDL_SCANCODE_F6},
{Platform::F7, SDL_SCANCODE_F7},
{Platform::F8, SDL_SCANCODE_F8},
{Platform::F9, SDL_SCANCODE_F9},
{Platform::LeftShift, SDL_SCANCODE_LSHIFT},
{Platform::LeftControl, SDL_SCANCODE_LCTRL},
{Platform::LeftAlt, SDL_SCANCODE_LALT},
{Platform::LeftSuper, SDL_SCANCODE_LGUI},
{Platform::RightShift, SDL_SCANCODE_RSHIFT},
{Platform::RightControl, SDL_SCANCODE_RCTRL},
{Platform::RightAlt, SDL_SCANCODE_RALT},
{Platform::RightSuper, SDL_SCANCODE_RGUI},
{Platform::Menu, SDL_SCANCODE_MENU},
{Platform::Unknown, SDL_SCANCODE_UNKNOWN}};

SDL_Scancode toSDLScancode(Platform::Key key)
{
    for (size_t i = 0; i < sizeof(toSDLScancodeTable)/sizeof(toSDLScancodeTable[0]); ++i)
    {
        if (toSDLScancodeTable[i].key == key)
        {
            return toSDLScancodeTable[i].scancode;
        }
    }

    return SDL_SCANCODE_UNKNOWN;
}

Platform::Key toKey(SDL_Scancode scancode)
{
    for (size_t i = 0; i < sizeof(toSDLScancodeTable)/sizeof(toSDLScancodeTable[0]); ++i)
    {
        if (toSDLScancodeTable[i].scancode == scancode)
        {
            return toSDLScancodeTable[i].key;
        }
    }

    return Platform::Unknown;
}

Platform::MouseButton toMouseButton(Uint32 button)
{
    switch (button)
    {
    case SDL_BUTTON_LEFT:
    {
        return Platform::LeftMouseButton;
    }
    case SDL_BUTTON_MIDDLE:
    {
        return Platform::MiddleMouseButton;
    }
    case SDL_BUTTON_RIGHT:
    {
        return Platform::RightMouseButton;
    }
    default:
    {
        return Platform::UnknownMouseButton;
    }
    }
}

Platform::Platform() : running(false), frametime(0.0f), gpuFrametime(0.0f), fullscreen(false)
{
    SDL_Init(SDL_INIT_EVERYTHING);

    window = nullptr;
    context = nullptr;
}

Platform::~Platform()
{
    SDL_Quit();
}

void Platform::initWindow(uint32_t width,
                          uint32_t height,
                          uint32_t MSAA)
{
    if (window != nullptr)
    {
        return;
    }

    window = SDL_CreateWindow("",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              width,
                              height,
                                SDL_WINDOW_OPENGL
                              | SDL_WINDOW_SHOWN
                              | SDL_WINDOW_RESIZABLE);

    if (window == nullptr)
    {
        THROW(PlatformException, SDL_GetError());
        return;
    }

    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, MSAA);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_DEBUG_FLAG);

    #define TRY_VERSION(major, minor)\
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, major);\
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, minor);\
    context = SDL_GL_CreateContext(window);\
    if (context != nullptr)\
    {\
        goto success;\
    }\

    TRY_VERSION(4, 5)
    TRY_VERSION(4, 4)
    TRY_VERSION(4, 3)
    TRY_VERSION(4, 2)
    TRY_VERSION(4, 1)
    TRY_VERSION(4, 0)
    TRY_VERSION(3, 3)

    success:;

    if (context == nullptr)
    {
        THROW(PlatformException, SDL_GetError());
        return;
    }

    SDL_Event event;
    event.type = SDL_WINDOWEVENT;
    event.window.event = SDL_WINDOWEVENT_RESIZED;
    event.window.data1 = width;
    event.window.data2 = height;

    SDL_PushEvent(&event);
}

void Platform::destroyWindow()
{
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);

    context = nullptr;
    window = nullptr;
}

void Platform::run(void (*updateFunction)(Platform *platform))
{
    running = true;

    float titleUpdateDelay = 0.5f;
    float titleUpdateCountdown = 0.0f;
    float displayFrametime = 0.0f;

    GPUTimer *gpuTimer = gfxApi->createTimer();
    uint64_t gpuTime = 0;

    while (running)
    {
        mouseWheel = Int2();

        Uint64 start = SDL_GetPerformanceCounter();

        SDL_PumpEvents();

        gpuTimer->begin();

        updateFunction(this);

        gpuTimer->end();

        Uint64 cpuEnd = SDL_GetPerformanceCounter();

        cpuFrametime = float(cpuEnd - start) / SDL_GetPerformanceFrequency();

        SDL_GL_SwapWindow(window);
        glFinish();

        Uint64 end = SDL_GetPerformanceCounter();

        if (gpuTimer->resultAvailable())
        {
            gpuTime = gpuTimer->getResult();
        }

        frametime = float(end-start) / float(SDL_GetPerformanceFrequency());

        gpuFrametime = float(gpuTime) / float(gpuTimer->getResultResolution());

        titleUpdateCountdown -= frametime;

        if (titleUpdateCountdown <= 0.0f)
        {
            titleUpdateCountdown = titleUpdateDelay;

            displayFrametime = frametime;
        }

        char title[256];
        memset(title, '\x00', sizeof(title));

        std::snprintf(title,
                      sizeof(title),
                      "Frametime: %f ms",
                      displayFrametime*1000.0f);

        SDL_SetWindowTitle(window, title);
    }

    DELETE(gpuTimer);
}

bool Platform::pollEvent(Event& event)
{
    SDL_Event sdlEvent;

    int pending = SDL_PollEvent(&sdlEvent);

    if (pending == 0)
    {
        return false;
    }

    switch (sdlEvent.type)
    {
    case SDL_QUIT:
    {
        event.type = Event::Quit;
        break;
    }
    case SDL_WINDOWEVENT:
    {
        switch (sdlEvent.window.event)
        {
        case SDL_WINDOWEVENT_RESIZED:
        {
            event.type = Event::WindowResize;

            event.resize.width = sdlEvent.window.data1;
            event.resize.height = sdlEvent.window.data2;
            break;
        }
        default:
        {
            event.type = Event::Unknown;
            break;
        }
        }
        break;
    }
    case SDL_KEYDOWN:
    {
        event.type = Event::KeyDown;
        event.key.key = toKey(sdlEvent.key.keysym.scancode);
        break;
    }
    case SDL_KEYUP:
    {
        event.type = Event::KeyUp;
        event.key.key = toKey(sdlEvent.key.keysym.scancode);
        break;
    }
    case SDL_MOUSEMOTION:
    {
        event.type = Event::MouseMotion;
        event.mouseMotion.x = sdlEvent.motion.x;
        event.mouseMotion.y = sdlEvent.motion.y;
        event.mouseMotion.relativeX = sdlEvent.motion.xrel;
        event.mouseMotion.relativeY = sdlEvent.motion.yrel;
        break;
    }
    case SDL_MOUSEBUTTONDOWN:
    {
        event.type = Event::MouseButtonDown;
        event.mouseButton.button = toMouseButton(sdlEvent.button.button);
        event.mouseButton.doubleClicked = sdlEvent.button.clicks == 2;
        break;
    }
    case SDL_MOUSEBUTTONUP:
    {
        event.type = Event::MouseButtonUp;
        event.mouseButton.button = toMouseButton(sdlEvent.button.button);
        event.mouseButton.doubleClicked = sdlEvent.button.clicks == 2;
        break;
    }
    case SDL_MOUSEWHEEL:
    {
        event.type = Event::MouseWheel;
        event.mouseWheel.relativeX = sdlEvent.wheel.x;
        event.mouseWheel.relativeY = sdlEvent.wheel.y;

        mouseWheel.x = sdlEvent.wheel.x;
        mouseWheel.y = sdlEvent.wheel.y;
        break;
    }
    default:
    {
        event.type = Event::Unknown;
        break;
    }
    }

    return true;
}

bool Platform::eventsLeft() const
{
    return SDL_HasEvents(SDL_FIRSTEVENT, SDL_LASTEVENT);
}

uint64_t Platform::getTime() const
{
    return SDL_GetPerformanceCounter();
}

uint64_t Platform::getTimerFrequency() const
{
    return SDL_GetPerformanceFrequency();
}

size_t Platform::getWindowWidth() const
{
    if (window == nullptr)
    {
        return 0;
    }

    int result;
    SDL_GetWindowSize(window, &result, nullptr);

    return result;
}

size_t Platform::getWindowHeight() const
{
    if (window == nullptr)
    {
        return 0;
    }

    int result;
    SDL_GetWindowSize(window, nullptr, &result);

    return result;
}

Int2 Platform::getMousePosition() const
{
    Int2 pos;

    SDL_GetMouseState(&pos.x, &pos.y);

    return pos;
}

void Platform::setMousePosition(Int2 position)
{
    if (window != nullptr)
    {
        SDL_WarpMouseInWindow(window, position.x, position.y);
    }
}

bool Platform::isLeftMouseButtonPressed() const
{
    return SDL_GetMouseState(nullptr, nullptr) & SDL_BUTTON_LMASK;
}

bool Platform::isRightMouseButtonPressed() const
{
    return SDL_GetMouseState(nullptr, nullptr) & SDL_BUTTON_RMASK;
}

bool Platform::isMiddleMouseButtonPressed() const
{
    return SDL_GetMouseState(nullptr, nullptr) & SDL_BUTTON_MMASK;
}

Int2 Platform::getMouseWheel() const
{
    return mouseWheel;
}

bool Platform::isCursorVisible() const
{
    return SDL_ShowCursor(-1);
}

void Platform::setCursorVisible(bool visible) const
{
    SDL_ShowCursor(visible ? 1 : 0);
}

bool Platform::isKeyPressed(Key key) const
{
    return SDL_GetKeyboardState(nullptr)[toSDLScancode(key)] != 0;
}

bool Platform::getFullscreen() const
{
    return fullscreen;
}

void Platform::setFullscreen(bool fullscreen_)
{
    if (window != nullptr)
    {
        SDL_SetWindowFullscreen(window, fullscreen_ ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);
    }

    fullscreen = fullscreen_;
}
