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

void EventHandler::add(WindowEventHandler* new_window_event_handler) {
    window_event_handler = new_window_event_handler;
}

void EventHandler::remove(KeyboardHandler* keyboard_handler) {
    for (size_t i = 0; i < keyboard_handlers.size(); ++i) {
        if (keyboard_handlers[i] == keyboard_handler) {
            keyboard_handlers.erase(keyboard_handlers.begin() + i);
            return;
        }
    }
    throw std::runtime_error("Error: KeyboardHandler para eliminar inválido");
}

void EventHandler::remove(MouseHandler* mouse_handler) {
    for (size_t i = 0; i < mouse_handlers.size(); ++i) {
        if (mouse_handlers[i] == mouse_handler) {
            mouse_handlers.erase(mouse_handlers.begin() + i);
            return;
        }
    }
    throw std::runtime_error("Error: MouseHandler para eliminar inválido");
}

void EventHandler::removeWindowEventHandler() {
    window_event_handler = nullptr;
}

void EventHandler::poll() {
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            quit_flag = true;
        }
        if (isWindowEvent(event) && window_event_handler) {
            window_event_handler->handle(event);
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

bool EventHandler::isWindowEvent(SDL_Event event) const {
    return event.type == SDL_WINDOWEVENT;
}

bool EventHandler::isKeyboardEvent(SDL_Event event) const {
    return (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP);
}

bool EventHandler::isMouseEvent(SDL_Event event) const {
    return (event.type == SDL_MOUSEMOTION ||
        event.type == SDL_MOUSEBUTTONDOWN ||
        event.type == SDL_MOUSEBUTTONUP);
}
