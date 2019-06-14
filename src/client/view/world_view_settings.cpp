#include "client/view/world_view_settings.h"

WorldViewSettings::WorldViewSettings(const size_t& screen_width, const size_t& screen_height,
                                     const TextureCreator& texture_creator) :
    screen_width(screen_width), screen_height(screen_height),
    world_size(200.335, 200.00125),   // Tamaño del mundo en metros
    pixel_per_meter(50),
    textures(texture_creator) {
}

const size_t& WorldViewSettings::getScreenWidth() const {
    return screen_width;
}

const size_t& WorldViewSettings::getScreenHeight() const {
    return screen_height;
}

const double& WorldViewSettings::getRatio() const {
    return pixel_per_meter;
}

const TextureLoader& WorldViewSettings::getTextureLoader() const {
    return textures;
}

void WorldViewSettings::changeRatioCameraMode() {
    pixel_per_meter = 100;
}

void WorldViewSettings::changeRatioScreenMode() {
    pixel_per_meter = screen_width / world_size.x;
}

void WorldViewSettings::setWorldSize(const Size & size) {
    world_size = size;
    changeRatioScreenMode();
}
