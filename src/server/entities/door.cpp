#include "server/entities/door.h"

// TODO registerDoor to buttons

DoorEntity::DoorEntity(const float x, const float y, const float angle, DoorLogica * logica) :
	Entity(TYPE_GATE, x, y, angle), WithState(logica->value()),
	logica(logica) {}

DoorEntity::DoorEntity(YAML::Node yaml) :
Entity(TYPE_GATE, yaml),
WithState(STATE_CLOSED),
logica(loadDoorLogica(yaml["logica"])) {}

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