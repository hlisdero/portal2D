#include "common/entities/entity.h"

Entity::Entity(EntityType type, float x, float y, float rotation) :
    type(type), x(x), y(y), rotation(rotation) {}

Entity::Entity(EntityType type, YAML::Node yaml) :
    type(type), 
    x(yaml["x"].as<float>()), 
    y(yaml["y"].as<float>()), 
    rotation(yaml["rotation"].as<float>()) {}

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

float Entity::getRotationDeg() const {
    return this->rotation;
}

float Entity::getRotationRad() const {
    return this->rotation * PI / 180.0;
}

void Entity::setRotationDeg(float rotation) {
    this->rotation = rotation;
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
