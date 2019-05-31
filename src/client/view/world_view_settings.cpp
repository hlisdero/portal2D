#include "client/view/world_view_settings.h"

WorldViewSettings::WorldViewSettings(size_t screen_width, size_t screen_height,
                                     size_t level_width, size_t level_height,
                                     float32 world_width, size_t world_height,
                                     const TextureCreator& texture_creator) :
    screen_width(screen_width), screen_height(screen_height),
    level_width(level_width), level_height(level_height),
    world_size(world_width, world_height),
    meter_to_pixel(screen_width/world_width, screen_height/world_height),
    textures(texture_creator) {}

const Ratio& WorldViewSettings::getRatio() const {
    return meter_to_pixel;
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
    meter_to_pixel.x = meter_to_pixel.x*level_width/screen_width;
    meter_to_pixel.y = meter_to_pixel.x*level_height/screen_height;
}
