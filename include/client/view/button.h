#ifndef BUTTON_H
#define BUTTON_H

#include "entity.h"
#include "sprite.h"
#include "mouse_handler.h"
#include "mouse_event.h"

class Button : public MouseHandler, public Entity {
public:
    Button(Sprite sprite, int x, int y);

    void handle(const MouseEvent& event);
};

#endif  // BUTTON_H
