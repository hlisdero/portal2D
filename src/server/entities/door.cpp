#include "server/entities/door.h"

// TODO registerDoor to buttons

DoorEntity::DoorEntity(const float x, const float y, const float angle, DoorLogica & logica) :
	StateEntity(TYPE_DOOR, x, y, angle, STATE_CLOSED),
	logica(logica) {}

void DoorEntity::updateState() {
	this->setState(this->logica.value());
}