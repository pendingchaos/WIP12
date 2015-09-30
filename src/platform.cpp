#include "platform.h"

#include "memory.h"
#include "error.h"
#include "graphics/gfxapi.h"
#include "graphics/gputimer.h"
#include "globals.h"

#include <cstdio>

struct toSDLKeycodeStruct {
    Key key;
    SDL_Keycode keycode;
};

toSDLKeycodeStruct toSDLKeycodeTable[] = {
{Key::Space, SDLK_SPACE},
{Key::Apostrophe, SDLK_QUOTE},
{Key::Comma, SDLK_COMMA},
{Key::Minus, SDLK_MINUS},
{Key::Period, SDLK_PERIOD},
{Key::Slash, SDLK_SLASH},
{Key::_0, SDLK_0},
{Key::_1, SDLK_1},
{Key::_2, SDLK_2},
{Key::_3, SDLK_3},
{Key::_4, SDLK_4},
{Key::_5, SDLK_5},
{Key::_6, SDLK_6},
{Key::_7, SDLK_7},
{Key::_8, SDLK_8},
{Key::_9, SDLK_9},
{Key::Semicolon, SDLK_SEMICOLON},
{Key::Equal, SDLK_EQUALS},
{Key::A, SDLK_a},
{Key::B, SDLK_b},
{Key::C, SDLK_c},
{Key::D, SDLK_d},
{Key::E, SDLK_e},
{Key::F, SDLK_f},
{Key::G, SDLK_g},
{Key::H, SDLK_h},
{Key::I, SDLK_i},
{Key::J, SDLK_j},
{Key::K, SDLK_k},
{Key::L, SDLK_l},
{Key::M, SDLK_m},
{Key::N, SDLK_n},
{Key::O, SDLK_o},
{Key::P, SDLK_p},
{Key::Q, SDLK_q},
{Key::R, SDLK_r},
{Key::S, SDLK_s},
{Key::T, SDLK_t},
{Key::U, SDLK_u},
{Key::V, SDLK_v},
{Key::W, SDLK_w},
{Key::X, SDLK_x},
{Key::Y, SDLK_y},
{Key::Z, SDLK_z},
{Key::LeftBracket, SDLK_LEFTBRACKET},
{Key::RightBracket, SDLK_RIGHTBRACKET},
{Key::Backslash, SDLK_BACKSLASH},
{Key::Escape, SDLK_ESCAPE},
{Key::Enter, SDLK_RETURN},
{Key::Tab, SDLK_TAB},
{Key::Backspace, SDLK_BACKSPACE},
{Key::Insert, SDLK_INSERT},
{Key::Delete, SDLK_DELETE},
{Key::Right, SDLK_RIGHT},
{Key::Left, SDLK_LEFT},
{Key::Down, SDLK_DOWN},
{Key::Up, SDLK_UP},
{Key::PageUp, SDLK_PAGEUP},
{Key::PageDown, SDLK_PAGEDOWN},
{Key::Home, SDLK_HOME},
{Key::End, SDLK_END},
{Key::CapsLock, SDLK_CAPSLOCK},
{Key::ScrollLock, SDLK_SCROLLLOCK},
{Key::NumLock, SDLK_NUMLOCKCLEAR},
{Key::PrintScreen, SDLK_PRINTSCREEN},
{Key::Pause, SDLK_PAUSE},
{Key::F1, SDLK_F1},
{Key::F2, SDLK_F2},
{Key::F3, SDLK_F3},
{Key::F4, SDLK_F4},
{Key::F5, SDLK_F5},
{Key::F6, SDLK_F6},
{Key::F7, SDLK_F7},
{Key::F8, SDLK_F8},
{Key::F9, SDLK_F9},
{Key::LeftShift, SDLK_LSHIFT},
{Key::LeftControl, SDLK_LCTRL},
{Key::LeftAlt, SDLK_LALT},
{Key::LeftSuper, SDLK_LGUI},
{Key::RightShift, SDLK_RSHIFT},
{Key::RightControl, SDLK_RCTRL},
{Key::RightAlt, SDLK_RALT},
{Key::RightSuper, SDLK_RGUI},
{Key::Menu, SDLK_MENU},
{Key::Unknown, SDLK_UNKNOWN}};

