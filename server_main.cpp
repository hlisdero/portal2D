#include <iostream>
#include <stdexcept>
#include "server.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        return 1;
    }
    try {
        Server server(argv[1]);
        server.run();
        return 0;
    } catch(std::runtime_error err) {
        std::cerr << err.what() << std::endl;
        return 1;
    }
}
