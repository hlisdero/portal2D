#include <iostream>
#include "common/protocol/protocol.h"
#include "common/socket/passive_socket.h"

int main() {
    PassiveSocket passive_skt("8080");
    passive_skt.bind();
    passive_skt.listen();

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

    WorldEvent world_event;
    world_event.type = ENTITY_CREATION;
    world_event.id = 4;
    world_event.entity_type = TYPE_PORTAL;
    world_event.position = Position(1.4, 1.5, 90);
    world_event.state = STATE_DISABLED;
    protocol.send(world_event);
    
    return 0;
}
