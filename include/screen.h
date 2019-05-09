#ifndef SCREEN_H
#define SCREEN_H

#include "window.h"
#include "renderer.h"
#include "texture.h"
#include "texture_creator.h"

class Screen {
public:
    explicit Screen(size_t width = DEFAULT_SCREEN_WIDTH,
                    size_t height = DEFAULT_SCREEN_HEIGHT);

    Screen(const Screen&) = delete;
    Screen& operator=(const Screen&) = delete;
    Screen(Screen&& other) = delete;
    Screen& operator=(Screen&& other) = delete;

    void clear();
    void render(Texture& texture);
    void update();

    const TextureCreator& getTextureCreator() const;

private:
    static const size_t DEFAULT_SCREEN_WIDTH = 640;
    static const size_t DEFAULT_SCREEN_HEIGHT = 480;

    Window window;
    Renderer renderer;
    const TextureCreator texture_creator;
};

#endif  // SCREEN_H
