#include "server/server.h"

Server::Server(const std::string& map_name) :
    game(map_name, client_manager),
    passive_skt(SETTINGS.PORT) {
    passive_skt.bind();
    passive_skt.listen();
}

Server::~Server() {
    quit = true;
    passive_skt.shutdown();
    game.stop();
    main_thread.join();
}

void Server::run() {
    main_thread = std::thread(&Server::runGame, this);

    char c = 0;
    while (c != 'q' && !quit) {
        std::cin >> c;
    }
}

void Server::runGame() {
    size_t players = 0;
    while (players < game.getMinPlayers() && !quit) {
        ActiveSocket skt = passive_skt.accept();
        if (!skt.isValid()) {
            return;
        }
        client_manager.addClient(std::move(skt));
        ++players;
    }
    if (quit) {
        return;
    }
    game.init();
    game.run();
    quit = true;
}
