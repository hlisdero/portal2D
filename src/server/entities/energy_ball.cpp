#include "server/entities/energy_ball.h"

#include "server/entities/energy_receiver.h"

EnergyBallEntity::EnergyBallEntity(const float intialX, const float intialY, 
	const float angle, GameEventCreator & gameEventCreator, EnergyEmitterEntity & owner) :
	TeleportableEntity(TYPE_ENERGY_BALL, intialX, intialY, 
		angle, gameEventCreator), owner(owner) {}

void EnergyBallEntity::handleContactWith(Entity * other, b2Contact * contact, bool inContact) {
	TeleportableEntity::handleContactWith(other, contact, inContact);

	if(isGoingThroughPortal() ||
		other->getType() >= DYNAMIC_ENTITY_START ||
		other->getType() == TYPE_PORTAL ||
		other->getType() == TYPE_ENERGY_BAR) {
		return;
	}

	if(other == &owner && justEmitted) {
		justEmitted = inContact;
		return;
	}

	if(other->getType() == TYPE_ENERGY_RECEIVER) {
		other->as<EnergyReceiverEntity>()->setState(STATE_ENABLED);
	}

	owner.setNoBall();
	gameEventCreator.addBallDestruction(this);
}