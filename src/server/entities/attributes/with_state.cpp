#include "server/entities/attributes/with_state.h"

WithState::WithState(const State state) : state(state) {}

const State& WithState::getState() const {
	return state;
}

void WithState::setState(const State& new_state) {
	state = new_state;
}
