#include "button.h"

Button::Button(Sprite sprite, int x, int y) :
    sprite(std::move(sprite)), x(x), y(y) {}

Sprite& Button::getSprite() {
    return sprite;
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

void Button::handle(const MouseEvent& event) {
	bool inside = event.isInside(getX(), getY(), getWidth(), getHeight());
    Sprite& sprite = getSprite();
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
