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
#include "server/objects/game_status.h"

class Game {
public:
	Game(const std::string& map_name, ClientManager& client_manager);

    size_t createPlayer();
    size_t getMinPlayers() const;

    void init();
    void run();
    void stop();
	void update();

private:
    std::queue<WorldEvent>& world_events;
    std::queue<ViewEvent>& view_events;
    ClientManager& client_manager;
    EventCreator event_creator;
    bool quit = false;

    // Lo anterior
	SafeQueue<GameEvent> eventsQueue;
	GameEventCreator gameEventCreator;
    Map map;
    World world;

    void processGameEvents();
    void processQueue();
    PortalColor stateToPortalColor(const State& state) const;
};

#endif  // GAME_H
