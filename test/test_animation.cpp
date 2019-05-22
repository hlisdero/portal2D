#include "catch.hpp"
#include <SDL2/SDL.h>
#include "client/view/screen.h"
#include "client/view/animation.h"

TEST_CASE("Animation Test", "[integration]") {
    Screen screen;
    size_t width = screen.getWidth();
    size_t height = screen.getHeight();

    const TextureCreator& textureCreator = screen.getTextureCreator();
    Texture background = textureCreator("../test/data/background.png");
    Texture character = textureCreator("../test/data/foo.png", Color("cyan"));
    Animation animation(textureCreator("../test/data/animation.png", Color("cyan")));
    animation.addClip(0, 0, 64, 205);
    animation.addClip(64, 0, 64, 205);
    animation.addClip(128, 0, 64, 205);
    animation.addClip(196, 0, 64, 205);

    bool quit = false;
    SDL_Event e;
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        screen.setRenderDrawColor("white");
        screen.clear();
        screen.render(background, 0, 0);
        screen.render(character, 240, 190);
        screen.render(animation, (width - animation.getWidth()) / 2,
                                 (height - animation.getHeight()) / 2);
        screen.update();
    }
}
