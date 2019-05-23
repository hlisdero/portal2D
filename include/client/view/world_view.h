#ifndef WORLD_VIEW_H
#define WORLD_VIEW_H

#include <vector>
#include "client/view/screen.h"
#include "client/objects/drawable_box2D.h"
#include "client/objects/player.h"
#include "client/objects/block.h"
#include "common/ratio.h"

class WorldView {
public:
    WorldView(float32 width, float32 height);

    WorldView(const WorldView&) = delete;
    WorldView& operator=(const WorldView&) = delete;
    WorldView(WorldView&& other) = delete;
    WorldView& operator=(WorldView&& other) = delete;

    ~WorldView();

    size_t createPlayer(const Position& initial);
    size_t createBlock(const Position& initial);

    void updatePosition(size_t index, const Position& position);

    void update();

private:
    Ratio meter_to_pixel;
    Screen screen;
    Texture background;
    std::vector<DrawableBox2D*> view_objects;

    void clearScreen();
    void renderBackground();
    void renderObjects();

    void checkValidIndex(size_t index);
};

#endif  // WORLD_VIEW_H
