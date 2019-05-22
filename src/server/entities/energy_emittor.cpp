#include "server/entities/energy_emittor.h"

EnergyEmittorEntity::EnergyEmittorEntity(const float x, const float y, const float angle) : 
	MEntity(TYPE_ENERGY_EMITTOR x, y, angle) {}

bool EnergyEmittorEntity::hasABall() const {
	return this->hasABall;
}

void EnergyEmittorEntity::setNoBall() {
	this->hasABall = false;
}

EnergyBallEntity * EnergyEmittorEntity::emit() {
	this->hasABall = true;
	return new EnergyBallEntity(this->getX(), this->getY(), this->getAngle());
}