#include "server/server.h"

Server::Server(const char * mapName, ActiveSocket skt) :
	interface(std::move(skt)),
    eventCreator(interface.getSendQueue()),
    game(mapName, eventCreator) {
	game.addPlayer(&player);
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
            movePlayer(event.direction, event.pressed);
        } else if (event.type == MOUSE) {
            game.createPortal(player, event.click_direction);
        } else if (event.type == QUIT) {
            quit = true;
        }
    }
    game.update();
}

void Server::movePlayer(const MoveDirection direction, const bool pressed) {
	if (pressed) {
		player.keyDown(direction);
	} else {
		player.keyUp(direction);
	}
}
