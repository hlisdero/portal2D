#include "client/view/camera_manager.h"

CameraManager::CameraManager(Screen& screen) : screen(screen) {}

void CameraManager::add(size_t index, DrawableBox2D* drawable) {
    drawables[index] = drawable;
}

void CameraManager::remove(size_t index) {
    if (!drawables.count(index)) {
        return;
    }
    drawables.erase(index);
    screen.destroyCamera();
    if (drawables.empty()) {
        return;
    }
    DrawableBox2D* new_drawable = (*drawables.begin()).second;
    screen.createCamera(*new_drawable);
}

void CameraManager::select(size_t index) {
    if (!drawables.count(index)) {
        throw std::runtime_error("Error: el objeto para crear la cámara no existe");
    }
    screen.createCamera(*drawables[index]);
}
