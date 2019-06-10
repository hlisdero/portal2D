#ifndef SERVER_H
#define SERVER_H

#include <vector>
#include "common/clock_loop.h"
#include "common/protocol/interface.h"
#include "common/events/view_event.h"
#include "common/events/world_event.h"

#include "server/game.h"
#include "server/entities/player.h"
#include "server/events/event_creator.h"

class Server {
public:
	Server(const char * mapName, ActiveSocket skt);

    Server(const Server&) = delete;
    Server& operator=(const Server&) = delete;
    Server(Server&& other) = delete;
    Server& operator=(Server&& other) = delete;

    void run();

    void processQueue();

private:
    Interface<WorldEvent, ViewEvent> interface;
	EventCreator eventCreator;
	Game game;
    bool quit = false;
};

#endif  // SERVER_H
