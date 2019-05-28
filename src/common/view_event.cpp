#include "common/view_event.h"

ViewEvent::ViewEvent(MoveDirection direction, bool pressed, bool repeat) :
    direction(direction), pressed(pressed), repeat(repeat) {}
