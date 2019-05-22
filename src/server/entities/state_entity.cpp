#include "server/entities/state_entity.h"

StateEntity::StateEntity(const EntityType type, const float x, const float y, const float angle, const State state) :
	MEntity(type, x, y, angle), state(state) {}
	
bool StateEntity::getState() const {
	return this->state;
}

void StateEntity::setState(const State state) {
	this->state = state;
}
void StateEntity::setState(const bool state) {
	this->state = state;
}