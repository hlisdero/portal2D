#include "client/objects/block.h"

Block::Block(const Size& size, const Position& initial,
             const double& ratio, const Texture& texture, double angle) :
    DrawableBox2D(size, initial, ratio, angle), sprite(texture) {}

const Texture& Block::getTexture() {
    return sprite.getTexture();
}

SDL_Rect* Block::getClip() {
    return sprite.getClip();
}
