#include "client/objects/diagonal_metal_block.h"

DiagonalMetalBlock::DiagonalMetalBlock(const Size& size,
        const Position& initial, const double& ratio,
        const Texture& texture, double rotation) :
    Block(size, initial, ratio, texture, rotation) {
    sprite.addClip(198, 600, 193, 193);
}
