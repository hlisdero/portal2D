#ifndef KEYBOARD_EVENT_H
#define KEYBOARD_EVENT_H

#include <SDL2/SDL.h>

class KeyboardEvent {
public:
    KeyboardEvent(const SDL_Event& event);

    uint32_t key = 0;
    bool pressed = false;
    bool repeat = false;
};

#endif  // KEYBOARD_EVENT_H
