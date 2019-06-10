#ifndef SERVER_H
#define SERVER_H

#include <string>
#include "common/socket/passive_socket.h"
#include "server/game.h"
#include "server/client_manager.h"
#include "server/events/event_creator.h"

class Server {
public:
	Server(const std::string& map_name);

    Server(const Server&) = delete;
    Server& operator=(const Server&) = delete;
    Server(Server&& other) = delete;
    Server& operator=(Server&& other) = delete;

    void run();

private:
    ClientManager client_manager;
	Game game;
    PassiveSocket passive_skt;
    bool quit = false;
};

#endif  // SERVER_H
