#include "server/entities/entity.h"

Entity::Entity(EntityType type, float x, float y, float rotation) :
    type(type), position(x, y), rotation(rotation) {}

const b2Vec2 & Entity::getPosition() const {
    return position;
}

void Entity::setPosition(const b2Vec2 & newPosition) {
    position = newPosition;
}

float Entity::getRotationDeg() const {
    return rotation;
}

float Entity::getRotationRad() const {
    return rotation * PI / 180.0;
}

void Entity::setRotationDeg(float rotation) {
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
