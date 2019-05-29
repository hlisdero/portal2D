#include "client/objects/stone_block.h"

StoneBlock::StoneBlock(const Size& size, const Position& initial, Ratio& ratio, const Texture& texture) :
    Block(size, initial, ratio, texture) {
    sprite.addClip(1, 172, 193, 193);
}