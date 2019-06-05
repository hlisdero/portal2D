#include "server/entities/attributes/with_subscribable_state.h"

void WithSubscribableState::subscribe(DoorEntity * door) {
	this->subscribers.insert(door);
}

void WithSubscribableState::setState(const bool state) {
	WithState::setState(state);

	// notify subscribers
	for(auto subscriber : this->subscribers) {
		subscriber->updateState();
	}
}