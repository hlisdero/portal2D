#ifndef SERVER_H
#define SERVER_H

#include <string>
#include <thread>
#include <iostream>
#include "common/socket/passive_socket.h"
#include "server/game.h"
#include "server/client_manager.h"
#include "server/events/event_creator.h"
#include "server/objects/server_settings.h"

extern ServerSettings SETTINGS;

class Server {
public:
	explicit Server(const std::string& map_name);

    Server(const Server&) = delete;
    Server& operator=(const Server&) = delete;
    Server(Server&& other) = delete;
    Server& operator=(Server&& other) = delete;

    ~Server();

    void run();

private:
    std::thread main_thread;
    bool quit = false;
    ClientManager client_manager;
	Game game;
    PassiveSocket passive_skt;

    void runGame();
};

#endif  // SERVER_H
