#include "client/objects/animated_drawable.h"

AnimatedDrawable::AnimatedDrawable(int x, int y, int width, int height, FiniteAnimation animation) :
    x(x), y(y), width(width), height(height), animation(animation) {}

const Texture& AnimatedDrawable::getTexture() {
    return animation.getTexture();
}

int AnimatedDrawable::getX() const {
    return x;
}

int AnimatedDrawable::getY() const {
    return y;
}

int AnimatedDrawable::getWidth() const {
    return width;
}

int AnimatedDrawable::getHeight() const {
    return height;
}

SDL_Rect* AnimatedDrawable::getClip() {
    return animation.getClip();
}

bool AnimatedDrawable::finished() const {
    return animation.finished();
}
