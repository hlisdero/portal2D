#ifndef PLAYER_H
#define PLAYER_H

#include "client/objects/drawable_box2D.h"
#include "client/texture/animation.h"
#include "client/texture/finite_animation.h"

class Player : public DrawableBox2D {
public:
    Player(const Size& size, const Position& initial, const WorldViewSettings& settings, const Texture& texture);

    virtual const Texture& getTexture() override;
    virtual SDL_Rect* getClip() override;
    virtual SDL_RendererFlip getFlipState() const override;

    virtual const char * updatePosition(const Position& new_position) override;

    void startDeathAnimation();
    bool finishedDeathAnimation() const;

private:
    Animation idle;
    Animation run;
    FiniteAnimation jump_rise;
    FiniteAnimation jump_apex;
    FiniteAnimation jump_fall;
    Animation jump_land;
    FiniteAnimation death;
    Animation* current;

    SDL_RendererFlip flip_state = SDL_FLIP_NONE;

    void updateFlipState(const Position& new_position);
    const char * updateAnimation(const Position& new_position);
    bool isMovingHorizontally(const Position& new_position) const;
};

#endif  // PLAYER_H
