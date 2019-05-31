#include "server/entities/energy_receiver.h"

EnergyReceiverEntity::EnergyReceiverEntity(const float x, const float y) :
	Entity(TYPE_ENERGY_RECEIVER, x, y, 0), WithSubscribableState(STATE_DISABLED) {}

EnergyReceiverEntity::EnergyReceiverEntity(YAML::Node yaml) :
	Entity(TYPE_ENERGY_RECEIVER, yaml), WithSubscribableState(STATE_DISABLED) {}

void EnergyReceiverEntity::handleContactWith(Entity * other, b2Contact *, bool) {
	if(other->getType() == TYPE_ENERGY_BALL) {
		this->setState(STATE_ENABLED);
	}
}
