#include "client/screen/animation.h"

Animation::Animation(const Texture& texture) : Sprite(texture) {}

SDL_Rect* Animation::getClip() {
    SDL_Rect* clip = Sprite::getClip();
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
