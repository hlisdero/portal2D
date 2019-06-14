#ifndef CAMERA_H
#define CAMERA_H

#include "client/objects/drawable_box2D.h"

class Camera {
public:
    Camera(int width, int height,
           const DrawableBox2D& drawable);

    void center();

    SDL_Rect position = {0, 0, 0, 0};

private:
    const DrawableBox2D& drawable;
};

#endif  // CAMERA_H
