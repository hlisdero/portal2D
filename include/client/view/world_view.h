#ifndef WORLD_VIEW_H
#define WORLD_VIEW_H

#include <map>
#include <stdexcept>
#include "client/client_settings.h"
#include "client/screen/screen.h"
#include "client/sound/sound_manager.h"
#include "client/view/camera_manager.h"
#include "client/view/event_manager.h"
#include "client/view/main_player.h"
#include "client/view/view_object_creator.h"
#include "client/view/world_view_settings.h"

extern ClientSettings CLIENT_SETTINGS;

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

    void createEntity(size_t index, EntityType type,
                      const Position& initial, const State& state);
    void destroyEntity(size_t index);

    void updatePosition(size_t index, const Position& position);
    void updateState(size_t index, const State& state);
    void selectPlayer(size_t index);

    void update();

    void setVictory();
    void setDefeat();

private:
    EventManager event_manager;
    SoundManager sound_manager;
    Screen screen;
    CameraManager camera_manager;
    WorldViewSettings settings;
    Background background;
    std::map<size_t, DrawableBox2D*> view_objects;
    std::vector<indexedDrawable> dead_view_objects;
    ViewObjectCreator object_creator;
    MainPlayer * main_player = nullptr;
    bool victory = false;
    bool defeat = false;

    void renderObjects();
    void renderTexture(const std::string& name);
};

#endif  // WORLD_VIEW_H
