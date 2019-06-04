#include "server/entities/energy_receiver.h"

EnergyReceiverEntity::EnergyReceiverEntity(YAML::Node yaml) :
	Entity(TYPE_ENERGY_RECEIVER, yaml), WithSubscribableState(STATE_DISABLED) {}

void EnergyReceiverEntity::handleContactWith(Entity * other, b2Contact *, bool) {
	if(other->getType() == TYPE_ENERGY_BALL) {
		this->setState(STATE_ENABLED);
	}
}
