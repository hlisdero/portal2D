#include "server/entities/rock.h"

RockEntity::RockEntity(float x, float y, float rotation) :
	TeleportableEntity(TYPE_ROCK, x, y, rotation), initialPosition(x, y) {}

void RockEntity::grab(PlayerEntity * player) {
	// Disable body while keeping fixture created for future use.
	getBody()->SetActive(false);

	holder = player;
}

void RockEntity::release() {
	getBody()->SetActive(true);
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