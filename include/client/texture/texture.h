#ifndef TEXTURE_H
#define TEXTURE_H

#include <stdexcept>
#include <string>
#include <SDL2/SDL.h>

class Texture {
public:
    explicit Texture(SDL_Texture* texture, size_t width, size_t height);

    Texture(const Texture&) = delete;
    Texture& operator=(const Texture&) = delete;

    Texture(Texture&& other);
    Texture& operator=(Texture&& other);

    ~Texture();

    SDL_Texture* get() const;

    size_t width;
    size_t height;

private:
    SDL_Texture* texture = nullptr;
};

#endif  // TEXTURE_H
