#ifndef ACID_H
#define ACID_H

#include "client/objects/drawable_box2D.h"
#include "client/texture/animation.h"

class Acid : public DrawableBox2D {
public:
    Acid(const Size& size, const Position& initial, Ratio& ratio, const Texture& texture);

    virtual const Texture& getTexture() override;
    virtual SDL_Rect* getClip() override;

private:
    Animation animation;
};

#endif  // ACID_H
