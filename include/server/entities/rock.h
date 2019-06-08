#ifndef ROCK_ENTITY_H
#define ROCK_ENTITY_H

#include "common/entities/entity.h"
#include "server/entities/attributes/body_linked.h"

class RockEntity :  public Entity, public BodyLinked {
public:
	// TODO add rock type
	RockEntity(float x, float y, float rotation);

	// TODO
	//void respawn();
};

#endif  // ROCK_ENTITY_H
