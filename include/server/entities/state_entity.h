#ifndef STATE_ENTITY_H
#define STATE_ENTITY_H

#include "server/entities/m_entity.h"

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

class StateEntity : public MEntity {
public:
	StateEntity(const EntityType type, const float x, const float y, const float angle, const State state);
	
	bool getState() const;
	void setState(const State state);
	void setState(const bool state);
private:
	bool state;
};

#endif  // PLAYER_ENTITY_H