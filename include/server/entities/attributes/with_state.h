#ifndef WITH_STATE_H
#define WITH_STATE_H

#include "yaml-cpp/yaml.h"
#include "common/objects/state.h"
#include "server/events/game_event_creator.h"

class WithState {
public:
	WithState(const State state, GameEventCreator & gameEventCreator);
	// TODO replace bool by int?
	WithState(const bool state, GameEventCreator & gameEventCreator);

	bool getState() const;
	void setState(const State state);
	virtual void setState(const bool state);

private:
	bool state;
	GameEventCreator & gameEventCreator;
};

#endif  // WITH_STATE_H
