#include "server/entities/attributes/with_state.h"

WithState::WithState(const State state, GameEventCreator & gameEventCreator) : state(state), gameEventCreator(gameEventCreator) {}
WithState::WithState(const bool state, GameEventCreator & gameEventCreator) : state(state), gameEventCreator(gameEventCreator) {}

bool WithState::getState() const {
	return this->state;
}

void WithState::setState(const State state) {
	this->setState((bool) state);
}

void WithState::setState(const bool state) {
	this->state = state;
}
