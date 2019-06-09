#ifndef TEST_BUTTON_H
#define TEST_BUTTON_H

#include "client/objects/drawable.h"
#include "client/texture/sprite.h"
#include "client/event/mouse_handler.h"
#include "client/event/mouse_event.h"

class TestButton : public MouseHandler, public Drawable {
public:
    TestButton(const Texture& texture, int x, int y);

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

#endif  // TEST_BUTTON_H
