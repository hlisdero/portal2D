#ifndef TEXTURE_CREATOR_H
#define TEXTURE_CREATOR_H

#include <string>
#include <SDL2/SDL_image.h>

#include "client/texture/texture.h"
#include "client/screen/renderer.h"
#include "client/texture/color.h"

class TextureCreator {
public:
    explicit TextureCreator(const Renderer& renderer);

    Texture operator()(const std::string& path) const;

    Texture operator()(const std::string& path, const Color& color_key) const;

private:
    const Renderer& renderer;
};

#endif  // TEXTURE_CREATOR_H
