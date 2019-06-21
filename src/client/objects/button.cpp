#include "client/objects/button.h"

Button::Button(const Size& size, const Position& initial,
               const WorldViewSettings& settings, const Texture& texture,
               SoundManager& sound_manager) :
    Block(size, initial, settings, texture), sound_manager(sound_manager) {
    updateState(STATE_DISABLED);
    sprite.addClip(1, 116, 175, 55);
    sprite.addClip(1, 210, 175, 55);
}

SDL_Rect* Button::getClip() {
    if (getState() == STATE_ENABLED) {
        sprite.setClip(1);
    } else {
        sprite.setClip(0);
    }
    return sprite.getClip();
}

void Button::playSound() {
    if (getState() == STATE_ENABLED) {
        sound_manager.playSoundEffect("button_on");
    } else {
        sound_manager.playSoundEffect("button_off");
    }
}
