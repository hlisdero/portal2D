#include <iostream>
#include "common/protocol/interface.h"

int main() {
    ActiveSocket skt("localhost", "8080");
    skt.connect();
    Interface<ViewEvent, WorldEvent> interface(std::move(skt));

    ViewEvent event;
    event.type = KEYBOARD;
    event.direction = UP;
    event.pressed = true;
    event.repeat = false;
    event.click_direction = ClickDirection(4.0, -2.0);
    interface.send_queue.push(event);

    WorldEvent world_event = interface.receive_queue.pop();

    if (world_event.type == ENTITY_CREATION) {
        std::cout << "Tipo correcto!" << std::endl;
    }
    if (world_event.id == 4) {
        std::cout << "ID correcto!" << std::endl;
    }
    if (world_event.entity_type == TYPE_PORTAL) {
        std::cout << "Tipo de entidad correcto!" << std::endl;
    }
    if (world_event.position == Position(1.4, 1.5, 90)) {
        std::cout << "Posición correcta!" << std::endl;
    }
    if (world_event.state == STATE_DISABLED) {
        std::cout << "Estado correcto!" << std::endl;
    }
    return 0;
}
