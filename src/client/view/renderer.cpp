#include "renderer.h"

Renderer::Renderer(SDL_Window* window) {
    renderer = SDL_CreateRenderer(window, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        std::string error_message("Error al crear el renderer: ");
        error_message += std::string(SDL_GetError());
        throw std::runtime_error(error_message);
    }

    // Seteamos el color a negro
    setDrawColor(0xFF, 0xFF, 0xFF, 0xFF);
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
    return std::move(Texture(texture, surface.getWidth(), surface.getHeight()));
}

void Renderer::setDrawColor(const Color& color) {
    setDrawColor(color.r, color.g, color.b, color.a);
}

void Renderer::setDrawColor(uint8_t red, uint8_t green,
                            uint8_t blue, uint8_t alpha) {
    int ret_code = SDL_SetRenderDrawColor(renderer, red, green, blue, alpha);
    if (ret_code) {
        std::string error_message("Error al setear el color del renderizador: ");
        error_message += std::string(SDL_GetError());
        throw std::runtime_error(error_message);
    }
}

void Renderer::drawPoint(int width, int height) {
    int ret_code = SDL_RenderDrawPoint(renderer, width, height);
    if (ret_code) {
        std::string error_message("Error al dibujar un punto: ");
        error_message += std::string(SDL_GetError());
        throw std::runtime_error(error_message);
    }
}

void Renderer::drawLine(int start_width, int start_height,
                        int end_width, int end_height) {
    int ret_code = SDL_RenderDrawLine(renderer, start_width, start_height,
                                                end_width, end_height);
    if (ret_code) {
        std::string error_message("Error al dibujar una línea: ");
        error_message += std::string(SDL_GetError());
        throw std::runtime_error(error_message);
    }
}

void Renderer::drawFillRect(int start_width, int start_height,
                            int end_width, int end_height) {
    SDL_Rect fillRect = { start_width, start_height, end_width, end_height };
    int ret_code = SDL_RenderFillRect(renderer, &fillRect);
    if (ret_code) {
        std::string error_message("Error al dibujar un rectángulo: ");
        error_message += std::string(SDL_GetError());
         throw std::runtime_error(error_message);
    }
}

void Renderer::drawRect(int start_width, int start_height,
                        int end_width, int end_height) {
    SDL_Rect outlineRect = { start_width, start_height, end_width, end_height };
    int ret_code = SDL_RenderDrawRect(renderer, &outlineRect);
    if (ret_code) {
        std::string error_message("Error al dibujar un rectángulo: ");
        error_message += std::string(SDL_GetError());
        throw std::runtime_error(error_message);
    }
}

void Renderer::setViewport(int start_width, int start_height,
                           int end_width, int end_height) {
    SDL_Rect viewport = { start_width, start_height, end_width, end_height };
    int ret_code = SDL_RenderSetViewport(renderer, &viewport);
    if (ret_code) {
        std::string error_message("Error al setear el viewport: ");
        error_message += std::string(SDL_GetError());
        throw std::runtime_error(error_message);
    }
}

void Renderer::clear() {
    int ret_code = SDL_RenderClear(renderer);
    if (ret_code) {
        std::string error_message("Error al limpiar el renderer: ");
        error_message += std::string(SDL_GetError());
        throw std::runtime_error(error_message);
    }
}

void Renderer::renderCopy(Texture& texture, int x, int y) {
    SDL_Rect dest = {x, y, texture.getWidth(), texture.getHeight()};
    render(texture.get(), NULL, &dest, texture.getRotation(), texture.getFlipState());
}

void Renderer::renderCopy(Sprite& sprite, int x, int y) {
    SDL_Rect dest = {x, y, sprite.getWidth(), sprite.getHeight()};
    render(sprite.getTexture(), &sprite.getClip(), &dest, sprite.getRotation(), sprite.getFlipState());
}

void Renderer::renderPresent() {
    SDL_RenderPresent(renderer);
}

void Renderer::render(SDL_Texture* texture, SDL_Rect* srcrect,
    SDL_Rect* dstrect, double angle, SDL_RendererFlip flip) {
    int ret_code = SDL_RenderCopyEx(renderer, texture,
                    srcrect, dstrect, angle, NULL, flip);
    if (ret_code) {
        std::string error_message("Error al renderizar la textura: ");
        error_message += std::string(SDL_GetError());
        throw std::runtime_error(error_message);
    }
}
