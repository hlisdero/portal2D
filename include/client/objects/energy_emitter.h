#ifndef ENERGY_EMITTER_H
#define ENERGY_EMITTER_H

#include "client/objects/block.h"

class EnergyEmitter : public Block {
public:
    EnergyEmitter(const Size& size, const Position& initial,
                  const WorldViewSettings& settings, const Texture& texture);
};

#endif  // ENERGY_EMITTER_H
