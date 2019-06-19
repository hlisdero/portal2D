#include "client/texture/texture_loader.h"

TextureLoader::TextureLoader(const TextureCreator& textureCreator) {
    texture_map.emplace("Background", textureCreator("../data/sprites/background.png"));
    texture_map.emplace("Player", textureCreator("../data/sprites/character.png"));
    texture_map.emplace("Entities", textureCreator("../data/sprites/entities.png"));
    texture_map.emplace("Miscellaneous", textureCreator("../data/sprites/miscellaneous.png"));
    texture_map.emplace("FX", textureCreator("../data/sprites/fx.png"));
    texture_map.emplace("Victory", textureCreator("../data/sprites/victory.png"));
    texture_map.emplace("Defeat", textureCreator("../data/sprites/defeat.png"));
}

const Texture& TextureLoader::operator[](const std::string& key) const {
    return texture_map.at(key);
}
