#ifndef ROCK_H
#define ROCK_H

#include "client/objects/block.h"

class Rock : public Block {
public:
    Rock(const Size& size, const Position& initial,
         const WorldViewSettings& settings, const Texture& texture);
};

#endif  // ROCK_H
