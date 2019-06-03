#include "client/objects/energy_receiver.h"

EnergyReceiver::EnergyReceiver(const Size& size,
        const Position& initial, const WorldViewSettings& settings,
        const Texture& texture) :
    Block(size, initial, settings, texture) {
    sprite.addClip(1, 1028, 193, 193);
}
