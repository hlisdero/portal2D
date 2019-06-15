#include "client/objects/energy_emitter.h"

EnergyEmitter::EnergyEmitter(const Size& size,
        const Position& initial, const WorldViewSettings& settings,
        const Texture& texture) :
    Block(size, initial, settings, texture) {
    sprite.addClip(831, 10, 192, 192);
}
