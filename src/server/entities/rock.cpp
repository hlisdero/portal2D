#include "server/entities/rock.h"

RockEntity::RockEntity(float x, float y, float rotation, GameEventCreator & gameEventCreator) :
	TeleportableEntity(TYPE_ROCK, x, y, rotation, gameEventCreator), initialPosition(x, y) {}

void RockEntity::handleContactWith(Entity * other, b2Contact * contact, bool inContact) {
	TeleportableEntity::handleContactWith(other, contact, inContact);

	if(inContact && (other->getType() == TYPE_ENERGY_BAR ||
		other->getType() == TYPE_END_BARRIER)) {
		respawn();
	}
}

void RockEntity::grab(PlayerEntity * player) {
	// Disable body while keeping fixture created for future use.
	gameEventCreator.addSetActiveEntity(this, false);

	holder = player;
}

void RockEntity::release() {
	gameEventCreator.addSetActiveEntity(this, true);
	holder = nullptr;
}

PlayerEntity* RockEntity::getHolder() {
	return holder;
}

void RockEntity::respawn() {
	getBody()->SetLinearVelocity(b2Vec2(0.0f,0.0f));
	teleportTo(initialPosition);
}