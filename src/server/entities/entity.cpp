#include "server/entities/entity.h"

#include "server/objects/math.h"

Entity::Entity(EntityType type, float x, float y, float rotation) :
    type(type), x(x), y(y), rotation(rotation) {}

float Entity::getX() const {
    return x;
}

float Entity::getY() const {
    return y;
}

void Entity::setX(float x) {
    this->x = x;
}

void Entity::setY(float y) {
    this->y = y;
}

int Entity::getRotationDeg() const {
    return rotation;
}

float Entity::getRotationRad() const {
    return Math::degToRad(rotation);
}

void Entity::setRotationDeg(int rotation) {
    this->rotation = rotation;
}

EntityType Entity::getType() const {
    return type;
}

void Entity::setId(const int id) {
    this->id = id;
}

int Entity::getId() const {
    return id;
}

bool Entity::isDestroyed() {
    return destroyed;
}

void Entity::destroy() {
    destroyed = true;
}
