#include "server/server_interface.h"

ServerInterface::ServerInterface() : scene() {}

void ServerInterface::addPlayer() {
	this->scene.addPlayer();
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