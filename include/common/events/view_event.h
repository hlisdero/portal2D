#ifndef VIEW_EVENT_H
#define VIEW_EVENT_H

#include "common/objects/move_direction.h"
#include "common/objects/click_direction.h"
#include "common/objects/state.h"

enum ViewEventType {
    INVALID = 0,
    QUIT,
    MOVE,
    MOUSE,
    PIN_TOOL,
    RESET_PORTALS,
    GRAB_RELEASE_ROCK
};

class ViewEvent {
public:
    explicit ViewEvent() = default;
    ViewEvent(int player_id, MoveDirection direction, bool pressed, bool repeat);
    ViewEvent(int player_id, const ClickDirection& click_direction, State color);
    ViewEvent(int player_id, const ClickDirection& click_direction);
    ViewEvent(int player_id, ViewEventType type);

    ViewEventType type = INVALID;
    int player_id = -1;
    MoveDirection direction = NONE;
    bool pressed = false;
    bool repeat = false;
    ClickDirection click_direction = {0, 0};
    State state = STATE_DEFAULT;
};

#endif  // VIEW_EVENT_H
