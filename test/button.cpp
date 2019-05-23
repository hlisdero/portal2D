#include "button.h"

Button::Button(Texture& texture, int x, int y) :
    sprite(texture), x(x), y(y) {
    sprite.addClip(0, 0, 300, 200);
    sprite.addClip(0, 200, 300, 200);
    sprite.addClip(0, 400, 300, 200);
    sprite.addClip(0, 600, 300, 200);
}

Texture& Button::getTexture() {
    return sprite.getTexture();
}

int Button::getX() const {
    return x;
}

int Button::getY() const {
    return y;
}

int Button::getWidth() const {
    return sprite.getWidth();
}

int Button::getHeight() const {
    return sprite.getHeight();
}

SDL_Rect* Button::getClip() {
    return sprite.getClip();
}

void Button::handle(const MouseEvent& event) {
	bool inside = event.isInside(getX(), getY(), getWidth(), getHeight());
	if (!inside) {
        sprite.setClip(0);
        return;
	}
    if (event.motion) {
        sprite.setClip(1);
    } else if (event.pressed) {
        sprite.setClip(2);
    } else {
        sprite.setClip(3);
    }
}
