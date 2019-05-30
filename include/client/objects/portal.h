#ifndef PORTAL_H
#define PORTAL_H

#include "client/objects/block.h"

class Portal : public Block {
public:
    Portal(const Size& size, const Position& initial,
           Ratio& ratio, const Texture& texture, double rotation);
};

#endif  // PORTAL_H
