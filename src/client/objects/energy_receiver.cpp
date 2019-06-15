#include "client/objects/energy_receiver.h"

EnergyReceiver::EnergyReceiver(const Size& size,
        const Position& initial, const WorldViewSettings& settings,
        const Texture& texture) :
    Block(size, initial, settings, texture) {
    updateState(STATE_DISABLED);
    sprite.addClip(1247, 10, 192, 192);
    sprite.addClip(1037, 10, 192, 192);
}

SDL_Rect* EnergyReceiver::getClip() {
    if (getState() == STATE_ENABLED) {
        sprite.setClip(1);
    } else {
        sprite.setClip(0);
    }
    return sprite.getClip();
}