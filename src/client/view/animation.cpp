#include "animation.h"

Animation::Animation(Texture texture) : Sprite(std::move(texture)) {}

SDL_Rect& Animation::getClip() {
    SDL_Rect& clip = Sprite::getClip();
    if (slowdown-- == 0) {
        slowdown = 4;
        next();
    }
    return clip;
}

void Animation::next() {
    if (getClipNumber() == size()-1) {
        setClip(0); // Restart animation
    } else {
        setClip(getClipNumber() + 1);   // Next
    }
}
