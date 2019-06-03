#ifndef ENERGY_BALL_H
#define ENERGY_BALL_H

#include "client/objects/animated_drawable_box2D.h"

class EnergyBall : public AnimatedDrawableBox2D {
public:
    EnergyBall(const Size& size, const Position& initial,
               const double& ratio, const Texture& texture, double rotation = 0.0);
};

#endif  // ENERGY_BALL_H
