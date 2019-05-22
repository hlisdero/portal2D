#include "client/view/sprite_manager.h"

SpriteManager::SpriteManager(const TextureCreator& textureCreator) {
	sprites[TYPE_PLAYER] = new Sprite(textureCreator("../data/sprites/character.png", Color("cyan")));

	sprites[TYPE_PLAYER]->addClip(286, 635, 176, 199);

	sprites[TYPE_METAL_BLOCK] = new Sprite(textureCreator("../data/sprites/blocks.png", Color("cyan")));

	sprites[TYPE_METAL_BLOCK]->addClip(0, 600, 194, 194);

	sprites[TYPE_ROCK] = new Sprite(textureCreator("../data/sprites/blocks.png", Color("cyan")));

	sprites[TYPE_ROCK]->addClip(0, 22, 130, 130);
}

Sprite& SpriteManager::getSprite(EntityType type) const {
	return *sprites[type];
}

SpriteManager::~SpriteManager() {
    for (int i = 0; i < sprites.size(); ++i) {
        delete sprites[i];
    }
}
