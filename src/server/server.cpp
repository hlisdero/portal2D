#include "server/server.h"

Server::Server(const char * mapName) :
	eventCreator(queue), game(mapName, eventCreator) {
	game.addPlayer(&player);
    eventCreator.addEntityCreations(game.getStaticEntities());
    eventCreator.addEntityCreations(game.getDynamicEntities());
}

BlockingQueue<WorldEvent>& Server::getQueue() {
	return queue;
}

void Server::update() {
	game.update();
}

void Server::processQueue(BlockingQueue<ViewEvent>& queue) {
    while (!queue.empty()) {
        ViewEvent event = queue.pop();
        if (event.type == KEYBOARD) {
            movePlayer(event.direction, event.pressed);
        } else if (event.type == MOUSE) {
            createPortal(event.click_direction);
        }
    }
}

void Server::movePlayer(const MoveDirection direction, const bool pressed) {
	if (pressed) {
		player.keyDown(direction);
	} else {
		player.keyUp(direction);
	}
}

void Server::createPortal(ClickDirection& direction) {
	game.createPortal(player, direction);
}
