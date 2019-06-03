#ifndef ANIMATED_DRAWABLE_BOX2D_H
#define ANIMATED_DRAWABLE_BOX2D_H

#include "client/objects/drawable_box2D.h"
#include "client/texture/animation.h"

class AnimatedDrawableBox2D : public DrawableBox2D {
public:
    AnimatedDrawableBox2D(const Size& size, const Position& initial,
                          const double& ratio, const Texture& texture, double angle = 0.0);

    virtual const Texture& getTexture() override;
    virtual SDL_Rect* getClip() override;

protected:
    Animation animation;
};

#endif  // ANIMATED_DRAWABLE_BOX2D_H
