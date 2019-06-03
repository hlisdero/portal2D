#include "client/objects/energy_ball.h"

EnergyBall::EnergyBall(const Size& size, const Position& initial,
                       const double& ratio, const Texture& texture, double rotation) :
    AnimatedDrawableBox2D(size, initial, ratio, texture, rotation) {
    for (int i = 0; i < 3; ++i) {
        animation.addClip(1 + 112*i, 1920, 111, 59);
    }
}
