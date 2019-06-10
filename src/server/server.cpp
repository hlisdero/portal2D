#include "server/server.h"

Server::Server(const std::string& map_name) :
    game(map_name, client_manager),
    passive_skt("8080") {
    passive_skt.bind();
    passive_skt.listen();
}

void Server::run() {
    int players = 0;
    while (players < game.getMinPlayers()) {
        ActiveSocket skt = passive_skt.accept();
        client_manager.addClient(std::move(skt));
        ++players;
    }
    game.init();
    client_manager.addSelectPlayer(0, game.getPlayerId());
    game.run();
}
