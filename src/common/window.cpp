#include "window.h"
#include <string>

Window::Window(size_t width, size_t height) : renderer() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::string error_message("Error al inicializar SDL: ");
        error_message += std::string(SDL_GetError());
        throw std::runtime_error(error_message);
    }

    if (SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1" ) == SDL_FALSE) {
        throw std::runtime_error("Error: Linear texture filtering not enabled");
    }

    window = SDL_CreateWindow( "Ventana de prueba", SDL_WINDOWPOS_UNDEFINED,
                    SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN );
    if (!window) {
        std::string error_message("Error al crear la ventana: ");
        error_message += std::string(SDL_GetError());
        throw std::runtime_error(error_message);
    }

    renderer = Renderer(window);
}

Window::~Window() {
    SDL_DestroyWindow(window);
    SDL_Quit();
}

TextureCreator Window::getTextureCreator() const {
    return TextureCreator(renderer);
}

void Window::clearRenderer() {
    renderer.clear();
}

void Window::render(Texture& texture) {
    renderer.renderCopy(texture);
}

void Window::update() {
    renderer.renderPresent();
}
