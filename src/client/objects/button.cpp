#include "client/objects/button.h"

Button::Button(const Size& size, const Position& initial,
                const WorldViewSettings& settings, const Texture& texture) :
    Block(size, initial, settings, texture) {
    sprite.addClip(1, 116, 175, 55);
    sprite.addClip(1, 210, 175, 55);
}

void Button::toggleState() {
    if (sprite.getClipNumber() == 0) {
        sprite.setClip(1);
    } else {
        sprite.setClip(0);
    }
}
