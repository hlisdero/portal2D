#include "server/entities/door.h"

// TODO registerDoor to buttons

DoorEntity::DoorEntity(const float x, const float y, const float angle, DoorLogica & logica) :
	Entity(TYPE_DOOR, x, y, angle), WithState(STATE_CLOSED),
	logica(logica) {}

void DoorEntity::updateState() {
	this->setState(this->logica.value());
}