#ifndef DIAGONAL_METAL_BLOCK_H
#define DIAGONAL_METAL_BLOCK_H

#include "client/objects/block.h"

class DiagonalMetalBlock : public Block {
public:
    DiagonalMetalBlock(const Size& size, const Position& initial,
                       const WorldViewSettings& settings, const Texture& texture, double rotation);
};

#endif  // DIAGONAL_METAL_BLOCK_H
