#ifndef SDL2PLATFORM_H
#define SDL2PLATFORM_H

#ifdef USE_SDL2
#include <stdint.h>

#include <SDL2/SDL.h>

#include "platform/platform.h"

class SDL2Platform : public Platform
{
    public:
        SDL2Platform();
        ~SDL2Platform();

        virtual void initWindow(uint32_t width,
                                uint32_t height,
                                uint32_t MSAA);
        virtual void destroyWindow();

        virtual void run(void (*updateFunction)(Platform *platform));
        virtual bool pollEvent(Event& event);
        virtual bool eventsLeft() const;

        virtual uint64_t getTime() const;
        virtual uint64_t getTimerFrequency() const;
        virtual float getFrametime() const
        {
            return frametime;
        }

        virtual size_t getWindowWidth() const;
        virtual size_t getWindowHeight() const;

        virtual Int2 getMousePosition() const;
        virtual void setMousePosition(Int2 position);
        virtual bool isLeftMouseButtonPressed() const;
        virtual bool isRightMouseButtonPressed() const;
        virtual bool isMiddleMouseButtonPressed() const;

        virtual bool isCursorVisible() const;
        virtual void setCursorVisible(bool visible) const;

        virtual bool isKeyPressed(Key key) const;

        virtual bool getFullscreen() const;
        virtual void setFullscreen(bool fullscreen);
    private:
        SDL_Window *window;
        SDL_GLContext context;
        float frametime;
        bool fullscreen;
};
#endif

#endif // SDL2PLATFORM_H
