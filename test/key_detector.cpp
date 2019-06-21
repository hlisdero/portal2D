#include "key_detector.h"

KeyDetector::KeyDetector(int x, int y, std::vector<Sprite*> sprites) :
    x(x), y(y), sprites(sprites) {}

const Texture& KeyDetector::getTexture() {
    return sprites[current]->getTexture();
}

int KeyDetector::getX() const {
    return x;
}

int KeyDetector::getY() const {
    return y;
}

int KeyDetector::getWidth() const {
    return sprites[current]->getWidth();
}

int KeyDetector::getHeight() const {
    return sprites[current]->getHeight();
}

void KeyDetector::handle(const KeyboardEvent& event) {
    if (event.pressed) {
        if (event.key == SDL_SCANCODE_W) {
            current = 1;
        } else if (event.key == SDL_SCANCODE_A) {
            current = 2;
        } else if (event.key == SDL_SCANCODE_S) {
            current = 3;
        } else if (event.key == SDL_SCANCODE_D) {
            current = 4;
        } else {
            current = 0;
        }
    } else {
        current = 0;
    }
}
