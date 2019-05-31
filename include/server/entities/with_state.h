#ifndef WITH_STATE_H
#define WITH_STATE_H

#include "yaml-cpp/yaml.h"

enum State {
	// EnergyReceiver, Button
	STATE_DISABLED = 0,
	STATE_ENABLED,

	// Portal
	STATE_BLUE = 0,
	STATE_ORANGE,

	// Door
	STATE_CLOSED = 0,
	STATE_OPENED
};

class WithState {
public:
	WithState(const State state);
	WithState(const bool state);

	bool getState() const;
	void setState(const State state);
	virtual void setState(const bool state);

private:
	bool state;
};

#endif  // WITH_STATE_H
