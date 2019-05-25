#ifndef VIEW_EVENT_H
#define VIEW_EVENT_H

#include "common/move_direction.h"

class ViewEvent {
public:
    explicit ViewEvent() = default;
    explicit ViewEvent(MoveDirection direction);

    MoveDirection direction = NONE;
};

#endif  // VIEW_EVENT_H
