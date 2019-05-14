#include "screen.h"

Screen::Screen(size_t width, size_t height) :
    window(width, height), renderer(window.get()),
    texture_creator(renderer) {}

void Screen::clear() {
    renderer.clear();
}

void Screen::render(Texture& texture) {
    renderer.renderCopy(texture);
}

void Screen::update() {
    renderer.renderPresent();
}

const TextureCreator& Screen::getTextureCreator() const {
    return texture_creator;
}
