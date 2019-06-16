#ifndef PORTAL_H
#define PORTAL_H

#include "common/objects/state.h"
#include "client/objects/block.h"

class Portal : public Block {
public:
    Portal(const Size& size, const Position& initial,
           const WorldViewSettings& settings, const Texture& texture,
           const State& state);
};

#endif  // PORTAL_H