SDL_Keycode toSDLKeycode(Key key)
{
    for (size_t i = 0; i < sizeof(toSDLKeycodeTable)/sizeof(toSDLKeycodeStruct); ++i)
    {
        if (toSDLKeycodeTable[i].key == key)
        {
            return toSDLKeycodeTable[i].keycode;
        }
    }

    return SDLK_UNKNOWN;
}

Key toKey(SDL_Keycode scancode)
{
    for (size_t i = 0; i < sizeof(toSDLKeycodeTable)/sizeof(toSDLKeycodeStruct); ++i)
    {
        if (toSDLKeycodeTable[i].keycode == scancode)
        {
            return toSDLKeycodeTable[i].key;
        }
    }

    return Key::Unknown;
}

MouseButton toMouseButton(Uint32 button)
{
    switch (button)
    {
    case SDL_BUTTON_LEFT:
    {
        return MouseButton::Left;
    }
    case SDL_BUTTON_MIDDLE:
    {
        return MouseButton::Middle;
    }
    case SDL_BUTTON_RIGHT:
    {
        return MouseButton::Right;
    }
    default:
    {
        return MouseButton::Unknown;
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
    destroyWindow();

    SDL_Quit();
}

void Platform::initWindow(uint32_t width,
                          uint32_t height)
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
    if (context != nullptr)
    {
        SDL_GL_DeleteContext(context);
        SDL_DestroyWindow(window);

        context = nullptr;
        window = nullptr;
    }
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

        gpuTimer->swap();
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
        event.type = EventType::Quit;
        break;
    }
    case SDL_WINDOWEVENT:
    {
        switch (sdlEvent.window.event)
        {
        case SDL_WINDOWEVENT_RESIZED:
        {
            event.type = EventType::WindowResize;

            event.resize.width = sdlEvent.window.data1;
            event.resize.height = sdlEvent.window.data2;
            break;
        }
        default:
        {
            event.type = EventType::Unknown;
            break;
        }
        }
        break;
    }
    case SDL_KEYDOWN:
    {
        event.type = EventType::KeyDown;
        event.key.key = toKey(sdlEvent.key.keysym.sym);
        break;
    }
    case SDL_KEYUP:
    {
        event.type = EventType::KeyUp;
        event.key.key = toKey(sdlEvent.key.keysym.sym);
        break;
    }
    case SDL_MOUSEMOTION:
    {
        event.type = EventType::MouseMotion;
        event.mouseMotion.x = sdlEvent.motion.x;
        event.mouseMotion.y = sdlEvent.motion.y;
        event.mouseMotion.relativeX = sdlEvent.motion.xrel;
        event.mouseMotion.relativeY = sdlEvent.motion.yrel;
        break;
    }
    case SDL_MOUSEBUTTONDOWN:
    {
        event.type = EventType::MouseButtonDown;
        event.mouseButton.button = toMouseButton(sdlEvent.button.button);
        event.mouseButton.doubleClicked = sdlEvent.button.clicks == 2;
        break;
    }
    case SDL_MOUSEBUTTONUP:
    {
        event.type = EventType::MouseButtonUp;
        event.mouseButton.button = toMouseButton(sdlEvent.button.button);
        event.mouseButton.doubleClicked = sdlEvent.button.clicks == 2;
        break;
    }
    case SDL_MOUSEWHEEL:
    {
        event.type = EventType::MouseWheel;
        event.mouseWheel.relativeX = sdlEvent.wheel.x;
        event.mouseWheel.relativeY = sdlEvent.wheel.y;

        mouseWheel.x = sdlEvent.wheel.x;
        mouseWheel.y = sdlEvent.wheel.y;
        break;
    }
    default:
    {
        event.type = EventType::Unknown;
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
    return SDL_GetKeyboardState(nullptr)[SDL_GetScancodeFromKey(toSDLKeycode(key))] != 0;
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
