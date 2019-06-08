#include "server/entities/door.h"

DoorEntity::DoorEntity(float x, float y, float rotation, DoorLogicaPtr logica) :
    Entity(TYPE_GATE, x, y, rotation),
    WithState(STATE_CLOSED),
    logica(std::move(logica)) {}

void DoorEntity::updateState() {
	bool newState = this->logica->value();
	this->setState(newState);

	b2Filter filter;
	filter.maskBits = (newState == STATE_OPENED) ? 0x0000 : 0xFFFF;
	this->getBody()->GetFixtureList()->SetFilterData(filter);
}

void DoorEntity::attachBody(b2Body * body) {
	BodyLinked::attachBody(body);

	updateState();
}

void DoorEntity::attach(subscribablesMap & subscribables) {
	this->logica->attach(this, subscribables);
}
