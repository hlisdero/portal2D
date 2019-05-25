#ifndef BUTTON_H
#define BUTTON_H

#include "client/objects/drawable.h"
#include "client/texture/sprite.h"
#include "client/event/mouse_handler.h"
#include "client/event/mouse_event.h"

class Button : public MouseHandler, public Drawable {
public:
    Button(const Texture& texture, int x, int y);

    virtual const Texture& getTexture() override;
    int getX() const override;
    int getY() const override;
    int getWidth() const override;
    int getHeight() const override;

    virtual SDL_Rect* getClip() override;

    virtual void handle(const MouseEvent& event);

private:
    Sprite sprite;
    int x;
    int y;
};

#endif  // BUTTON_H
