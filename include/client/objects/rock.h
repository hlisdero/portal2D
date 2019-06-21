#ifndef ROCK_H
#define ROCK_H

#include "client/objects/drawable_box2D.h"
#include "client/texture/sprite.h"
#include "client/texture/finite_animation.h"
#include "client/sound/sound_manager.h"

class Rock : public DrawableBox2D {
public:
    Rock(const Size& size, const Position& initial,
         const WorldViewSettings& settings, const Texture& texture,
         SoundManager& sound_manager);

	virtual const Texture& getTexture() override;
	virtual SDL_Rect* getClip() override;

    virtual bool setDestroy() override;
    virtual bool isFinished() override;

    virtual void playDestroySound() override;

private:
	Sprite idle;
	FiniteAnimation destruction;
	Sprite * current;
    SoundManager& sound_manager;
};

#endif  // ROCK_H
