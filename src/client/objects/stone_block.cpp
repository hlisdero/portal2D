#include "client/objects/stone_block.h"

StoneBlock::StoneBlock(const Size& size, const Position& initial,
                       const WorldViewSettings& settings, const Texture& texture) :
    Block(size, initial, settings, texture) {
    sprite.addClip(195, 7, 191, 191);
}
