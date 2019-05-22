#include "server/entities/energy_receiver.h"

EnergyReceiverEntity(const float x, const float y) :
	StateEntity(TYPE_ENERGY_RECEIVER, x, y, 0, STATE_DISABLED) {}

void EnergyReceiverEntity::beginContactWith(MEntity * other, b2Contact * contact) {
	if(other->getType() == TYPE_ENERGY_BALL) {
		this->setState(STATE_ENABLED);
	}
}