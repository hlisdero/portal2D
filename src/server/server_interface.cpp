#include "server/server_interface.h"

ServerInterface::ServerInterface() : scene() {}

void ServerInterface::addPlayer() {
	this->scene.addPlayer();
}

void ServerInterface::updatePhysics() {
	this->scene.updatePhysics();
}