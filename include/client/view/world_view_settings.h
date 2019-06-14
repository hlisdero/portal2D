#ifndef WORLD_VIEW_SETTINGS_H
#define WORLD_VIEW_SETTINGS_H

#include "client/texture/texture_creator.h"
#include "client/texture/texture_loader.h"

class WorldViewSettings {
public:
    WorldViewSettings(const size_t& screen_width, const size_t& screen_height,
                      const TextureCreator& texture_creator);

    WorldViewSettings(const WorldViewSettings&) = delete;
    WorldViewSettings& operator=(const WorldViewSettings&) = delete;
    WorldViewSettings(WorldViewSettings&& other) = delete;
    WorldViewSettings& operator=(WorldViewSettings&& other) = delete;

    const size_t& getScreenWidth() const;
    const size_t& getScreenHeight() const;

    const double& getRatio() const;

    const TextureLoader& getTextureLoader() const;

private:
    const size_t& screen_width;
    const size_t& screen_height;
    double pixel_per_meter;

    TextureLoader textures;
};

#endif  // WORLD_VIEW_SETTINGS_H
