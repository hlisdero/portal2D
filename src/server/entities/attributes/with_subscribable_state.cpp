#include "server/entities/attributes/with_subscribable_state.h"

void WithSubscribableState::subscribe(GateEntity * gate) {
	this->subscribers.insert(gate);
}

void WithSubscribableState::setState(const State& state) {
	WithState::setState(state);

	// notify subscribers
	for (auto subscriber : this->subscribers) {
		subscriber->updateState();
	}
}
