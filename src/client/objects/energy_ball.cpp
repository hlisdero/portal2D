#include "client/objects/energy_ball.h"

EnergyBall::EnergyBall(const Size& size, const Position& initial,
                       const WorldViewSettings& settings, const Texture& texture) :
	DrawableBox2D(size, initial, settings),
    idle(texture), destruction(texture), current(&idle) {
    for (int i = 0; i < 3; ++i) {
        idle.addClip(1 + 112*i, 1920, 111, 59);
    }

    for (int i = 0; i < 3; ++i) {
        destruction.addClip(1 + 181*i, 1725, 180, 174);
    }
}

const Texture& EnergyBall::getTexture() {
    return current->getTexture();
}

SDL_Rect* EnergyBall::getClip() {
    return current->getClip();
}

bool EnergyBall::setDestroy() {
    current = &destruction;
    return false;
}

bool EnergyBall::isFinished() {
    return current == &destruction && static_cast<FiniteAnimation*>(current)->finished();
}