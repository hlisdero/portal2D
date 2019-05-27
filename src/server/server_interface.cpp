#include "server/server_interface.h"

ServerInterface::ServerInterface() : world(this->map), player(1.0f, 5.0f) {
	this->world.createPlayer(&this->player);
}

void ServerInterface::movePlayer(const MoveDirection direction, const bool pressed) {
	if(pressed) {
		this->player.keyDown(direction);
	} else {
		this->player.keyUp(direction);
	}
}

void ServerInterface::updatePhysics() {
	this->world.updatePhysics();
}

std::vector<Entity> ServerInterface::getStaticEntities() const {
	return this->world.getStaticEntities();
}

std::vector<Entity> ServerInterface::getDynamicEntities() const {
	return this->world.getDynamicEntities();
}
