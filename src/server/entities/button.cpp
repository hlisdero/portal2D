#include "server/entities/button.h"

ButtonEntity::ButtonEntity(const float x, const float y) : 
	StateEntity(TYPE_BUTTON, x, y, 0, STATE_DISABLED) {}

void ButtonEntity::beginContactWith(MEntity * other, b2Contact *) {
	if(other->getType() == TYPE_PLAYER || other->getType() == TYPE_ROCK) {
		// TODO enhance the detection
		this->setState(STATE_ENABLED);
	}
}

void ButtonEntity::endContactWith(MEntity * other, b2Contact *) {
	if(other->getType() == TYPE_PLAYER || other->getType() == TYPE_ROCK) {
		this->setState(STATE_DISABLED);
	}
}

void ButtonEntity::registerDoor(DoorEntity * door) {
	this->doors.push_back(door);
}

void ButtonEntity::broadcastChange() {
	for(uint i = 0; i < this->doors.size(); i++) {
		this->doors[i]->updateState();
	}
}