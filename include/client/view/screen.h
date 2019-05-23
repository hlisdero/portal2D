#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include "client/objects/drawable.h"
#include "client/objects/drawable_box2D.h"
#include "client/view/window.h"
#include "client/view/renderer.h"
#include "client/view/texture_creator.h"
#include "client/view/texture.h"
#include "client/view/sprite.h"
#include "client/view/color.h"

class Screen {
public:
    explicit Screen(size_t width = DEFAULT_SCREEN_WIDTH,
                    size_t height = DEFAULT_SCREEN_HEIGHT);

    Screen(const Screen&) = delete;
    Screen& operator=(const Screen&) = delete;
    Screen(Screen&& other) = delete;
    Screen& operator=(Screen&& other) = delete;

    size_t getWidth() const;
    size_t getHeight() const;

    void clear();

    void render(Texture& texture, int x, int y);
    void render(Texture& texture, const SDL_Rect* srcrect, const SDL_Rect* dstrect);
    void render(Sprite& sprite, int x, int y);
    void render(Drawable& drawable);
    void render(DrawableBox2D& drawable);

    void setRenderDrawColor(const std::string& color_name);
    void setRenderDrawColor(uint8_t red, uint8_t green,
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

    void resetViewport();

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
