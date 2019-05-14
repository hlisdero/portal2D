#include "texture.h"

Texture::Texture(SDL_Texture* texture) :
    texture(texture) {}

Texture::~Texture() {
    if (texture) {
        SDL_DestroyTexture(texture);
    }
}

Texture::Texture(Texture&& other) {
    texture = other.texture;
    other.texture = nullptr;
}

Texture& Texture::operator=(Texture&& other) {
    texture = other.texture;
    other.texture = nullptr;
    return *this;
}

SDL_Texture* Texture::get() const {
    return texture;
}
