#include "common/entities/p_entity.h"

#include <iostream>

PEntity::PEntity(EntityType type, int x, int y, Sprite & sprite) : Entity(type, x, y), sprite(sprite) {}

Sprite & PEntity::getSprite() {
	return this->sprite;
}