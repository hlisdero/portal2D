#ifndef ENERGY_BALL_ENTITY_H
#define ENERGY_BALL_ENTITY_H

#include "server/entities/entity.h"
#include "server/entities/attributes/teleportable_entity.h"
#include "server/events/game_event_creator.h"
#include "server/objects/server_settings.h"

class EnergyBallEntity;

#include "server/entities/energy_emitter.h"

class EnergyBallEntity :  public TeleportableEntity {
public:
	EnergyBallEntity(const float intialX, const float intialY, const float angle, 
		GameEventCreator& gameEventCreator, EnergyEmitterEntity & owner);

	virtual void handleContactWith(Entity * other, b2Contact * contact, bool inContact) override;

private: 
	EnergyEmitterEntity & owner;
	bool justEmitted = true;

	void evaluateCollision(b2Contact * contact);
};

#endif  // ENERGY_BALL_ENTITY_H
