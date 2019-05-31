#include "server/entities/button.h"

ButtonEntity::ButtonEntity(const float x, const float y) :
	Entity(TYPE_BUTTON, x, y, 0), WithSubscribableState(STATE_DISABLED) {}

ButtonEntity::ButtonEntity(YAML::Node yaml) :
	Entity(TYPE_BUTTON, yaml), WithSubscribableState(STATE_DISABLED) {}

void ButtonEntity::handleContactWith(Entity * other, b2Contact *, bool inContact) {
	if(other->getType() == TYPE_PLAYER || other->getType() == TYPE_ROCK) {
		// TODO enhance the detection
		this->setState(inContact ? STATE_ENABLED : STATE_DISABLED);
	}
}