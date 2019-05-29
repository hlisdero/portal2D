#include "client/objects/energy_ball.h"

EnergyBall::EnergyBall(const Size& size, const Position& initial, Ratio& ratio, const Texture& texture) :
    AnimatedDrawableBox2D(size, initial, ratio, texture) {
    for (int i = 0; i < 3; ++i) {
        animation.addClip(1 + 112*i, 1920, 111, 59);
    }
}
