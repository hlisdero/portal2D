#include "client/event/keyboard_event.h"

KeyboardEvent::KeyboardEvent(const SDL_Event& event) {
    pressed = (event.key.state == SDL_PRESSED);
    repeat = (event.key.repeat != 0);
    key = event.key.keysym.scancode;
}
