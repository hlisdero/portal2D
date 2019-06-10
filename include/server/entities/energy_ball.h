#ifndef ENERGY_BALL_ENTITY_H
#define ENERGY_BALL_ENTITY_H

#include "server/entities/entity.h"
#include "server/entities/attributes/teleportable_entity.h"
#include "server/events/game_event_creator.h"

class EnergyBallEntity;

#include "server/entities/energy_emitter.h"

// TODO load from file
#define ENERGY_BALL_SPEED 2.0f

class EnergyBallEntity :  public TeleportableEntity {
public:
	EnergyBallEntity(const float intialX, const float intialY, const float angle, 
		GameEventCreator& gameEventCreator, EnergyEmitterEntity & owner);

	virtual void handleContactWith(Entity * other, b2Contact * contact, bool inContact) override;

	void notifyOwner();

private: 
	EnergyEmitterEntity & owner;
};

#endif  // ENERGY_BALL_ENTITY_H
