#include "catch.hpp"
#include <SDL2/SDL.h>
#include "client/screen/screen.h"
#include "client/screen/animation.h"
#include "character.h"

TEST_CASE("Animation Test", "[modules][animation]") {
    Screen screen;
    size_t width = screen.getWidth();
    size_t height = screen.getHeight();

    const TextureCreator& textureCreator = screen.getTextureCreator();
    Texture background = textureCreator("../test/data/background.png");
    Texture foo = textureCreator("../test/data/foo.png", Color("cyan"));
    Texture animation = textureCreator("../test/data/animation.png", Color("cyan"));
    Character character(width/2, height/2, animation);

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
        screen.render(foo, 240, 190);
        screen.render(character);
        screen.update();
    }
}
