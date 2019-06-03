#ifndef ENERGY_BAR_H
#define ENERGY_BAR_H

#include "client/objects/animated_drawable_box2D.h"

class EnergyBar : public AnimatedDrawableBox2D {
public:
    EnergyBar(const Size& size, const Position& initial,
              const WorldViewSettings& settings, const Texture& texture);
};

#endif  // ENERGY_BAR_H
