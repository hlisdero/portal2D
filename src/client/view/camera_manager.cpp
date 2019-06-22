#include "client/view/camera_manager.h"

CameraManager::CameraManager(Screen& screen) : screen(screen) {}

void CameraManager::add(DrawableBox2D* drawable) {
    drawables.insert(drawable);
}

void CameraManager::removeAndReplace(DrawableBox2D* oldCamera) {
    if (!drawables.erase(oldCamera)) {
        return;
    }

    if (current == oldCamera) {
        screen.destroyCamera();

        if (!drawables.empty()) {
           select(*drawables.begin());
        }
    }
}

void CameraManager::select(DrawableBox2D* newCamera) {
    if (!drawables.count(newCamera)) {
        throw std::runtime_error("Error: el objeto para crear la cámara no existe");
    }
    screen.createCamera(*newCamera);
    current = newCamera;
}
