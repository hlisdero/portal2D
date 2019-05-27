#include "common/entities/entity.h"

Entity::Entity(EntityType type, float x, float y, float angle) :
    type(type), x(x), y(y), angle(angle) {}

float Entity::getX() const {
    return this->x;
}

float Entity::getY() const {
    return this->y;
}

void Entity::setX(float x) {
    this->x = x;
}

void Entity::setY(float y) {
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
