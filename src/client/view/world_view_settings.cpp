#include "client/view/world_view_settings.h"

WorldViewSettings::WorldViewSettings(const size_t& screen_width, const size_t& screen_height,
                                     const TextureCreator& texture_creator) :
    screen_width(screen_width), screen_height(screen_height),
    world_size(13.335, 10.00125),   // Tamaño del mundo en metros
    pixel_per_meter(screen_width/world_size.x),
    level_width(1440),
    level_height(1080),
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

size_t WorldViewSettings::getLevelWidth() const {
    return level_width;
}

size_t WorldViewSettings::getLevelHeight() const {
    return level_height;
}

const TextureLoader& WorldViewSettings::getTextureLoader() const {
    return textures;
}

void WorldViewSettings::changeRatioCameraMode() {
    pixel_per_meter = pixel_per_meter*level_width/screen_width;
}

void WorldViewSettings::changeRatioScreenMode() {
    pixel_per_meter = screen_width / world_size.x;
}
