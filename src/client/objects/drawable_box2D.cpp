#include "client/objects/drawable_box2D.h"

DrawableBox2D::DrawableBox2D(const Size& size, const Position& initial, const Ratio& ratio) :
    size(size), position(initial), meter_to_pixel(ratio) {}

int DrawableBox2D::getX() const {
    return position.x * meter_to_pixel.x;
}

int DrawableBox2D::getY() const {
    return position.y * meter_to_pixel.y;
}

int DrawableBox2D::getWidth() const {
    return size.x * meter_to_pixel.x;
}

int DrawableBox2D::getHeight() const {
    return size.y * meter_to_pixel.y;
}

double DrawableBox2D::getRotation() const {
    return angle;
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
