#include "server/entities/rock.h"

RockEntity::RockEntity(YAML::Node yaml) :
	TeleportableEntity(TYPE_ROCK, yaml) {}
