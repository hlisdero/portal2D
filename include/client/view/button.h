#ifndef BUTTON_H
#define BUTTON_H

#include "sprite.h"
#include "mouse_handler.h"
#include "mouse_event.h"

class Button : public MouseHandler {
public:
    Button(Sprite sprite, int x, int y);

    void handle(const MouseEvent& event);

    Sprite& get();
    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;

private:
    Sprite sprite;
    const int x = 0;
    const int y = 0;
};

#endif  // BUTTON_H
