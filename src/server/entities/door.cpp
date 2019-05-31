#include "server/entities/door.h"

// TODO registerDoor to buttons

DoorEntity::DoorEntity(const float x, const float y, const float angle, DoorLogica * logica) :
	Entity(TYPE_GATE, x, y, angle), WithState(logica->value()),
	logica(logica) {}

DoorEntity::DoorEntity(YAML::Node yaml) :
Entity(TYPE_GATE, yaml),
WithState(STATE_CLOSED),
logica(loadDoorLogica(yaml["logica"])) {}

void DoorEntity::updateState() {
	this->setState(this->logica->value());
}

void DoorEntity::attach(subscribablesMap & subscribables) {
	this->logica->attach(this, subscribables);
}