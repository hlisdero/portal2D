#ifndef ENERGY_EMITTER_H
#define ENERGY_EMITTER_H

#include "client/objects/block.h"

class EnergyEmitter : public Block {
public:
    EnergyEmitter(const Size& size, const Position& initial,
                  const double& ratio, const Texture& texture, double rotation);
};

#endif  // ENERGY_EMITTER_H
