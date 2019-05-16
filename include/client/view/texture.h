#ifndef TEXTURE_H
#define TEXTURE_H

#include <stdexcept>
#include <string>
#include <SDL2/SDL.h>

class Texture {
public:
    explicit Texture(SDL_Texture* texture, int width, int height);

    Texture(const Texture&) = delete;
    Texture& operator=(const Texture&) = delete;

    Texture(Texture&& other);
    Texture& operator=(Texture&& other);

    ~Texture();

    SDL_Texture* get() const;
    int getWidth() const;
    int getHeight() const;
    double getRotation() const;
    SDL_RendererFlip getFlipState() const;

    void rotate(double degrees);
    void flip(SDL_RendererFlip new_flip_state);

private:
    SDL_Texture* texture = nullptr;
    int width;
    int height;
    double rotation = 0.0;
    SDL_RendererFlip flip_state = SDL_FLIP_NONE;
};

#endif  // TEXTURE_H
