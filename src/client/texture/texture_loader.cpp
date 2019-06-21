#include "client/texture/texture_loader.h"

TextureLoader::TextureLoader(const TextureCreator& textureCreator) :
    asset_dir_prefix(CLIENT_SETTINGS.ASSET_DIR_PREFIX) {
    texture_map.emplace("Background", textureCreator(asset_dir_prefix + "sprites/background.png"));
    texture_map.emplace("Player", textureCreator(asset_dir_prefix + "sprites/character.png"));
    texture_map.emplace("Entities", textureCreator(asset_dir_prefix + "sprites/entities.png"));
    texture_map.emplace("Miscellaneous", textureCreator(asset_dir_prefix + "sprites/miscellaneous.png"));
    texture_map.emplace("FX", textureCreator(asset_dir_prefix + "sprites/fx.png"));
    texture_map.emplace("Victory", textureCreator(asset_dir_prefix + "sprites/victory.png"));
    texture_map.emplace("Defeat", textureCreator(asset_dir_prefix + "sprites/defeat.png"));
}

const Texture& TextureLoader::operator[](const std::string& key) const {
    return texture_map.at(key);
}
