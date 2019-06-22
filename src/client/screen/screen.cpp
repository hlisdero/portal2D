#include "client/screen/screen.h"

Screen::Screen(size_t width, size_t height) :
    window(width, height), renderer(window.get()),
    texture_creator(renderer) {}

Screen::~Screen() {
    if (camera) {
        delete camera;
    }
}

const size_t& Screen::getWidth() const {
    return window.width;
}

const size_t& Screen::getHeight() const {
    return window.height;
}

void Screen::handle(const SDL_Event& event) {
    switch (event.window.event) {
        case SDL_WINDOWEVENT_SIZE_CHANGED:
            window.width = event.window.data1;
            window.height = event.window.data2;
            update();
            break;
        case SDL_WINDOWEVENT_EXPOSED:
            update();
            break;
        case SDL_WINDOWEVENT_MINIMIZED:
            window.minimized = true;
            break;
        case SDL_WINDOWEVENT_MAXIMIZED:
        case SDL_WINDOWEVENT_RESTORED:
            window.minimized = false;
            break;
    }
}

void Screen::handle(const KeyboardEvent& event) {
    if (!event.pressed || event.key != SDL_SCANCODE_P) {
        return;
    }
    window.toggleFullscreen();
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
    makeRelativeToCamera(dst);
    SDL_Rect* src = drawable.getClip();
    const Texture& texture = drawable.getTexture();
    renderer.render(texture.get(), src, &dst, drawable.getRotation(), drawable.getFlipState());
}

void Screen::render(Background& background) {
    SDL_Rect dst = {background.getX(), background.getY(), background.getWidth(), background.getHeight()};
    const Texture& texture = background.getTexture();
    SDL_Rect* src = background.getClip();
    renderer.render(texture.get(), src, &dst);
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

void Screen::centerCamera() {
    if (camera) {
        camera->center();
    }
}

void Screen::update() {
    if (window.minimized) {
        return;
    }
    renderer.renderPresent();
}

const TextureCreator& Screen::getTextureCreator() const {
    return texture_creator;
}

void Screen::createCamera(const DrawableBox2D& drawable) {
    camera = new Camera(getWidth(), getHeight(), drawable);
}

const Camera* Screen::getCamera() const {
    return camera;
}

void Screen::destroyCamera() {
    delete camera;
    camera = nullptr;
}

void Screen::makeRelativeToCamera(SDL_Rect& rect) {
    if (!camera) {
        return;
    }
    rect.x = rect.x - camera->position.x;
    rect.y = rect.y - camera->position.y;
}
