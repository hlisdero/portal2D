#include "client/view/texture_database.h"

SpriteDatabase::SpriteDatabase(const TextureCreator & textureCreator) {
	this->sprites[Player] = new Sprite(textureCreator("../data/sprites/character.png", Color("cyan")));

	this->sprites[Player]->addClip(286, 635, 176, 199);
	
	this->sprites[MetalBlock] = new Sprite(textureCreator("../data/sprites/blocks.png", Color("cyan")));
	
	this->sprites[MetalBlock]->addClip(0, 600, 194, 194);
	
	this->sprites[Rock] = new Sprite(textureCreator("../data/sprites/blocks.png", Color("cyan")));
	
	this->sprites[Rock]->addClip(0, 22, 130, 130);
}

Sprite & SpriteDatabase::getSprite(EntityType type) {
	return *sprites[type];
}

// TODO destructor