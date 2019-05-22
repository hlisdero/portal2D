#include "client2/p_entity.h"

#include <iostream>

PEntity::PEntity(EntityType type, int x, int y, Sprite & sprite) : Entity(type, x, y, 0.0f), sprite(sprite) {}

Sprite & PEntity::getSprite() {
	return this->sprite;
}