#include "client/view/texture_database.h"

SpriteDatabase::SpriteDatabase(const TextureCreator & textureCreator) {
	this->sprites[TYPE_PLAYER] = new Sprite(textureCreator("../data/sprites/character.png", Color("cyan")));

	this->sprites[TYPE_PLAYER]->addClip(286, 635, 176, 199);
	
	this->sprites[TYPE_METAL_BLOCK] = new Sprite(textureCreator("../data/sprites/blocks.png", Color("cyan")));
	
	this->sprites[TYPE_METAL_BLOCK]->addClip(0, 600, 194, 194);
	
	this->sprites[TYPE_ROCK] = new Sprite(textureCreator("../data/sprites/blocks.png", Color("cyan")));
	
	this->sprites[TYPE_ROCK]->addClip(0, 22, 130, 130);
}

Sprite & SpriteDatabase::getSprite(EntityType type) {
	return *sprites[type];
}

// TODO destructor