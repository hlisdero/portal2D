#include <iostream>
#include <stdexcept>
#include "client.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "Error: argumentos invalidos."
                  << std::endl;
        return 0;
    }

    try {
        Client client(argv[1], argv[2]);
        client.run();
        return 0;
    } catch(std::runtime_error err) {
        std::cout << err.what() << std::endl;
        return 1;
    }
}
