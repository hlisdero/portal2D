#include "server/entities/energy_ball.h"

EnergyBallEntity::EnergyBallEntity(const float intialX, const float intialY, 
	const float angle, GameEventCreator & gameEventCreator) :
	TeleportableEntity(TYPE_ENERGY_BALL, intialX, intialY, 
		angle, gameEventCreator) {}