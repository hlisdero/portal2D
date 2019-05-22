#include "server/entities/energy_emittor.h"

EnergyEmittorEntity::EnergyEmittorEntity(const float x, const float y, const float angle) : 
	MEntity(TYPE_ENERGY_EMITTOR, x, y, angle) {}

bool EnergyEmittorEntity::hasABall() const {
	return this->hasABall_;
}

void EnergyEmittorEntity::setNoBall() {
	this->hasABall_ = false;
}

EnergyBallEntity * EnergyEmittorEntity::emit() {
	this->hasABall_ = true;
	return new EnergyBallEntity(this->getX(), this->getY(), this->getAngle());
}