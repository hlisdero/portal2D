#include "server/entities/door.h"

DoorEntity::DoorEntity(float x, float y, float rotation, DoorLogicaPtr logica, GameEventCreator & gameEventCreator) :
    Entity(TYPE_GATE, x, y, rotation),
    WithState(STATE_CLOSED, gameEventCreator),
    logica(std::move(logica)) {}

void DoorEntity::updateState() {
	bool new_state = this->logica->value();
	setState(new_state? STATE_OPEN : STATE_CLOSED);

	b2Filter filter;
	filter.maskBits = (new_state == STATE_OPEN) ? 0x0000 : 0xFFFF;
	this->getBody()->GetFixtureList()->SetFilterData(filter);
}

void DoorEntity::attachBody(b2Body * body) {
	BodyLinked::attachBody(body);

	updateState();
}

void DoorEntity::attach(subscribablesMap & subscribables) {
	this->logica->attach(this, subscribables);
}
