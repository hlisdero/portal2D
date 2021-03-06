#include "server/entities/rock.h"

#include "server/objects/server_settings.h"
extern ServerSettings SETTINGS;

RockEntity::RockEntity(float x, float y, float rotation, GameEventCreator & gameEventCreator) :
	TeleportableEntity(TYPE_ROCK, x, y, rotation, gameEventCreator), initialPosition(x, y) {}

void RockEntity::handleContactWith(Entity * other, b2Contact * contact, bool inContact) {
	TeleportableEntity::handleContactWith(other, contact, inContact);

	if(inContact &&
		(other->getType() == TYPE_ENERGY_BAR ||
		other->getType() == TYPE_ACID ||
		other->getType() == TYPE_END_BARRIER)) {
		respawn();
	}
}

void RockEntity::grab(PlayerEntity * player) {
	// Disable body while keeping fixture created for future use.
	gameEventCreator.addSetActiveEntity(this, false);

	holder = player;
}

void RockEntity::release(MoveDirection direction) {
	float newX = holder->getX();

	if(direction != NONE) {
		float holderVelocityX = holder->getBody()->GetLinearVelocity().x;

		if(holderVelocityX != 0) {
			direction = holderVelocityX > 0 ? RIGHT : LEFT;
		}

		if(direction == RIGHT) {
			newX = holder->getX() + SETTINGS.RELEASE_ROCK_DISTANCE;
		} else {
			newX = holder->getX() + -1 * SETTINGS.RELEASE_ROCK_DISTANCE;
		}
	}

	resetVelocity();
	teleportTo(newX, holder->getY());
	
	holder = nullptr;
	gameEventCreator.addSetActiveEntity(this, true);
}

PlayerEntity* RockEntity::getHolder() {
	return holder;
}

void RockEntity::resetVelocity() {
	getBody()->SetLinearVelocity(b2Vec2(0.0f,0.0f));
	getBody()->SetAngularVelocity(0);

}

void RockEntity::respawn() {
	resetVelocity();
	teleportTo(initialPosition.x, initialPosition.y);
	gameEventCreator.addRockRespawn(this);
}