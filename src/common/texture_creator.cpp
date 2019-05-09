#include "texture_creator.h"

TextureCreator::TextureCreator(const Renderer& renderer) :
    renderer(renderer) {}

Texture TextureCreator::operator()(const std::string& path) const {
    Surface surface(path);
    Texture texture = renderer.createTextureFromSurface(surface);
    return std::move(texture);
}
