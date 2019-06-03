#include "client/objects/block.h"

Block::Block(const Size& size, const Position& initial,
             const WorldViewSettings& settings, const Texture& texture) :
    DrawableBox2D(size, initial, settings), sprite(texture) {}

const Texture& Block::getTexture() {
    return sprite.getTexture();
}

SDL_Rect* Block::getClip() {
    return sprite.getClip();
}
