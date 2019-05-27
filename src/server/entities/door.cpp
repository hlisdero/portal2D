#include "server/entities/door.h"

// TODO registerDoor to buttons

DoorEntity::DoorEntity(const float x, const float y, const float angle, DoorLogica * logica) :
	Entity(TYPE_DOOR, x, y, angle), WithState(logica->value()),
	logica(logica) {}

DoorEntity::DoorEntity(YAML::Node yaml) :
Entity(TYPE_DOOR, yaml),
WithState(STATE_CLOSED),
// TODO logica
logica(nullptr) {
	this->setState(logica->value());
}

void DoorEntity::updateState() {
	this->setState(this->logica->value());
}