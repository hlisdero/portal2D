#include "server/entities/rock.h"

RockEntity::RockEntity(YAML::Node yaml) :
	TeleportableEntity(TYPE_ROCK, yaml), initialPosition(getX(), getY()) {}

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