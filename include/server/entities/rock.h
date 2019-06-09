#ifndef ROCK_ENTITY_H
#define ROCK_ENTITY_H

class RockEntity;

#include "server/entities/entity.h"
#include "server/entities/player.h"
#include "server/entities/attributes/teleportable_entity.h"

class RockEntity :  public TeleportableEntity {
public:
	// TODO add rock type
	RockEntity(float x, float y, float rotation);

	void grab(PlayerEntity * player);
	void release();

	PlayerEntity* getHolder();

	void respawn();
private:
	PlayerEntity* holder = nullptr;
	b2Vec2 initialPosition;
};

#endif  // ROCK_ENTITY_H
