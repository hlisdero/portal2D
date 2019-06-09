#include "server/entities/door.h"

DoorEntity::DoorEntity(float x, float y, float rotation, DoorLogicaPtr logica, GameEventCreator & gameEventCreator) :
    Entity(TYPE_GATE, x, y, rotation),
    WithState(STATE_CLOSED, gameEventCreator),
    logica(std::move(logica)),
    gameEventCreator(gameEventCreator) {}

void DoorEntity::updateState() {
	State oldValue = getState();
	State newState = this->logica->value() ? STATE_OPEN : STATE_CLOSED;
	setState(newState);

	if(oldValue != newState) {
		gameEventCreator.addSetActiveEntity(this, (newState == STATE_CLOSED));
	}
}

void DoorEntity::attachBody(b2Body * body) {
	BodyLinked::attachBody(body);

	updateState();
}

void DoorEntity::attach(subscribablesMap & subscribables) {
	this->logica->attach(this, subscribables);
}
