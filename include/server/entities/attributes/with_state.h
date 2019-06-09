#ifndef WITH_STATE_H
#define WITH_STATE_H

#include "yaml-cpp/yaml.h"
#include "common/objects/state.h"

class WithState {
public:
	WithState(const State state);

	const State& getState() const;
	void setState(const State& new_state);

private:
	State state = STATE_DEFAULT;
};

#endif  // WITH_STATE_H
