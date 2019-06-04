#ifndef STATE_H
#define STATE_H

enum State {
	// EnergyReceiver, Button
	STATE_DISABLED = 0,
	STATE_ENABLED,

	// Portal
	COLOR_BLUE = 0,
	COLOR_ORANGE,

	// Door
	STATE_CLOSED = 0,
	STATE_OPENED
};
typedef enum State PortalColor;

#endif  // STATE_H
