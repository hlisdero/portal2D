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
#include "common/objects/size.h"

class WorldView {
public:
    WorldView(BlockingQueue<ViewEvent>& queue);

    WorldView(const WorldView&) = delete;
    WorldView& operator=(const WorldView&) = delete;
    WorldView(WorldView&& other) = delete;
    WorldView& operator=(WorldView&& other) = delete;

    ~WorldView();

    void pollEvents();
    bool quit() const;

    const ViewObjectCreator& getObjectCreator() const;
    int getPlayerIndex() const;

    void createEntity(size_t index, EntityType type, const Position& initial);
    void destroyEntity(size_t index);

    void updatePosition(size_t index, const Position& position);
    void updateState(size_t index, const State& state);
    void selectPlayer(size_t index);

    void update();

    void setWorldSize(const Size & size);

private:
    EventManager event_manager;
    SoundManager sound_manager;
    Screen screen;
    WorldViewSettings settings;
    Background background;
    std::map<size_t, DrawableBox2D*> view_objects;
    MainPlayer * main_player = nullptr;
    ViewObjectCreator object_creator;

    void renderObjects();
};

#endif  // WORLD_VIEW_H
