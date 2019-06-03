#include "client/objects/diagonal_metal_block.h"

DiagonalMetalBlock::DiagonalMetalBlock(const Size& size,
        const Position& initial, const WorldViewSettings& settings,
        const Texture& texture, double rotation) :
    Block(size, initial, settings, texture, rotation) {
    sprite.addClip(198, 600, 193, 193);
}
