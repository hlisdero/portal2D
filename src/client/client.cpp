#include "client/client.h"

Client::Client(float world_width, float world_height) :
    interface(std::move(ActiveSocket("localhost", "8080"))),
    view(world_width, world_height, interface.getSendQueue()) {}

void Client::run() {
    ClockLoop<60> clock;
    while (true) {
        view.pollEvents();
        if (view.quit()) {
            break;
        }
        processQueue();

        clock.waitNextLoop();
    }
    sendQuitSignal();
}

void Client::processQueue() {
    BlockingQueue<WorldEvent>& queue = interface.getReceiveQueue();
    std::vector<WorldEvent> events = queue.popAll();
    for (const auto& event : events) {
        if (event.type == POSITION_UPDATE) {
            view.updatePosition(event.id, event.position);
        } else if (event.type == ENTITY_CREATION) {
            view.createEntity(event.id, event.entity_type, event.position);
        }
    }
    view.update();
}

void Client::sendQuitSignal() {
    BlockingQueue<ViewEvent>& queue = interface.getSendQueue();
    ViewEvent quit_event;
    quit_event.type = QUIT;
    queue.push(quit_event);
}
