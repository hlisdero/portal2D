#include "client/objects/animated_drawable_box2D.h"

AnimatedDrawableBox2D::AnimatedDrawableBox2D(const Size& size, const Position& initial,
                                             const WorldViewSettings& settings, const Texture& texture, double angle) :
    DrawableBox2D(size, initial, settings, angle), animation(texture) {}

const Texture& AnimatedDrawableBox2D::getTexture() {
    return animation.getTexture();
}

SDL_Rect* AnimatedDrawableBox2D::getClip() {
    return animation.getClip();
}
