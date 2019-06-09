#ifndef WITH_STATE_H
#define WITH_STATE_H

#include "yaml-cpp/yaml.h"
#include "common/objects/state.h"
#include "server/events/game_event_creator.h"

class WithState {
public:
	WithState(const State state, GameEventCreator & gameEventCreator);

	const State& getState() const;
	virtual void setState(const State& new_state);

private:
	State state = STATE_DEFAULT;
	GameEventCreator & gameEventCreator;
};

#endif  // WITH_STATE_H
