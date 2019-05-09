#ifndef RENDERER_H
#define RENDERER_H

#include <stdexcept>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "texture.h"
#include "surface.h"

class Renderer {
public:
    explicit Renderer() = default;
    explicit Renderer(SDL_Window* window);

    Renderer(const Renderer&) = delete;
    Renderer& operator=(const Renderer&) = delete;

    Renderer(Renderer&& other);
    Renderer& operator=(Renderer&& other);

    Texture createTextureFromSurface(Surface& surface) const;

    void clear();

    void renderCopy(Texture& Texture);

    void renderPresent();

    ~Renderer();

private:
    SDL_Renderer* renderer = nullptr;
};

#endif  // RENDERER_H
