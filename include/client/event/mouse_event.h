#ifndef MOUSE_EVENT_H
#define MOUSE_EVENT_H

#include <SDL2/SDL.h>

class MouseEvent {
public:
    MouseEvent(const SDL_Event& event);

    bool isInside(int x, int y, int w, int h) const;

    int x = 0;
    int y = 0;
    bool motion = false;
    bool pressed = false;
};

#endif  // MOUSE_EVENT_H
