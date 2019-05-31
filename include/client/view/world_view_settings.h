#ifndef WORLD_VIEW_SETTINGS_H
#define WORLD_VIEW_SETTINGS_H

#include "client/texture/texture_creator.h"
#include "client/texture/texture_loader.h"
#include "common/ratio.h"
#include "common/size.h"

class WorldViewSettings {
public:
    WorldViewSettings(size_t screen_width, size_t screen_height,
                      size_t level_width, size_t level_height,
                      float32 world_width, size_t world_height, const TextureCreator& texture_creator);

    WorldViewSettings(const WorldViewSettings&) = delete;
    WorldViewSettings& operator=(const WorldViewSettings&) = delete;
    WorldViewSettings(WorldViewSettings&& other) = delete;
    WorldViewSettings& operator=(WorldViewSettings&& other) = delete;

    const Ratio& getRatio() const;
    size_t getLevelWidth() const;
    size_t getLevelHeight() const;
    const TextureLoader& getTextureLoader() const;

    void changeRatioCameraMode();

private:
    size_t screen_width;
    size_t screen_height;
    size_t level_width;
    size_t level_height;
    Size world_size;
    Ratio meter_to_pixel;

    TextureLoader textures;
};

#endif  // WORLD_VIEW_SETTINGS_H
