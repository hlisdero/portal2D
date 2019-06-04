#ifndef ROCK_ENTITY_H
#define ROCK_ENTITY_H

#include "common/entities/entity.h"
#include "server/entities/body_linked.h"

class RockEntity :  public Entity, public BodyLinked {
public:
	// TODO add rock type
	RockEntity(YAML::Node yaml);

	// TODO
	//void respawn();
};

#endif  // ROCK_ENTITY_H
