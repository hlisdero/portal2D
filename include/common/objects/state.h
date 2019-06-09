#ifndef STATE_H
#define STATE_H

enum State {
    STATE_DEFAULT = 0,

	// EnergyReceiver, Button
	STATE_DISABLED = 0,
	STATE_ENABLED,

	// Door
	STATE_CLOSED = 0,
	STATE_OPEN
};

#endif  // STATE_H
