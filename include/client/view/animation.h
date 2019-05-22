#ifndef ANIMATION_H
#define ANIMATION_H

#include "client/view/sprite.h"

class Animation : public Sprite {
public:
    explicit Animation(Texture texture);

    virtual SDL_Rect& getClip() override;

private:
    int slowdown = 4;

    void next();
};

#endif  // ANIMATION_H
