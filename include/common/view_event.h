#ifndef VIEW_EVENT_H
#define VIEW_EVENT_H

#include "common/move_direction.h"
#include "common/click_direction.h"

enum EventType {
    INVALID = 0,
    KEYBOARD,
    MOUSE,
};

class ViewEvent {
public:
    explicit ViewEvent() = default;
    ViewEvent(MoveDirection direction, bool pressed, bool repeat);
    ViewEvent(ClickDirection click_direction);

    EventType type = INVALID;
    MoveDirection direction = NONE;
    bool pressed = false;
    bool repeat = false;
    ClickDirection click_direction = {0, 0};
};

#endif  // VIEW_EVENT_H
