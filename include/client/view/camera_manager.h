#ifndef CAMERA_MANAGER_H
#define CAMERA_MANAGER_H

#include <map>
#include <unordered_set>
#include <stdexcept>
#include <algorithm>
#include "client/screen/screen.h"

class CameraManager {
public:
    explicit CameraManager(Screen& screen);

    void add(DrawableBox2D* drawable);
    void removeAndReplace(DrawableBox2D* oldCamera);

    void select(DrawableBox2D* newCamera);

private:
    Screen& screen;
    std::unordered_set<DrawableBox2D*> drawables;
    DrawableBox2D* current;
};

#endif  // CAMERA_MANAGER_H
