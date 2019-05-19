#include "client2/client_interface.h"

ClientInterface::ClientInterface() : scene(640,480,40,20) {}

void ClientInterface::setEntities(const std::vector<MEntity> staticEntities, const std::vector<MEntity> dynamicEntities) {
	this->scene.setEntities(staticEntities, dynamicEntities);
}

void ClientInterface::setDynamicEntities(const std::vector<MEntity> dynamicEntities) {
	this->scene.setDynamicEntities(dynamicEntities);
}