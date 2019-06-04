#ifndef WITH_STATE_H
#define WITH_STATE_H

#include "yaml-cpp/yaml.h"
#include "server/entities/state.h"

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
