#include "client/objects/drawable_box2D.h"

DrawableBox2D::DrawableBox2D(const Size& size, const Position& initial, Ratio& ratio) :
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

void DrawableBox2D::updatePosition(const Position& new_position) {
    position = new_position;
}
