#include "client/screen/surface.h"

Surface::Surface(const std::string& path) {
    surface = IMG_Load(path.c_str());
    if (!surface) {
        std::string error_message("Error al cargar imagen: ");
        error_message += std::string(IMG_GetError());
        throw std::runtime_error(error_message);
    }
    width = surface->w;
    height = surface->h;
}

Surface::Surface(const std::string& path, const Color& color_key) :
    Surface(path) {
    setColorKey(color_key);
}

void Surface::setColorKey(const Color& color_key) {
    int ret_code = SDL_SetColorKey(this->get(), SDL_TRUE,
        SDL_MapRGB(this->get()->format, color_key.r, color_key.g, color_key.b));
    if (ret_code) {
        std::string error_message("Error al setear la color key: ");
        error_message += std::string(SDL_GetError());
        throw std::runtime_error(error_message);
    }
}

Surface::~Surface() {
    SDL_FreeSurface(surface);
}

SDL_Surface* Surface::get() const {
    return surface;
}

int Surface::getWidth() const {
    return width;
}

int Surface::getHeight() const {
    return height;
}
