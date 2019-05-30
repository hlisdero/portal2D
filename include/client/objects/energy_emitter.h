#ifndef ENERGY_EMITTER_H
#define ENERGY_EMITTER_H

#include "client/objects/block.h"

class EnergyEmitter : public Block {
public:
    EnergyEmitter(const Size& size, const Position& initial,
                   Ratio& ratio, const Texture& texture, double rotation);
};

#endif  // ENERGY_EMITTER_H
