#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include <SDL2/SDL.h>
#include <vector>
#include "mouse_event.h"
#include "keyboard_event.h"
#include "keyboard_handler.h"
#include "mouse_handler.h"

class EventHandler {
public:
    explicit EventHandler() = default;

    EventHandler(const EventHandler&) = delete;
    EventHandler& operator=(const EventHandler&) = delete;
    EventHandler(EventHandler&& other) = delete;
    EventHandler& operator=(EventHandler&& other) = delete;

    operator bool() const;
    operator int() const = delete;

    void add(KeyboardHandler* keyboard_handler);
    void add(MouseHandler* mouse_handler);

    void poll();

private:
    bool quit = false;
    SDL_Event event;
    std::vector<KeyboardHandler*> keyboard_handlers;
    std::vector<MouseHandler*> mouse_handlers;

    void broadcast(KeyboardEvent event) const;
    void broadcast(MouseEvent event) const;

    bool isKeyboardEvent(SDL_Event event) const;
    bool isMouseEvent(SDL_Event event) const;
};

#endif  // EVENT_HANDLER_H
