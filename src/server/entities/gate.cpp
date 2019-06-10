#include "server/entities/gate.h"

GateEntity::GateEntity(float x, float y, float rotation, GateLogicaPtr logica, GameEventCreator & gameEventCreator) :
    Entity(TYPE_GATE, x, y, rotation),
    WithState(STATE_CLOSED, gameEventCreator),
    logica(std::move(logica)),
    gameEventCreator(gameEventCreator) {}

void GateEntity::updateState() {
	State oldValue = getState();
	State newState = this->logica->value() ? STATE_OPEN : STATE_CLOSED;
	setState(newState);

	if(oldValue != newState) {
		gameEventCreator.addSetActiveEntity(this, (newState == STATE_CLOSED));
	}
}

void GateEntity::attachBody(b2Body * body) {
	BodyLinked::attachBody(body);

	updateState();
}

void GateEntity::attach(subscribablesMap & subscribables) {
	this->logica->attach(this, subscribables);
}
