#include "entity.h"

Entity::Entity(Sprite sprite, int x, int y) :
    sprite(std::move(sprite)), x(x), y(y) {}

Sprite& Entity::getSprite() {
    return sprite;
}

int Entity::getX() const {
    return x;
}

int Entity::getY() const {
    return y;
}

int Entity::getWidth() const {
    return sprite.getWidth();
}

int Entity::getHeight() const {
    return sprite.getHeight();
}
