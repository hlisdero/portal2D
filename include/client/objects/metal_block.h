#ifndef METAL_BLOCK_H
#define METAL_BLOCK_H

#include "client/objects/block.h"

class MetalBlock : public Block {
public:
    MetalBlock(const Size& size, const Position& initial, const Ratio& ratio, const Texture& texture);
};

#endif  // METAL_BLOCK_H
