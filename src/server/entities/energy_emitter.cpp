#include "server/entities/energy_emitter.h"

EnergyEmitterEntity::EnergyEmitterEntity(float x, float y, float rotation) :
    Entity(TYPE_ENERGY_EMITTER, x, y, rotation) {}

bool EnergyEmitterEntity::hasABall() const {
	return this->hasABall_;
}

void EnergyEmitterEntity::setNoBall() {
	this->hasABall_ = false;
}

EnergyBallEntity * EnergyEmitterEntity::emit() {
	this->hasABall_ = true;
	// TODO
	// return new EnergyBallEntity(this->getX(), this->getY(), this->getRotationDeg());
	return nullptr;
}
