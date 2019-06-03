#include "client/view/world_view_settings.h"

WorldViewSettings::WorldViewSettings(const size_t& screen_width, const size_t& screen_height,
                                     float32 world_width, size_t world_height,
                                     const TextureCreator& texture_creator) :
    screen_width(screen_width), screen_height(screen_height),
    world_size(world_width, world_height),
    pixel_to_meter(screen_width/world_width),
    level_width(1920),
    level_height(1440),
    textures(texture_creator) {
}

const double& WorldViewSettings::getRatio() const {
    return pixel_to_meter;
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
    pixel_to_meter = pixel_to_meter*level_width/screen_width;
}
