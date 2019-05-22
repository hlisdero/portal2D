#ifndef ENERGY_RECEIVER_ENTITY_H
#define ENERGY_RECEIVER_ENTITY_H

#include "Box2D/Box2D.h"

#include "server/entities/state_entity.h"

class EnergyReceiverEntity : public StateEntity {
public:
	EnergyReceiverEntity(const float x, const float y);

	virtual void beginContactWith(MEntity * other, b2Contact * contact) override;
};

#endif  // ENERGY_RECEIVER_ENTITY_H