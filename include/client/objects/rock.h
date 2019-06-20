#ifndef ROCK_H
#define ROCK_H

#include "client/objects/drawable_box2D.h"
#include "client/texture/sprite.h"
#include "client/texture/finite_animation.h"

class Rock : public DrawableBox2D {
public:
    Rock(const Size& size, const Position& initial,
         const WorldViewSettings& settings, const Texture& texture);

	virtual const Texture& getTexture() override;
	virtual SDL_Rect* getClip() override;

    virtual bool setDestroy() override;
    virtual bool isFinished() override;

private:
	Sprite idle;
	FiniteAnimation destruction;
	Sprite * current;
};

#endif  // ROCK_H
