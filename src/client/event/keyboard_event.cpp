#include "keyboard_event.h"

KeyboardEvent::KeyboardEvent(const SDL_Event& event) {
    pressed = (event.key.state == SDL_PRESSED);
    repeat = (event.key.repeat != 0);
    switch (event.key.keysym.sym) {
        case SDLK_w:
            key = 'w';
            break;
        case SDLK_a:
            key = 'a';
            break;
        case SDLK_s:
            key = 's';
            break;
        case SDLK_d:
            key = 'd';
            break;
        default:
            key = 0;
            break;
    }
}
