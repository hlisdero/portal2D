#ifndef WORLD_VIEW_H
#define WORLD_VIEW_H

#include <map>
#include <stdexcept>
#include "client/screen/screen.h"
#include "client/sound/sound_manager.h"
#include "client/view/event_manager.h"
#include "client/view/main_player.h"
#include "client/view/view_object_creator.h"
#include "client/view/world_view_settings.h"
#include "common/entities/entity.h"

class WorldView {
public:
    WorldView(float32 world_width, float32 world_height);

    WorldView(const WorldView&) = delete;
    WorldView& operator=(const WorldView&) = delete;
    WorldView(WorldView&& other) = delete;
    WorldView& operator=(WorldView&& other) = delete;

    ~WorldView();

    void pollEvents();
    BlockingQueue& getQueue();
    bool quit() const;

    const ViewObjectCreator& getObjectCreator() const;

    void createEntities(const std::vector<Entity*>& entities);

    void updatePosition(size_t index, const Position& position);
    void updatePosition(const std::vector<Entity*>& entities);

    void update();

private:
    const size_t screen_width = 1024;
    const size_t screen_height = 768;
    EventManager event_manager;
    SoundManager sound_manager;
    Screen screen;
    WorldViewSettings settings;
    Background background;
    std::map<size_t, DrawableBox2D*> view_objects;
    MainPlayer * main_player = nullptr;
    ViewObjectCreator object_creator;

    void renderObjects();
    void checkValidIndex(size_t index);
    void createEntity(EntityType type, size_t id, const Position& initial);
    void createPlayerWithCamera(size_t id, const Position& position);
};

#endif  // WORLD_VIEW_H
