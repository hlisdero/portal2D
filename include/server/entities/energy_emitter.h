#ifndef ENERGY_EMITTER_ENTITY_H
#define ENERGY_EMITTER_ENTITY_H

#include "server/entities/entity.h"
#include "server/entities/energy_ball.h"

class EnergyEmitterEntity : public Entity {
public:
    EnergyEmitterEntity(float x, float y, float rotation);

	bool hasABall() const;
	void setNoBall();
	EnergyBallEntity * emit();
private:
	bool hasABall_;
};

#endif  // ENERGY_EMITTER_ENTITY_H
