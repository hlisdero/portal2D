#include "surface.h"

Surface::Surface(const std::string& path) {
    surface = IMG_Load(path.c_str());
    if (!surface) {
        std::string error_message("Error al cargar imagen: ");
        error_message += std::string(IMG_GetError());
        throw std::runtime_error(error_message);
    }
}

Surface::~Surface() {
    SDL_FreeSurface(surface);
}

SDL_Surface* Surface::get() const {
    return surface;
}
