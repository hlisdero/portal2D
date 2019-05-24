#ifndef TEXTURE_LOADER_H
#define TEXTURE_LOADER_H

#include <unordered_map>
#include <string>
#include "client/screen/texture_creator.h"
#include "client/screen/texture.h"

class TextureLoader {
public:
    explicit TextureLoader(const TextureCreator& textureCreator);

    TextureLoader(const TextureLoader&) = delete;
    TextureLoader& operator=(const TextureLoader&) = delete;
    TextureLoader(TextureLoader&& other) = delete;
    TextureLoader& operator=(TextureLoader&& other) = delete;

    const Texture& operator[](const std::string& key) const;

private:
    std::unordered_map<std::string, Texture> texture_map;
};

#endif  // TEXTURE_LOADER_H
