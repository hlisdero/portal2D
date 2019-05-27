#include "server/entities/with_state.h"

WithState::WithState(const State state) : state(state) {}
WithState::WithState(const bool state) : state(state) {}

bool WithState::getState() const {
	return this->state;
}

void WithState::setState(const State state) {
	this->state = state;
}
void WithState::setState(const bool state) {
	this->state = state;
}
