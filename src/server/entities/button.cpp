#include "server/entities/button.h"

ButtonEntity::ButtonEntity(const float x, const float y) :
	Entity(TYPE_BUTTON, x, y, 0), WithState(STATE_DISABLED) {}

ButtonEntity::ButtonEntity(YAML::Node yaml) :
	Entity(TYPE_BUTTON, yaml), WithState(STATE_DISABLED) {}

void ButtonEntity::handleContactWith(Entity * other, b2Contact *, bool inContact) {
	if(other->getType() == TYPE_PLAYER || other->getType() == TYPE_ROCK) {
		// TODO enhance the detection
		this->setState(inContact ? STATE_ENABLED : STATE_DISABLED);
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
