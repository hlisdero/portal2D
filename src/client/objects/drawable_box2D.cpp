#include "client/objects/drawable_box2D.h"

DrawableBox2D::DrawableBox2D(const Size& size, const Position& initial,
                             const double& ratio, double angle) :
    size(size), position(initial), pixel_per_meter(ratio), angle(angle) {}

int DrawableBox2D::getX() const {
    return position.x * pixel_per_meter;
}

int DrawableBox2D::getY() const {
    return position.y * pixel_per_meter;
}

int DrawableBox2D::getWidth() const {
    return size.x * pixel_per_meter;
}

int DrawableBox2D::getHeight() const {
    return size.y * pixel_per_meter;
}

double DrawableBox2D::getRotation() const {
    return -angle;  // BOX2D counterclockwise, SDL clockwise
}

float32 DrawableBox2D::currentX() const {
    return position.x;
}

float32 DrawableBox2D::currentY() const {
    return position.y;
}

void DrawableBox2D::updatePosition(const Position& new_position, double angle) {
    position = new_position;
    angle = angle;
}
