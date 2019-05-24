#include "client/objects/block.h"

Block::Block(const Position& initial, Ratio& ratio, Texture& texture) :
    DrawableBox2D(initial, ratio), sprite(texture) {
    sprite.addClip(1, 600, 193, 192);
}

Texture& Block::getTexture() {
    return sprite.getTexture();
}

int Block::getWidth() const {
    return sprite.getWidth();
}

int Block::getHeight() const {
    return sprite.getHeight();
}

SDL_Rect* Block::getClip() {
    return sprite.getClip();
}
