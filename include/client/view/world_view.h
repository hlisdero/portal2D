#ifndef WORLD_VIEW_H
#define WORLD_VIEW_H

#include <vector>
#include "client/screen/screen.h"
#include "client/texture/texture_loader.h"
#include "client/objects/objects.h"
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

    void createPlayer(size_t index, const Position& initial);
    void createMetalBlock(size_t index, const Position& initial);
    void createStoneBlock(size_t index, const Position& initial);
    void createAcid(size_t index, const Position& initial);
    void createButton(size_t index, const Position& initial);
    void createEnergyBall(size_t index, const Position& initial);
    void createEnergyReceiver(size_t index, const Position& initial, double rotation = 0.0);
    void createRock(size_t index, const Position& initial, double rotation = 0.0);

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
