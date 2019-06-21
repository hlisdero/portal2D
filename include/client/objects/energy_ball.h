#ifndef ENERGY_BALL_H
#define ENERGY_BALL_H

#include "client/objects/drawable_box2D.h"
#include "client/texture/animation.h"
#include "client/texture/finite_animation.h"
#include "client/sound/sound_manager.h"

class EnergyBall : public DrawableBox2D {
public:
    EnergyBall(const Size& size, const Position& initial,
               const WorldViewSettings& settings, const Texture& texture,
               SoundManager& sound_manager);

	virtual const Texture& getTexture() override;
	virtual SDL_Rect* getClip() override;

    virtual bool destroyNow() override;
    virtual bool isFinished() override;

    virtual void playDestroySound() override;

private:
    Animation idle;
    FiniteAnimation destruction;
    Animation* current;
    SoundManager& sound_manager;
};

#endif  // ENERGY_BALL_H
