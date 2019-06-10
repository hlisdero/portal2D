#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include <SDL2/SDL.h>
#include <vector>
#include <stdexcept>
#include "client/event/mouse_event.h"
#include "client/event/keyboard_event.h"
#include "client/event/keyboard_handler.h"
#include "client/event/mouse_handler.h"
#include "client/event/window_event_handler.h"

class EventHandler {
public:
    explicit EventHandler() = default;

    EventHandler(const EventHandler&) = delete;
    EventHandler& operator=(const EventHandler&) = delete;
    EventHandler(EventHandler&& other) = delete;
    EventHandler& operator=(EventHandler&& other) = delete;

    bool quit() const;

    void add(KeyboardHandler* keyboard_handler);
    void add(MouseHandler* mouse_handler);
    void add(WindowEventHandler* window_event_handler);

    void remove(KeyboardHandler* keyboard_handler);
    void remove(MouseHandler* mouse_handler);
    void removeWindowEventHandler();

    void poll();

private:
    bool quit_flag = false;
    SDL_Event event;
    std::vector<KeyboardHandler*> keyboard_handlers;
    std::vector<MouseHandler*> mouse_handlers;
    WindowEventHandler* window_event_handler = nullptr;

    void broadcast(KeyboardEvent event) const;
    void broadcast(MouseEvent event) const;

    bool isWindowEvent(SDL_Event event) const;
    bool isKeyboardEvent(SDL_Event event) const;
    bool isMouseEvent(SDL_Event event) const;
};

#endif  // EVENT_HANDLER_H
