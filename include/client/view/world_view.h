#ifndef WORLD_VIEW_H
#define WORLD_VIEW_H

#include <vector>
#include "client/screen/screen.h"
#include "client/texture/texture_loader.h"
#include "client/objects/drawable_box2D.h"
#include "client/objects/player.h"
#include "client/objects/metal_block.h"
#include "client/objects/stone_block.h"
#include "client/objects/acid.h"
#include "client/objects/button.h"
#include "client/objects/background.h"
#include "common/ratio.h"
#include "common/size.h"
#include "common/entities/entity.h"

class WorldView {
public:
    WorldView(float32 width, float32 height);

    WorldView(const WorldView&) = delete;
    WorldView& operator=(const WorldView&) = delete;
    WorldView(WorldView&& other) = delete;
    WorldView& operator=(WorldView&& other) = delete;

    ~WorldView();

    size_t createPlayer(const Position& initial);
    size_t createMetalBlock(const Position& initial);
    size_t createStoneBlock(const Position& initial);
    size_t createAcid(const Position& initial);
    size_t createButton(const Position& initial);

    void updatePosition(size_t index, const Position& position);

    void update();

private:
    Ratio meter_to_pixel;
    Screen screen;
    TextureLoader textures;
    Background background;
    std::vector<DrawableBox2D*> view_objects;

    void renderObjects();
    void checkValidIndex(size_t index);
};

#endif  // WORLD_VIEW_H
