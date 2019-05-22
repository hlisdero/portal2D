#include "client/event/event_handler.h"

bool EventHandler::quit() const {
    return quit_flag;
}

void EventHandler::add(KeyboardHandler* keyboard_handler) {
    keyboard_handlers.push_back(keyboard_handler);
}

void EventHandler::add(MouseHandler* mouse_handler) {
    mouse_handlers.push_back(mouse_handler);
}

void EventHandler::poll() {
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            quit = true;
        }
        if (isKeyboardEvent(event)) {
            KeyboardEvent keyboard_event(event);
            broadcast(keyboard_event);
        }
        if (isMouseEvent(event)) {
            MouseEvent mouse_event(event);
            broadcast(mouse_event);
        }
    }
}

void EventHandler::broadcast(KeyboardEvent event) const {
    for (auto &handler : keyboard_handlers) {
        handler->handle(event);
    }
}

void EventHandler::broadcast(MouseEvent event) const {
    for (auto &handler : mouse_handlers) {
        handler->handle(event);
    }
}

bool EventHandler::isKeyboardEvent(SDL_Event event) const {
    if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
        return true;
    } else {
        return false;
    }
}

bool EventHandler::isMouseEvent(SDL_Event event) const {
    if (event.type == SDL_MOUSEMOTION ||
        event.type == SDL_MOUSEBUTTONDOWN ||
        event.type == SDL_MOUSEBUTTONUP) {
        return true;
    } else {
        return false;
    }
}
