#include "client/objects/gate.h"

Gate::Gate(const Size& size, const Position& initial,
           const WorldViewSettings& settings, const Texture& texture) :
    DrawableBox2D(size, initial, settings), sprite(texture), animation(texture) {
    sprite.addClip(1, 21, 193, 385);
    for (int i = 0; i < 10; ++i) {
        animation.addClip(1 + 194*i, 2051, 193, 385);
    }
    for (int i = 0; i < 9; ++i) {
        animation.addClip(1 + 194*i, 2437, 193, 385);
    }
}

const Texture& Gate::getTexture() {
    if (open_flag) {
        return animation.getTexture();
    } else {
        return sprite.getTexture();
    }
}

SDL_Rect* Gate::getClip() {
    if (open_flag) {
        return animation.getClip();
    } else {
        return sprite.getClip();
    }
}

void Gate::open() {
    open_flag = true;
}
