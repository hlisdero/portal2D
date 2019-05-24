#ifndef MOUSE_HANDLER_H
#define MOUSE_HANDLER_H

#include "client/event/mouse_event.h"

class MouseHandler {
public:
    virtual void handle(const MouseEvent& event) = 0;

    virtual ~MouseHandler() = default;
};

#endif  // MOUSE_HANDLER_H
