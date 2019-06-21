#ifndef PLAYER_H
#define PLAYER_H

#include "client/objects/drawable_box2D.h"
#include "client/texture/animation.h"
#include "client/texture/finite_animation.h"
#include "client/sound/sound_manager.h"

class Player : public DrawableBox2D {
public:
    Player(const Size& size, const Position& initial,
           const WorldViewSettings& settings, const Texture& texture,
           SoundManager& sound_manager);

    virtual const Texture& getTexture() override;
    virtual SDL_Rect* getClip() override;
    virtual SDL_RendererFlip getFlipState() const override;

    virtual void updatePosition(const Position& new_position) override;

    virtual bool destroyNow() override;
    virtual bool isFinished() override;

    virtual void playSound() override;
    virtual void playDestroySound() override;

private:
    Animation idle;
    Animation run;
    FiniteAnimation jump_rise;
    FiniteAnimation jump_apex;
    FiniteAnimation jump_fall;
    Animation jump_land;
    FiniteAnimation death;
    Animation* current;
    SoundManager& sound_manager;

    SDL_RendererFlip flip_state = SDL_FLIP_NONE;

    void updateFlipState(const Position& new_position);
    void updateAnimation(const Position& new_position);
    bool isMovingHorizontally(const Position& new_position) const;
};

#endif  // PLAYER_H
