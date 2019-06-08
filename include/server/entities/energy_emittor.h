#ifndef ENERGY_EMITTOR_ENTITY_H
#define ENERGY_EMITTOR_ENTITY_H

#include "server/entities/entity.h"
#include "server/entities/energy_ball.h"

class EnergyEmittorEntity : public Entity {
public:
    EnergyEmittorEntity(float x, float y, float rotation);

	bool hasABall() const;
	void setNoBall();
	EnergyBallEntity * emit();
private:
	bool hasABall_;
};

#endif  // ENERGY_EMITTOR_ENTITY_H
