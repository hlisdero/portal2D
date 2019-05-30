#ifndef WORLD_VIEW_H
#define WORLD_VIEW_H

#include <vector>
#include <stdexcept>
#include "client/screen/screen.h"
#include "client/sound/sound_manager.h"
#include "client/view/view_object_creator.h"
#include "common/ratio.h"
#include "common/entities/entity.h"

class WorldView {
public:
    WorldView(float32 width, float32 height);

    WorldView(const WorldView&) = delete;
    WorldView& operator=(const WorldView&) = delete;
    WorldView(WorldView&& other) = delete;
    WorldView& operator=(WorldView&& other) = delete;

    ~WorldView();

    void createEntities(const std::vector<Entity*>& entities);

    void updatePosition(size_t index, const Position& position);
    void updatePosition(const std::vector<Entity*>& entities);

    void update();

private:
    Ratio meter_to_pixel;
    Screen screen;
    std::vector<DrawableBox2D*> view_objects;

public:
    ViewObjectCreator view_object_creator;

private:
    void renderObjects();
    void checkValidIndex(size_t index);
    void reserveSize(size_t index);
    void createEntity(EntityType type, size_t id, const Position& initial);
};

#endif  // WORLD_VIEW_H
