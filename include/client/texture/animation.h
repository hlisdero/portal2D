#ifndef ANIMATION_H
#define ANIMATION_H

#include "client/texture/sprite.h"

class Animation : public Sprite {
public:
    explicit Animation(const Texture& texture);

    virtual SDL_Rect* getClip() override;

private:
    int slowdown = 7;

    void next();
};

#endif  // ANIMATION_H
