#include "server/entities/energy_receiver.h"

EnergyReceiverEntity::EnergyReceiverEntity(float x, float y, float rotation, GameEventCreator & gameEventCreator) :
	Entity(TYPE_ENERGY_RECEIVER, x, y, rotation), WithSubscribableState(STATE_DISABLED, gameEventCreator) {}