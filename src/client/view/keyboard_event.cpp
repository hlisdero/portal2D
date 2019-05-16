#include "keyboard_event.h"

KeyboardEvent::KeyboardEvent(const SDL_Event& event) {
    switch (event.key.keysym.sym) {
        case SDLK_a:
            key = 'a';
            break;
        case SDLK_d:
            key = 'd';
            break;
        case SDLK_q:
            key = 'q';
            break;
        case SDLK_w:
            key = 'w';
            break;
        case SDLK_e:
            key = 'e';
            break;
        default:
            key = 0;
            break;
    }
}
