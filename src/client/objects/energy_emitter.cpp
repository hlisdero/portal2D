#include "client/objects/energy_emitter.h"

EnergyEmitter::EnergyEmitter(const Size& size,
        const Position& initial, const double& ratio,
        const Texture& texture, double rotation) :
    Block(size, initial, ratio, texture, rotation) {
    sprite.addClip(198, 1028, 193, 193);
}
