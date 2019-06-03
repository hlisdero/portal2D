#include "client/objects/energy_bar.h"

EnergyBar::EnergyBar(const Size& size, const Position& initial,
                     const double& ratio, const Texture& texture, double rotation) :
    AnimatedDrawableBox2D(size, initial, ratio, texture, rotation) {
    for (int i = 0; i < 4; ++i) {
        animation.addClip(1 + 252*i, 824, 251, 251);
    }
}
