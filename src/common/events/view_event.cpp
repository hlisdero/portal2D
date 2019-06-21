#include "common/events/view_event.h"

ViewEvent::ViewEvent(int player_id, MoveDirection direction,
                     bool pressed, bool repeat) :
    type(MOVE), player_id(player_id),
    direction(direction), pressed(pressed), repeat(repeat) {}

ViewEvent::ViewEvent(int player_id,
                     const ClickDirection& click_direction,
                     State color) :
    type(MOUSE), player_id(player_id),
    click_direction(click_direction), state(color) {}

ViewEvent::ViewEvent(int player_id, const ClickDirection& click_direction) :
    type(PIN_TOOL), player_id(player_id),
    click_direction(click_direction) {}

ViewEvent::ViewEvent(int player_id, ViewEventType type) :
	type(type), player_id(player_id) {}
