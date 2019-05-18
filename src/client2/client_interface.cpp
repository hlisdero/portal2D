#include "client2/client_interface.h"

ClientInterface::ClientInterface() {}

void ClientInterface::setEntities(const std::vector<Entity> staticEntities, const std::vector<Entity> dynamicEntities) {
	this->scene.setEntities(staticEntities, dynamicEntities);
}

void ClientInterface::setDynamicEntities(const std::vector<Entity> dynamicEntities) {
	this->scene.setDynamicEntities(dynamicEntities);
}