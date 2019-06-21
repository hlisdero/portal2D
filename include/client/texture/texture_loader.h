#ifndef TEXTURE_LOADER_H
#define TEXTURE_LOADER_H

#include <unordered_map>
#include <string>
#include "client/client_settings.h"
#include "client/texture/texture_creator.h"
#include "client/texture/texture.h"

extern ClientSettings CLIENT_SETTINGS;

class TextureLoader {
public:
    explicit TextureLoader(const TextureCreator& textureCreator);

    TextureLoader(const TextureLoader&) = delete;
    TextureLoader& operator=(const TextureLoader&) = delete;
    TextureLoader(TextureLoader&& other) = delete;
    TextureLoader& operator=(TextureLoader&& other) = delete;

    const Texture& operator[](const std::string& key) const;

private:
    const std::string asset_dir_prefix;
    std::unordered_map<std::string, Texture> texture_map;
};

#endif  // TEXTURE_LOADER_H
