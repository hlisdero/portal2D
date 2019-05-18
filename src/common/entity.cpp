#include "common/entity.h"

Entity::Entity(EntityType type, float x, float y) : 
	type(type), x(x), y(y) {}

float Entity::getX() {
    return this->x;
}

float Entity::getY() {
    return this->y;
}

void Entity::setX(float x) {
    this->x = x;
}

void Entity::setY(float y) {
	this->y = y;
}

EntityType Entity::getType() {
    return this->type;
}