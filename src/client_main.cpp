#include <iostream>
#include <stdexcept>
#include <string>
#include "client/client.h"
#include "client/login/login.h"

int main(/*int argc, char *argv[]*/) {
    try {
        Login login;
        // login.run(argc, argv);
        // Tamaño del mundo en metros 13,335 x 10,00125
        Client client(login.getHostname(), login.getPort(), 13.335, 10.00125);
        client.run();
        return 0;
    } catch (std::runtime_error err) {
        std::cerr << err.what() << std::endl;
        return 1;
    }
}
