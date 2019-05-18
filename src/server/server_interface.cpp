#include "server/server_interface.h"

ServerInterface::ServerInterface() : scene(), player(1.0f, 0.0f) {
	this->scene.createPlayer(this->player);
}

void ServerInterface::movePlayer(MoveDirection direction) {
	this->player.move(direction);
}

void ServerInterface::updatePhysics() {
	this->scene.updatePhysics();
}

std::vector<Entity> ServerInterface::getStaticEntities() {
	return this->scene.getStaticEntities();
}

std::vector<Entity> ServerInterface::getDynamicEntities() {
	return this->scene.getDynamicEntities();
}