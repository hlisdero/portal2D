#ifndef DYNAMICS_UPDATE_EVENT_H
#ifndef DYNAMICS_UPDATE_EVENT_H

#include "server/events/world_event.h"

class DynamicsUpdateEvent : public WorldEvent {
public:
	DynamicsUpdateEvent(std::vector<Entity*> entities);

private:
}

#endif