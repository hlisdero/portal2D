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
        case SDLK_1:
            key = '1';
            break;
        case SDLK_2:
            key = '2';
            break;
        case SDLK_3:
            key = '3';
            break;
        case SDLK_4:
            key = '4';
            break;
        case SDLK_9:
            key = '9';
            break;
        case SDLK_0:
            key = '0';
            break;
        default:
            key = 0;
            break;
    }
}
