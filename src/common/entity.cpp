#include "common/entity.h"

Entity::Entity(EntityType type, float32 x, float32 y, float32 angle) :
    type(type), x(x), y(y), angle(angle) {}

float32 Entity::getX() const {
    return x;
}

float32 Entity::getY() const {
    return y;
}

float Entity::getAngle() const {
    return angle;
}

void Entity::setX(float32 x) {
    this->x = x;
}
void Entity::setY(float32 y) {
    this->y = y;
}

EntityType Entity::getType() const {
    return type;
}

void Entity::setAngle(float angle) {
    this->angle = angle;
}
