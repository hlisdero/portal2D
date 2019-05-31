#ifndef ROCK_H
#define ROCK_H

#include "client/objects/block.h"

class Rock : public Block {
public:
    Rock(const Size& size, const Position& initial,
         const Ratio& ratio, const Texture& texture, double rotation);
};

#endif  // ROCK_H
