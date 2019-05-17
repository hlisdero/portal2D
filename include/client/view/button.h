#ifndef BUTTON_H
#define BUTTON_H

#include "entity.h"
#include "sprite.h"
#include "mouse_handler.h"
#include "mouse_event.h"

class Button : public MouseHandler, public Entity {
public:
    Button(Sprite sprite, int x, int y);

    virtual Sprite& getSprite() override;
    int getWidth() const override;
    int getHeight() const override;

    virtual void handle(const MouseEvent& event);

private:
    Sprite sprite;
};

#endif  // BUTTON_H
