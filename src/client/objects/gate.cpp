#include "client/objects/gate.h"

Gate::Gate(const Size& size, const Position& initial,
           const WorldViewSettings& settings, const Texture& texture,
           SoundManager& sound_manager) :
    DrawableBox2D(size, initial, settings), sprite(texture), animation(texture),
    sound_manager(sound_manager) {
    updateState(STATE_CLOSED);
    sprite.addClip(2, 216, 192, 384);
    for (int i = 0; i < 10; ++i) {
        animation.addClip(2 + 194*i, 216, 192, 384);
    }
    for (int i = 0; i < 9; ++i) {
        animation.addClip(2 + 194*i, 602, 192, 384);
    }
}

const Texture& Gate::getTexture() {
    if (getState() == STATE_OPEN) {
        return animation.getTexture();
    } else {
        return sprite.getTexture();
    }
}

SDL_Rect* Gate::getClip() {
    if (getState() == STATE_OPEN) {
        return animation.getClip();
    } else {
        animation.reset();
        return sprite.getClip();
    }
}

void Gate::updateState(const State& new_state) {
    DrawableBox2D::updateState(new_state);
}

void Gate::playSound() {
    sound_manager.playSoundEffect("gate");
}
