#include "server/entities/rock.h"

RockEntity::RockEntity(const float intialX, const float intialY) :
	Entity(TYPE_ROCK, intialX, intialY, 0) {}

RockEntity::RockEntity(YAML::Node yaml) :
	Entity(TYPE_ROCK, yaml) {}
