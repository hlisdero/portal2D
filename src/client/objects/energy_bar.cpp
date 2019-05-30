#include "client/objects/energy_bar.h"

EnergyBar::EnergyBar(const Size& size, const Position& initial,
                     Ratio& ratio, const Texture& texture, double rotation) :
    AnimatedDrawableBox2D(size, initial, ratio, texture) {
    for (int i = 0; i < 4; ++i) {
        animation.addClip(1 + 252*i, 824, 251, 251, rotation);
    }
}
