#include "client/view/sprite.h"

Sprite::Sprite(Texture& texture) : texture(texture), current(0) {}

void Sprite::addClip(int x, int y, int w, int h,
    double angle, SDL_RendererFlip flip) {
    SDL_Rect clip = {x, y, w, h};
    clips.push_back(clip);
    rotations.push_back(angle);
    flip_states.push_back(flip);
}

SDL_Rect* Sprite::getClip() {
    checkValidClip();
    return &clips[current];
}

size_t Sprite::getClipNumber() const {
    return current;
}

size_t Sprite::size() const {
    return clips.size();
}

void Sprite::setClip(size_t index) {
    if (index >= clips.size()) {
        throw std::runtime_error("Error: Número de clip inválido");
    }
    current = index;
}

double Sprite::getRotation() const {
    checkValidClip();
    return rotations[current];
}

SDL_RendererFlip Sprite::getFlipState() const {
    checkValidClip();
    return flip_states[current];
}

Texture& Sprite::getTexture() const {
    return texture;
}

int Sprite::getWidth() const {
    checkValidClip();
    return clips[current].w;
}

int Sprite::getHeight() const {
    checkValidClip();
    return clips[current].h;
}

void Sprite::checkValidClip() const {
    if (clips.empty()) {
        throw std::runtime_error("Error: Sprite sin clips");
    }
}
