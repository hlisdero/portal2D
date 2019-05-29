#include "client/objects/block.h"

Block::Block(const Size& size, const Position& initial, Ratio& ratio, const Texture& texture) :
    DrawableBox2D(size, initial, ratio), sprite(texture) {}

const Texture& Block::getTexture() {
    return sprite.getTexture();
}

SDL_Rect* Block::getClip() {
    return sprite.getClip();
}
