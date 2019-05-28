#ifndef VIEW_EVENT_H
#define VIEW_EVENT_H

#include "common/move_direction.h"

class ViewEvent {
public:
    explicit ViewEvent() = default;
    ViewEvent(MoveDirection direction, bool pressed, bool repeat);

    MoveDirection direction = NONE;
    bool pressed = false;
    bool repeat = false;
};

#endif  // VIEW_EVENT_H
