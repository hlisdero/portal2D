#ifndef CAMERA_H
#define CAMERA_H

#include "client/objects/drawable_box2D.h"

class Camera {
public:
    Camera(const size_t& width, const size_t& height,
           const DrawableBox2D& drawable);

    void center();

    int x;
    int y;

private:
    const size_t& width;
    const size_t& height;
    const DrawableBox2D& drawable;
};

#endif  // CAMERA_H
