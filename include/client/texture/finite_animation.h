#ifndef FINITE_ANIMATION_H
#define FINITE_ANIMATION_H

#include "client/texture/animation.h"

class FiniteAnimation : public Animation {
public:
    explicit FiniteAnimation(const Texture& texture);

    virtual SDL_Rect* getClip() override;

private:
    int slowdown = 4;

    void next();
};

#endif  // FINITE_ANIMATION_H
