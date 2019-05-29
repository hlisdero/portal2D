#include "client/objects/energy_receiver.h"

EnergyReceiver::EnergyReceiver(const Size& size, const Position& initial, Ratio& ratio, const Texture& texture, double rotation) :
    Block(size, initial, ratio, texture) {
    sprite.addClip(1, 814, 193, 193, rotation);
}
