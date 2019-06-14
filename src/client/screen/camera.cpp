#include "client/screen/camera.h"

Camera::Camera(int width, int height,
               const DrawableBox2D& drawable) :
    drawable(drawable) {
    position = {0, 0, width, height};
}

void Camera::center() {
    position.x = drawable.getX() + drawable.getWidth()/2 - position.w / 2;
    position.y = drawable.getY() + drawable.getHeight()/2 - position.h / 2;
}
