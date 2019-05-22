#ifndef PLAYER_H
#define PLAYER_H

#include "client/objects/drawable.h"
#include "client/event/keyboard_handler.h"
#include "client/view/sprite.h"
#include "common/position.h"
#include "common/move_direction.h"

class Player : public Drawable, public KeyboardHandler {
public:
    Player(Sprite sprite, const Position initial);

    virtual Sprite& getSprite() override;
    virtual int getX() const override;
    virtual int getY() const override;
    virtual int getWidth() const override;
    virtual int getHeight() const override;

    virtual void handle(const KeyboardEvent& event) override;

    void updatePosition();

private:
    Sprite sprite;
    Position position;
};

#endif  // PLAYER_H
