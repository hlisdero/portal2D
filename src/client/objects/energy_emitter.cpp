#include "client/objects/energy_emitter.h"

EnergyEmitter::EnergyEmitter(const Size& size,
        const Position& initial, const WorldViewSettings& settings,
        const Texture& texture) :
    Block(size, initial, settings, texture) {
    sprite.addClip(198, 1028, 193, 193);
}
