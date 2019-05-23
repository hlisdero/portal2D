#include "client/objects/block.h"

Block::Block(const Position& initial, Ratio& ratio, const TextureCreator& textureCreator) :
    DrawableBox2D(initial, ratio), sprite(textureCreator("../data/sprites/blocks.png")) {
    sprite.addClip(1, 600, 193, 192);
}

Sprite& Block::getSprite() {
    return sprite;
}

int Block::getWidth() const {
    return sprite.getWidth();
}

int Block::getHeight() const {
    return sprite.getHeight();
}
