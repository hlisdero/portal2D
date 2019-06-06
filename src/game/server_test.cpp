#include <iostream>
#include "common/protocol/protocol.h"
#include "common/socket/passive_socket.h"

int main() {
    PassiveSocket passive_skt("8080");
    passive_skt.bind();
    passive_skt.listen();
    while (true) {
        ActiveSocket skt = passive_skt.accept();
        Protocol protocol(std::move(skt));
        ViewEvent event = protocol.receiveViewEvent();
        if (event.type == KEYBOARD) {
            std::cout << "Tipo correcto!" << std::endl;
        }
        if (event.direction == UP) {
            std::cout << "Dirección correcta!" << std::endl;
        }
        if (event.pressed) {
            std::cout << "Pressed correcto!" << std::endl;
        }
        if (!event.repeat) {
            std::cout << "Repeat correcto!" << std::endl;
        }
        printf("%.10f\t%.10f\n", event.click_direction.x, event.click_direction.y);
        if (event.click_direction.x == 4.0 && event.click_direction.y == -2.0) {
            std::cout << "Dirección del click correcta!" << std::endl;
        }
    }

    return 0;
}
