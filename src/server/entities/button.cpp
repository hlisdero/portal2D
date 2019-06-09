#include "server/entities/button.h"

ButtonEntity::ButtonEntity(float x, float y, float rotation, GameEventCreator & gameEventCreator) :
	Entity(TYPE_BUTTON, x, y, rotation), WithSubscribableState(STATE_DISABLED, gameEventCreator) {}

void ButtonEntity::handleContactWith(Entity * other, b2Contact *, bool inContact) {
	if (other->getType() == TYPE_PLAYER || other->getType() == TYPE_ROCK) {
		// TODO enhance the detection
		setState(inContact ? STATE_ENABLED : STATE_DISABLED);
	}
}
