#include "renderer.h"

Renderer::Renderer(SDL_Window* window) {
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::string error_message("Error al crear el renderer: ");
        error_message += std::string(SDL_GetError());
        throw std::runtime_error(error_message);
    }

    // Seteamos el color del renderer a negro
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF );
}

Renderer::~Renderer() {
    SDL_DestroyRenderer(renderer);
}

Texture Renderer::createTextureFromSurface(Surface& surface) const {
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface.get());
    if (!texture) {
        std::string error_message("Error al crear textura: ");
        error_message += std::string(SDL_GetError());
        throw std::runtime_error(error_message);
    }
    return std::move(Texture(texture));
}

void Renderer::clear() {
    int ret_code = SDL_RenderClear(renderer) != 0;
    if (ret_code) {
        std::string error_message("Error al limpiar el renderer: ");
        error_message += std::string(SDL_GetError());
        throw std::runtime_error(error_message);
    }
}

void Renderer::renderCopy(Texture& texture) {
    // Renderiza la textura completa
    int ret_code = SDL_RenderCopy(renderer, texture.get(), NULL, NULL);
    if (ret_code) {
        std::string error_message("Error al renderizar la textura: ");
        error_message += std::string(SDL_GetError());
        throw std::runtime_error(error_message);
    }
}

void Renderer::renderPresent() {
    SDL_RenderPresent(renderer);
}
