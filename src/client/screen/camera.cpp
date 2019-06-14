#include "client/screen/camera.h"

Camera::Camera(int width, int height,
               int level_width, int level_height,
               const DrawableBox2D& drawable) :
    level_width(level_width), level_height(level_height), drawable(drawable) {
    position = {0, 0, width, height};
}

void Camera::center() {
    position.x = drawable.getX() + drawable.getWidth()/2 - position.w / 2;
    position.y = drawable.getY() + drawable.getHeight()/2 - position.h / 2;

    if (position.x < 0) {
        position.x = 0;
    }
    if (position.y < 0) {
        position.y = 0;
    }
    if (position.x > level_width - position.w) {
        position.x = level_width - position.w;
    }
    if (position.y > level_height - position.h) {
        position.y = level_height - position.h;
    }
}
