#ifndef ENERGY_EMITTOR_ENTITY_H
#define ENERGY_EMITTOR_ENTITY_H

#include "server/entities/state_entity.h"
#include "server/entities/energy_ball.h"

class EnergyEmittorEntity : public MEntity {
public:
	EnergyEmittorEntity(const float x, const float y, const float angle);

	bool hasABall() const;
	void setNoBall();
	EnergyBallEntity * emit();
private:
	bool hasABall_;
};

#endif  // ENERGY_EMITTOR_ENTITY_H