#ifndef ENERGY_RECEIVER_H
#define ENERGY_RECEIVER_H

#include "client/objects/block.h"

class EnergyReceiver : public Block {
public:
    EnergyReceiver(const Size& size, const Position& initial,
                   const WorldViewSettings& settings, const Texture& texture);

    virtual SDL_Rect* getClip() override;
};

#endif  // ENERGY_RECEIVER_H
