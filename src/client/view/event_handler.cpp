#include "event_handler.h"

EventHandler::EventHandler(Texture& texture) : texture(texture) {}

EventHandler::operator bool() const {
    return !quit;
}

void EventHandler::poll() {
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            quit = true;
        }
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_a:
                    texture.rotate(-60);
                    break;
                case SDLK_d:
                    texture.rotate(60);
                    break;
                case SDLK_q:
                    texture.flip(SDL_FLIP_HORIZONTAL);
                    break;
                case SDLK_w:
                    texture.flip(SDL_FLIP_NONE);
                    break;
                case SDLK_e:
                    texture.flip(SDL_FLIP_VERTICAL);
                    break;
            }
        }
    }
}
