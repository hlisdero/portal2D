#include "entity.h"

Entity::Entity(int x, int y) : x(x), y(y) {}

int Entity::getX() const {
    return x;
}

int Entity::getY() const {
    return y;
}

void Entity::setX(int new_x) {
    x = new_x;
}

void Entity::setY(int new_y) {
    y = new_y;
}
