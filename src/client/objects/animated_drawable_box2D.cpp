#include "client/objects/animated_drawable_box2D.h"

AnimatedDrawableBox2D::AnimatedDrawableBox2D(const Size& size, const Position& initial,
                                             const Ratio& ratio, const Texture& texture) :
    DrawableBox2D(size, initial, ratio), animation(texture) {}

const Texture& AnimatedDrawableBox2D::getTexture() {
    return animation.getTexture();
}

SDL_Rect* AnimatedDrawableBox2D::getClip() {
    return animation.getClip();
}
