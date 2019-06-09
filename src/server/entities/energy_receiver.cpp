#include "server/entities/energy_receiver.h"

EnergyReceiverEntity::EnergyReceiverEntity(float x, float y, float rotation) :
	Entity(TYPE_ENERGY_RECEIVER, x, y, rotation), WithSubscribableState(STATE_DISABLED) {}

void EnergyReceiverEntity::handleContactWith(Entity * other, b2Contact *, bool) {
	if(other->getType() == TYPE_ENERGY_BALL) {
		setState(STATE_ENABLED);
	}
}
