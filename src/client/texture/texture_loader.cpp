#include "client/texture/texture_loader.h"

TextureLoader::TextureLoader(const TextureCreator& textureCreator) {
    texture_map.emplace("Background", textureCreator("/var/portal2d/sprites/background.png"));
    texture_map.emplace("Player", textureCreator("/var/portal2d/sprites/character.png"));
    texture_map.emplace("Entities", textureCreator("/var/portal2d/sprites/entities.png"));
    texture_map.emplace("Miscellaneous", textureCreator("/var/portal2d/sprites/miscellaneous.png"));
    texture_map.emplace("FX", textureCreator("/var/portal2d/sprites/fx.png"));
}

const Texture& TextureLoader::operator[](const std::string& key) const {
    return texture_map.at(key);
}
