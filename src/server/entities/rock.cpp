#include "server/entities/rock.h"

RockEntity::RockEntity(YAML::Node yaml) :
	Entity(TYPE_ROCK, yaml) {}
