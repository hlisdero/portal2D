#include "client/objects/drawable_box2D.h"

DrawableBox2D::DrawableBox2D(const Size& size, const Position& initial,
                             const WorldViewSettings& settings) :
    size(size), position(initial),
    pixel_per_meter(settings.getRatio()),
    window_height(settings.getScreenHeight()) {}

int DrawableBox2D::getX() const {
    // Transformo el sistema de coordenadas de Box2D al de SDL
    // La posición se mide desde el medio del objeto
    return position.x * pixel_per_meter - getWidth()/2;
}

int DrawableBox2D::getY() const {
    // Transformo el sistema de coordenadas de Box2D al de SDL
    // La posición se mide desde el medio del objeto
    return window_height - (position.y * pixel_per_meter + getHeight()/2);
}

int DrawableBox2D::getWidth() const {
    return size.x * pixel_per_meter;
}

int DrawableBox2D::getHeight() const {
    return size.y * pixel_per_meter;
}

double DrawableBox2D::getRotation() const {
    return -position.z;  // BOX2D counterclockwise, SDL clockwise
}

double DrawableBox2D::currentX() const {
    return position.x;
}

double DrawableBox2D::currentY() const {
    return position.y;
}

const State& DrawableBox2D::getState() const {
    return state;
}

void DrawableBox2D::updatePosition(const Position& new_position) {
    position = new_position;
}

void DrawableBox2D::updateState(const State& new_state) {
    state = new_state;
}

bool DrawableBox2D::destroyNow() {
    return true;
}

bool DrawableBox2D::isFinished() {
    return false;
}

void DrawableBox2D::playSound() {
    // Do nothing
}

void DrawableBox2D::playDestroySound() {
    // Do nothing
}
