#ifndef PLAYER_H
#define PLAYER_H

#include "client/objects/drawable_box2D.h"
#include "client/event/keyboard_handler.h"
#include "client/view/animation.h"
#include "client/view/texture_creator.h"
#include "common/position.h"
#include "common/ratio.h"
#include "common/move_direction.h"

class Player : public DrawableBox2D, public KeyboardHandler {
public:
    Player(const Position& initial, Ratio& ratio, const Texture& texture);

    virtual const Texture& getTexture() override;
    virtual int getWidth() const override;
    virtual int getHeight() const override;
    virtual SDL_Rect* getClip() override;

    virtual void handle(const KeyboardEvent& event) override;

private:
    Animation idle;
};

#endif  // PLAYER_H
