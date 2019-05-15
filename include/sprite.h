#ifndef SPRITE_H
#define SPRITE_H

#include <stdexcept>
#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include "texture.h"

class Sprite {
public:
    explicit Sprite(Texture texture);

    Sprite(const Sprite&) = delete;
    Sprite& operator=(const Sprite&) = delete;
    Sprite(Sprite&& other) = delete;
    Sprite& operator=(Sprite&& other) = delete;

    ~Sprite() = default;

    void addClip(int x, int y, int w, int h);
    SDL_Rect& getClip();

    SDL_Texture* getTexture() const;
    int getWidth() const;
    int getHeight() const;

private:
    Texture texture;
    std::vector<SDL_Rect> clips;
    size_t current = 0;

    void checkValidClip() const;
};

#endif  // SPRITE_H
