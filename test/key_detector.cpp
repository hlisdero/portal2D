#include "key_detector.h"

KeyDetector::KeyDetector(int x, int y, std::vector<Sprite*> sprites) :
    Entity(x, y), sprites(sprites) {}

Sprite& KeyDetector::getSprite() {
    return *sprites[current];
}

int KeyDetector::getWidth() const {
    return sprites[current]->getWidth();
}

int KeyDetector::getHeight() const {
    return sprites[current]->getHeight();
}

void KeyDetector::handle(const KeyboardEvent& event) {
    if (event.pressed) {
        if (event.key == 'w') {
            current = 1;
        } else if (event.key == 'a') {
            current = 2;
        } else if (event.key == 's') {
            current = 3;
        } else if (event.key == 'd') {
            current = 4;
        } else {
            current = 0;
        }
    } else {
        current = 0;
    }
}
