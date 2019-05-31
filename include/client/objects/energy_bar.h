#ifndef ENERGY_BAR_H
#define ENERGY_BAR_H

#include "client/objects/animated_drawable_box2D.h"

class EnergyBar : public AnimatedDrawableBox2D {
public:
    EnergyBar(const Size& size, const Position& initial,
              const Ratio& ratio, const Texture& texture, double rotation);
};

#endif  // ENERGY_BAR_H
