#include <iostream>
#include <stdexcept>
#include "client/client.h"

int main() {
    try {
        // World size in meter 53.32 x 40
        Client client(53.32, 40);
        client.run();
        return 0;
    } catch(std::runtime_error err) {
        std::cerr << err.what() << std::endl;
        return 1;
    }
}
