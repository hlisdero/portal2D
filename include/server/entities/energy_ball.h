#ifndef ENERGY_BALL_ENTITY_H
#define ENERGY_BALL_ENTITY_H

#include "server/entities/state_entity.h"
#include "server/entities/body_linked_entity.h"

// TODO load from file
#define ENERGY_BALL_SPEED 5.0f

class EnergyBallEntity : public MEntity, public BodyLinkedEntity {
public:
	EnergyBallEntity(const float intialX, const float intialY, const float angle);
};

#endif  // ENERGY_BALL_ENTITY_H