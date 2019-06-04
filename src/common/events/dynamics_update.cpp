#include "common/events/dynamics_update.h"

DynamicsUpdateEvent::DynamicsUpdateEvent(std::vector<EntityPosition> entities) : WorldEvent(DYNAMICS_UPDATE), entities(entities) {}

const std::vector<EntityPosition> & DynamicsUpdateEvent::getUpdates() const {
	return this->entities;
}