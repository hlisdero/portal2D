#include "client/screen/camera.h"

Camera::Camera(const size_t& width, const size_t& height,
               const DrawableBox2D& drawable) :
    width(width), height(height), drawable(drawable) {
}

void Camera::center() {
    x = drawable.getX() + drawable.getWidth()/2 - width / 2;
    y = drawable.getY() + drawable.getHeight()/2 - height / 2;
}
