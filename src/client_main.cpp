#include <iostream>
#include <stdexcept>
#include <string>
#include "client/client.h"
#include "client/login/login.h"

int main(/*int argc, char *argv[]*/) {
    try {
        Login login;
        // login.run(argc, argv);
        // Tamaño del mundo en metros 53.32 x 40
        Client client(login.getHostname(), login.getPort(), 17.78, 13.33);
        client.run();
        return 0;
    } catch (std::runtime_error err) {
        std::cerr << err.what() << std::endl;
        return 1;
    }
}
