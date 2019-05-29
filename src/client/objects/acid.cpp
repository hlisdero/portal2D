#include "client/objects/acid.h"

Acid::Acid(const Size& size, const Position& initial, Ratio& ratio, const Texture& texture) :
    DrawableBox2D(size, initial, ratio), animation(texture) {
    for (int i = 0; i < 8; ++i) {
        animation.addClip(1 + 301*i, 1545, 300, 61);
    }
}

const Texture& Acid::getTexture() {
    return animation.getTexture();
}

SDL_Rect* Acid::getClip() {
    return animation.getClip();
}
