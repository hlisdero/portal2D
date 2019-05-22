#include "common/entities/p_entity.h"

PEntity::PEntity(EntityType type, int x, int y, const TextureCreator & textureCreator) : Entity(type, x, y), sprite(textureCreator("../data/sprites/foo.png", Color("cyan"))) {
    sprite.addClip(0, 0, 64, 205);
}

#include <iostream>
Sprite & PEntity::getSprite() {
	return this->sprite;
}