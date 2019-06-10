#include <iostream>
#include <stdexcept>
#include <string>
#include "server/server.h"

int main(int argc, char *argv[]) {
    std::string map_name = "../data/maps/map2.yaml";
    if (argc > 1) {
    	map_name = std::string(argv[1]);
    }
    try {
        Server server(map_name);
        server.run();
        return 0;
    } catch (std::runtime_error err) {
        std::cerr << err.what() << std::endl;
        return 1;
    }
}
