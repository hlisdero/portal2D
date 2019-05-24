#ifndef WITH_STATE_H
#define WITH_STATE_H

enum State {
	// EnergyReceiver, Button
	STATE_ENABLED = 0,
	STATE_DISABLED,

	// Portal
	STATE_BLUE = 0,
	STATE_ORANGE,

	// Door
	STATE_OPENED = 0,
	STATE_CLOSED
};

class WithState {
public:
	WithState(const State state);

	bool getState() const;
	void setState(const State state);
	void setState(const bool state);
private:
	bool state;
};

#endif  // WITH_STATE_H
