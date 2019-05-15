#include "sprite.h"

Sprite::Sprite(Texture texture) : texture(std::move(texture)) {}

void Sprite::addClip(int x, int y, int w, int h) {
    SDL_Rect clip = {x, y, w, h};
    clips.push_back(clip);
}

SDL_Rect& Sprite::getClip() {
    checkValidClip();
    SDL_Rect& clip = clips[current++];
    if (current >= clips.size()) {
        current = 0;
    }
    return clip;
}

SDL_Texture* Sprite::getTexture() const {
    return texture.get();
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
