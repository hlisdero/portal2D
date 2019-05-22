#ifndef KEYBOARD_HANDLER_H
#define KEYBOARD_HANDLER_H

#include "client/event/keyboard_event.h"

class KeyboardHandler {
public:
    virtual void handle(const KeyboardEvent& event) = 0;

    virtual ~KeyboardHandler() = default;
};

#endif  // KEYBOARD_HANDLER_H
