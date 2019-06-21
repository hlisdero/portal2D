#include <iostream>
#include <stdexcept>
#include <string>

#include "server/server.h"
#include "server/objects/server_settings.h"

int main(int argc, char *argv[]) {
    std::string map_name = MAPS_DIRECTORY + SETTINGS.DEFAULT_MAP;
    if (argc > 1) {
    	map_name = std::string(argv[1]);
    }

    try {
        Server server(map_name);
        server.run();
    } catch (const std::runtime_error& err) {
        std::cerr << err.what() << std::endl;
        return 1;
    }

    return 0;
}
