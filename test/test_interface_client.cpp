#include <iostream>
#include "common/protocol/interface.h"

int main() {
    ActiveSocket skt("localhost", "8080");
    Interface<ViewEvent, WorldEvent> interface(std::move(skt));
    BlockingQueue<ViewEvent>& view_event_queue = interface.getSendQueue();
    BlockingQueue<WorldEvent>& world_event_queue = interface.getReceiveQueue();

    ViewEvent event;
    event.type = MOVE;
    event.direction = UP;
    event.pressed = true;
    event.repeat = false;
    event.click_direction = ClickDirection(4.0, -2.0);
    view_event_queue.push(event);

    WorldEvent world_event = world_event_queue.pop();

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

    interface.closeWait();
    return 0;
}
