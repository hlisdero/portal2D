#include "server/server.h"

Server::Server(const char * mapName, ActiveSocket skt) :
	interface(std::move(skt)),
    eventCreator(interface.getSendQueue()),
    game(mapName, eventCreator) {
	game.addPlayer(&game.player);
    eventCreator.addEntityCreations(game.getStaticEntities());
    eventCreator.addEntityCreations(game.getDynamicEntities());
}

void Server::run() {
    ClockLoop<60> clock;
    while (!quit) {
        processQueue();
        clock.waitNextLoop();
    }
}

void Server::processQueue() {
    BlockingQueue<ViewEvent>& queue = interface.getReceiveQueue();
    std::vector<ViewEvent> events = queue.popAll();
    for (auto& event : events) {
        if (event.type == KEYBOARD) {
            game.movePlayer(event.direction, event.pressed);
        } else if (event.type == MOUSE) {
            game.createPortal(game.player, event.click_direction);
        } else if (event.type == QUIT) {
            quit = true;
        }
    }
    game.update();
}
