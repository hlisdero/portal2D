#include "character.h"

Character::Character(int x, int y, Texture& texture) :
    x(x), y(y), animation(texture) {
    animation.addClip(0, 0, 64, 205);
    animation.addClip(64, 0, 64, 205);
    animation.addClip(128, 0, 64, 205);
    animation.addClip(196, 0, 64, 205);
}

Texture& Character::getTexture() {
    return animation.getTexture();
}

int Character::getX() const {
    return x;
}

int Character::getY() const {
    return y;
}

int Character::getWidth() const {
    return animation.getWidth();
}

int Character::getHeight() const {
    return animation.getHeight();
}

SDL_Rect* Character::getClip() {
    return animation.getClip();
}
