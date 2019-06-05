#ifndef WITH_SUBSCRIBABLE_STATE_H
#define WITH_SUBSCRIBABLE_STATE_H

#include <unordered_set>

class WithSubscribableState;

#include "server/entities/door.h"
#include "server/entities/attributes/with_state.h"

class WithSubscribableState : public WithState {
public:
	// inherit constructors
	using WithState::WithState;

	void subscribe(DoorEntity * door);

	virtual void setState(const bool state) override;

private:
	std::unordered_set<DoorEntity*> subscribers;
};

#endif  // WITH_SUBSCRIBABLE_STATE_H
