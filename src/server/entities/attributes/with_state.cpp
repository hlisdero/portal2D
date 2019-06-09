#include "server/entities/attributes/with_state.h"

WithState::WithState(const State state, GameEventCreator & gameEventCreator) : state(state), gameEventCreator(gameEventCreator) {}
WithState::WithState(const bool state, GameEventCreator & gameEventCreator) : state(state), gameEventCreator(gameEventCreator) {}

bool WithState::getState() const {
	return state;
}

void WithState::setState(const State newState) {
	if(newState != state) {
		gameEventCreator.addUpdateStateEvent((Entity*)this, newState);
	}
	setState((bool) newState);
}

void WithState::setState(const bool newState) {
	state = newState;
}
