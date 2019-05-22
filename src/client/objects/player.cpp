#include "client/objects/player.h"

Player::Player(Sprite sprite, const Position initial) :
    sprite(std::move(sprite)), position(initial) {}

Sprite& Player::getSprite() {
    return sprite;
}

int Player::getX() const {
    return position.x;
}

int Player::getY() const {
    return position.y;
}

int Player::getWidth() const {
    return sprite.getWidth();
}

int Player::getHeight() const {
    return sprite.getHeight();
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
