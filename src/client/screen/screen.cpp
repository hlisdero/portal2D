#include "client/screen/screen.h"

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

void Screen::render(const Texture& texture, int x, int y, double scale_factor) {
    // Puede perder precisión debido al casteo
    int w = texture.width * scale_factor;
    int h = texture.height * scale_factor;
    SDL_Rect rect = {x, y, w, h};
    renderer.render(texture.get(), nullptr, &rect);
}

void Screen::render(Drawable& drawable) {
    SDL_Rect dst = {drawable.getX(), drawable.getY(), drawable.getWidth(), drawable.getHeight()};
    SDL_Rect* src = drawable.getClip();
    const Texture& texture = drawable.getTexture();
    renderer.render(texture.get(), src, &dst, drawable.getRotation(), drawable.getFlipState());
}

void Screen::render(DrawableBox2D& drawable) {
    // Transformo el sistema de coordenadas de Box2D al de SDL
    // La posición se mide desde el medio del objeto
    int x = drawable.getX() - drawable.getWidth()/2;
    int y = window.height - (drawable.getY() + drawable.getHeight()/2);

    SDL_Rect dst = {x, y, drawable.getWidth(), drawable.getHeight()};
    SDL_Rect* src = drawable.getClip();
    const Texture& texture = drawable.getTexture();
    renderer.render(texture.get(), src, &dst, drawable.getRotation(), drawable.getFlipState());
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
