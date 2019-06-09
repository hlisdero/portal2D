#ifndef WINDOW_EVENT_HANDLER_H
#define WINDOW_EVENT_HANDLER_H

#include <SDL2/SDL.h>

class WindowEventHandler {
public:
    virtual void handle(const SDL_Event& event) = 0;

    virtual ~WindowEventHandler() = default;
};

#endif  // WINDOW_EVENT_HANDLER_H
