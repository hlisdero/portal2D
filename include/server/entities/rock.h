#ifndef ROCK_ENTITY_H
#define ROCK_ENTITY_H

#include "server/entities/entity.h"
#include "server/entities/player.h"
#include "server/entities/attributes/teleportable_entity.h"
#include "server/events/game_event_creator.h"

class PlayerEntity;

class RockEntity :  public TeleportableEntity {
public:
	// TODO add rock type
	RockEntity(float x, float y, float rotation, GameEventCreator & GameEventCreator);

	virtual void handleContactWith(Entity * other, b2Contact * contact, bool inContact) override;

	void grab(PlayerEntity * player);
	void release(MoveDirection direction);

	PlayerEntity* getHolder();

	void respawn();

private:
	PlayerEntity* holder = nullptr;
	b2Vec2 initialPosition;
};

#endif  // ROCK_ENTITY_H
