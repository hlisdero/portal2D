#ifndef ENERGY_RECEIVER_H
#define ENERGY_RECEIVER_H

#include "client/objects/block.h"

class EnergyReceiver : public Block {
public:
    EnergyReceiver(const Size& size, const Position& initial,
                   const Ratio& ratio, const Texture& texture, double rotation);
};

#endif  // ENERGY_RECEIVER_H
