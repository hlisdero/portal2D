#ifndef ROCK_ENTITY_H
#define ROCK_ENTITY_H

#include "server/entities/state_entity.h"
#include "server/entities/body_linked_entity.h"

class RockEntity : public MEntity, public BodyLinkedEntity {
public:
	// TODO add rock type
	RockEntity(const float intialX, const float intialY);

	// TODO
	//void respawn();
};

#endif  // ROCK_ENTITY_H