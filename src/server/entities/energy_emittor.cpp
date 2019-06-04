#include "server/entities/energy_emittor.h"

EnergyEmittorEntity::EnergyEmittorEntity(YAML::Node yaml) :
Entity(TYPE_ENERGY_EMITTER, yaml) {}

bool EnergyEmittorEntity::hasABall() const {
	return this->hasABall_;
}

void EnergyEmittorEntity::setNoBall() {
	this->hasABall_ = false;
}

EnergyBallEntity * EnergyEmittorEntity::emit() {
	this->hasABall_ = true;
	return new EnergyBallEntity(this->getX(), this->getY(), this->getRotationDeg());
}
