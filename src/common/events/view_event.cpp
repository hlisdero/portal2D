#include "common/events/view_event.h"

ViewEvent::ViewEvent(int player_id, MoveDirection direction,
                     bool pressed, bool repeat) :
    type(KEYBOARD), player_id(player_id),
    direction(direction), pressed(pressed), repeat(repeat) {}

ViewEvent::ViewEvent(int player_id, ClickDirection click_direction) :
    type(MOUSE), player_id(player_id), click_direction(click_direction) {}
