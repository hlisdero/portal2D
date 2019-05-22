#include "client/view/screen.h"

Screen::Screen(size_t width, size_t height) :
    window(width, height), renderer(window.get()),
    texture_creator(renderer) {}

size_t Screen::getWidth() const {
    return window.width;
}

size_t Screen::getHeight() const {
    return window.height;
}

void Screen::clear() {
    renderer.clear();
}

void Screen::render(Texture& texture, int x, int y) {
    renderer.renderCopy(texture, x, y);
}

void Screen::render(Sprite& sprite, int x, int y) {
    renderer.renderCopy(sprite, x, y);
}

void Screen::render(Drawable& drawable) {
    renderer.renderCopy(drawable.getSprite(), drawable.getX(), drawable.getY());
}

void Screen::setRenderDrawColor(const std::string& color_name) {
    renderer.setDrawColor(Color(color_name));
}

void Screen::setRenderDrawColor(uint8_t red, uint8_t green,
                                uint8_t blue, uint8_t alpha) {
    renderer.setDrawColor(red, green, blue, alpha);
}

void Screen::drawPoint(int width, int height) {
    renderer.drawPoint(width, height);
}

void Screen::drawLine(int start_width, int start_height,
                      int end_width, int end_height) {
    renderer.drawLine(start_width, start_height, end_width, end_height);
}

void Screen::drawFillRect(int start_width, int start_height,
                          int end_width, int end_height) {
    renderer.drawFillRect(start_width, start_height, end_width, end_height);
}

void Screen::drawRect(int start_width, int start_height,
                      int end_width, int end_height) {
    renderer.drawRect(start_width, start_height, end_width, end_height);
}

void Screen::setViewport(int start_width, int start_height,
                         int end_width, int end_height) {
    renderer.setViewport(start_width, start_height, end_width, end_height);
}

void Screen::resetViewport() {
    renderer.setViewport(0, 0, window.width, window.height);
}

void Screen::update() {
    renderer.renderPresent();
}

const TextureCreator& Screen::getTextureCreator() const {
    return texture_creator;
}
