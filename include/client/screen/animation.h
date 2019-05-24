#ifndef ANIMATION_H
#define ANIMATION_H

#include "client/screen/sprite.h"

class Animation : public Sprite {
public:
    explicit Animation(const Texture& texture);

    virtual SDL_Rect* getClip() override;

private:
    int slowdown = 4;

    void next();
};

#endif  // ANIMATION_H
