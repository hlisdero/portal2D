#ifndef SPRITE_H
#define SPRITE_H

#include <stdexcept>
#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include "client/screen/texture.h"

class Sprite {
public:
    explicit Sprite(const Texture& texture);

    void addClip(int x, int y, int w, int h,
        double angle = 0.0, SDL_RendererFlip flip = SDL_FLIP_NONE);
    virtual SDL_Rect* getClip();

    size_t getClipNumber() const;
    size_t size() const;
    void setClip(size_t index);

    double getRotation() const;
    SDL_RendererFlip getFlipState() const;

    const Texture& getTexture() const;
    int getWidth() const;
    int getHeight() const;

private:
    const Texture& texture;
    std::vector<SDL_Rect> clips;
    std::vector<double> rotations;
    std::vector<SDL_RendererFlip> flip_states;
    size_t current = 0;

    void checkValidClip() const;
};

#endif  // SPRITE_H
