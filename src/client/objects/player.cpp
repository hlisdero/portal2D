#include "client/objects/player.h"

Player::Player(const Position& initial, Ratio& ratio, const TextureCreator& textureCreator) :
    DrawableBox2D(initial, ratio), idle(textureCreator("../data/sprites/character.png")) {
    idle.addClip(1, 2073, 104, 215);
    idle.addClip(106, 2073, 104, 215);
    idle.addClip(211, 2073, 104, 215);
    idle.addClip(316, 2073, 104, 215);
    idle.addClip(421, 2073, 104, 215);
    idle.addClip(526, 2073, 104, 215);
    idle.addClip(631, 2073, 104, 215);
}

Sprite& Player::getSprite() {
    return idle;
}

int Player::getWidth() const {
    return idle.getWidth();
}

int Player::getHeight() const {
    return idle.getHeight();
}

void Player::handle(const KeyboardEvent& event) {
    MoveDirection direction = NONE;
    switch (event.key) {
        case 'w':
            direction = UP;
            break;
        case 'a':
            direction = LEFT;
            break;
        case 'd':
            direction = RIGHT;
            break;
    }

    if (direction != NONE) {
        // world.move(this);
    }
}
