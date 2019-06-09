#include "test_button.h"

TestButton::TestButton(const Texture& texture, int x, int y) :
    sprite(texture), x(x), y(y) {
    sprite.addClip(0, 0, 300, 200);
    sprite.addClip(0, 200, 300, 200);
    sprite.addClip(0, 400, 300, 200);
    sprite.addClip(0, 600, 300, 200);
}

const Texture& TestButton::getTexture() {
    return sprite.getTexture();
}

int TestButton::getX() const {
    return x;
}

int TestButton::getY() const {
    return y;
}

int TestButton::getWidth() const {
    return sprite.getWidth();
}

int TestButton::getHeight() const {
    return sprite.getHeight();
}

SDL_Rect* TestButton::getClip() {
    return sprite.getClip();
}

void TestButton::handle(const MouseEvent& event) {
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
