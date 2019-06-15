#include "client/event/mouse_event.h"

MouseEvent::MouseEvent(const SDL_Event& event) {
    SDL_GetMouseState(&x, &y);
    switch (event.type) {
        case SDL_MOUSEMOTION:
            motion = true;
            pressed = false;
            break;
        case SDL_MOUSEBUTTONDOWN:
            motion = false;
            pressed = true;
            button = event.button.button;
            break;
        case SDL_MOUSEBUTTONUP:
            motion = false;
            pressed = false;
            break;
    }
}

bool MouseEvent::isInside(int x, int y, int w, int h) const {
    if (this->x < x || this->x > x + w) {
        return false;
    } else if (this->y < y || this->y > y + h) {
        return false;
    } else {
        return true;
    }
}
