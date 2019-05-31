#ifndef WORLD_VIEW_H
#define WORLD_VIEW_H

#include <map>
#include <stdexcept>
#include "client/screen/screen.h"
#include "client/sound/sound_manager.h"
#include "client/view/view_object_creator.h"
#include "client/view/world_view_settings.h"
#include "common/ratio.h"
#include "common/entities/entity.h"

class WorldView {
public:
    WorldView(float32 width, float32 height,
              size_t level_width, size_t level_height);

    WorldView(const WorldView&) = delete;
    WorldView& operator=(const WorldView&) = delete;
    WorldView(WorldView&& other) = delete;
    WorldView& operator=(WorldView&& other) = delete;

    ~WorldView();

    const ViewObjectCreator& getObjectCreator() const;

    void createEntities(const std::vector<Entity*>& entities);

    void updatePosition(size_t index, const Position& position, double angle = 0.0);
    void updatePosition(const std::vector<Entity*>& entities);

    void update();

private:
    const size_t screen_width = 1024;
    const size_t screen_height = 768;
    Screen screen;
    WorldViewSettings settings;
    Background background;
    std::map<size_t, DrawableBox2D*> view_objects;
    ViewObjectCreator object_creator;

    void renderObjects();
    void checkValidIndex(size_t index);
    void createEntity(EntityType type, size_t id, const Position& initial, double rotation);
    void createPlayerWithCamera(size_t id, const Position& position);
};

#endif  // WORLD_VIEW_H
