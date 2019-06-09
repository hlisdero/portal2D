#ifndef STATE_H
#define STATE_H

enum State {
	// EnergyReceiver, Button
	STATE_DISABLED = 0,
	STATE_ENABLED,

	// Door
	STATE_CLOSED = 0,
	STATE_OPENED
};

#endif  // STATE_H
