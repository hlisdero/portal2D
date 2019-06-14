#ifndef CAMERA_MANAGER_H
#define CAMERA_MANAGER_H

#include <map>
#include <stdexcept>
#include "client/screen/screen.h"

class CameraManager {
public:
    explicit CameraManager(Screen& screen);

    void add(size_t index, DrawableBox2D* drawable);
    void remove(size_t index);

    void select(size_t index);

private:
    Screen& screen;
    std::map<size_t, DrawableBox2D*> drawables;
};

#endif  // CAMERA_MANAGER_H
