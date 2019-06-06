#include "client/client.h"

Client::Client(float world_width, float world_height) :
    view(world_width, world_height) {
}

void Client::createInitialView(BlockingQueue<WorldEvent>& queue) {
    while (!queue.empty()) {
        WorldEvent event = queue.pop();
        if (event.type == ENTITY_CREATION) {
            view.createEntity(event.id, event.entity_type, event.position);
        } else {
            throw std::runtime_error("Error al crear el mundo: "
                                     "la cola del servidor tiene eventos inválidos");
        }
    }
    view.update();
}

void Client::processQueue(BlockingQueue<WorldEvent>& queue) {
    while (!queue.empty()) {
        WorldEvent event = queue.pop();
        if (event.type == POSITION_UPDATE) {
            view.updatePosition(event.id, event.position);
        } else if (event.type == ENTITY_CREATION) {
            view.createEntity(event.id, event.entity_type, event.position);
        }
    }
    view.update();
}

void Client::pollEvents() {
    view.pollEvents();
}

BlockingQueue<ViewEvent>& Client::getQueue() {
    return view.getQueue();
}

bool Client::quit() const {
    return view.quit();
}
