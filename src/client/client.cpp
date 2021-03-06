#include "client/client.h"

Client::Client(const std::string& hostname, const std::string& port) :
    interface(std::move(ActiveSocket(hostname, port))),
    view(interface.getSendQueue()) {}

void Client::run() {
    ClockLoop<60> clock;
    while (!quit) {
        if (!interface.valid()) {
            throw std::runtime_error("El servidor se ha desconectado inesperadamente");
        }
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
    for (const WorldEvent& event : events) {
        processEvent(event);
    }
    view.update();
}

void Client::processEvent(const WorldEvent& event) {
    if (event.type == POSITION_UPDATE) {
        view.updatePosition(event.id, event.position);
    } else if (event.type == STATE_UPDATE) {
        view.updateState(event.id, event.state);
    } else if (event.type == ENTITY_CREATION) {
        view.createEntity(event.id, event.entity_type, event.position, event.state);
    } else if (event.type == ENTITY_DESTRUCTION) {
        view.destroyEntity(event.id);
    } else if (event.type == SELECT_PLAYER) {
        view.selectPlayer(event.id);
    } else if (event.type == END_GAME_VICTORY) {
        view.setVictory();
    } else if (event.type == END_GAME_DEFEAT) {
        view.setDefeat();
    }
}

void Client::sendQuitSignal() {
    BlockingQueue<ViewEvent>& queue = interface.getSendQueue();
    ViewEvent quit_event(view.getPlayerIndex(), QUIT);
    queue.push(quit_event);
}
