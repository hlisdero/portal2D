#include "client/texture/texture_loader.h"

TextureLoader::TextureLoader(const TextureCreator& textureCreator) :
	textureCreator(textureCreator),
    sprites_dir_prefix(ASSETS_DIRECTORY + std::string("sprites/")) {
    addTexture("Background", "background.png");
    addTexture("Player", "character.png");
    addTexture("Entities", "entities.png");
    addTexture("Miscellaneous", "miscellaneous.png");
    addTexture("FX", "fx.png");
    addTexture("Victory", "victory.png");
    addTexture("Defeat", "defeat.png");
}

void TextureLoader::addTexture(const char * name, const char * file) {
    texture_map.emplace(name, textureCreator(sprites_dir_prefix + file));	
}

const Texture& TextureLoader::operator[](const std::string& key) const {
    return texture_map.at(key);
}
