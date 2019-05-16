#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include <SDL2/SDL.h>
#include "texture.h"

class EventHandler {
public:
    EventHandler(Texture& texture);

    EventHandler(const EventHandler&) = delete;
    EventHandler& operator=(const EventHandler&) = delete;
    EventHandler(EventHandler&& other) = delete;
    EventHandler& operator=(EventHandler&& other) = delete;

    operator bool() const;
    operator int() const = delete;

    void poll();

private:
    bool quit = false;
    SDL_Event event;

    Texture& texture;
};

#endif  // EVENT_HANDLER_H
