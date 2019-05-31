#ifndef WITH_STATE_H
#define WITH_STATE_H

enum State {
	// EnergyReceiver, Button
	STATE_ENABLED = 0,
	STATE_DISABLED,

	// Portal
	COLOR_BLUE = 0,
	COLOR_ORANGE,

	// Door
	STATE_OPENED = 0,
	STATE_CLOSED
};
typedef enum State PortalColor;

class WithState {
public:
	WithState(const State state);
	WithState(const bool state);

	bool getState() const;
	void setState(const State state);
	void setState(const bool state);
private:
	bool state;
};

#endif  // WITH_STATE_H
