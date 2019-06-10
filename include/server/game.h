#ifndef GAME_H
#define GAME_H

#include <vector>
#include <queue>
#include <string>
#include <stdexcept>
#include "common/clock_loop.h"
#include "server/client_manager.h"
#include "server/map.h"
#include "server/events/event_creator.h"
#include "server/entities/player.h"
#include "server/physics/world.h"
#include "server/events/game_event_creator.h"

class Game {
public:
	Game(const std::string& map_name, ClientManager& client_manager);

    int getPlayerId() const;
    int getMinPlayers() const;

    void init();
    void run();
	void update();

private:
    std::queue<WorldEvent>& world_events;
    std::queue<ViewEvent>& view_events;
    ClientManager& client_manager;
    EventCreator event_creator;
    bool quit = false;
    int player_id;

    // Lo anterior
	SafeQueue<GameEvent> eventsQueue;
	GameEventCreator gameEventCreator;
    Map map;
    World world;
    PlayerEntity player;

    void processGameEvents();
    void processQueue();
    int findPlayerId();
};

#endif  // GAME_H
