#include "client2/client_interface.h"

ClientInterface::ClientInterface() : scene(800,600,10,6) {}

void ClientInterface::addHandler(KeyboardHandler * handler) {
	this->scene.addHandler(handler);
}

void ClientInterface::setEntities(const std::vector<MEntity> staticEntities, const std::vector<MEntity> dynamicEntities) {
	this->scene.setEntities(staticEntities, dynamicEntities);
}

void ClientInterface::setDynamicEntities(const std::vector<MEntity> dynamicEntities) {
	this->scene.setDynamicEntities(dynamicEntities);
}

bool ClientInterface::doQuit() {
	return this->scene.doQuit();
}

void ClientInterface::poolEvent() {
	this->scene.poolEvent();
}

void ClientInterface::updateScreen() {
	this->scene.updateScreen();
}

void ClientInterface::renderScreen() {
	this->scene.render();
}