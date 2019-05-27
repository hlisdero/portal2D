#include "common/entities/entity.h"

Entity::Entity(EntityType type, float32 x, float32 y, float32 angle) :
    type(type), x(x), y(y), angle(angle) {}

float32 Entity::getX() const {
    return this->x;
}

float32 Entity::getY() const {
    return this->y;
}

void Entity::setX(float32 x) {
    this->x = x;
}

void Entity::setY(float32 y) {
    this->y = y;
}

float Entity::getAngle() const {
    return angle;
}

void Entity::setAngle(float angle) {
    this->angle = angle;
}

EntityType Entity::getType() const {
    return this->type;
}

void Entity::setId(const int id) {
    this->id = id;
}

int Entity::getId() const {
    return this->id;
}
