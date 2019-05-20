#include "server/server_interface.h"

ServerInterface::ServerInterface() : scene(), player(5.0f, 5.0f) {
	this->scene.createPlayer(this->player);
}

void ServerInterface::movePlayer(const MoveDirection direction) {
	this->player.keyDown(direction);
}

void ServerInterface::updatePhysics() {
	this->scene.updatePhysics();
}

std::vector<MEntity> ServerInterface::getStaticEntities() const {
	return this->scene.getStaticEntities();
}

std::vector<MEntity> ServerInterface::getDynamicEntities() const {
	return this->scene.getDynamicEntities();
}