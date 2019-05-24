#include "client/objects/background.h"

Background::Background(size_t width, size_t height, const Texture& texture) :
    width(width), height(height), texture(texture) {
    clip = {0, 0, (int) width, (int) height};
}

const Texture& Background::getTexture() {
    return texture;
}

int Background::getX() const {
    return 0;
}

int Background::getY() const {
    return 0;
}

int Background::getWidth() const {
    return width;
}

int Background::getHeight() const {
    return height;
}

SDL_Rect* Background::getClip() {
    return &clip;
}
