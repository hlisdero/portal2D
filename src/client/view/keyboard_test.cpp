#include "keyboard_test.h"


KeyboardTest::KeyboardTest(int x, int y, std::vector<Sprite*> sprites) :
    Entity(x, y), sprites(sprites) {}

Sprite& KeyboardTest::getSprite() {
    return *sprites[current];
}

int KeyboardTest::getWidth() const {
    return sprites[current]->getWidth();
}

int KeyboardTest::getHeight() const {
    return sprites[current]->getHeight();
}

void KeyboardTest::handle(const KeyboardEvent& event) {
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
