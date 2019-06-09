#ifndef STATE_H
#define STATE_H

enum State {
    STATE_DEFAULT = 0,

	// EnergyReceiver, Button
	STATE_DISABLED = 0,
	STATE_ENABLED,

	// Portal
	COLOR_BLUE = 0,
	COLOR_ORANGE,

	// Door
	STATE_CLOSED = 0,
	STATE_OPEN
};
typedef enum State PortalColor;

#endif  // STATE_H
