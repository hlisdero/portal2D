#ifndef WORLD_VIEW_SETTINGS_H
#define WORLD_VIEW_SETTINGS_H

#include "client/texture/texture_creator.h"
#include "client/texture/texture_loader.h"
#include "common/objects/size.h"

class WorldViewSettings {
public:
    WorldViewSettings(const size_t& screen_width, const size_t& screen_height,
                      float world_width, float world_height, const TextureCreator& texture_creator);

    WorldViewSettings(const WorldViewSettings&) = delete;
    WorldViewSettings& operator=(const WorldViewSettings&) = delete;
    WorldViewSettings(WorldViewSettings&& other) = delete;
    WorldViewSettings& operator=(WorldViewSettings&& other) = delete;

    const size_t& getScreenWidth() const;
    const size_t& getScreenHeight() const;
    const double& getRatio() const;
    size_t getLevelWidth() const;
    size_t getLevelHeight() const;
    const TextureLoader& getTextureLoader() const;

    void changeRatioCameraMode();

private:
    const size_t& screen_width;
    const size_t& screen_height;
    Size world_size;
    double pixel_per_meter;
    size_t level_width;
    size_t level_height;

    TextureLoader textures;
};

#endif  // WORLD_VIEW_SETTINGS_H
