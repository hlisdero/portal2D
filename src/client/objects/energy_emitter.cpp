#include "client/objects/energy_emitter.h"

EnergyEmitter::EnergyEmitter(const Size& size,
        const Position& initial, const Ratio& ratio,
        const Texture& texture, double rotation) :
    Block(size, initial, ratio, texture) {
    sprite.addClip(198, 1028, 193, 193, rotation);
}
