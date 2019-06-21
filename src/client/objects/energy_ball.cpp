#include "client/objects/energy_ball.h"

EnergyBall::EnergyBall(const Size& size, const Position& initial,
                       const WorldViewSettings& settings, const Texture& texture,
                       SoundManager& sound_manager) :
	DrawableBox2D(size, initial, settings),
    idle(texture), destruction(texture), current(&idle),
    sound_manager(sound_manager) {
    for (int i = 0; i < 3; ++i) {
        idle.addClip(1 + 112*i, 1920, 111, 59);
    }

    for (int i = 0; i < 7; ++i) {
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

void EnergyBall::playDestroySound() {
    sound_manager.playSoundEffect("ball_destruction");
}
