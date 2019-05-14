#ifndef TEXTURE_CREATOR_H
#define TEXTURE_CREATOR_H

#include <string>
#include <SDL2/SDL_image.h>

#include "texture.h"
#include "renderer.h"

class TextureCreator {
public:
    explicit TextureCreator(const Renderer& renderer);

    Texture operator()(const std::string& path) const;

private:
    const Renderer& renderer;
};

#endif  // TEXTURE_CREATOR_H
