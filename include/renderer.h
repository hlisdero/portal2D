#ifndef RENDERER_H
#define RENDERER_H

#include <stdexcept>
#include <string>
#include <cstdint>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "texture.h"
#include "surface.h"

class Renderer {
public:
    explicit Renderer(SDL_Window* window);

    Renderer(const Renderer&) = delete;
    Renderer& operator=(const Renderer&) = delete;
    Renderer(Renderer&& other) = delete;
    Renderer& operator=(Renderer&& other) = delete;

    Texture createTextureFromSurface(Surface& surface) const;

    void setRenderDrawColor(uint8_t red, uint8_t green,
                            uint8_t blue, uint8_t alpha);

    void clear();

    void renderCopy(Texture& Texture);

    void renderPresent();

    ~Renderer();

private:
    SDL_Renderer* renderer = nullptr;
};

#endif  // RENDERER_H
