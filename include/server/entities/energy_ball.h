#ifndef ENERGY_BALL_ENTITY_H
#define ENERGY_BALL_ENTITY_H

#include "server/entities/entity.h"
#include "server/entities/attributes/teleportable_entity.h"

// TODO load from file
#define ENERGY_BALL_SPEED 5.0f

class EnergyBallEntity :  public TeleportableEntity {
public:
	EnergyBallEntity(const float intialX, const float intialY, const float angle);
};

#endif  // ENERGY_BALL_ENTITY_H
