#include "client/objects/energy_bar.h"

EnergyBar::EnergyBar(const Size& size, const Position& initial,
                     const WorldViewSettings& settings, const Texture& texture) :
    AnimatedDrawableBox2D(size, initial, settings, texture) {
    for (int i = 0; i < 4; ++i) {
        animation.addClip(1 + 252*i, 824, 251, 251);
    }
}
