#include <iostream>
#include <stdexcept>
#include "client/client.h"
#include "client/login/login.h"

int main(int argc, char *argv[]) {
    try {
        Login login;
        login.run(argc, argv);  // Comentar para usar defaults

        // Tamaño del mundo en metros 53.32 x 40
        Client client(login.getHostname(), login.getPort(), 53.32, 40);
        client.run();
        return 0;
    } catch(std::runtime_error err) {
        std::cerr << err.what() << std::endl;
        return 1;
    }
}
