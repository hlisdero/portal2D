#ifndef WITH_SUBSCRIBABLE_STATE_H
#define WITH_SUBSCRIBABLE_STATE_H

#include <unordered_set>

class WithSubscribableState;

#include "server/entities/gate.h"
#include "server/entities/attributes/with_state.h"

class WithSubscribableState : public WithState {
public:
	// inherit constructors
	using WithState::WithState;

	void subscribe(GateEntity * gate);

	virtual void setState(const State& state) override;
	
	virtual ~WithSubscribableState() = default;

private:
	std::unordered_set<GateEntity*> subscribers;
};

#endif  // WITH_SUBSCRIBABLE_STATE_H
