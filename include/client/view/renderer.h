#ifndef RENDERER_H
#define RENDERER_H

#include <stdexcept>
#include <string>
#include <cstdint>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "client/view/texture.h"
#include "client/view/surface.h"
#include "client/view/color.h"

class Renderer {
public:
    explicit Renderer(SDL_Window* window);

    Renderer(const Renderer&) = delete;
    Renderer& operator=(const Renderer&) = delete;
    Renderer(Renderer&& other) = delete;
    Renderer& operator=(Renderer&& other) = delete;

    Texture createTextureFromSurface(Surface& surface) const;

    void setDrawColor(const Color& color);
    void setDrawColor(uint8_t red, uint8_t green,
                      uint8_t blue, uint8_t alpha);

    void drawPoint(int width, int height);

    void drawLine(int start_width, int start_height,
                  int end_width, int end_height);

    void drawFillRect(int start_width, int start_height,
                      int end_width, int end_height);

    void drawRect(int start_width, int start_height,
                  int end_width, int end_height);

    void setViewport(int start_width, int start_height,
                     int end_width, int end_height);

    void clear();

    void render(SDL_Texture* texture, const SDL_Rect* srcrect, const SDL_Rect* dstrect,
                double angle = 0.0, SDL_RendererFlip flip = SDL_FLIP_NONE);

    void renderPresent();

    ~Renderer();

private:
    SDL_Renderer* renderer = nullptr;
};

#endif  // RENDERER_H
