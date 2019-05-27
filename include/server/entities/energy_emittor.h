#ifndef ENERGY_EMITTOR_ENTITY_H
#define ENERGY_EMITTOR_ENTITY_H

#include "common/entities/entity.h"
#include "server/entities/energy_ball.h"

class EnergyEmittorEntity : public Entity {
public:
	EnergyEmittorEntity(const float x, const float y, const float angle);
	EnergyEmittorEntity(YAML::Node yaml);

	bool hasABall() const;
	void setNoBall();
	EnergyBallEntity * emit();
private:
	bool hasABall_;
};

#endif  // ENERGY_EMITTOR_ENTITY_H
