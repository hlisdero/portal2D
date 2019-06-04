#ifndef STATE_UPDATE_EVENT_H
#define STATE_UPDATE_EVENT_H

#include "common/events/world_event.h"
#include "server/entities/state.h"

class StateUpdateEvent : public WorldEvent {
public:
	StateUpdateEvent(int entityId, State newState);

private:
	int entityId;
	State newState;
};

#endif