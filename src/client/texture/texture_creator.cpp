#include "client/texture/texture_creator.h"

TextureCreator::TextureCreator(const Renderer& renderer) :
    renderer(renderer) {}

Texture TextureCreator::operator()(const std::string& path) const {
    Surface surface(path);
    Texture texture = renderer.createTextureFromSurface(surface);
    return std::move(texture);
}

Texture TextureCreator::operator()(const std::string& path,
                                   const Color& color_key) const {
    Surface surface(path, color_key);
    Texture texture = renderer.createTextureFromSurface(surface);
    return std::move(texture);
}
