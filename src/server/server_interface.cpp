#include "server/server_interface.h"

ServerInterface::ServerInterface() : scene(), player(1.0f, 0.0f) {
	this->scene.createPlayer(this->player);
}

void ServerInterface::movePlayer(const MoveDirection direction) {
	this->player.move(direction);
}

void ServerInterface::updatePhysics() {
	this->scene.updatePhysics();
}

std::vector<Entity> ServerInterface::getStaticEntities() const {
	return this->scene.getStaticEntities();
}

std::vector<Entity> ServerInterface::getDynamicEntities() const {
	return this->scene.getDynamicEntities();
}