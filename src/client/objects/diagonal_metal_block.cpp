#include "client/objects/diagonal_metal_block.h"

DiagonalMetalBlock::DiagonalMetalBlock(const Size& size,
        const Position& initial, Ratio& ratio,
        const Texture& texture, double rotation) :
    Block(size, initial, ratio, texture) {
    sprite.addClip(198, 600, 193, 193, rotation);
}
