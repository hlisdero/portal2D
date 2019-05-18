#include "common/entity.h"

Entity::Entity(EntityType type, float x, float y) : 
	type(type), x(x), y(y) {}

float Entity::getX() const {
    return this->x;
}

float Entity::getY() const {
    return this->y;
}

EntityType Entity::getType() const {
    return this->type;
}

void Entity::setX(const float x) {
    this->x = x;
}

void Entity::setY(const float y) {
	this->y = y;
}