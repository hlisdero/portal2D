#include <iostream>
#include <stdexcept>
#include "client.h"

int main() {
    try {
        // Hardcodeamos los parámetros para facilitar pruebas
        Client client("localhost", "2000");
        client.run();
        return 0;
    } catch(std::runtime_error err) {
        std::cout << err.what() << std::endl;
        return 1;
    }
}
