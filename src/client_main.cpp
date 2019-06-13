#include <iostream>
#include <stdexcept>
#include <string>
#include "client/client.h"
#include "client/login/login.h"

int main(int argc, char *argv[]) {
    try {
        Login login;
        login.run(argc, argv);
        Client client(login.getHostname(), login.getPort());
        client.run();
        return 0;
    } catch (std::runtime_error err) {
        std::cerr << err.what() << std::endl;
        return 1;
    }
}
