#ifndef PORTAL_H
#define PORTAL_H

#include "client/objects/block.h"

class Portal : public Block {
public:
    Portal(const Size& size, const Position& initial,
           const WorldViewSettings& settings, const Texture& texture);
};

#endif  // PORTAL_H
