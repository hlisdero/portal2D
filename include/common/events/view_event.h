#ifndef VIEW_EVENT_H
#define VIEW_EVENT_H

#include "common/objects/move_direction.h"
#include "common/objects/click_direction.h"
#include "common/objects/click_button.h"

enum ViewEventType {
    INVALID = 0,
    QUIT = 1,
    KEYBOARD = 2,
    MOUSE = 3,
};

class ViewEvent {
public:
    explicit ViewEvent() = default;
    ViewEvent(int player_id, MoveDirection direction, bool pressed, bool repeat);
    ViewEvent(int player_id, ClickDirection click_direction, ClickButton button);

    ViewEventType type = INVALID;
    int player_id = -1;
    MoveDirection direction = NONE;
    bool pressed = false;
    bool repeat = false;
    ClickDirection click_direction = {0, 0};
    ClickButton button = BUTTON_INVALID;
};

#endif  // VIEW_EVENT_H
