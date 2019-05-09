#ifndef WINDOW_H
#define WINDOW_H

#include <stdexcept>
#include <string>
#include <SDL2/SDL.h>

#include "renderer.h"
#include "texture_creator.h"

class Window {
public:
    explicit Window(size_t width = DEFAULT_SCREEN_WIDTH,
                    size_t height = DEFAULT_SCREEN_HEIGHT);

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;
    Window(Window&& other) = delete;
    Window& operator=(Window&& other) = delete;

    TextureCreator getTextureCreator() const;

    void clearRenderer();

    void render(Texture& texture);

    void update();

    ~Window();

private:
    static const int DEFAULT_SCREEN_WIDTH = 640;
    static const int DEFAULT_SCREEN_HEIGHT = 480;

    SDL_Window* window = nullptr;
    Renderer renderer;
};

#endif  // WINDOW_H
