#include "platform/sdl2/sdl2platform.h"

#include "memory.h"
#include "graphics/GL/glfl.h"
#include "error.h"

#include <cstdio>

#ifdef USE_SDL2
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

SDL2Platform::SDL2Platform() : frametime(0.0f), fullscreen(false)
{
    SDL_Init(SDL_INIT_EVERYTHING);

    window = nullptr;
    context = nullptr;
}

SDL2Platform::~SDL2Platform()
{
    SDL_Quit();
}

void SDL2Platform::initWindow(uint32_t width,
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

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

    context = SDL_GL_CreateContext(window);

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

void SDL2Platform::destroyWindow()
{
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);

    context = nullptr;
    window = nullptr;
}

void SDL2Platform::run(void (*updateFunction)(Platform *platform))
{
    running = true;

    float titleUpdateDelay = 0.75f;
    float titleUpdateCountdown = 0.0f;
    float displayFrametime = 0.0f;
    float displayGpuFrametime = 0.0f;

    GLuint timerQuery;
    glGenQueries(1, &timerQuery);

    while (running)
    {
        Uint64 start = SDL_GetPerformanceCounter();

        glBeginQuery(GL_TIME_ELAPSED, timerQuery);

        SDL_PumpEvents();

        updateFunction(this);

        glEndQuery(GL_TIME_ELAPSED);

        SDL_GL_SwapWindow(window);

        Uint64 end = SDL_GetPerformanceCounter();

        GLint done = 0;
        while (not done)
        {
            glGetQueryObjectiv(timerQuery, GL_QUERY_RESULT_AVAILABLE, &done);
        }

        GLuint64 gpuTime;
        glGetQueryObjectui64v(timerQuery, GL_QUERY_RESULT, &gpuTime);

        frametime = static_cast<float>(end-start) / static_cast<float>(SDL_GetPerformanceFrequency());

        float gpuFrametime = (gpuTime / 1000000000.0f);

        titleUpdateCountdown -= frametime;

        if (titleUpdateCountdown <= 0.0f)
        {
            titleUpdateCountdown = titleUpdateDelay;

            displayFrametime = frametime;
            displayGpuFrametime = gpuFrametime;
        }

        float cpuOverhead
        =   ((displayFrametime - displayGpuFrametime))
          / (displayFrametime) * 100.0f;

        char title[256];
        memset(title, '\x00', sizeof(title));

        std::snprintf(title,
                      sizeof(title),
                      "Frametime: %f FPS: %.0f GPU Frametime: %f GPU FPS: %f CPU overhead: %.0f%s",
                      displayFrametime,
                      1.0f/displayFrametime,
                      displayGpuFrametime,
                      1.0f/displayGpuFrametime,
                      cpuOverhead,
                      "%s");

        SDL_SetWindowTitle(window, title);
    }
}

bool SDL2Platform::pollEvent(Event& event)
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

bool SDL2Platform::eventsLeft() const
{
    return SDL_HasEvents(SDL_FIRSTEVENT, SDL_LASTEVENT);
}

uint64_t SDL2Platform::getTime() const
{
    return SDL_GetPerformanceCounter();
}

uint64_t SDL2Platform::getTimerFrequency() const
{
    return SDL_GetPerformanceFrequency();
}

size_t SDL2Platform::getWindowWidth() const
{
    if (window == nullptr)
    {
        return 0;
    }

    int result;
    SDL_GetWindowSize(window, &result, nullptr);

    return result;
}

size_t SDL2Platform::getWindowHeight() const
{
    if (window == nullptr)
    {
        return 0;
    }

    int result;
    SDL_GetWindowSize(window, nullptr, &result);

    return result;
}

Int2 SDL2Platform::getMousePosition() const
{
    Int2 pos;

    SDL_GetMouseState(&pos.x, &pos.y);

    return pos;
}

void SDL2Platform::setMousePosition(Int2 position)
{
    if (window != nullptr)
    {
        SDL_WarpMouseInWindow(window, position.x, position.y);
    }
}

bool SDL2Platform::isLeftMouseButtonPressed() const
{
    return SDL_GetMouseState(nullptr, nullptr) & SDL_BUTTON_LMASK;
}

bool SDL2Platform::isRightMouseButtonPressed() const
{
    return SDL_GetMouseState(nullptr, nullptr) & SDL_BUTTON_RMASK;
}

bool SDL2Platform::isMiddleMouseButtonPressed() const
{
    return SDL_GetMouseState(nullptr, nullptr) & SDL_BUTTON_MMASK;
}

bool SDL2Platform::isCursorVisible() const
{
    return SDL_ShowCursor(-1);
}

void SDL2Platform::setCursorVisible(bool visible) const
{
    SDL_ShowCursor(visible ? 1 : 0);
}

bool SDL2Platform::isKeyPressed(Key key) const
{
    return SDL_GetKeyboardState(nullptr)[toSDLScancode(key)] != 0;
}

bool SDL2Platform::getFullscreen() const
{
    return fullscreen;
}

void SDL2Platform::setFullscreen(bool fullscreen_)
{
    if (window != nullptr)
    {
        SDL_SetWindowFullscreen(window, fullscreen_ ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);
    }

    fullscreen = fullscreen_;
}
#endif
