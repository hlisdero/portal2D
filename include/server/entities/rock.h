#ifndef ROCK_ENTITY_H
#define ROCK_ENTITY_H

#include "common/entities/entity.h"
#include "server/entities/attributes/teleportable_entity.h"

class RockEntity :  public TeleportableEntity {
public:
	// TODO add rock type
	RockEntity(YAML::Node yaml);

	// TODO
	//void respawn();
};

#endif  // ROCK_ENTITY_H
