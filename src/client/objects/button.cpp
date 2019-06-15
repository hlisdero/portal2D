#include "client/objects/button.h"

Button::Button(const Size& size, const Position& initial,
                const WorldViewSettings& settings, const Texture& texture) :
    Block(size, initial, settings, texture) {
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

const char * Button::updateState(const State& new_state) {
    DrawableBox2D::updateState(new_state);
    return (getState() == STATE_ENABLED) ? "button_on" : "button_off";
}
