#include "server/entities/rock.h"

RockEntity::RockEntity(float x, float y, float rotation, GameEventCreator & gameEventCreator) :
	TeleportableEntity(TYPE_ROCK, x, y, rotation), initialPosition(x, y), gameEventCreator(gameEventCreator) {}

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
	setX(initialPosition.x);
	setY(initialPosition.y);
	markForPositionReset();
}