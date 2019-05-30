#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include "client/objects/drawable_box2D.h"
#include "client/texture/animation.h"
#include "client/texture/finite_animation.h"

class Player : public DrawableBox2D {
public:
    Player(const Size& size, const Position& initial, Ratio& ratio, const Texture& texture);

    virtual const Texture& getTexture() override;
    virtual SDL_Rect* getClip() override;
    virtual SDL_RendererFlip getFlipState() const override;

    virtual void updatePosition(const Position& new_position, double angle) override;

private:
    Animation idle;
    Animation run;
    FiniteAnimation jump_rise;
    FiniteAnimation jump_apex;
    FiniteAnimation jump_fall;
    Animation jump_land;
    Animation* current;

    SDL_RendererFlip flip_state = SDL_FLIP_NONE;

    void updateFlipState(const Position& new_position);
    void updateAnimation(const Position& new_position);
    bool isMovingHorizontally(const Position& new_position) const;
    float32 abs(float32 number) const;
};

#endif  // PLAYER_H
