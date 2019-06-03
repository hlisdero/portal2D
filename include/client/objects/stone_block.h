#ifndef STONE_BLOCK_H
#define STONE_BLOCK_H

#include "client/objects/block.h"

class StoneBlock : public Block {
public:
    StoneBlock(const Size& size, const Position& initial,
               const WorldViewSettings& settings, const Texture& texture);
};

#endif  // STONE_BLOCK_H
