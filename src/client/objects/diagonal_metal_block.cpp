#include "client/objects/diagonal_metal_block.h"

DiagonalMetalBlock::DiagonalMetalBlock(const Size& size,
        const Position& initial, const WorldViewSettings& settings,
        const Texture& texture) :
    Block(size, initial, settings, texture) {
    sprite.addClip(611, 11, 191, 191);
}
