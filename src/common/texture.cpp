#include "texture.h"

Texture::Texture(SDL_Texture* texture, int width, int height) :
    texture(texture), width(width), height(height){}

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

int Texture::getWidth() const {
    return width;
}

int Texture::getHeight() const {
    return height;
}
