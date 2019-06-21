#include "client/texture/finite_animation.h"

FiniteAnimation::FiniteAnimation(const Texture& texture) : Animation(texture) {}

SDL_Rect* FiniteAnimation::getClip() {
    SDL_Rect* clip = Sprite::getClip();
    if (slowdown-- == 0) {
        slowdown = 7;
        next();
    }
    return clip;
}

void FiniteAnimation::next() {
    if(getClipNumber() < size() - 1) {
        setClip(getClipNumber() + 1);   // Next
    }
    // Else : Keep last clip
}

void FiniteAnimation::reset() {
    setClip(0);
}

bool FiniteAnimation::finished() const {
    return (getClipNumber() == (size()-1));
}
