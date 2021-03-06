#include "client/texture/texture.h"

Texture::Texture(SDL_Texture* texture, size_t width, size_t height) :
    width(width), height(height), texture(texture) {}

Texture::~Texture() {
    if (texture) {
        SDL_DestroyTexture(texture);
    }
}

Texture::Texture(Texture&& other) {
    texture = other.texture;
    width = other.width;
    height = other.height;
    other.texture = nullptr;
    other.width = 0;
    other.height = 0;
}

Texture& Texture::operator=(Texture&& other) {
    texture = other.texture;
    width = other.width;
    height = other.height;
    other.texture = nullptr;
    other.width = 0;
    other.height = 0;
    return *this;
}

SDL_Texture* Texture::get() const {
    return texture;
}
