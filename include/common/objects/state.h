#ifndef STATE_H
#define STATE_H

enum State {
    STATE_DEFAULT = 0,

	// EnergyReceiver, Button
	STATE_DISABLED = 0,
	STATE_ENABLED,

	// Gate
	STATE_CLOSED = 0,
	STATE_OPEN,

    // Portal
    PORTAL_COLOR_BLUE = 0,
    PORTAL_COLOR_ORANGE,
};

#endif  // STATE_H
