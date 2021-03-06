#include "client/screen/window.h"
#include <string>

Window::Window(size_t width, size_t height) : width(width), height(height) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::string error_message("Error al inicializar SDL: ");
        error_message += std::string(SDL_GetError());
        throw std::runtime_error(error_message);
    }

    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1" )) {
        throw std::runtime_error("Error: Linear texture filtering not enabled");
    }

    // Inicializamos el sistema para cargar imágenes PNG
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        std::string error_message("Error al crear al inicializar SDL_image: ");
        error_message += std::string(SDL_GetError());
        throw std::runtime_error(error_message);
    }

    window = SDL_CreateWindow("Portal2D", SDL_WINDOWPOS_UNDEFINED,
                    SDL_WINDOWPOS_UNDEFINED, width, height,
                    SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (!window) {
        std::string error_message("Error al crear la ventana: ");
        error_message += std::string(SDL_GetError());
        throw std::runtime_error(error_message);
    }
}

Window::~Window() {
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_QuitSubSystem(SDL_INIT_VIDEO);
    SDL_Quit();
}

SDL_Window* Window::get() const {
    return window;
}

void Window::toggleFullscreen() {
    if (fullscreen) {
        SDL_SetWindowFullscreen(window, SDL_FALSE);
        fullscreen = false;
    } else {
        SDL_SetWindowFullscreen(window, SDL_TRUE);
        fullscreen = true;
        minimized = false;
    }
}
