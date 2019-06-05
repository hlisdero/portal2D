#include "common/events/view_event.h"

ViewEvent::ViewEvent(MoveDirection direction, bool pressed, bool repeat) :
    type(KEYBOARD), direction(direction), pressed(pressed), repeat(repeat) {}

ViewEvent::ViewEvent(ClickDirection click_direction) :
    type(MOUSE), click_direction(click_direction) {}
