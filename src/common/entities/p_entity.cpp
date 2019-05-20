#include "common/entities/p_entity.h"

PEntity::PEntity(EntityType type, int x, int y, const TextureCreator & textureCreator) : Entity(type, x, y), sprite(textureCreator("../test/data/foo.png", Color("cyan"))) {
}

Sprite & PEntity::getSprite() {
	return this->sprite;
}