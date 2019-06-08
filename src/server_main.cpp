#include <iostream>
#include <stdexcept>
#include "server/server.h"
#include "common/socket/passive_socket.h"

int main(int argc, char *argv[]) {
    const char * mapName = "../data/maps/map2.yaml";
    if (argc > 1) {
    	mapName = argv[1];
    }
    // Solución MAL DISEÑADA! Hay que poner todo dentro de Server!
    try {
        PassiveSocket passive_skt("8080");
        passive_skt.bind();
        passive_skt.listen();

        ActiveSocket skt = passive_skt.accept();
        Server server(mapName, std::move(skt));
        server.run();
        return 0;
    } catch(std::runtime_error err) {
        std::cerr << err.what() << std::endl;
        return 1;
    }
}
