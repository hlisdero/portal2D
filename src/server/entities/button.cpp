#include "server/entities/button.h"

ButtonEntity::ButtonEntity(float x, float y, float rotation, GameEventCreator & gameEventCreator) :
	Entity(TYPE_BUTTON, x, y, rotation), WithSubscribableState(STATE_DISABLED, gameEventCreator) {}

void ButtonEntity::handleContactWith(Entity * other, b2Contact * contact, bool inContact) {
	if (other->getType() != TYPE_PLAYER && other->getType() != TYPE_ROCK) {
		return;
	}

	if(inContact) {
		contacts.insert(contact);
	} else {
		contacts.erase(contact);
	}

	setState(contacts.size() > 0 ? STATE_ENABLED : STATE_DISABLED);
}
